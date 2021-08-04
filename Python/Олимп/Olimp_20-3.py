K = list(map(int, input()))

M = 1
N = 0
for i in reversed(K):
    N, M = M, N
    M = i * N + M

print(str(M) + '/' + str(N))
