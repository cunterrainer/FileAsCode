import numpy, random, os, shutil
from PIL import Image

def DeleteFolder(path:str):
    if os.path.exists(path):
        shutil.rmtree(path)

def CreateFolder(path:str):
    if not os.path.exists(path):
        os.makedirs(path)

imageFolder = "images"
DeleteFolder(imageFolder)
CreateFolder(imageFolder)
imageName = imageFolder + "/image"
images = 500
for i in range(images):
    print("Generating " + str(i+1) + " | " + str(images), end="\r")
    imarray = numpy.random.rand(random.randint(1, 1080),random.randint(1, 1920),3) * 255
    im = Image.fromarray(imarray.astype('uint8'))
    if i % 2 == 0:
        im.save(imageName + str(i+1) + ".png", "PNG", optimize=True, progressive=True)
    else:
        im.save(imageName + str(i+1) + ".jpg", "JPEG", optimize=True, progressive=True)