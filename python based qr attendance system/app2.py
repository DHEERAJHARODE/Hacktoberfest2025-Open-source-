import cv2
import pyzbar.pyzbar as pyzbar

# Initialize the webcam or external camera
cap = cv2.VideoCapture(0)  # Use 0 for the default camera, or specify the camera index if you have multiple cameras

mail = []

while True:
    # Read a frame from the camera
    ret, frame = cap.read()

    # Convert the frame to grayscale
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    # Detect QR codes in the frame
    decoded_objects = pyzbar.decode(gray)

    for obj in decoded_objects:
        data = obj.data.decode("utf-8")
        if data not in mail:
            mail.append(data)
            print(f"{data},")
            # Here, you can check if the scanned data exists in your candidate records and mark attendance accordingly.
            # You can update an Excel sheet or database here.

    # Display the frame with detected QR codes
    cv2.imshow('QR Code Scanner', frame)

    # Press 'q' to exit the loop
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# Release the camera and close the OpenCV window
cap.release()
cv2.destroyAllWindows()


import openpyxl

# Load the Excel workbook
workbook = openpyxl.load_workbook("attendance.xlsx")
sheet = workbook.active
for i in range(len(mail)):
# Update the sheet with attendance information
    sheet.cell(row=i+1, column=2, value=mail[i])  # Example: Marking attendance for the second candidate
    print("done")
# Save the workbook
workbook.save("attendance.xlsx")
