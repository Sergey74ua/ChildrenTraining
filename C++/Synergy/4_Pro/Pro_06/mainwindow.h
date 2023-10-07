#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QPushButton *myButton;
    QLabel *myLabel;

    int n=0;
    QString list[4] = {"Единорог", "Лев", "Жираф", "Крот" };

    QString text() {
        n = (n+1)%4;
        return list[n];
    };
};
#endif // MAINWINDOW_H
