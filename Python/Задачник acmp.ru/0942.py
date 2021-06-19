N = int(input())
arr5 = list(map(int, input().split()))
arr3 = arr5.copy()
arr1 = arr5.copy()

arr3.reverse()
arr1.sort()

sum = [0, 0, 0]

for i in range(N):
    sum[0] += arr1[i]
    sum[1] += arr3[i]
    sum[2] += arr5[i]

print(sum.index(min(sum))+1)

# Проще, решение всегда будет 1
# print(1)