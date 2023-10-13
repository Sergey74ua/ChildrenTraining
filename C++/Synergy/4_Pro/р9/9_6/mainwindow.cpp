#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Тест по вселенной Гарри Поттер");
    QPixmap* pixmap = new QPixmap(":/meme.png");;
    ui->label->setPixmap(pixmap->scaled(size(), Qt::KeepAspectRatio));
    // все кнопки удобно хранить в одном месте
    radioButtons = {ui->radioButton_1, ui->radioButton_2, ui->radioButton_3, ui->radioButton_4};
    // считываем файл нашей функцией
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
    // При такой реализации нужно чтобы был QLabel для текста вопроса
    if(!questions_iter->hasNext()){
        qDebug("Question not found");
        return;
    }
    // устанавливаем текст
    ui->label_question->setText(questions_iter->next());

    // для каждой из ЧЕТЫРЕХ! радио кнопок устанавливаем ответ (если будет меньше, то ошибка)
    for(auto rB : radioButtons){
        if(!questions_iter->hasNext()){
            qDebug("Need to add more answers to the file");
            return;
        }
        rB->setText(questions_iter->next());
    }

}

void MainWindow::readFile()
{
    QFile file(":/test1.txt"); //Открываем файл из ресурсов
    QByteArray data;           //Сюда запишем всё из файла
    if (!file.open(QIODevice::ReadOnly)) { //Если файл НЕ открыт
        qDebug("file don't open!");
        return; //Тест не будет прогружен
    }
    data = file.readAll(); //Считываем всё из файла
    file.close(); //файл больше не нужен

    questions = QString(data).split("\r\n"); //В список строк считываем всё с разделителем переноса строк
    QStringList str_answers = questions.front().split(" "); // ВАЖНО! Первая строка файла это ответы на вопросы через пробел
    int i=1; // счетчик вопросов
    count_question = str_answers.size(); // Количество вопросов в файле;
    for(auto elem : str_answers){ //создаем словарь "Вопрос - ответ"
        answers[i++]=elem.toInt();
    }
    questions.pop_front(); // Теперь первая строка файла нам не нужна
    questions_iter = new QListIterator<QString>(questions); //в будущем будем считывать строки итератором (так оптимальнее)
    //Уберите комментарий ниже если нужно вывести "Номер вопроса - Ответ" в консоли
    //qDebug()<<answers;

    setNextQuestion(); //Начинаем тест

}

/**
 * При нажатии на кнопку "Далее" переходим к следующему вопросу
 *
 * все radioButton становятся черного цвета и доступными для выбора
 * Делаем кнопку "Далее" недоступной
 * А кнопку "Выбрать" доступной
 * Если дошли до конца вопросов, то выводится Оценка
 * Иначе подгружаем следующий вопрос
 * Выводим либо пустой текст, либо текст с результатами на экран
 */

void MainWindow::on_button_next_clicked()
{
    QString str = "";
    current_question++;
    for (auto rb : radioButtons){
        rb->setStyleSheet("color: rgb(64, 65, 66)");
        rb->setEnabled(true);
    }
    ui->button_choice->setEnabled(true);
    ui->button_next->setEnabled(false);
    if(current_question>count_question)
    {
        ui->button_choice->setEnabled(false);
        ui->label_answer->setStyleSheet("color: rgb(148, 0, 211)");
        str = QString("Ваша оценка: %1 из %2").arg(ball).arg(count_question);
    }
    else{
        setNextQuestion();
    }

    ui->label_answer->setText(str);
}


/**
 * При нажатии на кнопку "выбрать" все radioButton становятся красными, кроме правильного ответа
 * Все radioButton становятся недоступными
 *
 * Если пользователь выбрал правильный ответ, то к переменной ball добавляем один
 * Выводим на экран строку "Это правильный ответ" или "Это неправивильный ответ"
 *
 * Делаем кнопку "Выбрать" недоступной
 * А кнопку "Далее" доступной
 */
void MainWindow::on_button_choice_clicked()
{
    for (auto rb : radioButtons){
        rb->setStyleSheet("color: rgb(220, 20, 60)");
        rb->setEnabled(false);
    }
    QString str;
    if(radioButtons[answers[current_question]-1]->isChecked()) {
        ui->label_answer->setStyleSheet("color: rgb(0, 128, 0)");
        str = "Это правильный ответ!";
        ball++;
    }
    else {
        ui->label_answer->setStyleSheet("color: rgb(220, 20, 60)");
        str = "Это неправильный ответ!";
    }

    radioButtons[answers[current_question]-1]->setStyleSheet("color: rgb(0, 128, 0)");
    ui->label_answer->setText(str);
    ui->button_choice->setEnabled(false);
    ui->button_next->setEnabled(true);
}
