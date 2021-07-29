import tkinter as tk
from factory import Factory

window = tk.Tk()
window.title('Фабрика')

g = tk.Canvas(window, width=480, height=320, bg='DarkGreen')
g.pack()

f = Factory()


def new_game():
    for i in f.Race:
        unit = f.new_unit(i)
        unit.console()

        file = tk.PhotoImage(file=unit.file)
        i.image = file
        g.create_image(unit.pos, image=i.image)

        g.create_text((unit.pos[0], unit.pos[1]+20), text=unit.pos, fill='lime')


button = tk.Button(window, text='Обновить', font=16, bg='LightGrey', command=new_game)
button.pack()

window.mainloop()
