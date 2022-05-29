## FACE RECOGNITION BASED ATTENDANCE SYSTEM

Facial detection based attendance system to ease the task of teachers &amp; eliminate the problem of proxies.
This project involves building an attendance system which utilizes facial recognition to mark the presence.

**Software used:-** Visual Studio Code(VS CODE)

**Technology Used:**

	1)tkinter for whole GUI
	2)OpenCV for taking images and face recognition (cv2.face.LBPHFaceRecognizer_create())
	3)deepface library for emotion detection
	4)MySQL for database

**Features:**

  	 HOME PAGE    
	1) Student management system (save Student info/Add Photo Sample, Update, Delete, Reset) 
	2) Train photo samples 
	3) Take attendance with Face Recognition 
	4) Attendance Report(Excel file/csv file) 
	5) Query page
	6) Feedback page
  	7) Exit
	
**How Facial Recognition Works?**

A facial recognition software captures and compares patterns on a person’s face and analyses the details to identify and verify the individual. While the underlying system is complex, the whole technology can be broken down into three steps:

	1) Face Detection: An essential step is locating human faces in real-time
	2) Transform Data: Once captured, the analogue facial information is transformed into a set of data or vectors based on a person’s facial features
	3) Face Match: The system matches the data above with the one in the database for verification
	
**Algorithms Used:**

	1) Haarcascade Opencv (Object/Face Detection)
	2) LBPH Opencv (Face Recognition)
	
**Database**

	Tables:
	1) student
	2) query
	3) emotion
	
	Username-root
	Password-ishita@0301

	To access the database(face_recognition):

	first create database name face_recognition
	restore face_recognition.sql file using Command:

	mysql -u root -p face_recognition<C:\face_recognition.sql

	in the path directory: C:\Program Files\MySQL\MySQL Server 8.0\bin

	(Run this command on command prompt as admin)
	(Make sure you have downloaded MySQL in your computer)

| ![main](https://github.com/ishita0301/Attendance-System-/blob/main/Front%20end/main.png)| ![student details](https://github.com/ishita0301/Attendance-System-/blob/main/Front%20end/student%20details.png)
|-|-|
| Home Page | Student Details |
| ![train data](https://github.com/ishita0301/Attendance-System-/blob/main/Front%20end/train%20data.png)| ![face](https://github.com/ishita0301/Attendance-System-/blob/main/Front%20end/face.png)
| Train Data | Face Recognition |
| ![face recognition](https://github.com/ishita0301/Attendance-System-/blob/main/Front%20end/face%20recognition.png)| ![attendance](https://github.com/ishita0301/Attendance-System-/blob/main/Front%20end/attendance.png)
| Face Identification | Attendance Record |
| ![query](https://github.com/ishita0301/Attendance-System-/blob/main/Front%20end/query.png)| ![feedback](https://github.com/ishita0301/Attendance-System-/blob/main/Front%20end/feedback.png)
| Queries | Feedback Record |
| ![emotion detection](https://github.com/ishita0301/Attendance-System-/blob/main/Front%20end/emotion%20detection.JPG)| ![graph](https://github.com/ishita0301/Attendance-System-/blob/main/Front%20end/graph.png)
| Emotion Detection | Feedback Graph |

