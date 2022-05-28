from tkinter import *
from tkinter import ttk
from PIL import Image,ImageTk
from tkinter import messagebox
import mysql.connector
import cv2
from time import strftime
from datetime import datetime
import os
# import numpy as np  
# from deepface import DeepFace
# import matplotlib.pyplot as plt

class Face_Recognition:
    def __init__(self,root):
        self.root=root
        self.root.geometry("1530x790+0+0")
        self.root.title("Face Identification")

        title_lbl=Label(self.root,text="FACE IDENTIFICATION",font=("times new roman",40,"bold"),bg="light grey",fg="navyblue")
        title_lbl.place(x=0,y=0,width=1300,height=50)

        img_top=Image.open(r"college_images\face_recog.jpg")
        img_top=img_top.resize((1300,680),Image.ANTIALIAS)
        self.photoimg_top=ImageTk.PhotoImage(img_top)

        f_lbl=Label(self.root,image=self.photoimg_top)
        f_lbl.place(x=0,y=50,width=1300,height=680)

        # img_top = Image.open(r"C:\Users\dell\Downloads\facerec.png")
        # img_top = img_top.resize((1530, 700))
        # self.photoimg_top = ImageTk.PhotoImage(img_top)

        # f_lbl = Label(self.root, image=self.photoimg_top)
        # f_lbl.place(x=0, y=80, width=1500, height=600)

        #img_bottom = Image.open(r"C:\Users\dell\img1.png")
        #img_bottom = img_bottom.resize((1530, 325), Image.ANTIALIAS)
        #self.photoimg_bottom = ImageTk.PhotoImage(img_bottom)

        #f_lbl = Label(self.root, image=self.photoimg_bottom)
        #f_lbl.place(x=0, y=440, width=1400, height=200)

        #check command
        b1_1=Button(self.root, text="CAPTURE",command=self.face_recog, cursor="hand2",font=("times new roman", 23, "bold"), bg="lightblue")
        b1_1.place(x=870, y=380, width=250, height=60)


    #..............Attendance...............
    def mark_attendance(self,i,r,n,d):
        with open("ishita.csv","r+",newline="\n") as f:
            myDataList=f.readlines()
            name_list=[]
            for line in myDataList:
                entry=line.split((","))
                name_list.append(entry[0])
            if((i not in name_list) and (r not in name_list) and (n not in name_list) and (d not in name_list)):
                now=datetime.now()
                d1=now.strftime("%d/%m/%Y")
                dtString=now.strftime("%H:%M:%S")
                f.writelines(f"\n{i},{r},{n},{d},{dtString},{d1},Present")
       

    #............Face recognition..............
    def face_recog(self):
        def draw_boundray(img,classifier,scaleFactor,minNeighbors,color,text,clf):
            gray_image=cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
            features=classifier.detectMultiScale(gray_image,scaleFactor,minNeighbors)

            coord=[]

            for(x,y,w,h) in features:
                cv2.rectangle(img,(x,y),(x+w,y+h),(0,255,0),3)
                id,predict=clf.predict(gray_image[y:y+h,x:x+w])
                confidence=int((100*(1-predict/300)))

                conn=mysql.connector.connect(host="localhost",user="root",password="ishita0301",database="face_recognition")
                my_cursor=conn.cursor()

                my_cursor.execute("Select Name from student where Student_Id="+str(id))
                n=my_cursor.fetchone()
                n="+".join(n)

                my_cursor.execute("Select Roll_No from student where Student_Id=" + str(id))
                r = my_cursor.fetchone()
                r = "+".join(r)

                my_cursor.execute("Select Department from student where Student_Id=" + str(id))
                d = my_cursor.fetchone()
                d = "+".join(d)

                my_cursor.execute("select Student_Id from student where Student_Id=" + str(id))
                i = my_cursor.fetchone()
                i = "+".join(i)

                if confidence>77:
                    cv2.putText(img, f"Student Id:{i}", (x, y - 75), cv2.FONT_HERSHEY_SIMPLEX, 0.8, (255, 255, 255), 3)
                    cv2.putText(img, f"Roll No:{r}", (x, y-55), cv2.FONT_HERSHEY_SIMPLEX, 0.8, (255,255,255), 3)
                    cv2.putText(img, f"Name:{n}", (x, y - 30), cv2.FONT_HERSHEY_SIMPLEX, 0.8, (255, 255, 255), 3)
                    cv2.putText(img, f"Department:{d}", (x, y - 5), cv2.FONT_HERSHEY_SIMPLEX, 0.8, (255, 255, 255), 3)
                    self.mark_attendance(i,r,n,d)

                else:
                    cv2.rectangle(img,(x, y), (x + w, y + h), (0, 255, 0), 3)
                    cv2.putText(img, "Unknown Face", (x, y - 5), cv2.FONT_HERSHEY_COMPLEX, 0.8, (255, 255, 255), 3)

                coord=[x,y,w,y]

            return coord

        def recognize(img,clf,faceCascade):
            coord=draw_boundray(img,faceCascade,1.1,10,(255,25,255),"Face",clf)
            return img

        faceCascade=cv2.CascadeClassifier(cv2.data.haarcascades+"haarcascade_frontalface_default.xml")
        clf=cv2.face.LBPHFaceRecognizer_create()
        clf.read("classifier.xml")

        video_cap=cv2.VideoCapture(0)
    
        while True:
            ret,img=video_cap.read()
            img=recognize(img,clf,faceCascade)
            cv2.imshow("Welcome to Face Recognition",img)
            
            # plt.imshow(img[:,:,::-1])
            # plt.show()

            if cv2.waitKey(1)==13:
                break

        video_cap.release()
        cv2.destroyAllWindows()


if __name__=="__main__":
    root=Tk()
    obj=Face_Recognition(root)
    root.mainloop()