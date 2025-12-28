from PIL import Image,ImageDraw,ImageFont
import math
char="$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\|()1{}[]?-_+~<>i!lI;:,\"^`'."[::1]
char0=" .:-=+*#%@"
textfile=open("Output","w")

interval=len(char0)/256
ScaleFactor=1
def getchar(x):
    return char0[math.floor(x*interval)]
im=Image.open("BMW.jpg")
width,height=im.size
print(width,height)

im=im.resize((int(ScaleFactor*width),int(ScaleFactor*height)),Image.NEAREST)
width,height=im.size
pix=im.load()
print(width,height)

for i in range(height):
    for j in range(width):
        r,g,b=pix[j,i]
        h=int(r/3+g/3+b/3)
        pix[j,i]=(h,h,h)
        textfile.write(getchar(h))
        
#im.save("Output1.png")
textfile.close()
        
