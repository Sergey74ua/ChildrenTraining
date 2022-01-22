-- 22.01.2022
--[[
Язык программирования Lua
скриптовый
строки - константные
]]
X = "Hello world"
print(X)

Y = io.read('*n')
if Y == 1 and (Y > 0 or Y == 1000) then
	io.write(X, X)
else
	print('нет')
end

arr = {1, 2, 3, 4, 5}
print(arr[1])

arr2 = {pn = 'понедельник', vt = 'вторник', sr = 'среда'}
print(arr2.vt .. arr2.sr)

function sum(x, y)
	local z = x + y
	return(z)
end
print(sum(5, 6))

repeat
	print('цикл repeat ', Y); Y = Y - 1
until Y < 3


while Y > 0 do
	print('цикл while ', Y); Y = Y - 1
end

for i = 1, 5, 2 do
	print('цикл for ', i)
end