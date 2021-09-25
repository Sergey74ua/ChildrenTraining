arr = list(map(int, input().split(',')))

R = 0
for i in range(len(arr)-2):
    for j in range(i+1, len(arr)-1):
        x = 2160/arr[i]/arr[j]
        if x-int(x)==0:
            for n in range(j+1, len(arr)):
                if x == arr[n]:
                    R = 1
                    break

print(R)


#Дорешивание