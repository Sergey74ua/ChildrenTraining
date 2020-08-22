def cakes(recipe, available):
    count = 999999
    for key, value in recipe.items():
        if key in available:
            temp = available[key] // value
        else:
            return 0
        if temp < count:
            count = temp
    return count

# тест для локального запуска
recipe = {"flour": 500, "sugar": 200, "eggs": 1}
available = {"flour": 1200, "sugar": 1200, "eggs": 5, "milk": 200}
print(recipe, "- рецепт")
print(available, "-  запасы")
print(cakes(recipe, available), "- максимальное число изделий")
input()

# более корректный вариант
# def cakes(recipe, available):
#     list = []
#     for ingredient in recipe:
#         if ingredient in available:
#             list.append(available[ingredient]/recipe[ingredient])
#         else:
#             return 0
#     return min(list)

# более короткий вариант
# def cakes(recipe, available):
#     return min(available.get(k, 0)/recipe[k] for k in recipe)
