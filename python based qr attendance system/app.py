import qrcode

data = "johndoe4@example.com"  # You can replace this with candidate email or unique identifier
qr = qrcode.QRCode(
    version=1,
    error_correction=qrcode.constants.ERROR_CORRECT_L,
    box_size=10,
    border=4,
)
qr.add_data(data)
qr.make(fit=True)

img = qr.make_image(fill_color="black", back_color="white")
img.save("johndoe_qr4.png")  # Save the QR code to a file
