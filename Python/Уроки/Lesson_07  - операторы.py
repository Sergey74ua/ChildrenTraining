# Урок № 7 по Python - стандартные функции

x = 123 #input("ввод в консоль - ")
print("конвертация в число -", int(x))
print("конвертация в дробное -", float(x))
print()

x = "Hello world!"
print("строка -", x)
print("длина строки -", len(x))
print("конвертация в строку -", str(len(x))+"ед.")
print("трансформация в список -", list(x))
print("трансформация в кортеж -", tuple(x))
print()

colors = [('red', 2), ('green', 1), ('blue', 3), ('purple', 5)]
print("список кортежей из 2 значений - ", colors)
colors = dict(colors)
print("трансформация в словарь - ", colors)
print()

x = [1, 1, 8, 3, 3, 2]
print("список - ", x)
print("минимальное значение - ", min(x))
print("максимальное значение - ", max(x))
print("сортировка списка - ", sorted(x))
print("сортировка списка наоборот - ", sorted(x, reverse=True))
print("сумма списка -", sum([2, 1, 3, 4, 7]))
print("сумма цикла списка -", sum(n**2 for n in x))
print("набор - ", set(x))
print()

print("bool любого числа -", bool(-5))
print("bool нуля -", bool(0))
print("bool любого символа -", bool("_"))
print("bool пустоты -", bool(""))
print()

help(str.split)

# any, all, enumerate, zip, reversed, next
# type, breakpoint, dir, vars, help, open, repr
# super, property, issubclass и isinstance, hasattr, getattr, setattr и delattr, classmethod и staticmethod
# iter, callable, filter and map, divmod, bin, oct и hex, abs, hash, object, ord и chr, exec и eval, compile, slice
# bytes, bytearray и memoryview, ascii, frozenset, importlib, format, complex

input()