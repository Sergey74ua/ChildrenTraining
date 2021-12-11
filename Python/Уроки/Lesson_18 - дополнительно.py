# divmod
print(divmod(10, 3), '\n')

x = int(input('Введите X: '))
print('x =', x, '\n')

# Стандарт
if x > 5 and x < 10:
    print('Стандарт: YES - x > 5 and x < 10 \n')
else:
    print('Стандарт: NO - x > 5 and x < 10 \n')

# Сокращенно
if 10 > x > 5:
    print('Сокращенно: YES - 10 > x > 5 \n')
else:
    print('Сокращенно: NO - 10 > x > 5 \n')

# Тернарный оператор
print('Тернарный: YES - x > 5 and x < 10 \n') if x > 5 and x < 10 else print('Тернарный: NO - x > 5 and x < 10 \n')

# ALL (каждое)
if all([x > 5, x < 10]):
    print('all(каждое): YES - [x > 5, x < 10] \n')
else:
    print('all(каждое): NO - [x > 5, x < 10] \n')


# ANY (любое)
if any([x > 5, x < 10]):
    print('any(любое): YES - [x > 5, x < 10] \n')
else:
    print('any(любое): NO - [x > 5, x < 10] \n')


# ZIP
arrName = ['Максим', 'Никита', 'Матвей']
arrAge = [15, 14, 12]
arrYear = [2005, 2007, 2009]

arr = list(zip(arrName, arrAge, arrYear))
print(*arr, '\n')

# zip в цикле
for name, age, year in zip(arrName, arrAge, arrYear):
	print(name, age, year)
print()

# распаковка zip
a, b, c = zip(*arr)
print('распаковка zip', a, '\n')
print('распаковка zip', b, '\n')
print('распаковка zip', c, '\n')

# enumerate
arr = ['один', 'два', 'три', 'четыре', 'пять']
for i, value in enumerate(arr):
    print(i, value)
print()

# iter + next + reversed
iArr = iter(reversed(arr))
print('next', next(iArr))
print('next', next(iArr))
print('next', next(iArr))
print()

# yield (вместо return)
def calc(x, y):
    yield(x + y)
    yield(x - y)
    yield(x * y)
    yield(x / y)

for i in calc(2, 3):
    print(i)
print()

# генераторы
print(*(i**2 for i in range(1, 10)))
print()


print(dir(arr))

# breakpoint, dir, vars, help, open, repr
# super, property, issubclass и isinstance, hasattr, getattr, setattr и delattr, classmethod и staticmethod
# iter, callable, filter and map, divmod, bin, oct и hex, abs, hash, object, ord и chr, exec и eval, compile, slice
# bytes, bytearray и memoryview, ascii, frozenset, importlib, format, complex

input()