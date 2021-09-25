word = list(input())
temp = list(range(len(word)))
arr = []

for i in range(len(word)):
    for j in range(len(word)):
        temp[j] = word[j]
    if word[i] == 'w':
        temp[i] = 'v'
        arr.append(''.join(temp))
    elif word[i] == 'v':
        temp[i] = 'w'
        arr.append(''.join(temp))
    elif word[i] == 's':
        temp[i] = 'c'
        arr.append(''.join(temp))
    elif word[i] == 'c':
        temp[i] = 's'
        arr.append(''.join(temp))
    elif word[i] == 'd':
        temp[i] = 't'
        arr.append(''.join(temp))
    elif word[i] == 't':
        temp[i] = 'd'
        arr.append(''.join(temp))

if len(arr) > 0:
    arr.sort()
    R = ','.join(arr)
else:
    R = -1

print(R)


#Дорешивание