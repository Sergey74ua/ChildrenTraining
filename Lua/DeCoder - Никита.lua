-- Декодирование, проба скриптов
os.setlocale('rus_rus.1251')

-- Исходный текст
text = [[
O}-nbR6X|XsARJX"R>-X'AR|ARXY"-}§U
'AR|ARX>7}zc§X}-¶'RnzcX7Xn-Ybzc§U
sARJzXb-XO}-5-+§XRAX¶s-¶AQ!Xn}-Ybz+§U
¶}65zXf-}QZ->7X}6ORbQ'RX¶RJ7>-}:::U

sARJzXORnR>7}TXLIc§XblXb6Xf}-sQWL§U
f>7Y7>-}X'XO>l"7X¶nR6c§XY-}6!§U
O>6}X¶7}Qb66Xn¶!'RcXJ-A->67§U
Jz}X}2JRnb7'§Xf->6bQ§X">lOX7Xn>-s:::U

sARJzXb-X'>Rn-A7X>!"R>X¶f-}U
7X¶Rf6}XA7+RbQ'R§X>6}R"7sbR§U
-X'RO"-XO>l¶A7qQX>6}-b+R}7sbR§U
RbXA6J!X}2J7>RcXb-5zn-}:::U

O}-nbR6X|XsARJX"R>-X'AR|ARXJz}§U
'ARXn">lOX"lqlXnzf}6¶b6AXb->lYl§U
-X'RO"-XAzX5}-!§X¶'-Y6ATXLblXY6§U
l¶fR'Rc¶!X7Xlc>7X¶nRcXfz}:::LU

'ARXf>R¶A7AXb->XAz¶!s7X75>6b§U
¶'-Y6ATXLb6XnR}blc¶!§Xn¶6X>zX}"7§U
n-YbRXAR§XsARX>zX">lOX">lO-X}J7>§U
IARXO}-nbR6§X-X5b-s7AXb6AXf>RJ}6>:::LU

5-Alf!A¶!X>7}}7RbzXY-}§U
7Xlc"6AX75X¶6>"Z-Xn¶6Xf}R+R6:U
O}-nbR6X|XsARJX'AR|ARXJz}X¶XARJR2§U
O}-nbR6X|XsARJX"R>-X'AR|ARXY"-}:::U
]]

decodeText = text
origSimbol = {}
numbSimbol = {}
for i = 1, #text do
    c = text: sub(i, i)
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
		for n = 1, #text do
			cTemp = text: sub(n, n)
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
print(text)

-- Заменяем символы
decodeText = decodeText: gsub('b', 'н') -- 32
decodeText = decodeText: gsub('l', 'у') -- 17
decodeText = decodeText: gsub('6', 'е') -- 33
decodeText = decodeText: gsub('R', 'о') -- 65
decodeText = decodeText: gsub('A', 'т') -- 42

decodeText = decodeText: gsub('-', 'а') -- 49
decodeText = decodeText: gsub('>', 'м') -- 37 -- р
decodeText = decodeText: gsub('7', 'и') -- 31
decodeText = decodeText: gsub('¶', 'с') -- 25
decodeText = decodeText: gsub("'", 'к') -- 19
decodeText = decodeText: gsub('|', '-') -- 9

decodeText = decodeText: gsub('}', 'л') -- 43
decodeText = decodeText: gsub('n', 'в') -- 22
decodeText = decodeText: gsub('O', 'г') -- 17
decodeText = decodeText: gsub('J', 'б') -- 18
decodeText = decodeText: gsub('"', 'д') -- 18
decodeText = decodeText: gsub('Y', 'ж') -- 12
decodeText = decodeText: gsub('c', 'й') -- 12
decodeText = decodeText: gsub('!', 'я') -- 11
decodeText = decodeText: gsub('f', 'п') -- 13
decodeText = decodeText: gsub('L', '"') -- 6
decodeText = decodeText: gsub('5', 'з') -- 8
decodeText = decodeText: gsub('+', 'х') -- 5
decodeText = decodeText: gsub('Q', 'ь') -- 8
decodeText = decodeText: gsub('Z', 'ц') -- 2
decodeText = decodeText: gsub(':', '.') -- 19
decodeText = decodeText: gsub('T', ':') -- 3
decodeText = decodeText: gsub('I', 'э') -- 2
decodeText = decodeText: gsub('W', '!') -- 1
decodeText = decodeText: gsub('q', 'ш') -- 2
decodeText = decodeText: gsub('2', 'ю') -- 5 ' '
decodeText = decodeText: gsub('z', 'ы') -- 19 )
decodeText = decodeText: gsub('s', 'ч') -- 15 .

decodeText = decodeText: gsub('X', ' ') -- 104
decodeText = decodeText: gsub('§', ',') -- 27
decodeText = decodeText: gsub('U', '') -- 24

print(decodeText)

io.read()

--[[
Главное - чтоб дома кто-то ждал,
Кто-то милый, ласковый и важный,
Чтобы на глазах, от счастья влажных,
Слезы пальцами легонько собирал...

Чтобы говорил: "Эй, ну не плачь!",
Прижимал к груди своей, жалея,
Грел сильнее всякой батареи,
Был любовник, парень, друг и врач...

Чтобы на кровати рядом спал
И сопел тихонько, мелодично,
А когда грустишь меланхолично,
Он тебя любимой называл...

Главное - чтоб дома кто-то был,
Кто вдруг душу выплеснет наружу,
А когда ты злая, скажет: "Ну же,
успокойся и уйми свой пыл..."

Оградит нас от печали и измен,
Скажет: "Не волнуйся, все мы люди,
Важно то, что мы друг друга любим,
Это главное, а значит нет проблем..."

Затупятся миллионы жал,
И уйдет из сердца все плохое.
Главное - чтоб кто-то был с тобою,
Главное - чтоб дома кто-то ждал...
]]