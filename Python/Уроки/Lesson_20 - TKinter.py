from tkinter import *
root=Tk() # создаем главное окно
root.title('Сумма двух чисел')

def summa():
    a = EntryA.get()
    a = int(a)

    b = EntryB.get() 
    b = int(b)

    result = str(a + b)
    EntryC.delete(0, END)
    EntryC.insert(0, result)

Label(root,text='Первое число').pack()
EntryA=Entry(root,width=10,font='Arial 16')
EntryA.pack()

Label(root,text='Второе число').pack()
EntryB=Entry(root,width=10,font='Arial 16')
EntryB.pack()

but=Button(root, text='Сумма', command=summa)
but.pack()

EntryC=Entry(root,width=20,font='Arial 16')
EntryC.pack()

root.mainloop()
