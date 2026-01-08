

import kivy
kivy.require('1.9.0')
from kivy.app import App
from kivy.lang import Builder
from kivy.uix.screenmanager import ScreenManager, Screen, FadeTransition
from kivy.properties import StringProperty, ObjectProperty,NumericProperty
from kivy.uix.tabbedpanel import TabbedPanel
from kivy.uix.boxlayout import BoxLayout
from kivy.uix.button import Button
from kivy.utils import platform
from kivy.uix.gridlayout import GridLayout
from kivy.uix.label import Label
from kivy.uix.scrollview import ScrollView
from kivy.base import runTouchApp
from kivy.properties import ListProperty
from kivy.uix.image import Image,AsyncImage
from kivy.uix.recycleview.views import RecycleDataViewBehavior
import sqlite3 as lite
import os
from datetime import datetime
from kivy.properties import StringProperty

global current_t

current_t = str(datetime.now().strftime('%I:%M %p'))
print(current_t)


class Tabs(ScrollView):
    def __init__(self, **kwargs):
        super(Tabs, self).__init__(**kwargs)


class Tabba(TabbedPanel):

    def btn1(self):
        global end_station
        end_station="GHATKOPAR"

    def btn2(self):
        global end_station
        end_station="VERSOVA"

    pass

class MainScreen(Screen):
    pass
class FirstScreen(Screen):
    
    pass

class SecondScreen(Screen):
    def btn3(self,name):
        global start_station
        start_station = name
    pass

class SecondScreen2(Screen):
    def btn3(self,name):
        global start_station
        start_station = name
    pass


class ThirdScreen(Screen):
    
    rows = ListProperty([("time","train")])
    print(rows)
    def clear_screen(self):
        self.rows = []
    def get_data(self):
        
        import mysql.connector
        mydb = mysql.connector.connect(host="localhost", user="root", passwd="123456", database="metro")
        mycursor = mydb.cursor()
        
        if end_station == "GHATKOPAR":
        
            if start_station == "VERSOVA":
                mycursor.execute("SELECT * FROM VG" )
                self.rows = mycursor.fetchall()
                #print(self.rows)

            elif start_station == "D N NAGAR":
                mycursor.execute("SELECT * FROM DNG")
                self.rows = mycursor.fetchall()
                # print(self.rows)

            elif start_station == "AZAD NAGAR":
                mycursor.execute("SELECT * FROM AZG")
                self.rows = mycursor.fetchall()
                # print(self.rows)

            elif start_station == "ANDHERI":
                mycursor.execute("SELECT * FROM ANG")
                self.rows = mycursor.fetchall()
                # print(self.rows)

            elif start_station == "WESTERN EXP HIGHWAY":
                mycursor.execute("SELECT * FROM WEG")
                self.rows = mycursor.fetchall()
                # print(self.rows)

            elif start_station == "CHAKALA(JB NAGAR)":
                mycursor.execute("SELECT * FROM CHG")
                self.rows = mycursor.fetchall()
                # print(self.rows)

            elif start_station == "AIRPORT ROAD":
                mycursor.execute("SELECT * FROM AIG")
                self.rows = mycursor.fetchall()
                # print(self.rows)

            elif start_station == "MAROL NAKA":
                mycursor.execute("SELECT * FROM VG")
                self.rows = mycursor.fetchall()
                # print(self.rows)

            elif start_station == "SAKI NAKA":
                mycursor.execute("SELECT * FROM VG")
                self.rows = mycursor.fetchall()
                # print(self.rows)

            elif start_station == "ASALPHA":
                mycursor.execute("SELECT * FROM VG")
                self.rows = mycursor.fetchall()
                # print(self.rows)

            elif start_station == "JAGRUTI NAGAR":
                mycursor.execute("SELECT * FROM VG")
                self.rows = mycursor.fetchall()
                # print(self.rows)

            elif start_station == "GHATKOPAR":
                mycursor.execute("SELECT * FROM VG")
                self.rows = mycursor.fetchall()
                # print(self.rows)

        elif end_station == "VERSOVA":

            if start_station == "GHATKOPAR":
                mycursor.execute("SELECT * FROM GV")
                self.rows = mycursor.fetchall()
                # print(self.rows)

            elif start_station == "JAGRUTI NAGAR":
                mycursor.execute("SELECT * FROM JAV")
                self.rows = mycursor.fetchall()
                # print(self.rows)

            elif start_station == "ASALPHA":
                mycursor.execute("SELECT * FROM ASV")
                self.rows = mycursor.fetchall()
                # print(self.rows)
            
            elif start_station == "SAKI NAKA":
                mycursor.execute("SELECT * FROM SNV")
                self.rows = mycursor.fetchall()
                # print(self.rows)

            elif start_station == "MAROL NAKA":
                mycursor.execute("SELECT * FROM MNV")
                self.rows = mycursor.fetchall()
                # print(self.rows)
            
            elif start_station == "AIRPORT ROAD":
                mycursor.execute("SELECT * FROM ARV")
                self.rows = mycursor.fetchall()
                # print(self.rows)
            
            elif start_station == "CHAKALA(JB NAGAR)":
                mycursor.execute("SELECT * FROM CJV")
                self.rows = mycursor.fetchall()
                # print(self.rows)
            
            elif start_station == "WESTERN EXP HIGHWAY":
                mycursor.execute("SELECT * FROM WHV")
                self.rows = mycursor.fetchall()
                # print(self.rows)
            
            elif start_station == "ANDHERI":
                mycursor.execute("SELECT * FROM ANV")
                self.rows = mycursor.fetchall()
                # print(self.rows)
            
            elif start_station == "AZAD NAGAR":
                mycursor.execute("SELECT * FROM AZV")
                self.rows = mycursor.fetchall()
                # print(self.rows)

            elif start_station == "D N NAGAR":
                mycursor.execute("SELECT * FROM DNV")
                self.rows = mycursor.fetchall()
                # print(self.rows)

            if start_station == "VERSOVA":
                mycursor.execute("SELECT * FROM VG")
                self.rows = mycursor.fetchall()
                # print(self.rows)
            

class FareScreen1(Screen):   
    pass

class FareScreen2(Screen):   
    pass

class FareScreen3(Screen):   
    pass

class FareScreen4(Screen):   
    pass

class ScreenManagement(ScreenManager):
    pass

presentation = Builder.load_file("layout2.kv")

class MetroIndicator(App):

    def build(self):
        return presentation


MetroIndicator().run()

