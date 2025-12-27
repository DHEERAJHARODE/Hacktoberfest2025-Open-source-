import javax.crypto.Cipher;
import java.security.KeyPair;
import java.security.KeyPairGenerator;
import java.security.PrivateKey;
import java.security.PublicKey;
import java.util.*;

public class CaesarRSA {

    private PrivateKey privateKey;
    private PublicKey publicKey;

    public static void main(String[] args) {
        CaesarRSA rsa = new CaesarRSA();
        String input = "";
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter your encrypted message : ");
        input = sc.nextLine();
        System.out.print("Enter your Shift : ");
        int shift = sc.nextInt();
        String ciphertext = "";
        char ExtractedCharacter;
        for (int i = 0; i < input.length(); i++) {
            ExtractedCharacter = input.charAt(i);
            if (ExtractedCharacter >= 'a' && ExtractedCharacter <= 'z') {
                ExtractedCharacter = (char) (ExtractedCharacter + shift);
                if (ExtractedCharacter > 'z') {
                    ExtractedCharacter = (char) (ExtractedCharacter + 'a' - 'z' - 1);
                }
                ciphertext = ciphertext + ExtractedCharacter;
            } else if (ExtractedCharacter >= 'A' && ExtractedCharacter <= 'Z') {
                ExtractedCharacter = (char) (ExtractedCharacter + shift);
                if (ExtractedCharacter > 'Z') {
                    ExtractedCharacter = (char) (ExtractedCharacter + 'A' - 'Z' - 1);
                }
                ciphertext = ciphertext + ExtractedCharacter;
            } else {
                ciphertext = ciphertext + ExtractedCharacter;
            }
        }
        System.out.println("Your encrypted caesar message is  : " + ciphertext);

        try {
            String encryptedMessage = rsa.encrypt(ciphertext);
            String decryptedMessage = rsa.decrypt(encryptedMessage);

            System.out.println("Encrypted RSA : " + encryptedMessage);
            System.out.println("Decrypted RSA : " + decryptedMessage);
        } catch (Exception ingored) {
        }
        
        String Decryption = "";
        for (int i = 0; i < ciphertext.length(); i++) {
            char ExtractedCharacters = ciphertext.charAt(i);
            if (ExtractedCharacters >= 'a' && ExtractedCharacters <= 'z') {
                ExtractedCharacter = (char) (ExtractedCharacters - shift);
                if (ExtractedCharacter < 'a') {
                    ExtractedCharacter = (char) (ExtractedCharacter - 'a' + 'z' + 1);
                }
                Decryption = Decryption + ExtractedCharacter;
            } else if (ExtractedCharacters >= 'A' && ExtractedCharacters <= 'Z') {
                ExtractedCharacter = (char) (ExtractedCharacters - shift);
                if (ExtractedCharacter < 'A') {
                    ExtractedCharacter = (char) (ExtractedCharacter - 'A' + 'Z' + 1);
                }
                Decryption = Decryption + ExtractedCharacter;
            } else {
                Decryption = Decryption + ExtractedCharacters;
            }
        }
        System.out.println("Your Decrypted message using Caesar  : " + Decryption);
    }

    public CaesarRSA() {
        try {
            KeyPairGenerator generator = KeyPairGenerator.getInstance("RSA");
            generator.initialize(512);
            KeyPair pair = generator.generateKeyPair();
            privateKey = pair.getPrivate();
            publicKey = pair.getPublic();
        } catch (Exception ignored) {
        }
    }

    public String encrypt(String message) throws Exception {
        byte[] messageToBytes = message.getBytes();
        Cipher cipher = Cipher.getInstance("RSA/ECB/PKCS1Padding");
        cipher.init(Cipher.ENCRYPT_MODE, publicKey);
        byte[] encryptedBytes = cipher.doFinal(messageToBytes);
        return encode(encryptedBytes);
    }

    private String encode(byte[] data) {
        return Base64.getEncoder().encodeToString(data);
    }

    public String decrypt(String encryptedMessage) throws Exception {
        byte[] encryptedBytes = decode(encryptedMessage);
        Cipher cipher = Cipher.getInstance("RSA/ECB/PKCS1Padding");
        cipher.init(Cipher.DECRYPT_MODE, privateKey);
        byte[] decryptedMessage = cipher.doFinal(encryptedBytes);
        return new String(decryptedMessage, "UTF8");
    }

    private byte[] decode(String data) {
        return Base64.getDecoder().decode(data);
    }
}