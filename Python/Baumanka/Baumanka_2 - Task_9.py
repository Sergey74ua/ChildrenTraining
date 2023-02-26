from tkinter import *
from random import randint

size_x, size_y = 400, 400

def click_button():
    canvas.delete('all')
    r = randint(1, 3)
    if r == 1:
        canvas.create_rectangle(20, 20, size_x-20, size_y-20, fill="Yellow", outline="Black", width=3)
    elif r == 2:
        canvas.create_oval(20, 20, size_x-20, size_y-20, fill="Yellow", outline="Black", width=3)
    else:
        canvas.create_polygon(20, size_y-20, size_x//2, 20, size_x-20, size_y-20, fill="Yellow", outline="Black", width=3)

root = Tk()
root.title("Квадрат, круг, треугольник")
root.geometry(f'{size_x+30}x{size_y+50}')
canvas = Canvas(root, height=400, width=400, bg="White")

btn = Button(text="Случайная фигура", command=click_button)
btn.pack()

canvas.pack()
root.mainloop()