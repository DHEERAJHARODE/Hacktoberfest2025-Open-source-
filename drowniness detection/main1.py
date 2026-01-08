
from tkinter import*
from tkinter.ttk import *
# loading Python Imaging Library
from PIL import ImageTk, Image
from tkinter import Label
from tkinter import Button

import cv2 as cv
import numpy as np
import pyttsx3
from scipy.spatial import distance
from imutils import face_utils
from imutils.video import VideoStream
from imutils.video import WebcamVideoStream
import numpy as np
import imutils
import argparse
from threading import Thread
import time
import dlib
import cv2
import pygame
import playsound

engine = pyttsx3.init('sapi5')
voices = engine.getProperty('voices')
# print(voices[1].id)
engine.setProperty('voice', voices[1].id)

def speak(audio):
    engine.say(audio)
    engine.runAndWait()

class Face_Recognition_System:
    def __init__(self,root):
        
        self.root=root      #initiazing root
        self.root.geometry("1530x790+0+0")           #size of window
        self.root.title("OBJECT DETECTION SYSTEM")
                #bg img
        img3=Image.open('objectdet.png')
        img3 = img3.resize((1530,710))
        self.photoimg3=ImageTk.PhotoImage(img3)
        
        bg_img=Label( self.root , image = self.photoimg3 )
        bg_img.place( x =0, y = 0 , width = 1530 , height =710 )
        speak("WELCOME TO OBJECT DETECTION")
       
        title_lbl=Label(bg_img,text="OBJECT DETECTION       ", font=('Times New Roman',27,'bold'),bg='white',fg='red')
        title_lbl.place(x=0,y=0,width=1530,height=45)
         #exit button
        img12=Image.open('index.png')
        img12 = img12.resize((160,160))
        self.photoimg12=ImageTk.PhotoImage(img12)
        b1=Button ( bg_img , image = self.photoimg12, cursor='heart' )
        b1.place ( x = 550 , y = 290 , width = 200 , height = 190 )
        b2=Button ( bg_img ,text="detect object",command=self.detection, cursor='heart', font=('Times New Roman',15,'bold'),bg='dark blue',fg='white' )
        b2.place ( x = 550 , y = 480 , width = 200 , height = 40 )

    def detection(self):
        
        
            #for loading and playing alarm
        def sound_alarm():
            pygame.mixer.init()
            pygame.mixer.music.load("Loud alarm.mp3")
            pygame.mixer.music.play()
            while pygame.mixer.music.get_busy()==True:
                continue 

        #minimum threshold of eye aspect ratio after which alarm will active
        eye_aspect_ratio_threshold=0.3

        #minimum consecutive frames
        eye_aspect_ratio_consecutive_frames=40                  #originaly was 50

        #for counting consecutive frames
        COUNTER=0
        ALARM_ON=False

        #loading face cascade
        face_cascade=cv2.CascadeClassifier("haarcascade_frontalface_default.xml")

        #calculation of eye aspect ratio
        def eye_aspect_ratio(eye):
        
            #distance between two sets of vertical eye landmarks(x,y) coordinates
            x=distance.euclidean(eye[1],eye[5])
            y=distance.euclidean(eye[2],eye[4])
            
            # distance between horizontal eye landmarks
            z=distance.euclidean(eye[0],eye[3])
            EAR=(x+y)/(2*z)
            return EAR

        #loading face detector and shape predector from dlib
        detector=dlib.get_frontal_face_detector()
        predictor=dlib.shape_predictor("shape_predictor_68_face_landmarks.dat")

        #extracting indexes of facial landmark of left and right
        (lstart,lend)=face_utils.FACIAL_LANDMARKS_IDXS['left_eye']
        (rstart,rend)=face_utils.FACIAL_LANDMARKS_IDXS['right_eye']

        #Start webcam video capture
        vs = cv2.VideoCapture(0)

        


        while True:
        
            #taking the frame
            frame= vs.read()
            
            #resizing
            try:
                img = cv2.resize(img, (1400, 1000))
                print(img.shape)
            except:
                break
            
            #converting to grayscale
            gray=cv2.cvtColor(frame,cv2.COLOR_BGR2GRAY)

            #detect faces in the grayscale frame
            faces=detector(gray,0)
            
            #looping through the detected faces
            for rect in faces:
                
                #determine the facial landmarks for the face region
                shape =predictor(gray,rect)
                shape=face_utils.shape_to_np(shape)
                
                #extract left eye coordinates
                leftEye= shape[lstart:lend]

                #extract left eye coordinates
                rightEye= shape[rstart:rend]

                #compute the ratios
                leftEAR=eye_aspect_ratio(leftEye)
                rightEAR=eye_aspect_ratio(rightEye)

                #averageing the eyeaspect ratio
                ear=(leftEAR+rightEAR)/2.0

                #compute the convex hull for the left and right eye,then
                #visualize each of the eye
                leftEyeHull=cv2.convexHull(leftEye)
                rightEyeHull=cv2.convexHull(rightEye)
                cv2.drawContours(frame,[leftEyeHull],-1,(0,255,0),1)
                cv2.drawContours(frame,[rightEyeHull],-1,(0,255,0),1)
                
                # cheacking if eye aspect ratio is below the blinkthreshhold
                #and if so
                if ear<eye_aspect_ratio_threshold:
                    COUNTER+=1
                    if COUNTER>=eye_aspect_ratio_consecutive_frames:
                        
                        #turning the alarm on
                        if not ALARM_ON:
                            ALARM_ON=True
                            
                            #playing alarm
                            t=Thread(target=sound_alarm)
                            t.deamon=True
                            t.start()
                            
                            #alert on window
                        cv2.putText(frame,"wake up!",(10,30),
                                        cv2.FONT_HERSHEY_SIMPLEX,0.7,(0,0,255),2)
                    
                    #if eye aspect value not below threshold
                else:
                    COUNTER=0
                    ALARM_ON=False
                
                #eye aspect ratio in frame
                cv2.putText(frame,"EAR: {:.2f}".format(ear),(300,30),
                            cv2.FONT_HERSHEY_SIMPLEX,0.7,(0,0,255),2)
            
            #Show video feed
                cv2.imshow('Video', frame)
                if(cv2.waitKey(1) & 0xFF == ord('q')):
                    break

        
if __name__== "__main__":
    root = Tk()
    obj = Face_Recognition_System(root)
    root.mainloop()
    
