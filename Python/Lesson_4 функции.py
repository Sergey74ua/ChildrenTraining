# Урок № 4 по Python

# основная функция для запуска других функций (перенести в конце урока)
def main():
    HW()
    HW_name("Максим")
    HW_name("Никита")
    HW_name("Матвей")

    HW_name_plus("Пользователь")
    HW_name_plus()

    Name_Age("Сергей", 46)
    Name_Age(39, "Ира")
    Name_Age(age = 39, name = "Ира")

    Summ(1, 2, 3, 4, 5)

    x = Summ_return(1, 2, 3, 4, 5, 6)
    print("Возвращаемая сумма:", x)
    print("Возвращаемая сумма:", Summ_return(1, 2, 3, 4, 5, 6, 7))
    
    Name, Age = Return_params()
    print(Name, Age)
    print(Return_params())

# функция
def HW():
    print("Hello world!")
    print("")

# функция с параметром
def HW_name(x):
    print("Hello +", x)
    print("")

# функция с параметром по умолчанию
def HW_name_plus(x = "____________"):
    print("Hello +=", x)
    print("")

# функция с именованными параметрами
def Name_Age(name, age):
    print("Имя:", name, "; Возраст:", age)
    print("")

# функция с множеством параметров
def Summ(*params):
    S = 0
    for i in params:
        S += i
    print("Сумма:", S)
    print("")

# функция с возвращением результата
def Summ_return(*params):
    S = 0
    for i in params:
        S += i
    return S

# функция с возвращением нескольких результатов
def Return_params():
    name = "Баррак Обама"
    age = 60
    return name, age

# global x - добавить пример функции с глобальной переменной

main()

input()