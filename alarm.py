import datetime
import time
import os
import platform

def play_sound():
    if platform.system() == "Windows":
        os.system("start alarm.mp3")
    elif platform.system() == "Darwin":
        os.system("afplay alarm.mp3")
    else:
        os.system("mpg123 alarm.mp3")

def set_alarm(alarm_time):
    print(f"⏰ Alarm set for {alarm_time}")
    while True:
        now = datetime.datetime.now().strftime("%H:%M")
        if now == alarm_time:
            print("🔔 Wake up! Alarm ringing!")
            play_sound()
            break
        time.sleep(30)

if __name__ == "__main__":
    time_input = input("Enter alarm time (HH:MM, 24-hour format): ")
    set_alarm(time_input)
