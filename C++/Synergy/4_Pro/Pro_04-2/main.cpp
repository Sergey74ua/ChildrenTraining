/* Создайте программу с помощью контейнер QMap, указывающую, сколько людей стоит в очереди на кассе.
 * Изначально в очереди стояло 5 человек, выведите в консоль это значение. Спустя некоторое время открыли
 * вторую кассу, и 2 человека ушли в другую очередь. Выведите в консоль новое число людей в очереди в первой кассе.
 */

#include <QCoreApplication>
#include <QString>
#include <QMap>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //Словарь с первой очередью
    QMap<QString, int> map {{"Queue 1", 5}};

    qDebug() << "Queues and quantity:";
    foreach (auto &key, map.keys())
        qDebug() << key << ":" << map.value(key) << "people";

    //Добавляем вторую очередь
    map.insert("Queue 2", 0);

    //Чать одной очереди переходит в другую
    int n = 2;
    map["Queue 1"] -= n;
    map["Queue 2"] += n;

    qDebug() << "\nQueues and quantity:";
    foreach (auto &key, map.keys())
        qDebug() << key << ":" << map.value(key) << "people";

    return a.exec();
}
