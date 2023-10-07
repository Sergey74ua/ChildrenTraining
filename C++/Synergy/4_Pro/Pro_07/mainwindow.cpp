#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString info = "Имя: " + ui->LineEdit->text();
    info += "\nРаса: " +  ui->comboBox->currentText();
    info += "\nКласс: " +  ui->comboBox_2->currentText();
    info += "\nВозраст: " +  ui->spinBox->text();
    info += "\nНавыки:";
    if (ui->checkBox->checkState())
        info += "\n\t- " +  ui->checkBox->text();
    if (ui->checkBox_3->checkState())
        info += "\n\t- " +  ui->checkBox_3->text();
    if (ui->checkBox_4->checkState())
        info += "\n\t- " +  ui->checkBox_4->text();
    if (ui->checkBox_2->checkState())
        info += "\n\t- " +  ui->checkBox_2->text();
    if (ui->checkBox_5->checkState())
        info += "\n\t- " +  ui->checkBox_5->text();
    QMessageBox::information(this, "Персонаж создан.", info);
}
