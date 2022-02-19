-- Äåêîäèğîâàíèå, ïğîáà ñêğèïòîâ
os.setlocale('rus_rus.1251')

-- Èñõîäíûé òåêñò
text = [[
ù&_APRWScpSCXx_c9/<S-ScpSRù}XSù_RALX1_:9ùx<1¶C/1S</x_<SxSCXd/LSxEù/LSE1_E1`w:¶ùLCc<Sùx1CC/`SL<X¶S-S¶ùRùdXS9Rù71RJX1_>:pcR!XS1}1SP1p/_SJXS71<WC/>cSRc!1`@:CùS9Rc¶Scp1SJXx_<<wSxùx1¶S7ù`S9ùx91NX1_:ESù_e1Jp/1S9ù<ASxSùLù_ùşSxEù1`@:/Sx_RXp¶c_SùJ/7/Sù_SP1N1Cù`SJXPXE<@:/SPc¶/_S<X`SxùPX&ScxCcEN/1S¶cPRXE<>:_191RWS7ùAS9ùRX¦SASC1S<şP<şSE1xC<w:x&c!CXS7C1Sù__191<WwSEùCW@SdRAJWS-SE1xCù`SASPù<1Cw:&RùEWSPRù¶/_wS!cEx_EX@Sc7S_ùx&ùşSx_1xC1C<>:xcRùEùşSJ/7ù`SASPù<11S¶ùEù<1C@:<şP<şS11SxC1dXwSES9R/xc_x_E//S<cC<:&X&S<1d&/`SP1dSxXC1`SxS9ù¶Rcdù`SP<x_RS/SEù<1C@:&ùd¶XS9ù¶SxùPù<17@SxùdR1_XS/SxE1pX@:ùCXSEX7SRc&cSp71_@S9<<XAS/S¶RùpX5:&X&SE1x1<ù@SùPcESp1<1Jù7Sùx_R<7SCùd/@:x&ù<WJ/_WS9ùSJ1R&X<cSx_ùA!/L@SRùEC<LSR1&5:XSJ/7C/LS9RXJ¶C/&ùESP<1x_A}/1S_R1Eùd/V>>:CùSCX¶ùSJCX_WS/S!1x_WwS9ù<dù¶XSxC1dS¶XSxC1d@:E1¶WSI_ùSCX&ùC1>S/Sp/_1<şSP1R<ùd/@:71¶E1¶ş@SCX¶ù1x_>SC1<WJASp1S>1<<`SE1&:&X_X_WxASCX7SESxXCALSxSXR7/¶X7/S7<X¶<7/:/<WS&/xCc_WScS91!1`SJXSx_1&<X7/S¶Eù`C<7/>:
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

print("Äëèííà òåêñòà: ", #text)
print("Âñåãî ñèìâîëîâ: ", #origSimbol, '\n')
print("Àëôàâèò - øèôğîâêà:")
print(abc, '\n')
print("×èñëî ñèìâîëîâ:")
print(numbAbc, '\n')
print(text)
print()

-- Çàìåíÿåì ñèìâîëû
decodeText = decodeText: gsub('S', ' ')
decodeText = decodeText: gsub('1', 'å')
decodeText = decodeText: gsub('ù', 'î')
decodeText = decodeText: gsub('}', 'ù')
decodeText = decodeText: gsub('X', 'à')
decodeText = decodeText: gsub('c', 'ó')
decodeText = decodeText: gsub('p', 'æ')
decodeText = decodeText: gsub('&', 'ê')
decodeText = decodeText: gsub('_', 'ò')
decodeText = decodeText: gsub('A', 'ÿ')
decodeText = decodeText: gsub('P', 'á')
decodeText = decodeText: gsub('C', 'í')
decodeText = decodeText: gsub('x', 'ñ')
decodeText = decodeText: gsub('R', 'ğ')
decodeText = decodeText: gsub('W', 'ü')
decodeText = decodeText: gsub(':', '\n')
decodeText = decodeText: gsub('9', 'ï')
decodeText = decodeText: gsub('/', 'è')
decodeText = decodeText: gsub('<', 'ë')
decodeText = decodeText: gsub('L', 'õ')
decodeText = decodeText: gsub('¶', 'ä')
decodeText = decodeText: gsub('d', 'ã')
decodeText = decodeText: gsub('E', 'â')
decodeText = decodeText: gsub('`', 'é')
decodeText = decodeText: gsub('!', '÷')
decodeText = decodeText: gsub('N', 'ø')
decodeText = decodeText: gsub('7', 'ì')
decodeText = decodeText: gsub('J', 'ç')
decodeText = decodeText: gsub('@', ',')
decodeText = decodeText: gsub('>', '.')
decodeText = decodeText: gsub('w', ';')
decodeText = decodeText: gsub('e', 'ú')
decodeText = decodeText: gsub('I', 'ı')
decodeText = decodeText: gsub('5', '!')
decodeText = decodeText: gsub('V', '?')
decodeText = decodeText: gsub('¦', ':')
print(decodeText)

io.read()
-- 