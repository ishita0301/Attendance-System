from tkinter import*
from tkinter import ttk
import tkinter.messagebox
from PIL import Image,ImageTk
from emotion import Emotion
from query import Query
from student import Student
import os
from tkinter import Toplevel
from attendance import Attendance
from emotion import Emotion
from query import Query
from train import Train
from face_recognition import Face_Recognition

class Face_Recognition_System:
    def __init__(self,root):
        self.root=root
        self.root.geometry("1530x790+0+0")
        self.root.title("Face Recognition System")

        # FIRST IMAGE
        img=Image.open(r"college_images\main.jpg")
        img=img.resize((450,100),Image.ANTIALIAS)
        self.photoimg=ImageTk.PhotoImage(img)

        f_lbl=Label(self.root,image=self.photoimg)
        f_lbl.place(x=0,y=0,width=450,height=100)

        # SECOND IMAGE
        img1=Image.open(r"college_images\main4.jpg")
        img1=img1.resize((450,100),Image.ANTIALIAS)
        self.photoimg1=ImageTk.PhotoImage(img1)

        f_lbl=Label(self.root,image=self.photoimg1)
        f_lbl.place(x=450,y=0,width=450,height=100)

        # THIRD IMAGE
        img2=Image.open(r"college_images\main2.jpg")
        img2=img2.resize((450,100),Image.ANTIALIAS)
        self.photoimg2=ImageTk.PhotoImage(img2)

        f_lbl=Label(self.root,image=self.photoimg2)
        f_lbl.place(x=900,y=0,width=450,height=100)

        # BACKGROUNG IMAGE
        img3=Image.open(r"college_images\cream.jpg")
        img3=img3.resize((1330,710),Image.ANTIALIAS)
        self.photoimg3=ImageTk.PhotoImage(img3)

        bg_img=Label(self.root,image=self.photoimg3)
        bg_img.place(x=0,y=100,width=1330,height=710)

        title_lbl=Label(bg_img,text="FACE RECOGNITION BASED ATTENDANCE SYSTEM", font=("comic sans ms",30,"bold"),bg="floral white",fg="slateblue4")
        title_lbl.place(x=0,y=0,width=1300,height=40)


        # STUDENT BUTTON
        img4=Image.open(r"college_images\student1.jpg")
        img4=img4.resize((190,190),Image.ANTIALIAS)
        self.photoimg4=ImageTk.PhotoImage(img4)

        b1=Button(bg_img,image=self.photoimg4,command=self.student_details,cursor="hand2")
        b1.place(x=90,y=70,width=190,height=190)

        b1_1=Button(bg_img,text="STUDENT DETAILS",command=self.student_details,cursor="hand2",font=("times new roman",15,"bold"),bg="slateblue4",fg="white")
        b1_1.place(x=90,y=240,width=190,height=30) 


        # TRAIN DATA BUTTON
        img5=Image.open(r"college_images\train1.jpg")
        img5=img5.resize((190,190),Image.ANTIALIAS)
        self.photoimg5=ImageTk.PhotoImage(img5)

        b1=Button(bg_img,image=self.photoimg5,cursor="hand2",command=self.train_data)
        b1.place(x=395,y=70,width=190,height=190)

        b1_1=Button(bg_img,text="TRAIN DATA",cursor="hand2",command=self.train_data,font=("times new roman",15,"bold"),bg="slateblue4",fg="white")
        b1_1.place(x=395,y=240,width=190,height=30) 


        # DETECT FACE BUTTON
        img6=Image.open(r"college_images\face2.jpg")
        img6=img6.resize((190,190),Image.ANTIALIAS)
        self.photoimg6=ImageTk.PhotoImage(img6)

        b1=Button(bg_img,image=self.photoimg6,cursor="hand2",command=self.face_data)
        b1.place(x=695,y=70,width=190,height=190)

        b1_1=Button(bg_img,text="FACE RECOGNITION",cursor="hand2",command=self.face_data,font=("times new roman",13,"bold"),bg="slateblue4",fg="white")
        b1_1.place(x=695,y=240,width=190,height=30) 


        # ATTENDANCE BUTTON
        img7=Image.open(r"college_images\att1.png")
        img7=img7.resize((190,190),Image.ANTIALIAS)
        self.photoimg7=ImageTk.PhotoImage(img7)

        b1=Button(bg_img,image=self.photoimg7,cursor="hand2",command=self.attendance_data)
        b1.place(x=995,y=70,width=190,height=190)

        b1_1=Button(bg_img,text="ATTENDANCE",cursor="hand2",command=self.attendance_data,font=("times new roman",15,"bold"),bg="slateblue4",fg="white")
        b1_1.place(x=995,y=240,width=190,height=30)


        # PHOTOS BUTTON
        img8=Image.open(r"college_images\photo.jpg")
        img8=img8.resize((190,190),Image.ANTIALIAS)
        self.photoimg8=ImageTk.PhotoImage(img8)

        b1=Button(bg_img,image=self.photoimg8,cursor="hand2",command=self.open_img)
        b1.place(x=90,y=305,width=190,height=190)

        b1_1=Button(bg_img,text="PHOTOS",cursor="hand2",command=self.open_img,font=("times new roman",15,"bold"),bg="slateblue4",fg="white")
        b1_1.place(x=90,y=490,width=190,height=30)


        # QUERY BUTTON
        img9=Image.open(r"college_images\query1.jpg")
        img9=img9.resize((190,190),Image.ANTIALIAS)
        self.photoimg9=ImageTk.PhotoImage(img9)

        b1=Button(bg_img,image=self.photoimg9,cursor="hand2",command=self.query_data)
        b1.place(x=395,y=305,width=190,height=190)

        b1_1=Button(bg_img,text="QUERY",cursor="hand2",command=self.query_data,font=("times new roman",15,"bold"),bg="slateblue4",fg="white")
        b1_1.place(x=395,y=490,width=190,height=30)


        # FEEDBACK BUTTON    
        img10=Image.open(r"college_images\feedback1.jpg")
        img10=img10.resize((190,190),Image.ANTIALIAS)
        self.photoimg10=ImageTk.PhotoImage(img10)

        b1=Button(bg_img,image=self.photoimg10,cursor="hand2",command=self.emotion_data)
        b1.place(x=695,y=305,width=190,height=190)

        b1_1=Button(bg_img,text="FEEDBACK",cursor="hand2",command=self.emotion_data,font=("times new roman",15,"bold"),bg="slateblue4",fg="white")
        b1_1.place(x=695,y=490,width=190,height=30)


        # EXIT BUTTON
        img11=Image.open(r"college_images\exit.jpg")
        img11=img11.resize((190,190),Image.ANTIALIAS)
        self.photoimg11=ImageTk.PhotoImage(img11)

        b1=Button(bg_img,image=self.photoimg11,cursor="hand2",command=self.iExit)
        b1.place(x=995,y=305,width=190,height=190)

        b1_1=Button(bg_img,text="EXIT",cursor="hand2",command=self.iExit,font=("times new roman",15,"bold"),bg="slateblue4",fg="white")
        b1_1.place(x=995,y=490,width=190,height=30)

    def open_img(self):
        os.startfile("data")

    # ..........FUNCTION BUTTONS..........

    def student_details(self):
        self.new_window=Toplevel(self.root)
        self.app=Student(self.new_window)

    def train_data(self):
        self.new_window=Toplevel(self.root)
        self.app=Train(self.new_window)

    def face_data(self):
        self.new_window = Toplevel(self.root)
        self.app = Face_Recognition(self.new_window)

    def attendance_data(self):
        self.new_window = Toplevel(self.root)
        self.app = Attendance(self.new_window)

    def query_data(self):
        self.new_window = Toplevel(self.root)
        self.app = Query(self.new_window)

    def emotion_data(self):
        self.new_window = Toplevel(self.root)
        self.app = Emotion(self.new_window)

    def iExit(self):
        self.iExit=tkinter.messagebox.askyesno("Face Recognition","Are you sure you want to exit?",parent=self.root)
        if self.iExit>0:
            self.root.destroy()
        else:
            return
    
    
if __name__ == "__main__" :
    root=Tk()
    obj=Face_Recognition_System(root) 
    root.mainloop() 