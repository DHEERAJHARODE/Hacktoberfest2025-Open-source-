import os, datetime, platform, glob, shutil
from tkinter import *


def rename():
    path = r'' + p.get()
    os.chdir(path)  # if we want to change our current working directory

    lst = (os.listdir(path))  # returns a list of all the files and folders of that directory
    ext = []

    new_name = word.get()
    i = 1
    j = 0
    for files in lst:
        ex = (os.path.splitext(files)[1])
        ext.append(ex)
        # for item in ext:
        dest = new_name + str(i) + ext[j]
        src = files
        dest = os.path.join(path, dest)
        os.rename(src, dest)
        i += 1
        j += 1
        print(dest)


def sort():
    path = r'' + p.get()
    filenames = glob.glob(path + "/*")
    dictionary = {}

    def win_file(file):
        return datetime.datetime.fromtimestamp(os.path.getctime(file))

    osys = platform.system()
    if osys == 'Windows':
        operating_system = 'win'

    for file in filenames:
        if operating_system == 'win':
            file_time = win_file(file)

        file_date = file_time.strftime(" %d %m %Y")
        dictionary[file] = file_date

    # print(dictionary)
    log = ''

    for key, value in dictionary.items():
        if not os.path.exists(path + value):
            os.makedirs(path + value)
        filename = key.split('\\')
        filename = filename[-1]
        if not os.path.exists(path + value + '\\' + filename):
            # print(path+value+'/'+filename)
            if os.path.isfile(key):
                shutil.move(key, path + value + '\\' + filename)
                log = log + key + 'moved to' + path + value + '\\' + filename + '/n' + '/n'
            elif os.path.isdir(key):
                shutil.copytree(key, path + value + '\\' + filename)
                shutil.rmtree(key)
                log = log + key + 'moved to' + path + value + '\\' + filename + '/n' + '/n'
    with open(path + 'log.txt', 'w') as f:
        f.write(log)


root = Tk()
root.title('RENAMER')
root.geometry('400x400')
root.configure(background="#263D42")
root.frame()

p = StringVar()
Label(root, text='FILE PATH', font=('TIMES NEW ROMAN', 12), fg="white", bg="#263D42").pack(pady=10)
ent1 = Entry(root, textvariable=p, font=('TIMES NEW ROMAN', 12))
ent1.pack()

word = StringVar()
Label(root, text='RENAME', font=('TIMES NEW ROMAN', 12), fg="white", bg="#263D42").pack(pady=10)
ent2 = Entry(root, textvariable=word, font=('TIMES NEW ROMAN', 12))
ent2.pack()

rename_button = Button(root, text='Change', command=rename, padx=100, pady=5, fg="#263D42", bg="white").pack(pady=30)
sort_button = Button(root, text='Sort', command=sort, padx=110, pady=5, fg="#263D42", bg="white").pack()

root.mainloop()
