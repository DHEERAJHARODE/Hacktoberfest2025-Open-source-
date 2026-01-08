import javax.crypto.Cipher;
import javax.crypto.spec.SecretKeySpec;
import java.util.Base64;

public class AESCryptoUtil {

    public static String encrypt(byte[] content) {
        try {
            byte byte_key[] = new byte[]{0x42, 0x43, 0x39, 0x35, 0x41, 0x41, 0x31, 0x31, 0x43, 0x38, 0x43, 0x37, 0x30, 0x37, 0x37, 0x36, 0x37, 0x41, 0x44, 0x31, 0x33, 0x45, 0x46, 0x38, 0x30, 0x37, 0x44, 0x34, 0x34, 0x44, 0x35, 0x31};
            SecretKeySpec key = new SecretKeySpec(byte_key, "AES"); // keyBytes32个字节，256位，
            Cipher cipher = Cipher.getInstance("AES/ECB/PKCS5Padding");// 创建密码器
            cipher.init(Cipher.ENCRYPT_MODE, key);
            byte[] result = cipher.doFinal(content);
            return Base64.getEncoder().encodeToString(result);
        } catch (Exception e) {
            e.printStackTrace();
        }
        return null;
    }

    public static String decrypt(final String strToDecrypt) {
        byte[] output = null;
        try {
            byte byte_key[] = new byte[]{0x42, 0x43, 0x39, 0x35, 0x41, 0x41, 0x31, 0x31, 0x43, 0x38, 0x43, 0x37, 0x30, 0x37, 0x37, 0x36, 0x37, 0x41, 0x44, 0x31, 0x33, 0x45, 0x46, 0x38, 0x30, 0x37, 0x44, 0x34, 0x34, 0x44, 0x35, 0x31};
            SecretKeySpec skey = new SecretKeySpec(byte_key, "AES");
            Cipher cipher = Cipher.getInstance("AES/ECB/PKCS5Padding");
            cipher.init(Cipher.DECRYPT_MODE, skey);
            output = cipher.doFinal(Base64.getDecoder().decode(strToDecrypt));
        } catch (Exception e) {
            System.out.println(e.toString());
        }
        return new String(output);
    }

    public static void main(String[] args) {
        String clear_text = "Hello Nerds!";
        String encrypted_data = encrypt(clear_text.getBytes());
        System.out.println(encrypted_data);
        String decrypted_date = decrypt(encrypted_data);
        System.out.println(decrypted_date);

    }
}
