-- Подборка криптов для декодирования
os.setlocale('rus_rus.1251')

--print('Для вызова справки наберите: help() \n')

-- Частотность употребления букв
ch = {'о - 10.97', 'е - 8.45', 'а - 8.01', 'и - 7.35', 'н - 6.70',
'т - 6.26', 'с - 5.47', 'р - 4.73', 'в - 4.54', 'л - 4.40', 'к - 3.49',
'м - 3.21', 'д - 2.98', 'п - 2.81', 'у - 2.62', 'я - 2.01', 'ы - 1.90',
'ь - 1.74', 'г - 1.70', 'з - 1.65', 'б - 1.59', 'ч - 1.44', 'й - 1.21',
'х - 0.97', 'ж - 0.94', 'ш - 0.73', 'ю - 0.64', 'ц - 0.48', 'щ - 0.36',
'э - 0.32', 'ф - 0.26', 'ъ - 0.04', 'ё - 0.04'}

-- Список слов из одной буквы
w1 = {'о', 'а', 'и', 'с', 'в', 'к', 'у', 'я'}

-- Список слов из двух букв (не все)
w2 = {'ад', 'ай', 'ах', 'бы', 'во', 'вы', 'да', 'до', 'ей', 'ее', 'еж',
'за', 'же', 'из', 'им', 'их', 'ко', 'ли', 'мы', 'на', 'не', 'ни', 'но',
'ну', 'ой', 'он', 'ох', 'от', 'по', 'со', 'та', 'те', 'то', 'ту', 'ты',
'уж', 'эй', 'юг', 'яд'}

-- Подсказка по вызову функций
function help()
	print([[
help() - список фукций
get(ch) - частотность букв
get(w1) - слова из 1 буквы
get(w2) - слова из 2 букв (не все)
leng(text) - общее число символов в тексте
abc(text) - cписок и число уникальных символов
all(text) - запустить все фукции
	]])
end

-- Вызов функций вывода справочных данных в консаль
function get(data)
	for i = 1, #data do
		print(data[i])
	end
end

-- Общее число символов в тексте
function leng(text)
	print("Общее число символов: ", #text)
end

-- Список и число уникальных символов
function abc(text)
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
	print("Всего символов: ", #origSimbol, '\n')
	print("Алфавит - шифровка:")
	abc = ""
	for i = 1, #origSimbol do
		abc = abc .. ' ' .. origSimbol[i]
	end
	print(abc, '\n')
	numbAbc = ""
	print("Число символов:")
	for i=1, #numbSimbol do
		numbAbc = numbAbc..origSimbol[i]..'-'..numbSimbol[i]..'; '
	end
	print(numbAbc, '\n')
end

-- Поиск слов с 2+ символами
function find2(text, sp)
	c = ''
	for i = 1, #text do
		c2 = c
		c = text: sub(i, i)
		if c2 == c and c2 ~= sp then
			l = i
			repeat
				l = l - 1
				lc = text: sub(l, l)
			until lc == sp
			r = i - 1
			repeat
				r = r + 1
				rc = text: sub(r, r)
			until rc == sp
			w = text: sub(l+1, r-1)
			print(w)
		end
	end
end

-- Поиск слов с 2+ символами, с выводом куска текста
function find22(text)
	local c = ''
	for i = 1, #text do
		local c2 = c
		c = text: sub(i, i)
		if c2 == c then
			w = text: sub(math.max(i-8, 1), math.min(i+8, #text))
			print(w)
		end
	end
end

-- Запустить все фукции
function all(text)
	help()
	get(ch)
	get(w1)
	get(w2)
	leng(text)
	abc(text)
end