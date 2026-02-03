def generateKey(string, key): 
  key = list(key) 
  if len(string) == len(key): 
    return(key) 
  else: 
    for i in range(len(string) -len(key)): 
      key.append(key[i % len(key)]) 
  return("" . join(key)) 
  
def encrypt(string, key): 
  encrypt_text = [] 
  for i in range(len(string)): 
    x = (ord(string[i]) +ord(key[i])) % 26
    x += ord('A') 
    encrypt_text.append(chr(x)) 
  return("" . join(encrypt_text)) 
def decrypt(encrypt_text, key): 
  original = [] 
  for i in range(len(encrypt_text)): 
    x = (ord(encrypt_text[i]) -ord(key[i]) + 26) % 26
    x += ord('A') 
    original.append(chr(x)) 
  return("" . join(original))

if __name__ == "__main__": 
  string = input("Enter the message: ")
  keyword = input("Enter the key: ")
  key = generateKey(string, keyword) 
  encrypt_text = encrypt(string,key) 
  print("Encrypted message is:", encrypt_text) 
  print("Decrypted message is:", decrypt(encrypt_text, key)) 
