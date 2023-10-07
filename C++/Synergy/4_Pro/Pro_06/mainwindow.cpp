#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    myButton = new QPushButton("Дальше", this);
    myButton -> setGeometry(150, 100, 100, 30);

    myLabel = new QLabel(list[n], this);
    myLabel -> setGeometry(150, 150, 100, 30);

    connect(myButton, &QPushButton::clicked, this, [=]() {
        myLabel -> setText(text());
    });
}

MainWindow::~MainWindow()
{
    delete ui;
    delete myButton;
    delete myLabel;
}
