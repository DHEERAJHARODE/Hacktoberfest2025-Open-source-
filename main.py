import requests
from datetime import datetime
import os
API_KEY=os.environ["API_KEY"]
APP_ID=os.environ["APP_ID"]

headers={
    "x-app-id":APP_ID,
    "x-app-key":API_KEY,
    "Content-Type": "application/json"
    # "x-remote-user-id":0
}
parameters={
    "query":input("what workout did you do today?"),
    "gender":"male",
    "weight_kg":"60.0",
    "height_cm":"170.0",
    "age":"19"
}
response=requests.post("https://trackapi.nutritionix.com/v2/natural/exercise",json=parameters,headers=headers)
nutrition_data=response.json()

data={}
for i in range(len(nutrition_data['exercises'])):
    user_data={'sheet1':{
        "date":datetime.now().strftime("%d/%m/%Y"),
         "time":datetime.now().strftime("%X"),
        "exercise":nutrition_data['exercises'][i]["user_input"],
        "duration":nutrition_data['exercises'][i]["duration_min"],
        "calories":nutrition_data['exercises'][i]["nf_calories"]
    }}
    data=user_data
    response = requests.post("https://api.sheety.co/41003832fdd39c2d2858d727ff7f1cfd/workoutTracking/sheet1", json=data,auth=(os.environ["USER_NAME"], os.environ["PASSWORD"]))
    # print(response.text)
print(f"Your data is successfully saved in sheet 😍😍")

