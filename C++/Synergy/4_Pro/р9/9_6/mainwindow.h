#pragma once
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
    void on_button_next_clicked();
    void on_button_choice_clicked();

private:
    Ui::MainWindow *ui;
    QStringList questions; // здесь храним все строки (вопросы и ответы на них)
    QMap<int, int> answers; // словарь где пара ключ-значение: номер вопроса - правильный ответ
    int count_question; // сколько всего вопросов
    int current_question = 1; //текущий вопрос
    int ball = 0; // сколько правильных ответов
    QList<QRadioButton*> radioButtons; // более быстрый способ доступа ко всем кнопкам ответов
    QListIterator<QString> *questions_iter;
};
