
# Выдает не тот результат.
# Ответ: 109348849 и 134397649 и 152349649 и 193404649.

for i in range(0, 10000):
	s=str(i).zfill(4)
	for j in range(5):
		t=int('1'+s[:j]+'34'+s[j:]+'49')
		q=t**0.5
		if t-round(q**2)==0:
			arr=[]
			for n in range(2, int(q**0.5)+1):
				if q%n==0:
					arr.append(n)
					if len(arr)>1:
						break
			if len(arr)==1:
				print(t)
