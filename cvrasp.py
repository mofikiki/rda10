import cv2
import serial 


ser = serial.Serial('/dev/cu.usbmodem14101',9600,timeout=10)
face_classifier=cv2.CascadeClassifier(cv2.data.haarcascades +"haarcascade_profileface.xml")

video=cv2.VideoCapture(0)
def detect_bounding_box(vid):

    gray_image=cv2.cvtColor(vid,cv2.COLOR_BGR2GRAY)
    faces=face_classifier.detectMultiScale(gray_image,scaleFactor=1.1,minNeighbors=5,minSize=(40,40))

   
    
    width,hieght,ch=vid.shape
    center_frame=(width/2) ,(hieght/2)
    
    if (len(faces)>0):
        x,y,w,h=faces[0]
        cv2.rectangle(vid,(x,y),(x+w,y+h),(0,255,0),4)
        center_object=((x+w)/2),((y+h)/2)
        area_object=((x+w)*(y+h))
        adesired=((width-250)*(hieght-250))

        a,b=center_frame
        c,d=center_object
        if (c<(a-20)):
            print("left")
            ser.write(str.encode("l"))
        elif (c > (a+20)):
            ser.write(str.encode("r"))
            print("right")
        
        if (area_object>adesired):
            ser.write(str.encode("b"))
            print("reverse")

        elif (area_object<adesired):
            ser.write(str.encode("f"))
            print("forward")


    return vid


while True:
    result,video_frame=video.read()
    if result is False:
        break
    dtected_faces= detect_bounding_box(video_frame)

    cv2.imshow("My Face Detection Project",dtected_faces)
    if cv2.waitKey(1)&0xFF==ord("q"):
        break

video.release()
cv2.destroyAllWindows

    