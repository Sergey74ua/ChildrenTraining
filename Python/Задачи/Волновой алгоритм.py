"""
YES
3 7
7 10
NO
5 5
7 10
##########
#     #  E
#  ## ## #
# #     ##
#  ##### #
#  #     #
#E########
"""

x, y = map(int, input().split())
wav = [[x, y]]
tmp = []
h, w = map(int, input().split())

arr = []
for i in range(h):
    arr.append(list(input()))

n = 0
arr[wav[0][0]][wav[0][1]] = n
st = [[-1, 0], [0, 1], [1, 0], [0, -1]]
while (len(wav)>0):
    n+=1
    for i in wav:
        for j in st:
            if (arr[i[0]+j[0]][i[1]+j[1]] == "E"):
                print("YES")
                exit()
            elif (arr[i[0]+j[0]][i[1]+j[1]] == " "):
                tmp.append([i[0]+j[0], i[1]+j[1]])
                arr[i[0]+j[0]][i[1]+j[1]] = n
    wav = []
    for i in tmp:
        wav.append(i)
    tmp = []
print("NO")
