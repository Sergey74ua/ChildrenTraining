from tkinter import *

def hi():
    label["text"] = "Hello " + entry.get()

root = Tk()
root.title("10")
root.geometry("250x200")

entry = Entry()
entry.pack(anchor=NW, padx=6, pady=6)

btn = Button(text="Click", command=hi)
btn.pack(anchor=NW, padx=6, pady=6)

label = Label()
label.pack(anchor=NW, padx=6, pady=6)

root.mainloop()