

import java.security.InvalidKeyException;
import java.security.KeyFactory;
import java.security.KeyPair;
import java.security.KeyPairGenerator;
import java.security.NoSuchAlgorithmException;
import java.security.PrivateKey;
import java.security.PublicKey;
import java.security.spec.InvalidKeySpecException;
import java.security.spec.PKCS8EncodedKeySpec;
import java.security.spec.X509EncodedKeySpec;
import java.util.Base64;
import java.util.HashMap;
import java.util.Map;

import javax.crypto.BadPaddingException;
import javax.crypto.Cipher;
import javax.crypto.IllegalBlockSizeException;
import javax.crypto.NoSuchPaddingException;

public class RsaCryptoUtil {
    private final static String CRYPTO_METHOD = "RSA";
    private final static int CRYPTO_BITS = 1024;
    public static Map<String, String> map;

    public static Map<String, String> generateKeyPair()
            throws NoSuchAlgorithmException {
        map = new HashMap<>();
        KeyPairGenerator kpg = KeyPairGenerator.getInstance(CRYPTO_METHOD);
        kpg.initialize(CRYPTO_BITS);
        KeyPair kp = kpg.genKeyPair();
        PublicKey publicKey = kp.getPublic();
        PrivateKey privateKey = kp.getPrivate();
        map.put("privateKey", Base64.getEncoder().encodeToString(privateKey.getEncoded()));
        map.put("publicKey", Base64.getEncoder().encodeToString(publicKey.getEncoded()));
        return map;
    }


    public static String encryptUsingPublicKey(String plain, String pubk)
            throws NoSuchAlgorithmException,
            NoSuchPaddingException,
            InvalidKeyException,
            IllegalBlockSizeException,
            BadPaddingException,
            InvalidKeySpecException {

        Cipher cipher = Cipher.getInstance("RSA/ECB/PKCS1Padding");
        cipher.init(Cipher.ENCRYPT_MODE, stringToPublicKey(pubk));
        byte[] encryptedBytes = cipher.doFinal(plain.getBytes());

        return Base64.getEncoder().encodeToString(encryptedBytes);
    }


    public static PrivateKey getPrivateKey(byte[] keyBytes) throws NoSuchAlgorithmException,
            InvalidKeySpecException {
        PKCS8EncodedKeySpec keySpec = new PKCS8EncodedKeySpec(keyBytes);
        KeyFactory keyFactory = KeyFactory.getInstance(CRYPTO_METHOD);
        return keyFactory.generatePrivate(keySpec);
    }

    public static String decryptDataUsingPrivateKey(String text, String privk) {
        try {
            byte[] data = Base64.getDecoder().decode(text);
            PrivateKey privateKey = getPrivateKey(Base64.getDecoder().decode(privk.getBytes("utf-8")));

            Cipher cipher = Cipher.getInstance(CRYPTO_METHOD);
            cipher.init(Cipher.DECRYPT_MODE, privateKey);
            return new String(cipher.doFinal(data), "utf-8");
        } catch (Exception e) {
            return null;
        }
    }


    private static PublicKey stringToPublicKey(String publicKeyString)
            throws InvalidKeySpecException,
            NoSuchAlgorithmException {

        byte[] keyBytes = Base64.getDecoder().decode(publicKeyString);
        X509EncodedKeySpec spec = new X509EncodedKeySpec(keyBytes);
        KeyFactory keyFactory = KeyFactory.getInstance(CRYPTO_METHOD);
        return keyFactory.generatePublic(spec);
    }

    private static PrivateKey stringToPrivateKey(String privateKeyString)
            throws InvalidKeySpecException,
            NoSuchAlgorithmException {

        byte[] pkcs8EncodedBytes = Base64.getDecoder().decode(privateKeyString);
        PKCS8EncodedKeySpec keySpec = new PKCS8EncodedKeySpec(pkcs8EncodedBytes);
        KeyFactory kf = KeyFactory.getInstance(CRYPTO_METHOD);
        return kf.generatePrivate(keySpec);
    }

    public static void main(String[] args) throws NoSuchAlgorithmException, NoSuchPaddingException, IllegalBlockSizeException, BadPaddingException, InvalidKeySpecException, InvalidKeyException {
        Map<String, String> keys = generateKeyPair();
        String publicKey = keys.get("publicKey");
        String privateKey = keys.get("privateKey");

        System.out.println("publicKey-------->" + publicKey);
        System.out.println("privateKey-------->" + privateKey);


        String data = "SecretData";
        String encryptedData = encryptUsingPublicKey(data, publicKey);
        String decryptedData = decryptDataUsingPrivateKey(encryptedData, privateKey);

        System.out.println("encryptedData-------->" + encryptedData);
        System.out.println("decryptedData-------->" + decryptedData);


    }
}
