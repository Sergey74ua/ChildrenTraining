-- �������������, ����� ��������
os.setlocale('rus_rus.1251')

-- �������� �����
text = [[
O}-nbR6X|XsARJX"R>-X'AR|ARXY"-}�U
'AR|ARX>7}zc�X}-�'RnzcX7Xn-Ybzc�U
sARJzXb-XO}-5-+�XRAX�s-�AQ!Xn}-Ybz+�U
�}65zXf-}QZ->7X}6ORbQ'RX�RJ7>-}:::U

sARJzXORnR>7}TXLIc�XblXb6Xf}-sQWL�U
f>7Y7>-}X'XO>l"7X�nR6c�XY-}6!�U
O>6}X�7}Qb66Xn�!'RcXJ-A->67�U
Jz}X}2JRnb7'�Xf->6bQ�X">lOX7Xn>-s:::U

sARJzXb-X'>Rn-A7X>!"R>X�f-}U
7X�Rf6}XA7+RbQ'R�X>6}R"7sbR�U
-X'RO"-XO>l�A7qQX>6}-b+R}7sbR�U
RbXA6J!X}2J7>RcXb-5zn-}:::U

O}-nbR6X|XsARJX"R>-X'AR|ARXJz}�U
'ARXn">lOX"lqlXnzf}6�b6AXb->lYl�U
-X'RO"-XAzX5}-!�X�'-Y6ATXLblXY6�U
l�fR'Rc�!X7Xlc>7X�nRcXfz}:::LU

'ARXf>R�A7AXb->XAz�!s7X75>6b�U
�'-Y6ATXLb6XnR}blc�!�Xn�6X>zX}"7�U
n-YbRXAR�XsARX>zX">lOX">lO-X}J7>�U
IARXO}-nbR6�X-X5b-s7AXb6AXf>RJ}6>:::LU

5-Alf!A�!X>7}}7RbzXY-}�U
7Xlc"6AX75X�6>"Z-Xn�6Xf}R+R6:U
O}-nbR6X|XsARJX'AR|ARXJz}X�XARJR2�U
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

print("������ ������: ", #text)
print("����� ��������: ", #origSimbol, '\n')
print("������� - ��������:")
print(abc, '\n')
print("����� ��������:")
print(numbAbc, '\n')
print(text)

-- �������� �������
decodeText = decodeText: gsub('b', '�') -- 32
decodeText = decodeText: gsub('l', '�') -- 17
decodeText = decodeText: gsub('6', '�') -- 33
decodeText = decodeText: gsub('R', '�') -- 65
decodeText = decodeText: gsub('A', '�') -- 42

decodeText = decodeText: gsub('-', '�') -- 49
decodeText = decodeText: gsub('>', '�') -- 37 -- �
decodeText = decodeText: gsub('7', '�') -- 31
decodeText = decodeText: gsub('�', '�') -- 25
decodeText = decodeText: gsub("'", '�') -- 19
decodeText = decodeText: gsub('|', '-') -- 9

decodeText = decodeText: gsub('}', '�') -- 43
decodeText = decodeText: gsub('n', '�') -- 22
decodeText = decodeText: gsub('O', '�') -- 17
decodeText = decodeText: gsub('J', '�') -- 18
decodeText = decodeText: gsub('"', '�') -- 18
decodeText = decodeText: gsub('Y', '�') -- 12
decodeText = decodeText: gsub('c', '�') -- 12
decodeText = decodeText: gsub('!', '�') -- 11
decodeText = decodeText: gsub('f', '�') -- 13
decodeText = decodeText: gsub('L', '"') -- 6
decodeText = decodeText: gsub('5', '�') -- 8
decodeText = decodeText: gsub('+', '�') -- 5
decodeText = decodeText: gsub('Q', '�') -- 8
decodeText = decodeText: gsub('Z', '�') -- 2
decodeText = decodeText: gsub(':', '.') -- 19
decodeText = decodeText: gsub('T', ':') -- 3
decodeText = decodeText: gsub('I', '�') -- 2
decodeText = decodeText: gsub('W', '!') -- 1
decodeText = decodeText: gsub('q', '�') -- 2
decodeText = decodeText: gsub('2', '�') -- 5 ' '
decodeText = decodeText: gsub('z', '�') -- 19 )
decodeText = decodeText: gsub('s', '�') -- 15 .

decodeText = decodeText: gsub('X', ' ') -- 104
decodeText = decodeText: gsub('�', ',') -- 27
decodeText = decodeText: gsub('U', '') -- 24

print(decodeText)

io.read()

--[[
������� - ���� ���� ���-�� ����,
���-�� �����, �������� � ������,
����� �� ������, �� ������� �������,
����� �������� �������� �������...

����� �������: "��, �� �� �����!",
�������� � ����� �����, �����,
���� ������� ������ �������,
��� ��������, ������, ���� � ����...

����� �� ������� ����� ����
� ����� ��������, ���������,
� ����� �������� ������������,
�� ���� ������� �������...

������� - ���� ���� ���-�� ���,
��� ����� ���� ��������� ������,
� ����� �� ����, ������: "�� ��,
��������� � ���� ���� ���..."

������� ��� �� ������ � �����,
������: "�� ��������, ��� �� ����,
����� ��, ��� �� ���� ����� �����,
��� �������, � ������ ��� �������..."

��������� �������� ���,
� ����� �� ������ ��� ������.
������� - ���� ���-�� ��� � �����,
������� - ���� ���� ���-�� ����...
]]