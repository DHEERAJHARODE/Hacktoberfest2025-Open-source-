// aes_gcm.c
// AES-256-GCM encrypt/decrypt with password-derived key (PBKDF2)
// Compile: gcc aes_gcm.c -o aes_gcm -lcrypto
// Usage  : ./aes_gcm "plaintext here" "your-password"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <openssl/evp.h>
#include <openssl/rand.h>

#define SALT_LEN 16
#define IV_LEN   12
#define KEY_LEN  32   // 256-bit
#define TAG_LEN  16
#define PBKDF2_ITERS 200000

static void print_hex(const char *label, const uint8_t *buf, size_t len) {
    printf("%s", label);
    for (size_t i = 0; i < len; i++) printf("%02x", buf[i]);
    printf("\n");
}

static int derive_key(const char *password, const uint8_t *salt, uint8_t *out_key) {
    // Derive 256-bit key from password using PBKDF2-HMAC-SHA256
    if (!PKCS5_PBKDF2_HMAC(password, (int)strlen(password),
                           salt, SALT_LEN, PBKDF2_ITERS,
                           EVP_sha256(), KEY_LEN, out_key)) {
        return 0;
    }
    return 1;
}

static int aes_gcm_encrypt(const uint8_t *key,
                           const uint8_t *iv, size_t iv_len,
                           const uint8_t *plaintext, int pt_len,
                           uint8_t *ciphertext, uint8_t *tag) {
    int len, ct_len;
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    if (!ctx) return -1;

    if (1 != EVP_CIPHER_CTX_ctrl(ctx, EVP_CTRL_AEAD_SET_IVLEN, (int)iv_len, NULL)) { EVP_CIPHER_CTX_free(ctx); return -1; }
    if (1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_gcm(), NULL, NULL, NULL)) { EVP_CIPHER_CTX_free(ctx); return -1; }
    if (1 != EVP_EncryptInit_ex(ctx, NULL, NULL, key, iv)) { EVP_CIPHER_CTX_free(ctx); return -1; }

    if (1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, pt_len)) { EVP_CIPHER_CTX_free(ctx); return -1; }
    ct_len = len;

    if (1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len)) { EVP_CIPHER_CTX_free(ctx); return -1; }
    ct_len += len;

    if (1 != EVP_CIPHER_CTX_ctrl(ctx, EVP_CTRL_AEAD_GET_TAG, TAG_LEN, tag)) { EVP_CIPHER_CTX_free(ctx); return -1; }

    EVP_CIPHER_CTX_free(ctx);
    return ct_len;
}

static int aes_gcm_decrypt(const uint8_t *key,
                           const uint8_t *iv, size_t iv_len,
                           const uint8_t *ciphertext, int ct_len,
                           const uint8_t *tag,
                           uint8_t *plaintext_out) {
    int len, pt_len;
    int ret = -1;
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    if (!ctx) return -1;

    if (1 != EVP_CIPHER_CTX_ctrl(ctx, EVP_CTRL_AEAD_SET_IVLEN, (int)iv_len, NULL)) goto end;
    if (1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_gcm(), NULL, NULL, NULL)) goto end;
    if (1 != EVP_DecryptInit_ex(ctx, NULL, NULL, key, iv)) goto end;

    if (1 != EVP_DecryptUpdate(ctx, plaintext_out, &len, ciphertext, ct_len)) goto end;
    pt_len = len;

    if (1 != EVP_CIPHER_CTX_ctrl(ctx, EVP_CTRL_AEAD_SET_TAG, TAG_LEN, (void *)tag)) goto end;

    if (1 != EVP_DecryptFinal_ex(ctx, plaintext_out + len, &len)) {
        // Auth failed (wrong password/IV/tag/ciphertext)
        pt_len = -1;
        goto end;
    }
    pt_len += len;
    ret = pt_len;

end:
    EVP_CIPHER_CTX_free(ctx);
    return ret;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s \"plaintext\" \"password\"\n", argv[0]);
        return 1;
    }
    const char *plaintext = argv[1];
    const char *password  = argv[2];
    int pt_len = (int)strlen(plaintext);

    uint8_t salt[SALT_LEN], iv[IV_LEN], key[KEY_LEN], tag[TAG_LEN];

    if (1 != RAND_bytes(salt, SALT_LEN)) { fprintf(stderr, "RAND salt failed\n"); return 1; }
    if (1 != RAND_bytes(iv, IV_LEN)) { fprintf(stderr, "RAND iv failed\n"); return 1; }
    if (!derive_key(password, salt, key)) { fprintf(stderr, "PBKDF2 failed\n"); return 1; }

    uint8_t *ciphertext = malloc(pt_len + 16); // GCM may return same size; reserve a bit extra
    if (!ciphertext) { fprintf(stderr, "malloc failed\n"); return 1; }

    int ct_len = aes_gcm_encrypt(key, iv, IV_LEN, (const uint8_t *)plaintext, pt_len, ciphertext, tag);
    if (ct_len <= 0) { fprintf(stderr, "Encrypt failed\n"); free(ciphertext); return 1; }

    print_hex("SALT      : ", salt, SALT_LEN);
    print_hex("IV        : ", iv, IV_LEN);
    print_hex("CIPHERTEXT: ", ciphertext, ct_len);
    print_hex("TAG       : ", tag, TAG_LEN);

    // Demonstrate decrypt:
    uint8_t *decrypted = malloc(ct_len + 1);
    if (!decrypted) { fprintf(stderr, "malloc failed\n"); free(ciphertext); return 1; }

    int dec_len = aes_gcm_decrypt(key, iv, IV_LEN, ciphertext, ct_len, tag, decrypted);
    if (dec_len < 0) {
        fprintf(stderr, "Decrypt failed (auth error)\n");
        free(ciphertext); free(decrypted);
        return 1;
    }
    decrypted[dec_len] = '\0';
    printf("DECRYPTED : %s\n", decrypted);

    free(ciphertext);
    free(decrypted);
    return 0;
}
