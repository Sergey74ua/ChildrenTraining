-- Декодирование, проба скриптов
os.setlocale('rus_rus.1251')

-- Исходный текст
text = [[
!p!A!a!A!X!t!yM!g!A!t!kyM!uy!a!-Ay8Ay#!g!u!X!u-Ay8A!X!a!gy>-;A!p!A!a!u!t-A!@yM!uyTyTy>A!t!a!g!a!y8y-Ay#y#!ty8y!a!yTy^y#y>A!!a!gy>n;A!!X!!ay#yTy^A!a!uy/y8A!X!ayM!a!|!!ay^!k!-Ay>!kAyM!ay#!uA!a!uAy#!a!ay_y8-;A!!u!2!u!ay#yo!tAy8A!t!-A!@yM!uyTyTy>-Ay#Ay#!X!ay!Ay#yT!ayM!a!ay_y8n;;!>yM!y#!2y8!X=;A!oy#y/y#-AyTy8!g!aA!t!A!2!a!g!a!|!!tA!w!uA!a!uy/y#Ay#!X!a!@!a!y#n;A!_A!2!a!k!u!|!!t-Ayl!aA!t!-A!@yM!uyTyTy>-A!k!a!w!uy_y^!k!a!X!aAyM!a!y#n;;!yT!u!a!!t-A!@yM!uyTyTy>-A!XA!@y8!A!kyM!a!X!u!X!!A!Xy8!A!y>!ay#A!!aA!o!a!ay#;A!AyMy8!!ay8!tA!kyM!uy"A!2!u!ay#!X!uyT!A!a!A!!u!t!aA!ay8!k!a!ty#O;A!e!ayM!a!A!t!ayM!Ayl!A!Xy#!ty8y!a!yTy^y#y>-A!y8!A!o!ay8!2yM!aA!wyM!u!y8yo-;A!p!Ay#A!a!uy/y8!A!t!kyM!uy!ay8A!!a!g!!ay^!k!uA!a!uy#!2y8yon;;!>yM!y#!2y8!X=;A!oy#y/y#-AyTy8!g!aA!t!A!2!a!g!a!|!!tA!w!uA!a!uy/y#Ay#!X!a!@!a!y#n;A!_A!2!a!k!u!|!!t-Ayl!aA!t!-A!@yM!uyTyTy>-A!k!a!w!uy_y^!k!a!X!aAyM!a!y#n;;!MA!w!u!X!wy>yTyTy>-A!2yM!uy_y>Ayl!yM!uAy#!X!a!X!aAyl!A!!a!k!u!|!-;A!p!Ay#y>A!X!a!gy8A!XA!t!kyM!uy!ay8A!2y8y#!ay^A!Xy#y!a!uAyM!a!w!gy>!|!-;A!!uA!v!uyM!2!uyT!A!Xy8!!a!@mM*yoyTy^y#y>-A!w!X!a!t!a!a!yTy^Ay#yT!!2!u!t!-;A!t!kyM!uy!a!Ay#!g!u!X!uAy#yT!u!a!A!2!a!ty8!|A!a!uyM!a!!u!t!n;;!>yM!y#!2y8!X=;A!oy#y/y#-AyTy8!g!aA!t!A!2!a!g!a!|!!tA!w!uA!a!uy/y#Ay#!X!a!@!a!y#n;A!_A!2!a!k!u!|!!t-Ayl!aA!t!-A!@yM!uyTyTy>-A!k!a!w!uy_y^!k!a!X!aAyM!a!y#n;
]]

decodeText = text

-- Заменяем символы
decodeText = decodeText: gsub('y#',   'с') -- 48
decodeText = decodeText: gsub('y8',   'i') -- 31
decodeText = decodeText: gsub('!X',   'в') -- 30
decodeText = decodeText: gsub('!_',   'I') -- 3
decodeText = decodeText: gsub('!',  'В') -- 1

decodeText = decodeText: gsub('!a',   'н') -- 98
decodeText = decodeText: gsub('!u',   'а') -- 54
decodeText = decodeText: gsub('yM',   'р') -- 33
decodeText = decodeText: gsub('!t',   'у') -- 32
decodeText = decodeText: gsub('yT',   'т') -- 28
decodeText = decodeText: gsub('!', 'и') -- 25
decodeText = decodeText: gsub('!',  'е') -- 23
decodeText = decodeText: gsub('!k',   'к') -- 20
decodeText = decodeText: gsub('!', 'д') -- 19
decodeText = decodeText: gsub('y>',   'я') -- 18
decodeText = decodeText: gsub('!2',   'п') -- 18
decodeText = decodeText: gsub('!g',   'л') -- 15
decodeText = decodeText: gsub('!@',   'б') -- 11
decodeText = decodeText: gsub('y^',   'ь') -- 11
decodeText = decodeText: gsub('!w',   'з') -- 11
decodeText = decodeText: gsub('!|',   'ж') -- 10
decodeText = decodeText: gsub('y/',   'ш') -- 8
decodeText = decodeText: gsub('y', 'I') -- 6
decodeText = decodeText: gsub('yl',   'щ') -- 6
decodeText = decodeText: gsub('y_',   'ц') -- 6
decodeText = decodeText: gsub('!o',   'Д') -- 5
decodeText = decodeText: gsub('!p',   'щ') -- 4
decodeText = decodeText: gsub('yo',   'э') -- 4
decodeText = decodeText: gsub('!', 'й') -- 4
decodeText = decodeText: gsub('!e',   'Ч') -- 4
decodeText = decodeText: gsub('!>',   'П') -- 3
decodeText = decodeText: gsub('!', '3') -- 3
decodeText = decodeText: gsub('y', 'х') -- 2
decodeText = decodeText: gsub('!', 'С') -- 2
decodeText = decodeText: gsub('y"',   'ю') -- 1
decodeText = decodeText: gsub('!M',   'А') -- 1
decodeText = decodeText: gsub('y',  'ч') -- 1
decodeText = decodeText: gsub('!v',   'К') -- 1
decodeText = decodeText: gsub('mM*',   "'") -- 1

decodeText = decodeText: gsub('A',   ' ') -- 121
decodeText = decodeText: gsub(';',  '\n') -- 27
decodeText = decodeText: gsub('-',   ',') -- 30
decodeText = decodeText: gsub('n',   ';') -- 10
decodeText = decodeText: gsub('=',   ':') -- 3
decodeText = decodeText: gsub('O',   '.') -- 1

origSimbol = {}
numbSimbol = {}
for i = 1, #decodeText do
    c = decodeText: sub(i, i)
	temp = 0
	for j = 1, #origSimbol do
		if c ~= origSimbol[j] then
			temp = temp + 1
		elseif c == origSimbol[j] then
			break
		end
	end
	if temp == #origSimbol then
		index = #origSimbol+1
		origSimbol[index] = c
		numTemp = 0
		for n = 1, #decodeText do
			cTemp = decodeText: sub(n, n)
			if c == cTemp then
				numTemp = numTemp + 1
			end
		end
		numbSimbol[index] = numTemp
	end
end

abc = ""
for i = 1, #origSimbol do
	abc = abc .. ' ' .. origSimbol[i]
end
numbAbc = ""
for i=1, #numbSimbol do
	numbAbc = numbAbc..origSimbol[i]..'-'..numbSimbol[i]..'; '
end

print("Длинна текста: ", #text)
print("Всего символов: ", #origSimbol, '\n')
print("Алфавит - шифровка:")
print(abc, '\n')
print("Число символов:")
print(numbAbc, '\n')

print(decodeText)

io.read()

-- 8 r $ в f
-- pz az ts bk Yz Ya ha jM rb 7u au wu
