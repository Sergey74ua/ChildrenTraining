 /* 2. Разработайте программу для управления заказами в ресторане. Используйте QQueue для хранения заказов, которые ожидают готовности.
  * Каждый заказ может быть представлен строкой с названиями заказанных блюд и напитков. Реализуйте операции добавления нового заказа в конец
  * очереди, обработки заказа (удаление из начала очереди) и просмотра текущего списка ожидающих заказов.
  */

#include <QCoreApplication>
#include <QString>
#include <QQueue>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTextStream out(stdout);
    QTextStream in(stdin);
    QQueue<QString> queue;
    QString order;
    int menu = 0, n = 1;

    while(menu != 3) {
        system("cls");

        //Просмотр заказов
        out << " -= Restaurant ordering order =-" << Qt::endl;
        if (queue.size() > 0)
            for (int i=0; i < queue.size(); ++i)
                out << i+n << ". " << queue[i] << Qt::endl;
        else
            out << "Waiting for orders." << Qt::endl;

        //Меню операций
        out << "\nOperations:  add 1 | ready 2 | output 3" << Qt::endl;
        if (menu == 0) {
            out << "Operation selection: ";
            out.flush();
            in >> menu;
        //Добавить заказ
        } else if (menu == 1) {
            out << "Add a new order: ";
            out.flush();
            in >> order;
            queue.enqueue(order);
            menu = 0;
        //Удалить заказ
        } else if (menu == 2) {
            out << "Order is ready: ";
            out.flush();
            if (!queue.isEmpty()) {
                qDebug() << queue.dequeue();
                n++;
            }
            menu = 0;
        //Выход
        } else if (menu == 3)
            break;
        else
            menu = 0;
    }

    return a.exec();
}
