-- 22.01.2022
--[[
����������� Lua
�������������
]]

os.setlocale('rus_rus.1251')

X = "Hello world"
print(X)

Y = io.read('*n')
if Y == 1 and (Y > 0 or Y == 1000) then
	io.write(X, X)
elseif Y ~= 0 then
	print('�� ����')
else
	print('�����')
end

a, b, c = 5, 10, 15
arr = {1, 2, 3, 4, 5}
print(arr[1])

arr2 = {pn = '�����������', vt = '�������', sr = '�����'}
print(arr2.vt .. arr2.sr)

function sum(x, y)
	local z = x + y
	return(z)
end
print(sum(5, 6))

repeat
	print('���� repeat ', Y); Y = Y - 1
until Y < 3


while Y > 0 do
	print('���� while ', Y); Y = Y - 1
end

for i = 1, 5, 2 do
	print('���� for ', i)
end

print(type("Hello world"))      --> string
print(type(10.4*3))             --> number
print(type(print))              --> function
print(type(type))               --> function
print(type(true))               --> boolean
print(type(nil))                --> nil
print(type(type(X)))            --> string

-- tonumber(Y) �������������� � �����
-- x, y = y, x - ��������!

s = 'walternate'  -- Immutable strings like Python.
t = "double-quotes are also fine"
u = [[ Double brackets
       start and end
       multi-line strings.]]
t = nil

print(math.random()) -- [0 �� 1]
print(math.random(10)) -- [1..�� �����];
print(math.random(10, 20)) -- [�� �����..�� �����].

-- ���������������
function f(x) return math.sin(x) end
f = function (x) return math.sin(x) end

-- ����� ������ � ������
for key, val in pairs(arr) do  -- Table iteration.
  print(key, val)
end

for i = 1, #arr do  -- #v is the size of v for lists.
  print(arr[i])  -- Indices start at 1 !! SO CRAZY!
end
-- ???? module.lua
-- local mod = require('module')
-- �� ���� �����������:
-- local mod = (function ()
--  <contents of mod.lua>
-- end)()

-- ������ �����
-- dofile("data/scripts/Main.lua");

-- ������:�
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

Y = io.read('*n')