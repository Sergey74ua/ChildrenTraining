X1, Y1, R, X2, Y2 = map(int, input())
catetX = X1 - X2
catetY = Y1 - Y2
if Math.Sqrt(catetX * catetX + catetY * catetY) <= R:
    print(1)
else:
    print(0)


#Верно!