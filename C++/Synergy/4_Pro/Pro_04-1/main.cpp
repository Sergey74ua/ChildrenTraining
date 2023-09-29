/* 1. С помощью контейнера QSet создайте перечень месяцев года. Посчитайте и выведите сколько месяцев вы внесли,
 * а затем выведите названия месяцев, указав, к какому сезону они относятся.
 */

#include <QCoreApplication>
#include <QString>
#include <QSet>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTextStream out(stdout);
    QString season;

    //Перечень месяцев
    QSet<QString> set = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    //Количество месяцев
    out << "Number of months: " << set.size() << Qt::endl;

    //Названия месяцев
    for(const QString &month : set) {
        if (month == "January" || month == "February" || month == "December")
            season = "winter";
        else if (month == "March" || month == "April" || month == "May")
            season = "spring";
        else if (month == "June" || month == "July" || month == "August")
            season = "summer";
        else if (month == "September" || month == "October" || month == "November")
            season = "autumn";
        else
            season = "not a season";
        out << month << " - " << season << Qt::endl;
    }

    return a.exec();
}
