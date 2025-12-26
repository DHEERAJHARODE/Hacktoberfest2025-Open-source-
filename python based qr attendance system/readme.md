 Attendance System using QR Codes

This Python project is designed to create an attendance system using QR codes. It allows you to maintain records of attendees at a session by generating unique QR codes for registered candidates, scanning these codes from a camera, and recording attendance in an Excel sheet. The system uses Python, OpenCV, and other libraries to achieve this functionality.

## Features

- Generate unique QR codes for registered candidates.
- Scan QR codes using the camera of your machine.
- Record attendance by updating an Excel sheet.
- Simple and extensible Python code.

## Setup

1. Clone the repository:

   ```bash
   git clone https://github.com/your-username/attendance-system.git
Install the required Python libraries:

bash
pip install qrcode[pil] opencv-python-headless pyzbar openpyxl
Run the app.py file to start the attendance system:

bash
python app.py
Follow the on-screen instructions to scan QR codes and record attendance.

Usage
Register candidates by generating unique QR codes for their emails or identifiers.
Run the app.py script to scan QR codes from the camera.
Detected QR codes will be printed on the terminal and recorded in an Excel sheet.
File Structure
app.py: The main Python script for scanning QR codes and recording attendance.
generate_qr.py: Python script to generate QR codes.
attendance.xlsx: Excel file to store attendance records.
Contributing
Feel free to contribute to this project by opening issues or submitting pull requests. Your feedback and contributions are highly appreciated.

License
This project is licensed under the MIT License - see the LICENSE file for details.

Author
Your Name
Happy coding!