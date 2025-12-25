import java.math.BigInteger;  
import java.security.NoSuchAlgorithmException;  
import java.security.NoSuchProviderException;  
import java.security.MessageDigest;  
import java.security.SecureRandom;  


public class Hashing   
{  
public static byte[] receiveSalt() throws NoSuchAlgorithmException  
{  
SecureRandom secRand = SecureRandom.getInstance("SHA1PRNG");  

byte[] s = new byte[15];  

secRand.nextBytes(s);  

return s;  
}  

private static String getSecurePswd(String psdToHash, byte[] saltArr)  
{  

String generatedPswd = null;  
try   
{  

MessageDigest msgDigest = MessageDigest.getInstance("MD5");  

msgDigest.update(saltArr);  

byte[] b = msgDigest.digest(psdToHash.getBytes());  

StringBuilder sbObj = new StringBuilder();  

for(int i = 0; i < b.length ; i++)  
{  
sbObj.append(Integer.toString((b[i] & 0xff) + 0x100, 16).substring(1));  
}  
// Get the complete hashed password in the hex format  
generatedPswd = sbObj.toString();  
}   


catch (NoSuchAlgorithmException obj)   
{  
obj.printStackTrace();  
}  

return generatedPswd;  
}  

public static void main(String argvs[]) throws NoSuchProviderException, NoSuchAlgorithmException  
{  
String str = "JavaTpoint"; 
byte[] saltArr = receiveSalt();  

String securePsd = getSecurePswd(str, saltArr);  
System.out.println("The HashCode Generated for " + str + " is: " + securePsd);  
String regeneratedPswdToVerify = getSecurePswd(str, saltArr);  
System.out.println("The HashCode Generated for " + str + " is: " + securePsd);  
}  
}  
