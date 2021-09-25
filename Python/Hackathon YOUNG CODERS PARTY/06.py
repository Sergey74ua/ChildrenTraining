arr = input()
arrkey = {}

for i in range(len(arr)-2):
    temp = (arr[i] + arr[i+1] + arr[i+2])
    S = arr.count(temp)
    arrkey[temp] = S

arr = []
key = []
for i in arrkey:
    arr.append(i)
    key.append(str(arrkey[i]))

print(','.join(arr)+','+','.join(key))


#Дорешивание