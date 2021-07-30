K = list(map(int, input()))

M = 1
for i in reversed(K): # 25 = 11/5
    N = i
    M = M + N * i
    

print(str(M) + '/' + str(N))
