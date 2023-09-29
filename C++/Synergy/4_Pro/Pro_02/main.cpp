/* sСоздай новый проект консольного приложения в Qt Creator. Подключи необходимые модули для работы с QString и QTextStream. В переменную типа QString сохрани своё имя.
 * С помощью метода append() добавь своё отчество/матчество, если оно есть (если нет - поставь восклицательный знак). С помощью метода prepend() добавь свою фамилию.
 * После каждого действия выводи результат на экран. А также выведи на экран размер получившейся строки и всю строку целиком заглавными буквами.
 * Критерии оценивания:
 * -	Использован объект класса QStringStream для вывода данных (1 балл)
 * -	Использованы методы append() и prepend() (1 балл)
 * -	Использованы методы size()/length()/count() и toUpper() (1 балл)
 * -	Содержимое первоначальной строки выводится на экран после каждого изменения (2 балла)
 * Итого: 5 баллов
*/

#include <QCoreApplication>
#include <QTextStream>
#include <QString>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTextStream in(stdin);
    QTextStream out(stdout);
    QString name, str;

    //Имя
    out << "Enter your name: ";
    out.flush();
    in >> name;
    out << "Your name: " << name << Qt::endl;

    //Отчество
    out << "Enter middle name: ";
    out.flush();
    in >> str;
    if (str.length() > 1) {
        name.append(" ");
        name.append(str);
    } else
        name.append("!");
    out << "Your name and patronymic: ";
    out << name << Qt::endl;

    //Фамилия
    out << "Enter your last name: ";
    out.flush();
    in >> str;
    name.prepend(" ");
    name.prepend(str);
    out << "Your last name, first name and patronymic: ";
    out << name << Qt::endl;

    //Размер
    out << "Line length: " << name.length() << " characters" << Qt::endl;

    //Заглавными
    out << "Capital letters: " << name.toUpper() << Qt::endl;

    return a.exec();
}
