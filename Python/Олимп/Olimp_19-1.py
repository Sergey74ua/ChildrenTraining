N = int(input())
kratn = N % 4
  
if kratn == 2:
  print(N + 1)
elif kratn == 3:
  print(0)
elif kratn == 0:
  print(-N)
elif kratn == 1:
  print(1)
else:
  print(1)