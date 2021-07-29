import tkinter as tk
from factory import Factory

window = tk.Tk()
window.title('Фабрика')

g = tk.Canvas(window, width=480, height=320, bg='DarkGreen')
g.pack()

f = Factory()


def new_game():
    g.delete("all")
    for i in f.Race:
        unit = f.new_unit(i)
        unit.console()

        file = tk.PhotoImage(file=unit.file)
        i.image = file
        g.create_image(unit.pos, image=i.image)
        g.create_text((unit.pos[0], unit.pos[1] - 36), text=unit.__class__.__name__, font=14, fill='White')
        g.create_text((unit.pos[0], unit.pos[1] + 32), text=unit.pos, fill='Lime')


button = tk.Button(window, text='Обновить', font=16, bg='LightGrey', command=new_game)
button.pack()

window.mainloop()
