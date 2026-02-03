#pip install pyttsx3 {for Speaking}
#pip install PyPDF2 {for Converting PDFs to readable files for Python}
import pyttsx3
import PyPDF2
file_path = input('Enter the File Path :')
book = open(file_path,'rb') #rb -> Read-Only-Mode
n = int(input('From Which page do you want to Start the Reader :'))
pdf_reader = PyPDF2.PdfFileReader(book)
pages = pdf_reader.numPages
speaker = pyttsx3.init()
for num in range(n,pages):
    page = pdf_reader.getPage(num)
    text = page.extractText()
    speaker.say(text)
    speaker.runAndWait()
