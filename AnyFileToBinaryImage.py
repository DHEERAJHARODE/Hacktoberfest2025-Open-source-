import base64
from PIL import Image
import os
import stat




file_path = "your_file_path"
with open(file_path,"rb") as  f:
    encodeData = base64.b64encode(f.read())



binaryData = "".join(format(ord(chr(c)), "b") for c in encodeData)

def binary_string_to_image(binary_string):
    # Calculate the width and height based on the desired ratio
    width = 7680
    height = 4320

    # Create a new image with specified width and height
    image = Image.new('1', (width, height))

    # Convert the binary string to a list of integers
    binary_data = [int(bit) for bit in binary_string]

    # Convert the list of integers to an image
    image.putdata(binary_data)


    return image


def get_file_metadata(file_path):
    file_stat = os.stat(file_path)
    metadata = {
        'File Name': os.path.basename(file_path),
        'Size': file_stat.st_size,
        'Permissions': stat.filemode(file_stat.st_mode),
        'Last Modified': file_stat.st_mtime,
        'Creation Time': file_stat.st_ctime
    }
    return metadata

# Example usage
metadata = get_file_metadata(file_path)
print(metadata)


def img_to_binary(file_path):
    # Read the binary image
    binary_string = ""
    image = Image.open(file_path).convert('1')
    width, height = image.size

    # Iterate through each pixel
    # Get the image size
    width, height = image.size

    # Create an empty list
    integer_list = []
    t_z = 0
    # Iterate through each pixel
    for y in range(height):
        for x in range(width):
            if(t_z>16):
                return integer_list
            # Get the pixel value (0 or 255)
            pixel_value = image.getpixel((x, y))
            if(str(pixel_value)=='255'):
                pixel_value = 1
                t_z =0
            else:
                t_z = t_z+1
                pixel_value = 0

            # Append the pixel value to the list
            integer_list.append(pixel_value)

    # Print or use the integer list
    return integer_list


# Example usage
count = 0
while(binaryData !=""):
    totle_size = 7680 * 4320
    if(len(binaryData)>=totle_size):
        one_img_data_string = binaryData[:totle_size]
        binaryData = binaryData[totle_size:]
        image = binary_string_to_image(one_img_data_string)
        image.save('test images/binary_image'+str(count)+'.png')
        count = count+1
    else:
        one_img_data_string = binaryData
        binaryData =""
        image = binary_string_to_image(one_img_data_string)
        image.save('test images/binary_image'+str(count)+'.png')
        image.show()


# Example usage

data = img_to_binary('test images/binary_image'+str(count)+'.png')
debinaryData = "".join(str(v) for v in data)













