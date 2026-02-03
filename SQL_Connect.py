# Contributer : Ravin D (ravin-d-27)
# This is the code for connecting MySQL With Python for Data Extraction

import mysql.connector as m

class MySQL_Connector(object):

    def __init__(self, username, password, host, db_name): # Essential things to connect MySQL and Python interface

        self.mydb = m.connect(host = host, user = username, passwd = password, database = db_name)
        self.c = self.mydb.cursor()
    
    def fetch_all(self, table): # This is the method to fetch all the data from the table of given database
        
        try:
            query = f"select * from {table}"
            self.c.execute(query)
            b = self.c.fetchall()
            return b
        except:
            print("Unable to fetch the data because of invalid parameters")

    def select_data(self, tablename, *args): # This is the method to fetch the particular data from the table of given database

        string = ''

        for i in args:
            string+=i+","
        
        try:
            string = string[:-1]
            self.execute(f"select {string} from {tablename}")
            b = self.c.fetchall()
            return b
        except:
            print("Unable to fetch the data because of invalid parameters")

        

