-- �������� ������� ��� �������������
os.setlocale('rus_rus.1251')

--print('��� ������ ������� ��������: help() \n')

-- ����������� ������������ ����
ch = {'� - 10.97', '� - 8.45', '� - 8.01', '� - 7.35', '� - 6.70',
'� - 6.26', '� - 5.47', '� - 4.73', '� - 4.54', '� - 4.40', '� - 3.49',
'� - 3.21', '� - 2.98', '� - 2.81', '� - 2.62', '� - 2.01', '� - 1.90',
'� - 1.74', '� - 1.70', '� - 1.65', '� - 1.59', '� - 1.44', '� - 1.21',
'� - 0.97', '� - 0.94', '� - 0.73', '� - 0.64', '� - 0.48', '� - 0.36',
'� - 0.32', '� - 0.26', '� - 0.04', '� - 0.04'}

-- ������ ���� �� ����� �����
w1 = {'�', '�', '�', '�', '�', '�', '�', '�'}

-- ������ ���� �� ���� ���� (�� ���)
w2 = {'��', '��', '��', '��', '��', '��', '��', '��', '��', '��', '��',
'��', '��', '��', '��', '��', '��', '��', '��', '��', '��', '��', '��',
'��', '��', '��', '��', '��', '��', '��', '��', '��', '��', '��', '��',
'��', '��', '��', '��'}

-- ��������� �� ������ �������
function help()
	print([[
help() - ������ ������
get(ch) - ����������� ����
get(w1) - ����� �� 1 �����
get(w2) - ����� �� 2 ���� (�� ���)
leng(text) - ����� ����� �������� � ������
abc(text) - c����� � ����� ���������� ��������
all(text) - ��������� ��� ������
	]])
end

-- ����� ������� ������ ���������� ������ � �������
function get(data)
	for i = 1, #data do
		print(data[i])
	end
end

-- ����� ����� �������� � ������
function leng(text)
	print("����� ����� ��������: ", #text)
end

-- ������ � ����� ���������� ��������
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
	print("����� ��������: ", #origSimbol, '\n')
	print("������� - ��������:")
	abc = ""
	for i = 1, #origSimbol do
		abc = abc .. ' ' .. origSimbol[i]
	end
	print(abc, '\n')
	numbAbc = ""
	print("����� ��������:")
	for i=1, #numbSimbol do
		numbAbc = numbAbc..origSimbol[i]..'-'..numbSimbol[i]..'; '
	end
	print(numbAbc, '\n')
end

-- ����� ���� � 2+ ���������
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

-- ����� ���� � 2+ ���������, � ������� ����� ������
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

-- ��������� ��� ������
function all(text)
	help()
	get(ch)
	get(w1)
	get(w2)
	leng(text)
	abc(text)
end