Z = input()
W = input()
X = 0
for i in 'abcdefghijklmnopqrstuvwxyz':
  if i in W and i in Z:
    X += 1
print(X)