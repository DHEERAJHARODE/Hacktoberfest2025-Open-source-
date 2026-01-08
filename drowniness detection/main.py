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
eye_aspect_ratio_consecutive_frames=50                  #originaly was 50

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
  cv2.imshow('frame', frame)
	
	
	# the 'q' button is set as the
	# quitting button you may use any
	# desired button of your choice
  if cv2.waitKey(1) & 0xFF == ord('q'):
    break
  
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
        cv2.putText(frame,"wake up!",(10,30),cv2.FONT_HERSHEY_SIMPLEX,0.7,(0,0,255),2)
    
    #if eye aspect value not below threshold
    else:
       COUNTER=0
       ALARM_ON=False
    
    #eye aspect ratio in frame
  cv2.putText(frame,"EAR: {:.2f}".format(ear),(300,30),
                cv2.FONT_HERSHEY_SIMPLEX,0.7,(0,0,255),2)
  
 
    

