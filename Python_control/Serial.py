import serial
from tkinter import *

ser = serial.Serial('/dev/ttyACM0',baudrate= 9600,timeout=1)
root = Tk()
myLabel = Label(root,text = "Leds interface")
red_button = Button(root,text = "Red!",command = lambda :arduino('R'),bg='#e12f09').grid(row=0,column=0)
reen_button = Button(root,text = "Green!",command = lambda :arduino('G'),bg='#21d907').grid(row=0,column=1)
blue_button = Button(root,text = "Blue!",command = lambda :arduino('B'),bg='#082aea').grid(row=0,column=2)



def arduino(color):

    if color == 'R':
        ser.write(b'R\r')
    elif color == 'G':
        ser.write(b'G\r')
    elif color == 'B':   
        ser.write(b'B\r')

root.mainloop()