#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    radioButtons = {ui->radioButton_4, ui->radioButton_3, ui->radioButton, ui->radioButton_2};
    readFile();
}

MainWindow::~MainWindow()
{
    delete ui;

    delete questions_iter;
    for (auto rB : radioButtons){
        delete rB;
    }
}

void MainWindow::setNextQuestion(){
    if(!questions_iter->hasNext()){
        qDebug("Question not found");
        return;
    }
    ui->label->setText(questions_iter->next());

    for(auto rB : radioButtons){
        if(!questions_iter->hasNext()){
            rB->setText("(ответ отсутствует)");
        }
        rB->setText(questions_iter->next());
    }
}

void MainWindow::readFile()
{
    QFile file(":/txt/test1.txt");
    QByteArray data;
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug("file don't open!");
        return;
    }
    data = file.readAll();
    file.close();

    questions = QString(data).split("\r\n");
    QStringList str_answers = questions.front().split(" ");
    int i = 1;
    count_question = str_answers.size();
    for(auto elem : str_answers){
        answers[i++]=elem.toInt();
    }
    questions.pop_front();
    questions_iter = new QListIterator<QString>(questions);

    setNextQuestion();
}

void MainWindow::on_pushButton_2_clicked()
{
    QString str = "";
    current_question++;
    for (auto rb : radioButtons){
        rb->setStyleSheet("color: rgb(64, 65, 66)");
        rb->setEnabled(true);
        rb->setChecked(false);
    }
    ui->pushButton->setEnabled(true);
    ui->pushButton_2->setEnabled(false);
    if(current_question>count_question)
    {
        ui->pushButton->setEnabled(false);
        ui->label_7->setStyleSheet("color: rgb(148, 0, 211)");
        str = QString("Ваша оценка: %1 из %2").arg(ball).arg(count_question);
    }
    else{
        setNextQuestion();
    }

    ui->label_7->setText(str);
}

void MainWindow::on_pushButton_clicked()
{
    for (auto rb : radioButtons){
        rb->setStyleSheet("color: rgb(220, 20, 60)");
        rb->setEnabled(false);
    }
    QString str;
    if(radioButtons[answers[current_question]-1]->isChecked()) {
        ui->label_7->setStyleSheet("color: rgb(0, 128, 0)");
        str = "ВЕРНО!";
        ball++;
    }
    else {
        ui->label_7->setStyleSheet("color: rgb(220, 20, 60)");
        str = "НЕ ВЕРНО!";
    }

    radioButtons[answers[current_question]-1]->setStyleSheet("color: rgb(0, 128, 0)");
    ui->label_7->setText(str);
    ui->pushButton->setEnabled(false);
    ui->pushButton_2->setEnabled(true);
}
