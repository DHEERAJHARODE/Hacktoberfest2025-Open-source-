from tkinter import *
import tkinter
from tkinter.ttk import *
from PIL import Image,ImageTk
from tkinter import Frame
from tkinter import Label
from tkinter import Button


class ChatBot:
    def __init__(self,root):
        self.root=root
        self.root.title("chatbot")
        self.root.geometry("730x620+0+0")
        self.root.bind('<Return>',self.enter_func)

        main_frame =Frame(root,bd=4,bg='powder blue',width = 610)
        main_frame.pack()
        image=Image.open('friendly-chatbot.jpg')
        # Resize the image using resize() method
        resize_image = image.resize((200, 70))
        self.img = ImageTk.PhotoImage(resize_image)
        Title_label =Label(main_frame,bd=3,relief = RAISED,anchor ='nw' , width = 730 ,compound=LEFT, image = self.img ,text="chat me",font=('arial',30,'bold'),fg='red',bg='white')
        Title_label.pack(side=TOP)
        self.scroll_y=tkinter.Scrollbar(main_frame,orient=VERTICAL)
        self.text=Text(main_frame,width=65,height=20,bd=3,relief=RAISED,font=('arial',14),yscrollcommand=self.scroll_y.set)
        self.scroll_y.pack(side=RIGHT,fill=Y)
        self.text.pack()
        btn_frame = Frame (self.root,bd=4,bg ='white',width = 720)
        btn_frame.pack()
        label_1=Label(btn_frame,text='Type Something',font=('arial',14,'bold'),fg='green',bg='white')
        label_1.grid(row=0,column=0,padx=5,sticky=W)
        
       
        self.entry=StringVar()
        self.entry1=tkinter.Entry(btn_frame,width=30,textvariable=self.entry,font=('Times New Roman',17,'bold'))
        self.entry1.grid(row=0,column=1,padx=5,sticky =W ) 
       
        self.send=Button(btn_frame ,text=" Send >> ",command=self.send,font =('arial',15,'bold'),width=8,bg='green',)
        self.send.grid(row = 0 , column = 2 , padx = 5 , sticky = W )
        
        self.clare=Button(btn_frame ,text=" clear data",command=self.clear,font =('arial',15,'bold'),width=8,fg='white',bg='red',)
        self.clare.grid(row = 1 , column = 0, padx = 5 , sticky = W )
        self.msg=''
        self.label_11=Label(btn_frame,text=self.msg,font=('arial',14,'bold'),fg='red',bg='white')
        self.label_11.grid(row=1,column=1,padx=5,sticky=W)
        
        
#====================================FUNCTION DECLARATION==================================

    def enter_func(self,event):
        self.send.invoke()
        self.entry.set('')
        
    def clear(self):
        self.text.delete('1.0',END)
        self.entry.set('')

    

    def send(self):
        send='\t\t\t'+'You:  '+self.entry.get()
        self.text.insert(END,'\n'+send)
        self.text.yview(END)
        if (self.entry.get()=='') :
            self.msg ='Please enter some input'
            self.label_11.config(text=self.msg,fg='red')
        else:
            self.msg=''
            self.label_11.config(text=self.msg,fg='red')
        
        if ('hello' in self.entry.get()) :
            self.text.insert(END ,'\n\n'+'Bot: Hi')
        elif ("hi" in self.entry.get()) :
            self.text.insert ( END , " \n\n " + " Bot: Hello " )
        elif ("how are you" in self.entry.get()) :
            self.text.insert ( END , " \n\n " + " Bot: fine and you " )
        elif ("fantastic" in self.entry.get()) :
            self.text.insert ( END , " \n\n " + " Bot: Nice To Hear " )
        elif ( "who created you" in self.entry.get()) :
            self.text.insert ( END , " \n\n " + " Bot: Tripti did using python " )
        elif ("bye" in self.entry.get()) :
            self.text.insert ( END , " \n\n " + " Bot: Thank You For Chatting " )
        else :
            self.text.insert ( END , " \n\n " + " Bot: Sorry I dindn't get it " )


if __name__== '__main__':
    root=tkinter.Tk()
    obj=ChatBot(root)
    root.mainloop()