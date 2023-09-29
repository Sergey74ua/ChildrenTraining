/* 1. Создать “Приложение QT Widgets” и разместить в нём с помощью встроенного графического редактора: Push Button, Label, Check Box, Text Edit.
 * Сделать скриншоты запуска приложения и файла .ui
 * 2. Удалить все виджеты на окне в графическом редакторе и разместить те же виджеты с помощью кода в функции main().
 * В качестве ответа на это домашнее задание прикрепите документ .doc со скриншотами запуска приложения, содержимого файла .ui и файла main.cpp
*/

#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QCheckBox>
#include <QTextEdit>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QPushButton *btn = new QPushButton("Press", &w);
    btn->setGeometry(10, 10, 100, 40);

    QLabel *lab = new QLabel("label", &w);
    lab->setGeometry(10, 80, 100, 40);

    QCheckBox *box = new QCheckBox("Check box", &w);
    box->setGeometry(10, 150, 100, 40);

    QTextEdit *edt = new QTextEdit("Text edit", &w);
    edt->setGeometry(130, 10, 150, 200);

    w.show();
    return a.exec();
}
