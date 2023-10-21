#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    radioButtons = {ui->radioButton, ui->radioButton_2, ui->radioButton_3, ui->radioButton_4};
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

//Чтение файла
void MainWindow::readFile()
{
    //Вопросы с файла
    QFile file(":/file/txt/test.txt");
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

    //Данные с файла
    QFile file1(":/file/txt/wand.txt");
    if (!file1.open(QIODevice::ReadOnly)) {
        qDebug("file don't open!");
        return;
    }
    data = file1.readAll();
    file1.close();
    wand = QString(data);

    QFile file2(":/file/txt/wood.txt");
    if (!file2.open(QIODevice::ReadOnly)) {
        qDebug("file don't open!");
        return;
    }
    data = file2.readAll();
    file2.close();
    wood = QString(data);

    QFile file3(":/file/txt/core.txt");
    if (!file3.open(QIODevice::ReadOnly)) {
        qDebug("file don't open!");
        return;
    }
    data = file3.readAll();
    file3.close();
    core = QString(data);
}

//Вопросы
void MainWindow::setNextQuestion(){
    if(!questions_iter->hasNext()){
        qDebug("Question not found");
        return;
    }
    ui->label_11->setText(questions_iter->next());

    for(auto rB : radioButtons){
        if(!questions_iter->hasNext()){
            rB->setText("(ответ отсутствует)");
        }
        rB->setText(questions_iter->next());
    }
}

//Волшебные палочки
void MainWindow::on_pushButton_clicked()
{
    ui->textBrowser->setText(wand);
}

//Рукоятки
void MainWindow::on_pushButton_2_clicked()
{
    ui->textBrowser->setText(wood);
}

//Сердцевина
void MainWindow::on_pushButton_3_clicked()
{
    ui->textBrowser->setText(core);
}

//Ответ
void MainWindow::on_pushButton_4_clicked()
{
    for (auto rb : radioButtons){
        rb->setStyleSheet("color: rgb(220, 20, 60)");
        rb->setEnabled(false);
    }
    QString str;
    if(radioButtons[answers[current_question]-1]->isChecked()) {
        ui->label_16->setStyleSheet("color: rgb(0, 128, 0)");
        str = "ВЕРНО!";
        ball++;
    }
    else {
        ui->label_16->setStyleSheet("color: rgb(220, 20, 60)");
        str = "НЕ ВЕРНО!";
    }

    radioButtons[answers[current_question]-1]->setStyleSheet("color: rgb(0, 128, 0)");
    ui->label_16->setText(str);
    ui->pushButton->setEnabled(false);
    ui->pushButton_2->setEnabled(true);
    ui->progressBar->setValue(current_question*10);
}

//Далее
void MainWindow::on_pushButton_5_clicked()
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
        ui->label_16->setStyleSheet("color: rgb(148, 0, 211)");
        str = QString("Ваша оценка: %1 из %2").arg(ball).arg(count_question);
    }
    else{
        setNextQuestion();
    }

    ui->label_16->setText(str);
}

//Завершить
void MainWindow::on_pushButton_6_clicked()
{
    QString str = "";
    ui->pushButton->setEnabled(false);
    ui->label_16->setStyleSheet("color: rgb(148, 0, 211)");
    str = QString("Ваша оценка: %1 из %2").arg(ball).arg(count_question);
    ui->label_16->setText(str);
}
