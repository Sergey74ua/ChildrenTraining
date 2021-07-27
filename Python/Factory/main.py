import tkinter as tk
from race import Race
from factory import Factory


f = Factory()

root = tk.Tk()
g = tk.Canvas(root, width=400, height=320)

for i in Race:
    unit = f.new_unit(i)
    print('Юнит рассы: ', i, ' с планеты: ', unit.from_planet(), ' на позиции: ', unit.pos)
    # ГОВНОКОД КАКОЙ-ТО
    img = tk.PhotoImage(file=unit.file)
    g.create_image(unit.pos, image=img)
    label = tk.Label(root, image=img)
    label.img = img

g.pack()
root.mainloop()
