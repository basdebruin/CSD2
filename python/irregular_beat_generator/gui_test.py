 # GUI Test
 # for funsies

from tkinter import *

def hello():
    print("hello, my peeps")

class App:
    def __init__(self, master):
        frame = Frame(master)
        frame.pack()

        self.button = Button(frame, text="HOI", command=hello)
        self.button.pack()
        self.but2 = Button(frame, text="QUIT", command=frame.quit)
        self.but2.pack()

        self.l = Label(text="label")
        self.l.pack()
        self.e = Entry(frame, width=20)
        self.e.pack()


root = Tk()

app = App(root)

root.mainloop()