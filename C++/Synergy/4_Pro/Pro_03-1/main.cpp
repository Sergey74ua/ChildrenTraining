/* 1. Создайте программу, которая будет моделировать список задач на день. Начните с пустого списка задач (QVector, QString).
 * Пользователь может добавлять задачи в список, удалять задачи по индексу и просматривать список задач. Реализуйте меню для этих операций.
 */

#include <QCoreApplication>
#include <QString>
#include <QVector>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTextStream out(stdout);
    QTextStream in(stdin);
    QVector<QString> list;
    QString task;
    int n, menu = 0;

    while(menu != 4) {
        system("cls");

        //Просмотр задач
        out << " -= Daily task list =-" << Qt::endl;
        if (list.size() > 0)
            for (int i=0; i < list.size(); ++i)
                out << i+1 << ". " << list[i] << Qt::endl;
        else
            out << "The list is empty." << Qt::endl;

        //Меню операций
        out << "\nMenu:  add 1 | delete 2 | clear 3 | output 4" << Qt::endl;
        if (menu == 0) {
            out << "Select menu item: ";
            out.flush();
            in >> menu;
        //Добавить задачу
        } else if (menu == 1) {
            out << "Add a new task: ";
            out.flush();
            in >> task;
            list.append(task);
            menu = 0;
        //Удалить задачу
        } else if (menu == 2) {
            out << "Delete a task by item: ";
            out.flush();
            in >> n;
            if (n >= 0 && n <= list.size())
                list.remove(n-1);
            menu = 0;
        //Очистить список
        } else if (menu == 3) {
            list.clear();
            menu = 0;
        //Выход
        } else if (menu == 4)
            break;
        else
            menu = 0;
    }

    return a.exec();
}
