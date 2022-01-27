-- 22.01.2022
--[[
Комментарии Lua
многострочные
]]

os.setlocale('rus_rus.1251')

X = "Hello world"
print(X)

a, b, c = 5, 10, 15

print(type("Hello world"))      --> string
print(type(10.4*3))             --> number
print(type(print))              --> function
print(type(type))               --> function
print(type(true))               --> boolean
print(type(nil))                --> nil
print(type(type(X)))            --> string

-- tonumber(Y) преобразование в число
-- x, y = y, x - работает!

s = 'walternate'  -- Immutable strings like Python.
t = "double-quotes are also fine"
u = [[ Double brackets
       start and end
       multi-line strings.]]
t = nil

Y = io.read('*n')
if Y == 1 and (Y > 0 or Y == 1000) then
	io.write(X, X)
elseif Y ~= 0 then
	print('не ноль')
else
	print('иначе')
end

function sum(x, y)
	local z = x + y
	return(z) -- можно несколько значений
end
print(sum(5, 6))

-- функциональщина
function f(x) return math.sin(x) end
f = function (x) return math.sin(x) end

-- ^ возведение в степень
-- tostring(Y) преобразование в строку (print стрингует и выводит)

-- не равно ~=

-- блок кода
do
	local x = math.max(1, 5, 3, 1, 6) -- локальные переменные закрыты
	print(x)
end

-- Строки: 
print(string.upper('aaaAAA'))
print(string.lower ('aaaAAA'))
print(string.gsub("aaaa","a","z",3)) --> zzza	3
print(string.find("Hello Lua user", "Lua", 1)) --> 7	9
print(string.reverse("Lua")) --> auL
print(string.format("the value is:%d",4)) --> the value is:4
print(string.char(97,98,99,100)) --> abcd
print(string.byte("ABCD",4)) --> 68
print(string.byte("ABCD")) --> 65
print(string.len("abc")) --> 3
print(string.rep("abcd",2)) --> abcdabcd

print(math.random()) -- [0 до 1]
print(math.random(10)) -- [1..до числа];
print(math.random(10, 20)) -- [от числа..до числа].

arr = {1, 2, 3, 4, 5}
print(arr[1])
print(#arr) -- длина массива

arr2 = {pn = 'понедельник', vt = 'вторник', sr = 'среда'}
table.sort(arr2)

mytable = { 5, 4, 3, 5, 5, 3, 3, 4, 4, 4, 4, 5, 3, }
mymetatable = {}
setmetatable(mytable,mymetatable)
print("METATABLE: ", mymetatable)

-- итератор (обход ключей и данных)
for key, i in ipairs(arr) do
   print(key, i)
end

repeat
	print('цикл repeat ', Y); Y = Y - 1
until Y < 3

while Y > 0 do
	print('цикл while ', Y); Y = Y - 1
end

for i = 1, 5, 2 do
	print('цикл for ', i)
end

for i = 1, #arr do  -- #v is the size of v for lists.
  print(arr[i])  -- Indices start at 1 !! SO CRAZY!
end

-- файл module.lua
-- local mod = require('module')
-- по сути равносильно:
-- local mod = (function ()
--  <contents of mod.lua>
-- end)()

-- Запуск файла
-- dofile("data/scripts/Main.lua");

Y = io.read('*n')