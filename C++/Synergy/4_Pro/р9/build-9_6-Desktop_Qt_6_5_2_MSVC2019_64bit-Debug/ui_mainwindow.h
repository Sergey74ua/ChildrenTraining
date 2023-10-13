/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QVBoxLayout *verticalLayout;
    QLabel *label_question;
    QRadioButton *radioButton_1;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QPushButton *button_choice;
    QLabel *label_answer;
    QPushButton *button_next;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(761, 485);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setEnabled(true);
        centralwidget->setAutoFillBackground(false);
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label = new QLabel(centralwidget);
        label->setObjectName("label");

        horizontalLayout_2->addWidget(label);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        label_question = new QLabel(centralwidget);
        label_question->setObjectName("label_question");
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_question->sizePolicy().hasHeightForWidth());
        label_question->setSizePolicy(sizePolicy);
        label_question->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setFamilies({QString::fromUtf8("Verdana")});
        font.setPointSize(14);
        label_question->setFont(font);
        label_question->setScaledContents(false);
        label_question->setWordWrap(true);

        verticalLayout->addWidget(label_question);

        radioButton_1 = new QRadioButton(centralwidget);
        radioButton_1->setObjectName("radioButton_1");
        sizePolicy.setHeightForWidth(radioButton_1->sizePolicy().hasHeightForWidth());
        radioButton_1->setSizePolicy(sizePolicy);
        radioButton_1->setMinimumSize(QSize(0, 0));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Verdana")});
        font1.setPointSize(11);
        radioButton_1->setFont(font1);

        verticalLayout->addWidget(radioButton_1);

        radioButton_2 = new QRadioButton(centralwidget);
        radioButton_2->setObjectName("radioButton_2");
        sizePolicy.setHeightForWidth(radioButton_2->sizePolicy().hasHeightForWidth());
        radioButton_2->setSizePolicy(sizePolicy);
        radioButton_2->setMinimumSize(QSize(0, 0));
        radioButton_2->setFont(font1);

        verticalLayout->addWidget(radioButton_2);

        radioButton_3 = new QRadioButton(centralwidget);
        radioButton_3->setObjectName("radioButton_3");
        sizePolicy.setHeightForWidth(radioButton_3->sizePolicy().hasHeightForWidth());
        radioButton_3->setSizePolicy(sizePolicy);
        radioButton_3->setMinimumSize(QSize(0, 0));
        radioButton_3->setFont(font1);

        verticalLayout->addWidget(radioButton_3);

        radioButton_4 = new QRadioButton(centralwidget);
        radioButton_4->setObjectName("radioButton_4");
        sizePolicy.setHeightForWidth(radioButton_4->sizePolicy().hasHeightForWidth());
        radioButton_4->setSizePolicy(sizePolicy);
        radioButton_4->setMinimumSize(QSize(0, 0));
        radioButton_4->setFont(font1);

        verticalLayout->addWidget(radioButton_4);

        button_choice = new QPushButton(centralwidget);
        button_choice->setObjectName("button_choice");
        sizePolicy.setHeightForWidth(button_choice->sizePolicy().hasHeightForWidth());
        button_choice->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Verdana")});
        font2.setPointSize(12);
        button_choice->setFont(font2);

        verticalLayout->addWidget(button_choice);

        label_answer = new QLabel(centralwidget);
        label_answer->setObjectName("label_answer");
        label_answer->setFont(font2);
        label_answer->setLayoutDirection(Qt::LeftToRight);
        label_answer->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_answer);

        button_next = new QPushButton(centralwidget);
        button_next->setObjectName("button_next");
        button_next->setEnabled(false);

        verticalLayout->addWidget(button_next);

        verticalLayout->setStretch(0, 2);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 1);
        verticalLayout->setStretch(3, 1);
        verticalLayout->setStretch(4, 1);

        horizontalLayout_2->addLayout(verticalLayout);

        horizontalLayout_2->setStretch(1, 3);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\232\320\260\321\200\321\202\320\270\320\275\320\276\321\207\320\272\320\260", nullptr));
        label_question->setText(QCoreApplication::translate("MainWindow", "\320\222\320\276\320\277\321\200\320\276\321\201", nullptr));
        radioButton_1->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\262\320\265\321\202", nullptr));
        radioButton_2->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\262\320\265\321\202", nullptr));
        radioButton_3->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\262\320\265\321\202", nullptr));
        radioButton_4->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\262\320\265\321\202", nullptr));
        button_choice->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214", nullptr));
        label_answer->setText(QString());
        button_next->setText(QCoreApplication::translate("MainWindow", "\320\224\320\260\320\273\320\265\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
