-- Консольная программа кодирования текста путем замены символов
os.setlocale('rus_rus.1251')

print("ИСХОДНЫЙ ТЕКСТ: ")
text = io.read()
print(text)

origSimbol = {text: sub(1, 1)}
math.randomseed(os.time())
codeSimbol = {string.char(3)}
codeText = ""

function rndSymbol()
	r = string.char(math.random(14, 127))
	for i = 1, #codeSimbol do
		if r == codeSimbol[i] then
			rndSymbol()
		end
	end
	return r
end

for i = 1, #text do
    c = string.lower(text: sub (i, i))
	temp = 0
	for j = 1, #origSimbol do
		if c ~= origSimbol[j] then
			temp = temp + 1
		elseif c == origSimbol[j] then
			codeText = codeText .. codeSimbol[j]
			break
		end
	end
	if temp == #origSimbol then
		origSimbol[#origSimbol+1] = c
		r = rndSymbol()
		codeSimbol[#codeSimbol+1] = r
		codeText = codeText .. r
	end
end

print("ЗАКОДИРОВАННЫЙ ТЕКСТ: ")
print(codeText)

io.read()