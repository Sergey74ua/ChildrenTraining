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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *Label;
    QLineEdit *LineEdit;
    QLabel *Label_2;
    QLabel *Label_3;
    QLabel *Label_4;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QSpinBox *spinBox;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox_3;
    QPushButton *pushButton;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox_2;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QCheckBox *checkBox;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_5;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(360, 480);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(10, 0, 341, 161));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(verticalLayoutWidget);
        groupBox->setObjectName("groupBox");
        formLayoutWidget = new QWidget(groupBox);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(0, 20, 339, 141));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setFormAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        formLayout->setContentsMargins(4, 4, 4, 4);
        Label = new QLabel(formLayoutWidget);
        Label->setObjectName("Label");

        formLayout->setWidget(0, QFormLayout::LabelRole, Label);

        LineEdit = new QLineEdit(formLayoutWidget);
        LineEdit->setObjectName("LineEdit");

        formLayout->setWidget(0, QFormLayout::FieldRole, LineEdit);

        Label_2 = new QLabel(formLayoutWidget);
        Label_2->setObjectName("Label_2");

        formLayout->setWidget(1, QFormLayout::LabelRole, Label_2);

        Label_3 = new QLabel(formLayoutWidget);
        Label_3->setObjectName("Label_3");

        formLayout->setWidget(2, QFormLayout::LabelRole, Label_3);

        Label_4 = new QLabel(formLayoutWidget);
        Label_4->setObjectName("Label_4");

        formLayout->setWidget(3, QFormLayout::LabelRole, Label_4);

        comboBox = new QComboBox(formLayoutWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");

        formLayout->setWidget(1, QFormLayout::FieldRole, comboBox);

        comboBox_2 = new QComboBox(formLayoutWidget);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName("comboBox_2");

        formLayout->setWidget(2, QFormLayout::FieldRole, comboBox_2);

        spinBox = new QSpinBox(formLayoutWidget);
        spinBox->setObjectName("spinBox");
        spinBox->setMaximum(9999);

        formLayout->setWidget(3, QFormLayout::FieldRole, spinBox);


        verticalLayout->addWidget(groupBox);

        verticalLayoutWidget_4 = new QWidget(centralwidget);
        verticalLayoutWidget_4->setObjectName("verticalLayoutWidget_4");
        verticalLayoutWidget_4->setGeometry(QRect(10, 370, 341, 61));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        groupBox_3 = new QGroupBox(verticalLayoutWidget_4);
        groupBox_3->setObjectName("groupBox_3");
        pushButton = new QPushButton(groupBox_3);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(80, 23, 181, 28));
        pushButton->setLayoutDirection(Qt::LeftToRight);

        verticalLayout_4->addWidget(groupBox_3);

        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(10, 170, 341, 191));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        groupBox_2 = new QGroupBox(horizontalLayoutWidget);
        groupBox_2->setObjectName("groupBox_2");
        verticalLayoutWidget_3 = new QWidget(groupBox_2);
        verticalLayoutWidget_3->setObjectName("verticalLayoutWidget_3");
        verticalLayoutWidget_3->setGeometry(QRect(0, 20, 171, 171));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(4, 4, 4, 4);
        checkBox = new QCheckBox(verticalLayoutWidget_3);
        checkBox->setObjectName("checkBox");
        QSizePolicy sizePolicy1(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(checkBox->sizePolicy().hasHeightForWidth());
        checkBox->setSizePolicy(sizePolicy1);

        verticalLayout_3->addWidget(checkBox);

        checkBox_3 = new QCheckBox(verticalLayoutWidget_3);
        checkBox_3->setObjectName("checkBox_3");

        verticalLayout_3->addWidget(checkBox_3);

        checkBox_4 = new QCheckBox(verticalLayoutWidget_3);
        checkBox_4->setObjectName("checkBox_4");

        verticalLayout_3->addWidget(checkBox_4);

        checkBox_2 = new QCheckBox(verticalLayoutWidget_3);
        checkBox_2->setObjectName("checkBox_2");

        verticalLayout_3->addWidget(checkBox_2);

        checkBox_5 = new QCheckBox(verticalLayoutWidget_3);
        checkBox_5->setObjectName("checkBox_5");

        verticalLayout_3->addWidget(checkBox_5);


        horizontalLayout->addWidget(groupBox_2);

        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8(""));
        label->setTextFormat(Qt::AutoText);
        label->setPixmap(QPixmap(QString::fromUtf8("kitty.png")));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 360, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\320\275\320\270\320\265 \320\277\320\265\321\200\321\201\320\276\320\275\320\260\320\266\320\260", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\320\236\320\261\321\211\320\270\320\265", nullptr));
        Label->setText(QCoreApplication::translate("MainWindow", "\320\230\320\274\321\217", nullptr));
        LineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\262\320\262\320\265\320\264\320\270\321\202\320\265 \320\270\320\274\321\217", nullptr));
        Label_2->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\321\201\321\201\320\260", nullptr));
        Label_3->setText(QCoreApplication::translate("MainWindow", "\320\232\320\273\320\260\321\201\321\201", nullptr));
        Label_4->setText(QCoreApplication::translate("MainWindow", "\320\222\320\276\320\267\321\200\320\260\321\201\321\202", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "\320\247\320\265\320\273\320\276\320\262\320\265\320\272", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "\320\255\320\273\321\214\321\204", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "\320\236\321\200\320\272", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "\320\223\320\275\320\276\320\274", nullptr));

        comboBox_2->setItemText(0, QCoreApplication::translate("MainWindow", "\320\222\320\276\320\270\320\275", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("MainWindow", "\320\234\320\260\320\263", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("MainWindow", "\320\233\321\203\321\207\320\275\320\270\320\272", nullptr));
        comboBox_2->setItemText(3, QCoreApplication::translate("MainWindow", "\320\233\320\265\320\272\320\260\321\200\321\214", nullptr));

        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\277\320\265\321\200\321\201\320\276\320\275\320\260\320\266\320\260", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\262\321\213\320\272\320\270", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "\320\241\320\270\320\273\320\260 \320\260\321\202\320\260\320\272\320\270", nullptr));
        checkBox_3->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\321\211\320\270\321\202\320\260 \320\261\321\200\320\276\320\275\320\270", nullptr));
        checkBox_4->setText(QCoreApplication::translate("MainWindow", "\320\241\320\272\320\276\321\200\320\276\321\201\321\202\321\214", nullptr));
        checkBox_2->setText(QCoreApplication::translate("MainWindow", "\320\234\320\265\321\202\320\272\320\276\321\201\321\202\321\214", nullptr));
        checkBox_5->setText(QCoreApplication::translate("MainWindow", "\320\227\320\264\320\276\321\200\320\276\320\262\321\214\320\265", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
