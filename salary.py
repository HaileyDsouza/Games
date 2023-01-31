# NOT DONE YET

from tkinter import *

win = Tk()
win.geometry('500x300')

# Create a canvas object
canvas = Canvas(win, width=1000, height=750, bg="White")

# Add a text in Canvas
canvas.create_text(100, 50, text="HELLO WORLD", fill="black", font=('Helvetica 15'))
canvas.pack()

win.mainloop()




