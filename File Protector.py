import random
import pyperclip
import mysql.connector as sql 
from tkinter import *
from tkinter import ttk
from datetime import datetime
from PIL import ImageTk,Image


mycon=sql.connect(host="localhost",user="root",passwd="sahil@3023",database='history')
if mycon.is_connected()==True:  
    print("Connected")

cur=mycon.cursor()

stmt='''create table if not exists main_table(
s_no int unique auto_increment,
original_txt varchar(6500) not null,
processed_txt varchar(6500) not null,
pass_id int(50) not null,
mode varchar(30) not null,
work varchar(15) not null,
time datetime);'''
cur.execute(stmt)

stmt='''create table if not exists delete_part(
s_no int unique auto_increment,
original_txt varchar(6500) not null,
processed_txt varchar(6500) not null,
pass_id int(50) not null,
mode varchar(30) not null,
work varchar(15) not null,
time_of_work datetime,
dlt_time datetime)'''
cur.execute(stmt)


#########################################

def encryption_window():
    def txt_pass_encryption():
        def encrypt_method_1(pass_num,message):
            pass_num3 = pass_num
            if pass_num >= 26 or pass_num==0:
                pass_num=pass_num%26
                if pass_num == 0:
                    pass_num = 17
            a = "abcdefghijklmnopqrstuvwxyz"
            A="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            num = "0123456789"#intialised data
            encrypt = ""#empty string in which concatition takes place
            for i in message:
                
                s=0#value that will receive encryption indentation
                
                if i in A:#encrption of upper case
                    new_indent = A.find(i)#indentation from intitialised data
                    s = new_indent + pass_num#if message= Z and Pass=1 then encryption should be A, new_indent=25(index of Z in variable A) and s=26
                    if s > 25:#limiting value according to intialised data (INDEX VALUE LIMIT)- last index value 25 of A
                        s = s % 25
                        if s != 0:
                            encrypt +=A[s-1]#26 % 25 = 1, now s = 1,so we need to move one block but  A[1]=B, but we need result A by (A[s-1])= A
                        else:
                            encrypt += A[24]
                    elif s <= 25:#in limit of last index
                        encrypt += A[s]
                        
                elif i in a:#lower case encryption
                    new_indent = a.find(i)
                    s = new_indent + pass_num
                    if s > 25:#limiting value (INDEX VALUE LIMIT)
                        s = s % 25
                        if s != 0:
                            encrypt += a[s-1]
                        else:# if pass=25 and message=z then encryption should be y
                            encrypt += a[24]
                    elif s <= 25:#in limit (INDEX VALUE LIMIT)
                        encrypt += a[s]
                        
                elif i in num:#num encryption
                    new_indent = num.find(i)
                    if pass_num>=10:
                        pass_num2=pass_num%10
                        if pass_num2==0:
                            pass_num2=4#using pass_num2 instead of pass_num as it will change its value
                        s= new_indent + pass_num2
                    else:
                        s = new_indent + pass_num#if pass num<10
                    if s>9:#limiting if s is greater by 9
                        s = s % 9
                        encrypt += num[s-1]
                    elif s <= 9:#in limit of 9 (INDEX VALUE LIMIT)
                        encrypt += num[s]
                        
                elif i ==" ":#for spaces
                    space_list = ["¥","€","¢","©","®","™","¶","•","¥","✓"]#special character in place of space
                    encrypt += (random.choice(space_list))#random character

                else:
                    char_dict={"@":"$" , "$":"&" , "\n":"∆" , "&":"π" , ".":"@" , "(":"}" , ")":"{" , "[":">" , "]":"/" , "{":"<" , "}":"=" , "<":"(" , ">":")" , "/":"[" , ":":"." , "=":"]" , "-":"^" , "+":"%" , "%":"-" , ",":"*" , "?":"\"" , "!":"\'" , "\'":"?" , "\"":"!","_":";"}
        #created dictionary for special characters and independent of pass__num value
                    if i in char_dict:
                        encrypt+=char_dict[i]
                    else:#if any special character is missed
                        print("THERE IS A PROBLEM IN ENCRYPTING FILE...")
           
            print("encrypted message :",encrypt)
            pyperclip.copy(encrypt)
            print("Encrypted Message Copied To Clipboard ...")

            time = datetime.now().strftime('%Y-%m-%d %H:%M:%S')
            stmt="insert into main_table (original_txt, processed_txt, pass_id, mode, work, time) values ('{}','{}',{},'{}','{}','{}')".format(message,encrypt,pass_num3 ,"Caeser Cipher",'Encryption',time)
            cur.execute(stmt) 
            mycon.commit()
            
        def encrypt_method_2(key,mssg):
            pass_num=key
            if key > 9:#key reducing method
                key=str(key)#to add all number and should not greater than 9
                added_value = 0#adding all number should be less then 10
                s=0 #intialising value in which limitation of number will take place
                for i in range (0,len(key)):
                    num=int(key[i])
                    s+=num
                    if s >9:
                        s=str(s)
                        s1,s2=s[0],s[1]
                        s1,s2=int(s1),int(s2)
                        s=s1+s2
                key = s

            if key == 0 or key == 1:
                key=4

            encrypt=[""] * key

            for colum in range(key):#encrypting method
                pointer = colum
                while pointer < len(mssg):#algo
                    encrypt[colum] += mssg[pointer]
                    pointer += key
                    
            for i in range(1,key):#adding dummy character if characters are less
                if len(encrypt[0])!= len(encrypt[i]):
                    encrypt[i]+=" "
            encryption="".join(encrypt) + "|"
            print("Encrypted Message =",encryption)
            pyperclip.copy(encryption)
            print("Message Copied To Clipboard ...")

            time = datetime.now().strftime('%Y-%m-%d %H:%M:%S')
            stmt="insert into main_table (original_txt, processed_txt, pass_id, mode, work, time) values ('{}','{}',{},'{}','{}','{}')".format(mssg,encryption,pass_num,"Transpose Cipher",'Encryption',time)
            cur.execute(stmt)
            mycon.commit()

        def encrypt_method_3(mssg,pass_num):
    
            A = {'A':'N','N':'A','B':'O','O':'B','C':'P','P':'C','D':'Q','Q':'D','E':'R','R':'E','F':'S','S':'F','G':'T','T':'G','H':'U','U':'H','I':'V','V':'I','J':'W','W':'J','K':'X','X':'K','L':'Y','Y':'L','M':'Z','Z':'M'}
            a = {'a':'n','n':'a','b':'o','o':'b','c':'p','p':'c','d':'q','q':'d','e':'r','r':'e','f':'s','s':'f','g':'t','t':'g','h':'u','u':'h','i':'v','v':'i','j':'w','w':'j','k':'x','x':'k','l':'y','y':'l','m':'z','z':'m'}
            num={'0':'5','5':'0','1':'6','6':'1','2':'7','7':'2','3':'8','8':'3','4':'9','9':'4'}
            char_dict={"@":"$" , "$":"&" , "\n":"∆" , "&":"π" , ".":"@" , "(":"}" , ")":"{" , "[":">" , "]":"/" , "{":"<" , "}":"=" , "<":"(" , ">":")" , "/":"[" , ":":"." , "=":"]" , "-":"^" , "+":"%" , "%":"-" , ",":"*" , "?":"\"" , "!":"\'" , "\'":"?" , "\"":"!","_":";"}
            space_list = ["¥","€","¢","©","®","™","¶","•","¥","✓"]#special character in place of space
            encrypt=""
            for i in mssg:
                if i in A:#upper letter
                    encrypt+=A[i]
                elif i in a:#lower letter
                    encrypt+=a[i]
                elif i in num:
                    encrypt+=num[i]#number
                elif i ==" ":#for spaces
                    encrypt += (random.choice(space_list))#random character
                else:#special charaer
                    if i in char_dict:
                        encrypt+=char_dict[i]
                    else:#if any special character is missed
                        print("THERE IS A PROBLEM IN ENCRYPTING FILE...")
            print("Encrypted Message :",encrypt)
            pyperclip.copy(encrypt)
            print("Encrypted Message Copied To Clipboard ...")

            time = datetime.now().strftime('%Y-%m-%d %H:%M:%S')
            stmt="insert into main_table (original_txt, processed_txt, pass_id, mode, work, time) values ('{}','{}',{},'{}','{}','{}')".format(mssg,encrypt,pass_num,"Substitution Cipher",'Encryption',time)
            cur.execute(stmt)
            mycon.commit()

        def encrypt_method_4(pass_num,key,message):

            pass_num3 = pass_num
            #TRANSPOSE ENCRYPTION
            if key > 9:#key reducing method
                key=str(key)#to add all number and should not greater than 9
                added_value = 0#adding all number should be less then 10
                g=0 #intialising value in which limitation of number will take place
                for i in range (0,len(key)):
                    num=int(key[i])
                    g+=num
                    if g >9:
                        g=str(g)
                        g1,g2=g[0],g[1]
                        g1,g2=int(g1),int(g2)
                        g=g1+g2

                key = g

            if key == 0 or key == 1:
                key=4

            encrypt1=[""] * key
            for colum in range(key):#encrypting method
                pointer = colum
                while pointer < len(message):#algo
                    encrypt1[colum] += message[pointer]
                    pointer += key
                
            for i in range(1,key):#adding dummy character if characters are less
                if len(encrypt1[0])!= len(encrypt1[i]):
                    encrypt1[i]+=" "
            encrypted="".join(encrypt1)

            #SUBSTITTION ENCRYPTION NOW
            A = {'A':'N','N':'A','B':'O','O':'B','C':'P','P':'C','D':'Q','Q':'D','E':'R','R':'E','F':'S','S':'F','G':'T','T':'G','H':'U','U':'H','I':'V','V':'I','J':'W','W':'J','K':'X','X':'K','L':'Y','Y':'L','M':'Z','Z':'M'}
            a = {'a':'n','n':'a','b':'o','o':'b','c':'p','p':'c','d':'q','q':'d','e':'r','r':'e','f':'s','s':'f','g':'t','t':'g','h':'u','u':'h','i':'v','v':'i','j':'w','w':'j','k':'x','x':'k','l':'y','y':'l','m':'z','z':'m'}
            num={'0':'5','5':'0','1':'6','6':'1','2':'7','7':'2','3':'8','8':'3','4':'9','9':'4'}
            encrypt2 = ""
            for i in encrypted:
                if i in A:#upper letter
                    encrypt2 += A[i]
                elif i in a:#lower letter
                    encrypt2 += a[i]
                elif i in num:
                    encrypt2 += num[i]#number
                else:
                    encrypt2 += i

            #CAESER CIPHER
            if pass_num >= 26 or pass_num==0:
                pass_num=pass_num%26
                if pass_num == 0:
                    pass_num = 17

            a = "abcdefghijklmnopqrstuvwxyz"
            A="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            num = "0123456789"#intialised data
            
            encrypt3 = ""#empty string in which concatition takes place
            for i in encrypt2:
                
                s=0#value that will receive encryption indentation
                
                if i in A:#encrption of upper case
                    new_indent = A.find(i)#indentation from intitialised data
                    s = new_indent + pass_num#if message= Z and Pass=1 then encryption should be A, new_indent=25(index of Z in variable A) and s=26
                    if s > 25:#limiting value according to intialised data (INDEX VALUE LIMIT)- last index value 25 of A
                        s = s % 25
                        if s != 0:
                            encrypt3 +=A[s-1]#26 % 25 = 1, now s = 1,so we need to move one block but  A[1]=B, but we need result A by (A[s-1])= A
                        else:
                            encrypt3 += A[24]
                    elif s <= 25:#in limit of last index
                        encrypt3 += A[s]
                        
                elif i in a:#lower case encryption
                    new_indent = a.find(i)
                    s = new_indent + pass_num
                    if s > 25:#limiting value (INDEX VALUE LIMIT)
                        s = s % 25
                        if s != 0:
                            encrypt3 += a[s-1]
                        else:# if pass=25 and message=z then encryption should be y
                            encrypt3 += a[24]
                    elif s <= 25:#in limit (INDEX VALUE LIMIT)
                        encrypt3 += a[s]
                        
                elif i in num:#num encryption
                    new_indent = num.find(i)
                    if pass_num>=10:
                        pass_num2=pass_num%10
                        if pass_num2==0:
                            pass_num2=4#using pass_num2 instead of pass_num as it will change its value
                        s= new_indent + pass_num2
                    else:
                        s = new_indent + pass_num#if pass num<10
                    if s>9:#limiting if s is greater by 9
                        s = s % 9
                        encrypt3 += num[s-1]
                    elif s <= 9:#in limit of 9 (INDEX VALUE LIMIT)
                        encrypt3 += num[s]
                        
                elif i ==" ":#for spaces
                    space_list = ["¥","€","¢","©","®","™","¶","•","¥","✓"]#special character in place of space
                    encrypt3 += (random.choice(space_list))#random character

                else:
                    char_dict={"@":"$" , "$":"&" , "\n":"∆" , "&":"π" , ".":"@" , "(":"}" , ")":"{" , "[":">" , "]":"/" , "{":"<" , "}":"=" , "<":"(" , ">":")" , "/":"[" , ":":"." , "=":"]" , "-":"^" , "+":"%" , "%":"-" , ",":"*" , "?":"\"" , "!":"\'" , "\'":"?" , "\"":"!","_":";"}
                    #created dictionary for special characters and independent of pass__num value
                    if i in char_dict:
                         encrypt3 += char_dict[i]
                    else:#if any special character is missed
                        print("THERE IS A PROBLEM IN ENCRYPTING FILE...")
                        exit

            print("encrypted message =",encrypt3)
            pyperclip.copy(encrypt3)
            print("Encrypted Message Copied To Clipboard ...")

            time = datetime.now().strftime('%Y-%m-%d %H:%M:%S')
            stmt="insert into main_table (original_txt, processed_txt, pass_id, mode, work, time) values ('{}','{}',{},'{}','{}','{}')".format(message,encrypt3,pass_num3,"Mixed Cipher",'Encryption',time)
            cur.execute(stmt)
            mycon.commit()

        message=str(mssg_entry.get())#message to be encrypted
        print(message)
        pass_num=int(pass_entry.get())#pass value according to which encryption takes place
        print(pass_num)
        key = pass_num
        mssg_entry.delete(0,END)
        pass_entry.delete(0,END)


        win3=Tk()
        win3.geometry('625x415')
        win3.resizable(0,0)
        win3.title("Encryption Mode")
        win3.configure(bg='#78866B')
        
        '''image = Image.open("bg.jpg")
        photo = ImageTk.PhotoImage(image)
        Label(win3,image=photo).pack()'''

        Label(win3,text='Select One Mode For Encryption',bg='black',fg='grey',padx=4,pady=5,borderwidth=4,relief='sunken').place(x=220,y=40)
        Button(win3,text="Caeser Cipher",bg='#B8860B',font='10',command=lambda:encrypt_method_1(pass_num,message)).place(x=120,y=120)
        Button(win3,text="Transpose Cipher",bg='#B8860B',font='10',command=lambda:encrypt_method_2(pass_num,message)).place(x=380,y=120)
        Button(win3,text="Substitution Cipher",bg='#B8860B',font='10',command=lambda:encrypt_method_3(message,pass_num)).place(x=380,y=210)
        Button(win3,text="Mixed Cipher",bg='#B8860B',font='10',command=lambda:encrypt_method_4(pass_num,key,message)).place(x=120,y=210)
        Label(win3,text='NOTE : Encrypted Messeage Will Be Directly Copied To Clipboard',bg='#900020',fg='white',padx=4,pady=4,borderwidth=10,relief='flat').place(x=140,y=300)
        win3.mainloop()


    win2=Tk()
    win2.geometry('625x415')
    win2.resizable(0,0)
    win2.title('Encryption Window')
    win2.configure(bg='#78866B')
    
    '''image = Image.open("bg.jpg")
        photo = ImageTk.PhotoImage(image)
        Label(win2,image=photo).pack()'''  

    Label(win2,text='Enter Text To Encrypt : ',bg='#78866B').place(x=150,y=80)
    Label(win2,text='Enter Numeric Password : ',bg='#78866B').place(x=150,y=102)
    mssg_var=StringVar()
    mssg_entry=Entry(win2,textvariable=mssg_var)
    mssg_entry.place(x=290,y=80)
    pass_var=StringVar()
    pass_entry=Entry(win2,textvariable=pass_var,show='*')
    pass_entry.place(x=290,y=102)
    Button(win2,text="Submit",bg='#5D8AA8',pady=4,padx=5,command=txt_pass_encryption).place(x=270,y=135)
    win2.mainloop()

####################################

def decryption_window():
    def txt_pass_decryption():
        message=str(mssg_entry.get())#message to be decrypted
        print(message)
        pass_num=int(pass_entry.get())#pass value according to which encryption takes place
        print(pass_num)
        key = pass_num
        mssg_entry.delete(0,END)
        pass_entry.delete(0,END)


        def decrypt_method_1(pass_num,encrypted_message):
            pass_num3 = pass_num
    
            if pass_num >=26 or pass_num==0:
                pass_num = pass_num % 26
                if pass_num==0:
                    pass_num=17
            decrypt=""
            for i in encrypted_message:
                
                a = "abcdefghijklmnopqrstuvwxyz"
                A="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                num = "0123456789"#intialised data
                
                space_list = ["¥","€","¢","©","®","™","¶","•","¥","✓"]#special character used in place of space
                s=0#value that will receive decryption indentation
                
                if i in A:#decrption of upper case
                    new_indent = A.find(i)#indentation from intitialised data
                    s = new_indent - pass_num#s can be -ve or +ve 
                    if s >=0:
                        decrypt+=A[s]
                    else:#if s is -ve then its decryption by reversing initialised data
                        A="ZYXWVUTSRQPONMLKJIHGFEDCBA"
                        s=-s
                        decrypt+=A[s - 1]
                elif i in a:#lower case decryption
                    new_indent = a.find(i)
                    s = new_indent - pass_num
                    if s >= 0:#+ve s
                        decrypt += a[s]
                    else:#if s is -ve then its decryption by reversing initialised data
                        a="zyxwvutsrqponmlkjihgfedcba"
                        s=-s
                        decrypt += a[s - 1]

                elif i in num:#num encryption
                    new_indent = num.find(i)
                    if pass_num>=10:#limiting according to num 
                        pass_num2=pass_num%10
                        if pass_num2==0:
                            pass_num2=4#using pass_num2 instead of pass_num as it will change its value
                        s= new_indent - pass_num2
                    else:#if pass num<10
                        s = new_indent - pass_num
                    if s >= 0:#+VE
                        decrypt+= num[s]
                    else:# decryption of -s by reversing intialised data
                        num="9876543210"
                        s=-s
                        decrypt += num[s - 1]
                        
                elif i in space_list:#space_list used in encryption for spaces using fir decryption of space
                    decrypt+= " "
                    
                else:#special character decryption by using encryption dictionary but changing key with value and vice-versa
                    char_dict={"$":"@" , "&":"$" , "∆":'\n' , "π":"&" , "@":"." , "}":"(" , "{":")" , ">":"[" , "/":"]" , "<":"{" , "=":"}" , "(":"<" , ")":">" , "[":"/" , ".":":" , "]":"=" , "^":"-" , "%":"+" , "-":"%" , "*":"," , "\"":"?" , "\'":"!" , "?":"\'" , "!":"\"",";":"_"}
                    #independent of pass_num
                    if i in char_dict:
                         decrypt+=char_dict[i]
                              
            print("Decrypted Message :",decrypt)
            pyperclip.copy(decrypt)
            print("Decrypted Message Copied To Clipboard ...")

            time = datetime.now().strftime('%Y-%m-%d %H:%M:%S')
            stmt="insert into main_table (original_txt, processed_txt, pass_id, mode, work, time) values ('{}','{}',{},'{}','{}','{}')".format(encrypted_message,decrypt,pass_num3 ,"Caeser Cipher",'Decryption',time)
            cur.execute(stmt)
            mycon.commit()

        def decrypt_method_2(key,mssg):
            pass_num = key
            if key > 9:#key reducing method
                key=str(key)#to add all number and should not greater than 9
                added_value = 0#adding all number should be less then 10
                s=0 #intialising value in which limitation of number will take place
                for i in range (0,len(key)):
                    num=int(key[i])
                    s+=num
                    if s >9:
                        s=str(s)
                        s1,s2=s[0],s[1]
                        s1,s2=int(s1),int(s2)
                        s=s1+s2

                key = s
             #intial len 29 
            if key == 0 or key == 1:
                key=4
                
            b=len(mssg) - 1
            lis=[""] * key
            s=b/key
            j=0#for upper value
            for i in range(0,key):
                    j+=1
                    lis[i] += mssg[int(s*i):int(s*j)]
                    
            num=len(lis[0])
            decrypt=""
            for i in range(0,num):
                for j in range(0,len(lis)):
                    decrypt += lis [j] [i]
            print("Decrypted Message :",decrypt)
            pyperclip.copy(decrypt)
            print("Decrypted Message Copied To Clipboard ...")

            time = datetime.now().strftime('%Y-%m-%d %H:%M:%S')
            stmt="insert into main_table (original_txt, processed_txt, pass_id, mode, work, time) values ('{}','{}',{},'{}','{}','{}')".format(mssg,decrypt,pass_num,"Transpose Cipher",'Decryption',time)
            cur.execute(stmt)
            mycon.commit()

        def decrypt_method_3(mssg,pass_num):
    
            A = {'A':'N','N':'A','B':'O','O':'B','C':'P','P':'C','D':'Q','Q':'D','E':'R','R':'E','F':'S','S':'F','G':'T','T':'G','H':'U','U':'H','I':'V','V':'I','J':'W','W':'J','K':'X','X':'K','L':'Y','Y':'L','M':'Z','Z':'M'}
            a = {'a':'n','n':'a','b':'o','o':'b','c':'p','p':'c','d':'q','q':'d','e':'r','r':'e','f':'s','s':'f','g':'t','t':'g','h':'u','u':'h','i':'v','v':'i','j':'w','w':'j','k':'x','x':'k','l':'y','y':'l','m':'z','z':'m'}
            num={'0':'5','5':'0','1':'6','6':'1','2':'7','7':'2','3':'8','8':'3','4':'9','9':'4'}
            char_dict={"$":"@" , "&":"$" , "∆":'\n' , "π":"&" , "@":"." , "}":"(" , "{":")" , ">":"[" , "/":"]" , "<":"{" , "=":"}" , "(":"<" , ")":">" , "[":"/" , ".":":" , "]":"=" , "^":"-" , "%":"+" , "-":"%" , "*":"," , "\"":"?" , "\'":"!" , "?":"\'" , "!":"\"",";":"_"}
            space_list = ["¥","€","¢","©","®","™","¶","•","¥","✓"]#special character in place of space
            decrypt=""
            for i in mssg:
                if i in A:#upper letter
                    decrypt+=A[i]
                elif i in a:#lower letter
                    decrypt+=a[i]
                elif i in num:#number
                    decrypt+=num[i]
                elif i in space_list:#space_list used in encryption for spaces using fir decryption of space
                    decrypt+= " "
                else:#special character
                    decrypt+=char_dict[i]
            print("Decrypted Message :",decrypt)
            pyperclip.copy(decrypt)
            print("Decrypted Message Copied To Clipboard ...")

            time = datetime.now().strftime('%Y-%m-%d %H:%M:%S')
            stmt="insert into main_table (original_txt, processed_txt, pass_id, mode, work, time) values ('{}','{}',{},'{}','{}','{}')".format(mssg,decrypt,pass_num,"Substitution Cipher",'Decryption',time)
            cur.execute(stmt)
            mycon.commit()

        def decrypt_method_4(pass_num,key,message):
            pass_num3 = pass_num
            #CAESER DECRYPTION
            if pass_num >= 26 or pass_num==0:
                pass_num=pass_num%26
                if pass_num == 0:
                    pass_num = 17
            decrypt1=""
            for i in message:
                
                a = "abcdefghijklmnopqrstuvwxyz"
                A="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                num = "0123456789"#intialised data
                space_list = ["¥","€","¢","©","®","™","¶","•","¥","✓"]#special character used in place of space
                s=0#value that will receive decryption indentation
                
                if i in A:#decrption of upper case
                    new_indent = A.find(i)#indentation from intitialised data
                    s = new_indent - pass_num#s can be -ve or +ve 
                    if s >=0:
                        decrypt1 += A[s]
                    else:#if s is -ve then its decryption by reversing initialised data
                        A="ZYXWVUTSRQPONMLKJIHGFEDCBA"
                        s=-s
                        decrypt1 += A[s - 1]
                elif i in a:#lower case decryption
                    new_indent = a.find(i)
                    s = new_indent - pass_num
                    if s >= 0:#+ve s
                        decrypt1 += a[s]
                    else:#if s is -ve then its decryption by reversing initialised data
                        a="zyxwvutsrqponmlkjihgfedcba"
                        s=-s
                        decrypt1 += a[s - 1]

                elif i in num:#num encryption
                    new_indent = num.find(i)
                    if pass_num>=10:#limiting according to num 
                        pass_num2=pass_num%10
                        if pass_num2==0:
                            pass_num2=4#using pass_num2 instead of pass_num as it will change its value
                        s= new_indent - pass_num2
                    else:#if pass num<10
                        s = new_indent - pass_num
                    if s >= 0:#+VE
                        decrypt1 += num[s]
                    else:# decryption of -s by reversing intialised data
                        num="9876543210"
                        s=-s
                        decrypt1 += num[s - 1]
                        
                elif i in space_list:#space_list used in encryption for spaces using fir decryption of space
                    decrypt1 += " "
                    
                else:#special character decryption by using encryption dictionary but changing key with value and vice-versa
                    char_dict={"$":"@" , "&":"$" , "∆":'\n' , "π":"&" , "@":"." , "}":"(" , "{":")" , ">":"[" , "/":"]" , "<":"{" , "=":"}" , "(":"<" , ")":">" , "[":"/" , ".":":" , "]":"=" , "^":"-" , "%":"+" , "-":"%" , "*":"," , "\"":"?" , "\'":"!" , "?":"\'" , "!":"\"",";":"_"}
                    if i in char_dict:
                         decrypt1 += char_dict[i]

            #SUBSTITUTION DECRYPTION
            A = {'A':'N','N':'A','B':'O','O':'B','C':'P','P':'C','D':'Q','Q':'D','E':'R','R':'E','F':'S','S':'F','G':'T','T':'G','H':'U','U':'H','I':'V','V':'I','J':'W','W':'J','K':'X','X':'K','L':'Y','Y':'L','M':'Z','Z':'M'}
            a = {'a':'n','n':'a','b':'o','o':'b','c':'p','p':'c','d':'q','q':'d','e':'r','r':'e','f':'s','s':'f','g':'t','t':'g','h':'u','u':'h','i':'v','v':'i','j':'w','w':'j','k':'x','x':'k','l':'y','y':'l','m':'z','z':'m'}
            num={'0':'5','5':'0','1':'6','6':'1','2':'7','7':'2','3':'8','8':'3','4':'9','9':'4'}
            decrypt2 = ""
            for i in decrypt1:
                if i in A:#upper letter
                    decrypt2 += A[i]
                elif i in a:#lower letter
                    decrypt2 += a[i]
                elif i in num:
                    decrypt2 += num[i]#number
                else:
                    decrypt2 += i

            #TRANSPOSE DECRYPTION
            if key > 9:#key reducing method
                key=str(key)#to add all number and should not greater than 9
                added_value = 0#adding all number should be less then 10
                g=0 #intialising value in which limitation of number will take place
                for i in range (0,len(key)):
                    num=int(key[i])
                    g+=num
                    if g >9:
                        g=str(g)
                        g1,g2=g[0],g[1]
                        g1,g2=int(g1),int(g2)
                        g=g1+g2

                key = g

            if key == 0 or key == 1:
                key=4

            b=len(decrypt2)
            lis=[""] * key
            s=b/key
            j=0#for upper value
            for i in range(0,key):
                j+=1
                lis[i] += decrypt2[int(s*i):int(s*j)]

            num=len(lis[0])
            decrypt3=""
            for i in range(0,num):
                for j in range(0,len(lis)):
                    decrypt3 += lis [j] [i]

            print("Decrypted Message :",decrypt3)
            pyperclip.copy(decrypt3)
            print("Decrypted Message Copied To Clipboard ...")

            time = datetime.now().strftime('%Y-%m-%d %H:%M:%S')
            stmt="insert into main_table (original_txt, processed_txt, pass_id, mode, work, time) values ('{}','{}',{},'{}','{}','{}')".format(message,decrypt3,pass_num3,"Mixed Cipher",'Decryption',time)
            cur.execute(stmt)
            mycon.commit()

        win3=Tk()
        win3.geometry('625x415')
        win3.resizable(0,0)
        win3.title("Decryption Mode")
        win3.configure(bg='#78866B')

        '''image = Image.open("bg.jpg")
        photo = ImageTk.PhotoImage(image)
        Label(win3,image=photo).pack()'''
        
        Label(win3,text='Select One Mode For Decryption',bg='black',fg='grey',padx=4,pady=5,borderwidth=4,relief='sunken').place(x=220,y=40)
        Button(win3,text="Caeser Cipher",bg='#B8860B',font='10',command=lambda:decrypt_method_1(pass_num,message)).place(x=120,y=120)
        Button(win3,text="Transpose Cipher",bg='#B8860B',font='10',command=lambda:decrypt_method_2(pass_num,message)).place(x=380,y=120)
        Button(win3,text="Substitution Cipher",bg='#B8860B',font='10',command=lambda:decrypt_method_3(message,pass_num)).place(x=380,y=210)
        Button(win3,text="Mixed Cipher",bg='#B8860B',font='10',command=lambda:decrypt_method_4(pass_num,key,message)).place(x=120,y=210)
        Label(win3,text='NOTE : Decrypted Messeage Will Be Directly Copied To Clipboard',bg='#900020',fg='white',padx=4,pady=4,borderwidth=10,relief='flat').place(x=140,y=300)
        win3.mainloop()


    win2=Tk()
    win2.geometry('625x415')
    win2.resizable(0,0)
    win2.title("Decryption Window")
    win2.configure(bg='#78866B')
    
    '''image = Image.open("bg.jpg")
        photo = ImageTk.PhotoImage(image)
        Label(win2,image=photo).pack()'''  

    Label(win2,text='Enter Text To Decrypt : ',bg='#78866B').place(x=150,y=80)
    Label(win2,text='Enter Numeric Password : ',bg='#78866B').place(x=150,y=102)
    mssg_var=StringVar()
    mssg_entry=Entry(win2,textvariable=mssg_var)
    mssg_entry.place(x=290,y=80)
    pass_var=StringVar()
    pass_entry=Entry(win2,textvariable=pass_var,show='*')
    pass_entry.place(x=290,y=102)
    Button(win2,text="Submit",bg='#5D8AA8',pady=4,padx=5,command=txt_pass_decryption).place(x=270,y=135)
    win2.mainloop()    

def history_window():
    history = Tk()
    history.title('History')
    history.configure(bg='#78866B')
    history.geometry('700x500')
    history.resizable(0,0)

    #style widget
    style = ttk.Style()

    #adding theme
    style.theme_use('clam')

    #configuring
    style.configure('Treeview',background='',foreground='black',rowheight=25,fieldbackground='silver')

    #applying
    style.map('Treeview',background=[('selected','RED')])

    #table widget treeview
    my_tree = ttk.Treeview(history)

    #colums variable
    my_tree['columns'] = ('ID','org_txt','proc_txt','pass','mode','work')

    #column variable detail configuration
    # #0 is phantom or default column in treeview to remove it stretch=0
    my_tree.column('#0',width=0 , stretch=NO)
    my_tree.column('ID', anchor=W ,width=20 , minwidth=20)
    my_tree.column('org_txt', anchor=W ,width=150 , minwidth=50)
    my_tree.column('proc_txt', anchor=W ,width=150 , minwidth=50)
    my_tree.column('pass', anchor=CENTER ,width=120 , minwidth=50)
    my_tree.column('mode', anchor= W ,width=120 , minwidth=50)
    my_tree.column('work', anchor=W ,width=120 , minwidth=50)

    #column variable heading to show in table
    my_tree.heading('#0',text='', anchor=W)
    my_tree.heading('ID',text='ID', anchor=CENTER)
    my_tree.heading('org_txt',text='Original text', anchor=CENTER)
    my_tree.heading('proc_txt',text='Processed text', anchor=CENTER)
    my_tree.heading('pass',text='Password', anchor=CENTER)
    my_tree.heading('mode',text='Mode', anchor=CENTER)
    my_tree.heading('work',text='Work', anchor=W)

    #tags for strip table
    my_tree.tag_configure('evenrow',background='yellow')
    my_tree.tag_configure('oddrow',background='light green')

    stmt='select * from main_table'
    cur.execute(stmt)
    result=cur.fetchall()
    l=len(result)

    #inserting data in table
    if l<11:
        for i in range(0,l):
            if i%2==0:
                my_tree.insert(parent='',index='end',iid=i,text='',values=(result[l-1-i][0 ],result[l-1-i][1],result[l-1-i][2],result[l-1-i][3],result[l-1-i][4],result[l-1-i][5]),tags=('evenrow',))
            else:
                my_tree.insert(parent='',index='end',iid=i,text='',values=(result[l-1-i][0 ],result[l-1-i][1],result[l-1-i][2],result[l-1-i][3],result[l-1-i][4],result[l-1-i][5]),tags=('oddrow',))
                
    else:
        i=1
        while i<11:
            if (i-1)%2==0:
                my_tree.insert(parent='',index='end',iid=i-1,text='',values=(result[l-i][0],result[l-i][1],result[l-i][2],result[l-i][3],result[l-i][4],result[l-i][5]),tags=('evenrow',))
                i+=1
            else:
                my_tree.insert(parent='',index='end',iid=i-1,text='',values=(result[l-i][0],result[l-i][1],result[l-i][2],result[l-i][3],result[l-i][4],result[l-i][5]),tags=('oddrow',))
                i+=1


    def remove_all():
        stmt='select * from main_table'
        cur.execute(stmt)
        result=cur.fetchall()
        l=len(result)
        if l<11 :
            for i in range (0,l):
                x=result[i][0]
                stmt = 'select * from main_table where s_no= {}'.format(x)
                cur.execute(stmt)
                result2 = cur.fetchone()
                time = datetime.now().strftime('%Y-%m-%d %H:%M:%S')
                stmt="insert into delete_part (original_txt, processed_txt, pass_id, mode, work, time_of_work, dlt_time) values ('{}','{}',{},'{}','{}','{}','{}')".format(result2[1],result2[2],result2[3],result2[4],result2[5],result2[6],time)
                cur.execute(stmt)
                mycon.commit()
                stmt = "DELETE FROM main_table WHERE s_no = {}".format(x)
                cur.execute(stmt)
                mycon.commit()
        else:
            i=1
            while i<11:
                x=result[l-i][0]
                stmt = 'select * from main_table where s_no= {}'.format(x)
                cur.execute(stmt)
                result2 = cur.fetchone()
                time = datetime.now().strftime('%Y-%m-%d %H:%M:%S')
                stmt="insert into delete_part (original_txt, processed_txt, pass_id, mode, work, time_of_work, dlt_time) values ('{}','{}',{},'{}','{}','{}','{}')".format(result2[1],result2[2],result2[3],result2[4],result2[5],result2[6],time)
                cur.execute(stmt)
                mycon.commit()
                stmt = "DELETE FROM main_table WHERE s_no = {}".format(x)
                cur.execute(stmt)
                mycon.commit()
                i+=1

        for record in my_tree.get_children():
            my_tree.delete(record)


    def remove_selected():
        curitem= my_tree.focus()
        m = my_tree.item(curitem)['values'][0]
        x = my_tree.selection()
        for record in x:
            stmt = 'select * from main_table where s_no= {}'.format(m)
            cur.execute(stmt)
            result2 = cur.fetchone()
            time = datetime.now().strftime('%Y-%m-%d %H:%M:%S')
            stmt="insert into delete_part (original_txt, processed_txt, pass_id, mode, work, time_of_work, dlt_time) values ('{}','{}',{},'{}','{}','{}','{}')".format(result2[1],result2[2],result2[3],result2[4],result2[5],result2[6],time)
            cur.execute(stmt)
            mycon.commit()
            stmt = "DELETE FROM main_table WHERE s_no = {}".format(m)#excess from dict
            cur.execute(stmt)
            mycon.commit()
            my_tree.delete(x)
            
    remove_all_bt=Button(history,text='Remove All',bg='#5D8AA8',borderwidth=2,relief='sunken',pady=4,padx=5,command=remove_all)
    remove_all_bt.place(x=300,y=300)

    remove_selected_bt=Button(history,text='Remove Selected',bg='#5D8AA8',borderwidth=2,relief='sunken',pady=4,padx=5,command=remove_selected)
    remove_selected_bt.place(x=283,y=355)

    
    Label(history ,text='NOTE : Remove All can delete upto 10 enteries at a time',bg='#900020',fg='white',padx=4,pady=4,borderwidth=10,relief='flat').place(x=170,y=405)


    my_tree.pack(padx=30,pady=30)

    history.mainloop()
######################

window_1=Tk()

window_1.title("File Protector")
window_1.geometry('625x415')
window_1.resizable(0,0)

image = Image.open("bg.jpg")
photo = ImageTk.PhotoImage(image)
image_label = Label(image=photo)
image_label.pack()

Button(text='File Encryption',bg='#00081F',fg='white',font='16',padx=4,pady=4,borderwidth=4,relief='raised',command=encryption_window).place(x=150,y=200)
Button(text='File Decryption',bg='#00081F',fg='white',font='16',padx=4,pady=4,borderwidth=4,relief='raised',command=decryption_window).place(x=350,y=200)
Button(text='History',bg='#00081F',fg='white',font='16',padx=4,pady=4,borderwidth=4,relief='raised',command=history_window).place(x=277,y=255)

Label(text="File Proctector",bg='#000922',fg='white',font='20',borderwidth=6,relief='sunken').place(x=260,y=79)
window_1.mainloop()

mycon.commit()
mycon.close()





