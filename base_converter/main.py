# gui based project - converter program

# importing libraries and tkinter attributes
import tkinter
from PIL import ImageTk,Image
from tkinter import PhotoImage
from tkinter import Canvas
from tkinter import Label
from tkinter import Frame
from tkinter import Button
from tkinter import RAISED
from tkinter import SUNKEN
from tkinter import LEFT
from tkinter import GROOVE
from tkinter import SOLID
from tkinter import RIDGE
from tkinter import FLAT
from tkinter import COMMAND
from tkinter import messagebox
from tkinter.messagebox import showerror
from tkinter import Toplevel
from tkinter import Entry
from tkinter import StringVar
from tkinter import IntVar
from tkinter import messagebox 
from tkinter import X
from tkinter import END
from tkinter import NW
from tkinter import TOP
from tkinter import Tk
from tkinter import CENTER
from tkinter import ttk , font

# starting the project - mainloop
root = tkinter.Tk()
root.title("Home Screen")
root.geometry("555x553+70+80")
#to get the specifies icon in place of leave shown on the top left corner 
#root.iconbitmap(img="logo.ico")
root.config(background="white",borderwidth=5,relief=RIDGE,highlightthickness=5,highlightcolor="maroon")

# resizable (0,0) makes it impossible for uer to change the width or height of the window
root.resizable(0,0)


def startprogram():
    root1 = tkinter.Tk()
    root1.title("Main Screen")
    root1.geometry("715x453+120+140")
    root1.resizable(0,0)
    #frame make a frame like space in window where we can attach any widget
    frame1 = Frame(root1, bg="black", borderwidth=8, relief=SUNKEN)
    frame1.pack(side=LEFT, fill="y")

    frame2 = Frame(root1, borderwidth=8, bg="black", relief=SUNKEN)
    frame2.pack(side=TOP, fill="x")
    #label is not responsive , i.e it does not interact with user . just use for detailing 
    label4 = Label(frame1, text="  Project Tkinter  ")
    label4.pack(padx=0)

    label = Label(frame1, text="         INSTRUCTION TO USE         ",fg="white",bg="dark violet")
    label.pack( pady=20,padx=0)

    #canvas make a specific place in any frame or window , used for main ly shape purposes
    canvasinf_w=180
    canvasinf_h=400
    caninf_widget=Canvas(frame1,bg="black",width=canvasinf_w, height=canvasinf_h,borderwidth=0)
    caninf_widget.pack(side=TOP,pady=0,fill="y")

    caninf_widget.create_rectangle(0, 0,188, 4,fill="white")

    text1 = Label(caninf_widget,text="1. You can choose the theme of \n this gui accordingly which \n suits you better",fg="purple")
    text1.pack(padx=5,pady=15)
    text2 = Label(caninf_widget,text="2. Here are 4 buttons which \n would direct you to the \n required converter system \n . e.g after clicking on dec to \n other bases, a converter \n program will appear for it.",fg="purple")
    text2.pack(padx=5,pady=15)
    text3 = Label(caninf_widget,text="3. Last, here is a quit button at \n the bottom corner which works \n the same way, the name it has.",fg="purple")
    text3.pack(padx=5,pady=15)
    text3 = Label(caninf_widget,text="NAH! this is not a guide. \n Just wanted to thank the user.",fg="purple")
    text3.pack(padx=5,pady=15)
    label5 = Label(frame2, text="CONVERSION GUI", font="Helvetica 16 bold", fg="black", bg = "grey",pady=25,padx=10)
    label5.pack()
    
    #commands are given with buttons to do that function which is called within commands
    def go_to_dark_theme():
        frame1.config(bg="black")
        frame2.config(bg="black")
        theme_button.config(text="Go for light THEME mode",bg="white",fg="purple",command=go_to_light_theme)
        label5.config(bg="grey")
        from_decimal.config(bg="black",fg="red")
        from_hexadecimal.config(bg="black",fg="red")
        from_octal.config(bg="black",fg="red")
        from_binary.config(bg="black",fg="red")
        quit_button.config(bg="#2b3635")
        caninf_widget.config(bg="black")
        label.config(bg="dark violet",fg="white")
    def go_to_light_theme():

        frame1.config(bg="white")
        frame2.config(bg="powder blue")
        label.config(text="         INSTRUCTION TO USE         ")
        theme_button.config(text="Go for dark THEME mode",bg="black",fg="yellow",command=go_to_dark_theme)        
        label5.config(bg="pink")
        from_decimal.config(bg="#f4788c",fg="navy blue")
        from_hexadecimal.config(bg="#f4788c",fg="navy blue")
        from_octal.config(bg="#f4788c",fg="navy blue")
        from_binary.config(bg="#f4788c",fg="navy blue") 
        quit_button.config(bg="#79867c")
        caninf_widget.config(bg="orange")
        label.config(bg="#ecbcb4",fg="blue")
    canvas_w=568
    canvas_h=400
    can_widget=Canvas(root1,bg="#708090",width=canvas_w, height=canvas_h)
    can_widget.pack(anchor=NW)

    can_widget.create_rectangle(5, 0,15, 553,fill="grey")

    def bi():
        # tn.set("CONVERTING...",font="bradley hand itc")
        #top is used for creating another window which passes the command given in previos window
        top = Toplevel()
        #through configure we can change theme , background , foreground colors anything realted to art work in tkinter windows
        top.configure(bg="#eaa221")
        #title paste the text on top of window, help to guide the user 
        top.title("decimal to other bases ~ jatin")
        top.geometry("550x600+120+40")
        top.resizable(0,0)
        # here scval is a form of entry widget which has 4 is 4 types : here intar is user as this is valu is inside a calculator
        scval = IntVar()
        scval.set("")
        # screen is basically the outpput of any value given to scval ; therfore textvar is used here to brag the values of scval
        screen = Entry(top, textvar=scval, font="lucida 40 bold",justify=CENTER,bg="black",fg="white")
        screen.pack(fill=X, ipadx=8, pady=10, padx=10,side=TOP)
        bf=Frame(top)
        bf.pack(side=TOP)
        # a=StringVar
        c=scval
        def press_btn_func(event):
            b=event.widget
            text = b['text']
           
            
            if text=="x":
                screen.insert(END,"*")
                return
            if text=="xx":
                screen.insert(END,"**")
                return
            
            if text == "=":
                try:
                    ex=screen.get()
                    ans=eval(ex)
                    screen.delete(0, END)
                    screen.insert(0, ans)
                    return
                except Exception as e:
                    print("Error...",e)
                    showerror("error",e)
                    return

            screen.insert(END,text)
        def allclear():
            scval.set("")
            screen.update()  
        def bks():
            ex=screen.get()
            ex=ex[0:len(ex)-1]
            screen.delete(0, END)
            screen.insert(0, ex)

        temp=1
        for i in range(0,3):
            for j in range(0,3):
                btn=Button(bf,text=str(temp),font="lucida 22 bold",bg="white",fg="black",width=4,height=0,relief=RIDGE)
                btn.grid(row=i,column=j)
                temp=temp+1
                btn.bind('<Button-1>',press_btn_func)
        zrbtn=Button(bf,text=".",font="lucida 22 bold",width=4,height=0,relief=RIDGE)
        zrbtn.grid(row=3,column=0)
        zrbtn.bind('<Button-1>',press_btn_func)
        dotbtn=Button(bf,text="0",font="lucida 22 bold",width=4,height=0,relief=RIDGE)
        dotbtn.grid(row=3,column=1)
        dotbtn.bind('<Button-1>',press_btn_func)
        dbzerobtn=Button(bf,text="00",font="lucida 22 bold",width=4,height=0,relief=RIDGE)
        # db stands for double zero
        dbzerobtn.grid(row=3,column=2)
        dbzerobtn.bind('<Button-1>',press_btn_func)
        # here are some basic mathematical operators such as sum , minus , multiply and idvide used in this calculator
        sumbtn=Button(bf,text="+",font="lucida 22 bold",width=4,height=0,relief=RIDGE,bg="#007ba7")
        sumbtn.grid(row=0,column=3)
        sumbtn.bind('<Button-1>',press_btn_func)
        minusbtn=Button(bf,text="-",font="lucida 22 bold",width=4,height=0,relief=RIDGE,bg="#007ba7")
        minusbtn.grid(row=1,column=3)
        minusbtn.bind('<Button-1>',press_btn_func)
        multbtn=Button(bf,text="x",font="lucida 22 bold",width=4,height=0,relief=RIDGE,bg="#007ba7")
        multbtn.grid(row=2,column=3)
        multbtn.bind('<Button-1>',press_btn_func)
        divbtn=Button(bf,text="/",font="lucida 22 bold",width=4,height=0,relief=RIDGE,bg="#007ba7")
        divbtn.grid(row=3,column=3)
        divbtn.bind('<Button-1>',press_btn_func)
        
        clearbtn=Button(bf,text="bksp",font="lucida 22 bold",bg="#ed2939",fg="black",width=5,height=0,relief=SOLID,command=bks,activebackground="#ed2939")
        clearbtn.grid(row=1,column=4,columnspan=2)
        allclbtn=Button(bf,text="AC",font="lucida 22 bold",bg="#ed2939",fg="black",activebackground="#ed2939",width=5,height=0,relief=SOLID,command=allclear)
        allclbtn.grid(row=0,column=4)
        # allclbtn.bind('<Button-1>',press_btn_func)
        equalbtn=Button(bf,text="=",font="lucida 22 bold",width=5,height=2,relief=FLAT)
        equalbtn.grid(row=2,column=4,rowspan=2,columnspan=2)        
        equalbtn.bind('<Button-1>',press_btn_func)
        
        res_octal = StringVar()
        res_hexadecimal = StringVar()
        res_binary = StringVar()
        def Convert():

            x1 = int(Entry.get(c1))
           
            octal = oct(x1)
            res_octal.set(octal)

            hexadecimal = (hex(x1))
            res_hexadecimal.set(hexadecimal)
            binary = bin(x1)
            res_binary.set(binary)
        
        x1Lab = Label(top,text="Value you want to convert",bg="#eaa221",fg="black",font="FiraSans 14 bold",width=0)
       

        binlab=Label(top,text="binary",bg="#eaa221",fg="maroon",font="FiraSans 24 bold",width=9)
        binans=Label(top,textvariable=res_binary,bg="black",fg="white",width=17,height=2,font="FireSans 12")
        octlab=Label(top,text="octal",bg="#eaa221",fg="maroon",font="FiraSans 24 bold",width=9)
        octans=Label(top,textvariable=res_octal,bg="black",fg="white",width=17,height=2,font="FireSans 12")
        hexlab=Label(top,text="hexdec",bg="#eaa221",fg="maroon",font="FiraSans 24 bold",width=9)
        hexans=Label(top,textvariable=res_hexadecimal,bg="black",fg="white",width=17,height=2,font="FireSans 12 ")

        convert = Button(top,text="convert",command=Convert,font="comicsans 18 italic",bg="black",fg="white",width=6)
        c1=Entry(top,textvar=c,font="lucida 22 bold",justify=CENTER,bg="black",fg="white",width=10)
        x1Lab.place(x=69,y=360)
        
        octlab.place(x=63,y=415)
        hexlab.place(x=63,y=470)
        binlab.place(x=63,y=525)
        c1.place(x=320,y=350)
        
        octans.place(x=230,y=415)
        hexans.place(x=230,y=470)
        binans.place(x=230,y=525)
        convert.place(x=430,y=465)


    def d():
        top1 = Toplevel()
        
        top1.configure(bg="#eaa221")
        top1.title("binary to other bases")
        top1.geometry("550x600+120+40")
        top1.resizable(0,0)      
        scval1 = IntVar()
        scval1.set("")
        screen1 = Entry(top1, textvar=scval1, font="lucida 40 bold",justify=CENTER,bg="black",fg="white")
        screen1.pack(fill=X, ipadx=8, pady=10, padx=10,side=TOP)
        bfd=Frame(top1)
        bfd.pack(side=TOP)
        c111=scval1
        def press_btn_func(event):
            rr=event.widget
            text = rr['text']
            
            if text=="x":
                screen1.insert(END,"*")
                return
            if text=="xx":
                screen1.insert(END,"**")
                return
            
            if text == "=":
                try:
                    ex=screen1.get()
                    ans=eval(ex)
                    screen1.delete(0, END)
                    screen1.insert(0, ans)
                    return
                except Exception as e:
                    print("Error...",e)
                    showerror("error",e)
                    return

            screen1.insert(END,text)
        def allclear():
            scval1.set("")
            screen1.update()  
        def bks():
            ex=screen1.get()
            ex=ex[0:len(ex)-1]
            screen1.delete(0, END)
            screen1.insert(0, ex)

        temp=1
        for i in range(0,3):
            for j in range(0,3):
                btn=Button(bfd,text=str(temp),font="lucida 22 bold",bg="white",fg="black",width=4,height=0,relief=RIDGE)
                btn.grid(row=i,column=j)
                temp=temp+1
                btn.bind('<Button-1>',press_btn_func)
        zrbtn=Button(bfd,text=".",font="lucida 22 bold",width=4,height=0,relief=RIDGE)
        zrbtn.grid(row=3,column=0)
        zrbtn.bind('<Button-1>',press_btn_func)
        dotbtn=Button(bfd,text="0",font="lucida 22 bold",width=4,height=0,relief=RIDGE)
        dotbtn.grid(row=3,column=1)
        dotbtn.bind('<Button-1>',press_btn_func)
        dbzerobtn=Button(bfd,text="00",font="lucida 22 bold",width=4,height=0,relief=RIDGE)
        dbzerobtn.grid(row=3,column=2)
        dbzerobtn.bind('<Button-1>',press_btn_func)
        sumbtn=Button(bfd,text="+",font="lucida 22 bold",width=4,height=0,relief=RIDGE,bg="#007ba7")
        sumbtn.grid(row=0,column=3)
        sumbtn.bind('<Button-1>',press_btn_func)
        minusbtn=Button(bfd,text="-",font="lucida 22 bold",width=4,height=0,relief=RIDGE,bg="#007ba7")
        minusbtn.grid(row=1,column=3)
        minusbtn.bind('<Button-1>',press_btn_func)
        multbtn=Button(bfd,text="x",font="lucida 22 bold",width=4,height=0,relief=RIDGE,bg="#007ba7")
        multbtn.grid(row=2,column=3)
        multbtn.bind('<Button-1>',press_btn_func)
        divbtn=Button(bfd,text="/",font="lucida 22 bold",width=4,height=0,relief=RIDGE,bg="#007ba7")
        divbtn.grid(row=3,column=3)
        divbtn.bind('<Button-1>',press_btn_func)
        
        clearbtn=Button(bfd,text="bksp",font="lucida 22 bold",bg="#ed2939",fg="black",width=5,height=0,relief=SOLID,command=bks,activebackground="#ed2939")
        clearbtn.grid(row=1,column=4,columnspan=2)
        allclbtn=Button(bfd,text="AC",font="lucida 22 bold",bg="#ed2939",fg="black",activebackground="#ed2939",width=5,height=0,relief=SOLID,command=allclear)
        allclbtn.grid(row=0,column=4)
        
        equalbtn=Button(bfd,text="=",font="lucida 22 bold",width=5,height=2,relief=FLAT)
        equalbtn.grid(row=2,column=4,rowspan=2,columnspan=2)        
        equalbtn.bind('<Button-1>',press_btn_func)
        
        res_octal = IntVar()
        res_hexadecimal = IntVar()
        res_decimal = IntVar()
        def Convert1():
            
            x1 = Entry.get(c1)
            

            su = int(x1, 2)
            octal = oct(su)
            res_octal.set(octal)

            su1 = int(x1, 2)
            hexadecimal = hex(su1)
            res_hexadecimal.set(hexadecimal)

            decimal = int(x1, 2)
            res_decimal.set(decimal)
        x1Lab = Label(top1,text="Value you want to convert",bg="#eaa221",fg="black",font="FiraSans 14 bold",width=0)
       

        declab=Label(top1,text="decimal",bg="#eaa221",fg="maroon",font="FiraSans 24 bold",width=9)
        decans=Label(top1,textvariable=res_decimal,bg="black",fg="white",width=17,height=2,font="FireSans 12")
        octlab=Label(top1,text="octal",bg="#eaa221",fg="maroon",font="FiraSans 24 bold",width=9)
        octans=Label(top1,textvariable=res_octal,bg="black",fg="white",width=17,height=2,font="FireSans 12")
        hexlab=Label(top1,text="hexdec",bg="#eaa221",fg="maroon",font="FiraSans 24 bold",width=9)
        hexans=Label(top1,textvariable=res_hexadecimal,bg="black",fg="white",width=17,height=2,font="FireSans 12 ")

        convert = Button(top1,text="convert",command=Convert1,font="comicsans 18 italic",bg="black",fg="white",width=6)
        c1=Entry(top1,textvar=c111,font="lucida 22 bold",justify=CENTER,bg="black",fg="white",width=10)
        x1Lab.place(x=69,y=360)
        
        octlab.place(x=63,y=415)
        hexlab.place(x=63,y=470)
        declab.place(x=63,y=525)
        c1.place(x=320,y=350)
        
        octans.place(x=230,y=415)
        hexans.place(x=230,y=470)
        decans.place(x=230,y=525)
        convert.place(x=430,y=465)

        

    def o():
        top2 = Toplevel()
        
        top2.configure(bg="#eaa221")
        top2.title("octal to other bases")
        top2.geometry("550x600+120+40")
        top2.resizable(0,0)
        scval = IntVar()
        scval.set("")
        screen = Entry(top2, textvar=scval, font="lucida 40 bold",justify=CENTER,bg="black",fg="white")
        screen.pack(fill=X, ipadx=8, pady=10, padx=10,side=TOP)
        bfq=Frame(top2)
        bfq.pack(side=TOP)
        c=scval
        def press_btn_func(event):
            oo=event.widget
            text = oo['text']
            
            if text=="x":
                screen.insert(END,"*")
                return
            if text=="xx":
                screen.insert(END,"**")
                return
            
            if text == "=":
                try:
                    ex=screen.get()
                    ans=eval(ex)
                    screen.delete(0, END)
                    screen.insert(0, ans)
                    return
                except Exception as e:
                    print("Error...",e)
                    showerror("error",e)
                    return

            screen.insert(END,text)
        def allclear():
            scval.set("")
            screen.update()  
        def bks():
            ex=screen.get()
            ex=ex[0:len(ex)-1]
            screen.delete(0, END)
            screen.insert(0, ex)

        temp=1
        for i in range(0,3):
            for j in range(0,3):
                btn=Button(bfq,text=str(temp),font="lucida 22 bold",bg="white",fg="black",width=4,height=0,relief=RIDGE)
                btn.grid(row=i,column=j)
                temp=temp+1
                btn.bind('<Button-1>',press_btn_func)
        zrbtn=Button(bfq,text=".",font="lucida 22 bold",width=4,height=0,relief=RIDGE)
        zrbtn.grid(row=3,column=0)
        zrbtn.bind('<Button-1>',press_btn_func)
        dotbtn=Button(bfq,text="0",font="lucida 22 bold",width=4,height=0,relief=RIDGE)
        dotbtn.grid(row=3,column=1)
        dotbtn.bind('<Button-1>',press_btn_func)
        dbzerobtn=Button(bfq,text="00",font="lucida 22 bold",width=4,height=0,relief=RIDGE)
        dbzerobtn.grid(row=3,column=2)
        dbzerobtn.bind('<Button-1>',press_btn_func)
        sumbtn=Button(bfq,text="+",font="lucida 22 bold",width=4,height=0,relief=RIDGE,bg="#007ba7")
        sumbtn.grid(row=0,column=3)
        sumbtn.bind('<Button-1>',press_btn_func)
        minusbtn=Button(bfq,text="-",font="lucida 22 bold",width=4,height=0,relief=RIDGE,bg="#007ba7")
        minusbtn.grid(row=1,column=3)
        minusbtn.bind('<Button-1>',press_btn_func)
        multbtn=Button(bfq,text="x",font="lucida 22 bold",width=4,height=0,relief=RIDGE,bg="#007ba7")
        multbtn.grid(row=2,column=3)
        multbtn.bind('<Button-1>',press_btn_func)
        divbtn=Button(bfq,text="/",font="lucida 22 bold",width=4,height=0,relief=RIDGE,bg="#007ba7")
        divbtn.grid(row=3,column=3)
        divbtn.bind('<Button-1>',press_btn_func)
        
        clearbtn=Button(bfq,text="bksp",font="lucida 22 bold",bg="#ed2939",fg="black",width=5,height=0,relief=SOLID,command=bks,activebackground="#ed2939")
        clearbtn.grid(row=1,column=4,columnspan=2)
        allclbtn=Button(bfq,text="AC",font="lucida 22 bold",bg="#ed2939",fg="black",activebackground="#ed2939",width=5,height=0,relief=SOLID,command=allclear)
        allclbtn.grid(row=0,column=4)
        equalbtn=Button(bfq,text="=",font="lucida 22 bold",width=5,height=2,relief=FLAT)
        equalbtn.grid(row=2,column=4,rowspan=2,columnspan=2)        
        equalbtn.bind('<Button-1>',press_btn_func)
        
        res_decimal = StringVar()
        res_hexadecimal = StringVar()
        res_binary = StringVar()
        def Convert():

            x1 = Entry.get(c1)
            
           
            decimal = str(int(x1, 8))
            res_decimal.set(decimal)
            
            dec1 = str(int(x1, 8))
            decnm = int(dec1)
            hexadecimal = hex(decnm)
            res_hexadecimal.set(hexadecimal)
            dec = str(int(x1, 8))
            bina = int(dec)
            binary = bin(bina)
            res_binary.set(binary)
        x1Lab = Label(top2,text="Value you want to convert",bg="#eaa221",fg="black",font="FiraSans 14 bold",width=0)
       

        binlab=Label(top2,text="binary",bg="#eaa221",fg="maroon",font="FiraSans 24 bold",width=9)
        binans=Label(top2,textvariable=res_binary,bg="black",fg="white",width=17,height=2,font="FireSans 12")
        declab=Label(top2,text="decimal",bg="#eaa221",fg="maroon",font="FiraSans 24 bold",width=9)
        decans=Label(top2,textvariable=res_decimal,bg="black",fg="white",width=17,height=2,font="FireSans 12")
        hexlab=Label(top2,text="hexdec",bg="#eaa221",fg="maroon",font="FiraSans 24 bold",width=9)
        hexans=Label(top2,textvariable=res_hexadecimal,bg="black",fg="white",width=17,height=2,font="FireSans 12 ")

        convert = Button(top2,text="convert",command=Convert,font="comicsans 18 italic",bg="black",fg="white",width=6)
        c1=Entry(top2,textvar=c,font="lucida 22 bold",justify=CENTER,bg="black",fg="white",width=10)
        x1Lab.place(x=69,y=360)
        
        declab.place(x=63,y=415)
        hexlab.place(x=63,y=470)
        binlab.place(x=63,y=525)
        c1.place(x=320,y=350)
        
        decans.place(x=230,y=415)
        hexans.place(x=230,y=470)
        binans.place(x=230,y=525)
        convert.place(x=430,y=465)


    def hd():
        top3 = Toplevel()
        
        top3.configure(bg="#eaa221")
        top3.title("hexa-decimal to other bases")
        top3.geometry("640x600+120+40")
        top3.resizable(0,0)
        scval = IntVar()
        scval.set("")
        screen = Entry(top3, textvar=scval, font="lucida 40 bold",justify=CENTER,bg="black",fg="white")
        screen.pack(fill=X, ipadx=8, pady=10, padx=10,side=TOP)
        bfw=Frame(top3)
        bfw.pack(side=TOP)
        c=scval
        def press_btn_func(event):
            hb=event.widget
            text = hb['text']
            
            if text=="x":
                screen.insert(END,"*")
                return
            if text=="xx":
                screen.insert(END,"**")
                return
            
            if text == "=":
                try:
                    ex=screen.get()
                    ans=eval(ex)
                    screen.delete(0, END)
                    screen.insert(0, ans)
                    return
                except Exception as e:
                    print("Error...",e)
                    showerror("error",e)
                    return

            screen.insert(END,text)
        def allclear():
            scval.set("")
            screen.update()  
        def bks():
            ex=screen.get()
            ex=ex[0:len(ex)-1]
            screen.delete(0, END)
            screen.insert(0, ex)

        temp=1
        for i in range(1,4):
            for j in range(1,4):
                btn=Button(bfw,text=str(temp),font="lucida 22 bold",bg="white",fg="black",width=4,height=0,relief=RIDGE)
                btn.grid(row=i,column=j)
                temp=temp+1
                btn.bind('<Button-1>',press_btn_func)
        dotbtn=Button(bfw,text=".",font="lucida 22 bold",width=4,height=0,relief=RIDGE)
        dotbtn.grid(row=4,column=1)
        dotbtn.bind('<Button-1>',press_btn_func)
        zrbtn=Button(bfw,text="0",font="lucida 22 bold",width=4,height=0,relief=RIDGE)
        zrbtn.grid(row=4,column=2)
        zrbtn.bind('<Button-1>',press_btn_func)
        dbzerobtn=Button(bfw,text="00",font="lucida 22 bold",width=8,height=0,relief=FLAT)
        dbzerobtn.grid(row=4,column=3,columnspan=2)
        dbzerobtn.bind('<Button-1>',press_btn_func)
        sumbtn=Button(bfw,text="+",font="lucida 22 bold",width=4,height=0,relief=RIDGE,bg="#007ba7")
        sumbtn.grid(row=1,column=5)
        sumbtn.bind('<Button-1>',press_btn_func)
        minusbtn=Button(bfw,text="-",font="lucida 22 bold",width=4,height=0,relief=RIDGE,bg="#007ba7")
        minusbtn.grid(row=2,column=5)
        minusbtn.bind('<Button-1>',press_btn_func)
        multbtn=Button(bfw,text="x",font="lucida 22 bold",width=4,height=0,relief=RIDGE,bg="#007ba7")
        multbtn.grid(row=3,column=5)
        multbtn.bind('<Button-1>',press_btn_func)
        divbtn=Button(bfw,text="/",font="lucida 22 bold",width=4,height=0,relief=RIDGE,bg="#007ba7")
        divbtn.grid(row=4,column=5)
        divbtn.bind('<Button-1>',press_btn_func)
        
        clearbtn=Button(bfw,text="bksp",font="lucida 22 bold",bg="#ed2939",fg="black",width=5,height=0,relief=SOLID,command=bks,activebackground="#ed2939")
        clearbtn.grid(row=2,column=6)
        allclbtn=Button(bfw,text="AC",font="lucida 22 bold",bg="#ed2939",fg="black",activebackground="#ed2939",width=5,height=0,relief=SOLID,command=allclear)
        allclbtn.grid(row=1,column=6)
        equalbtn=Button(bfw,text="=",font="lucida 22 bold",width=5,height=2,relief=FLAT)
        equalbtn.grid(row=3,column=6,rowspan=2)        
        equalbtn.bind('<Button-1>',press_btn_func)
        xbtn=Button(bfw,text="X",font="lucida 22 bold",width=4,height=0,relief=RIDGE,bg="#007ba7")
        xbtn.grid(row=3,column=4)
        xbtn.bind('<Button-1>',press_btn_func)
        abtn=Button(bfw,text="A",font="lucida 22 bold",width=4,height=0,relief=RIDGE,bg="#007ba7")
        abtn.grid(row=1,column=0)
        abtn.bind('<Button-1>',press_btn_func)
        bbtn=Button(bfw,text="B",font="lucida 22 bold",width=4,height=0,relief=RIDGE,bg="#007ba7")
        bbtn.grid(row=2,column=0)
        bbtn.bind('<Button-1>',press_btn_func)
        cbtn=Button(bfw,text="C",font="lucida 22 bold",width=4,height=0,relief=RIDGE,bg="#007ba7")
        cbtn.grid(row=3,column=0)
        cbtn.bind('<Button-1>',press_btn_func)
        dbtn=Button(bfw,text="D",font="lucida 22 bold",width=4,height=0,relief=RIDGE,bg="#007ba7")
        dbtn.grid(row=4,column=0)
        dbtn.bind('<Button-1>',press_btn_func)
        ebtn=Button(bfw,text="E",font="lucida 22 bold",width=4,height=0,relief=RIDGE,bg="#007ba7")
        ebtn.grid(row=1,column=4)
        ebtn.bind('<Button-1>',press_btn_func)
        fbtn=Button(bfw,text="F",font="lucida 22 bold",width=4,height=0,relief=RIDGE,bg="#007ba7")
        fbtn.grid(row=2,column=4)
        fbtn.bind('<Button-1>',press_btn_func)

        res_octal = StringVar()
        res_binary = StringVar()
        res_decimal = StringVar()
        def Convert():

            x1 = Entry.get(c1)
            dec = int(x1, 16)
            octal = oct(dec)
            res_octal.set(octal)

            chup = int(x1,16)
            binary = (bin(chup))
            res_binary.set(binary)

            chup1 = int(x1, 16)
            decimal = str(chup1)
            res_decimal.set(decimal)
        
        x1Lab = Label(top3,text="Value you want to convert",bg="#eaa221",fg="black",font="FiraSans 14 bold",width=0)
       

        declab=Label(top3,text="decimal",bg="#eaa221",fg="maroon",font="FiraSans 24 bold",width=9)
        decans=Label(top3,textvariable=res_decimal,bg="black",fg="white",width=17,height=2,font="FireSans 12")
        octlab=Label(top3,text="octal",bg="#eaa221",fg="maroon",font="FiraSans 24 bold",width=9)
        octans=Label(top3,textvariable=res_octal,bg="black",fg="white",width=17,height=2,font="FireSans 12")
        binlab=Label(top3,text="binary",bg="#eaa221",fg="maroon",font="FiraSans 24 bold",width=9)
        binans=Label(top3,textvariable=res_binary,bg="black",fg="white",width=17,height=2,font="FireSans 12 ")

        convert = Button(top3,text="convert",font="comicsans 18 italic",command=Convert,bg="black",fg="white",width=6)
        c1=Entry(top3,textvar=c,font="lucida 22 bold",justify=CENTER,bg="black",fg="white",width=10)
        x1Lab.place(x=69,y=360)
        
        
        octlab.place(x=63,y=415)
        binlab.place(x=63,y=470)
        declab.place(x=63,y=525)
        c1.place(x=320,y=350)
        
        octans.place(x=230,y=415)
        binans.place(x=230,y=470)
        decans.place(x=230,y=525)
        convert.place(x=490,y=460)

    def qui():
        root.destroy()
        root1.destroy()
        
    #complete    
    from_decimal=Button(root1,text="dec to other bases",font = " vedana 10 bold",bg="black",fg="red",activebackground="orange",activeforeground="white",borderwidth=6, relief=GROOVE,command=bi)
    from_decimal.place(x=290,y=175,height=60,width=150)
    # from_decimal=Button(root1,textvariable=tn,font = " vedana 10 bold",bg="black",fg="red",activebackground="orange",activeforeground="white",borderwidth=6, relief=GROOVE,command=bi)
    # from_decimal.place(x=290,y=175,height=60,width=150)
    # tn.set("dec to other bases")
    #complete
    from_binary=Button(root1,text="bin to other bases",font = " vedana 10 bold",bg="black",fg="red",activebackground="orange",activeforeground="white",borderwidth=6, relief=GROOVE,command=d)
    from_binary.place(x=480,y=175,height=60,width=150)
    #complete
    from_octal=Button(root1,text="oct to other bases",font = " vedana 10 bold",bg="black",fg="red",activebackground="orange",activeforeground="white",borderwidth=6, relief=GROOVE,command=o)
    from_octal.place(x=290,y=265,height=60,width=150)
    #complete
    from_hexadecimal=Button(root1,text="hexdec to other bases",font = " vedana 10 bold",bg="black",fg="red",activebackground="orange",activeforeground="white",borderwidth=6, relief=GROOVE,command=hd)
    from_hexadecimal.place(x=480,y=265,height=60,width=150)
    # gui quit (to remove)
    quit_button=Button(root1,text="quit",font = " vedana 10 bold",bg="#2b3635",fg="white",activebackground="orange",activeforeground="white",borderwidth=6, relief=RIDGE,command=qui)
    quit_button.place(x=560,y=390,height=50,width=120)
    theme_button=Button(root1,text="Go for light THEME",font = " vedana 10 bold",bg="white",fg="purple",activebackground="orange",activeforeground="white",borderwidth=6, relief=GROOVE,command=go_to_light_theme)
    theme_button.place(x=380,y=110,height=40,width=170)

    root.mainloop()

def startisclicked():
    #labelimage.destroy()
    label1.destroy()
    my_label.destroy()
    label2.destroy()
    startprogram()
# to get the image on the window
#img1 = PhotoImage(Image.open("pro tkin image.png"))
#labelimage = Label(root,image = img1,height=330,width=400)
#labelimage.pack(padx=10)

label1 = Label(root,text="Converter for Programmers",font="Comicsans 26 bold",bg="white",fg="red",justify="center")
label1.pack(pady=(0,50))

#my_img = ImageTk.PhotoImage(Image.open("huh.png"))
my_label = Button(text="START",background="white",font="verdana 40",width=200,height=60,relief=SOLID,border=3, command=startisclicked)
my_label.pack()

label2 = Label(root,text="Click on ' START ' button to proceed",bg="white",fg="black",font="helvetica 13 bold")
label2.pack()
#here is the finishing line of code which is written to run the window
root.mainloop()