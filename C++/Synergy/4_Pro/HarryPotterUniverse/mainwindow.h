#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QDebug>
#include <QRadioButton>
#include <QPixMap>
#include <QGraphicsPixmapItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void readFile();
    void setNextQuestion();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();

private:
    Ui::MainWindow *ui;
    QStringList questions;
    QMap<int, int> answers;
    int count_question;
    int current_question = 1;
    int ball = 0;
    QList<QRadioButton*> radioButtons;
    QListIterator<QString> *questions_iter;
    QString wand, wood, core;
};
#endif // MAINWINDOW_H
