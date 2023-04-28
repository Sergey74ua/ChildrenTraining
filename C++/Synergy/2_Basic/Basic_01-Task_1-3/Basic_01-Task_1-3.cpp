//1. Реализовать класс «Студент», придумать для него 3 подходящих поля и 3 подходящих метода (конструкторы, деструкторы, сеттеры
//и геттеры не в счёт). Защитить хотя бы одно поле модификатором доступа private, реализовать для него сеттер и геттер.

#include <iostream>
using namespace std;


class Student
{
    friend class Teacher;

    //Открытые поля, имя и возраст
public:
    string name;
    int age;

    Student(string name_ = "unknown", int age_ = 0) {
        name = name_;
        age = age_;
        course = 0;
    }

    //Геттер и сеттер для поля курса
    void set_course(int course_) {
        if (course_ > 0 && course_ <= 5)
            course = course_;
        else
            cout << "Incorrect course" << endl;
    }
    int get_course() {
        return course;
    }

    //Закрытое поле - курс
private:
    int course;


public:
    //1 метод класса - вывод данных
    void info()
    {
        cout << "Student name: " << name << endl;
        cout << "Student age: " << age << endl;
        cout << "Course of Study: " << get_course() << endl << endl;
    }

    //2 метод класса - коррекция имени
    void fix_name()
    {
        for (int i = 0; i < name.size(); i++)
            if (i == 0 || name[i - 1] == ' ')
                name[i] = toupper(name[i]);
            else
                name[i] = tolower(name[i]);
    }

    //3 метод класса - попытка коррекции возраста
    void fix_age()
    {
        if (age < 0)
            age = -age;
    }

    //3. Добавить в класс «Студент» статическую переменную и статический метод, который с ней взаимодействует.

    static int next_courses_counter;

    static void add_next_course()
    {
        next_courses_counter++;
    }

};


//2. Добавить класс «Учитель», дружественный классу «Студент», написать метод, взаимодействующий с одним из приватных полей класса «Студент».

class Teacher
{
public:
    void next_course(Student &student)
    {
        if (student.course < 5)
            student.course++;
        else
            cout << "maximum heading reached" << endl;
    };
};

int Student::next_courses_counter = 9;

int main()
{
    Student ivan = Student("iVaN vaSILevich peTROv", -18);
    ivan.set_course(2);

    cout << ivan.name << endl << ivan.age << endl << endl;
    ivan.fix_name();
    ivan.fix_age();
    ivan.info();

    Teacher docent = Teacher();
    docent.next_course(ivan);
    cout << "Next course from teacher: " << ivan.get_course() << endl << endl;

    cout << "Static courses counter: " << Student::next_courses_counter << endl;
    Student::add_next_course();
    cout << "Static courses counter: " << Student::next_courses_counter << endl;

    return 0;
}