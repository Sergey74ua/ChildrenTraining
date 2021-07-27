import tkinter as tk
from factory import Factory


window = tk.Tk()
window.title('Фабрика')
g = tk.Canvas(window, width=480, height=320)
g.pack()

f = Factory()

for i in Factory.Race:
    unit = f.new_unit(i)
    print('Юнит рассы: ', i, ' на позиции: ', unit.pos)
    file = tk.PhotoImage(file=unit.file)
    image = tk.Label()
    i.image = file
    g.create_image(unit.pos, image=i.image)

window.mainloop()
