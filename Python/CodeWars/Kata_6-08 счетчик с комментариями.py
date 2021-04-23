def likes(names):
    if len(names) == 0:
        return 'no one likes this'
    if len(names) == 1:
        return names[0] + ' likes this'
    if len(names) == 2:
        return names[0] + ' and ' + names[1] + ' like this'
    if len(names) == 3:
        return names[0] + ', ' + names[1] + ' and ' + names[2] + ' like this'
    if len(names) > 3:
        return names[0] + ', ' + names[1] + ' and ' + str(len(names)-2) + ' others like this'

# тест для локального запуска
test = ['Alex', 'Jacob', 'Mark', 'Max']
print(test, "- требуемый объем")
print(find_nb(test), "- число кубов для достижения объема")
input()

# likes([]) - 'no one likes this'
# likes(['Peter']) - 'Peter likes this'
# likes(['Jacob', 'Alex']) - 'Jacob and Alex like this'
# likes(['Max', 'John', 'Mark']) - 'Max, John and Mark like this'
# likes(['Alex', 'Jacob', 'Mark', 'Max']) - 'Alex, Jacob and 2 others like this'

# более короткий вариант
#def likes(names):
#    n = len(names)
#    return {
#        0: 'no one likes this',
#        1: '{} likes this', 
#        2: '{} and {} like this', 
#        3: '{}, {} and {} like this', 
#        4: '{}, {} and {others} others like this'
#    }[min(4, n)].format(*names[:3], others=n-2)