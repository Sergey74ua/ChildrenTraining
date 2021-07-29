N = int(input())

arr = list(map(int, input().split()))

for i in range(len(arr)):
    arr[i] = chr(arr[i] % 256)

print("".join(arr))
