#Сортировка пузырьком случайного списка

import os
import time
from random import randint

os.system('title Сортировка пузырьком')
os.system("mode con cols=100 lines=10")
os.system('color 0a')

start_list = [randint(0, 1000) for i in range(20)]
sort_list = list(start_list)

for i in range(len(sort_list)):
	for j in range(i+1, len(sort_list)):
		if sort_list[j] < sort_list[i]:
			sort_list[j], sort_list[i] = sort_list[i], sort_list[j]
			os.system('cls||clear')
			print(start_list)
			print("")
			print(sort_list)
			print("")
			time.sleep(0.2)

print("Список отсортирован")
input()