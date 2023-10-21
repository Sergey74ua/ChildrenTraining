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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QFrame *line;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_7;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLabel *label_6;
    QFrame *line_8;
    QGroupBox *groupBox;
    QTextBrowser *textBrowser;
    QFrame *line_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_8;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_9;
    QLabel *label_13;
    QLabel *label_10;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_11;
    QLabel *label_12;
    QFrame *line_3;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_5;
    QRadioButton *radioButton;
    QFrame *line_6;
    QRadioButton *radioButton_3;
    QFrame *line_5;
    QVBoxLayout *verticalLayout_6;
    QRadioButton *radioButton_2;
    QFrame *line_7;
    QRadioButton *radioButton_4;
    QProgressBar *progressBar;
    QFrame *line_4;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_14;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_16;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QLabel *label_15;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1000, 635);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/file/img/g0.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setLayoutDirection(Qt::LeftToRight);
        centralwidget->setAutoFillBackground(false);
        centralwidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 245, 239);"));
        centralwidget->setInputMethodHints(Qt::ImhNone);
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(10, 0, 981, 631));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName("label");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(0, 150));
        label->setStyleSheet(QString::fromUtf8("image: url(:/file/img/m2.png);"));

        horizontalLayout->addWidget(label);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName("label_2");
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMinimumSize(QSize(0, 150));
        label_2->setStyleSheet(QString::fromUtf8("image: url(:/file/img/g1.png);"));

        horizontalLayout->addWidget(label_2);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName("label_3");
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMinimumSize(QSize(0, 150));
        label_3->setStyleSheet(QString::fromUtf8("image: url(:/file/img/m5.png);"));

        horizontalLayout->addWidget(label_3);


        verticalLayout->addLayout(horizontalLayout);

        line = new QFrame(verticalLayoutWidget);
        line->setObjectName("line");
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName("label_5");
        label_5->setStyleSheet(QString::fromUtf8("image: url(:/file/img/w2.png);"));

        horizontalLayout_3->addWidget(label_5);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName("label_7");
        QFont font;
        font.setFamilies({QString::fromUtf8("Bookman Old Style")});
        font.setPointSize(16);
        font.setBold(true);
        label_7->setFont(font);
        label_7->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_7);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName("pushButton");
        QFont font1;
        font1.setPointSize(12);
        pushButton->setFont(font1);

        verticalLayout_4->addWidget(pushButton);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setFont(font1);

        verticalLayout_4->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(verticalLayoutWidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setFont(font1);

        verticalLayout_4->addWidget(pushButton_3);


        horizontalLayout_3->addLayout(verticalLayout_4);

        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName("label_6");
        label_6->setStyleSheet(QString::fromUtf8("image: url(:/file/img/w1.png);"));

        horizontalLayout_3->addWidget(label_6);


        verticalLayout_2->addLayout(horizontalLayout_3);

        line_8 = new QFrame(verticalLayoutWidget);
        line_8->setObjectName("line_8");
        line_8->setTabletTracking(false);
        line_8->setAcceptDrops(false);
        line_8->setFrameShape(QFrame::HLine);
        line_8->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_8);

        groupBox = new QGroupBox(verticalLayoutWidget);
        groupBox->setObjectName("groupBox");
        textBrowser = new QTextBrowser(groupBox);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(0, 20, 481, 200));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Book Antiqua")});
        font2.setPointSize(10);
        font2.setItalic(true);
        textBrowser->setFont(font2);

        verticalLayout_2->addWidget(groupBox);


        horizontalLayout_2->addLayout(verticalLayout_2);

        line_2 = new QFrame(verticalLayoutWidget);
        line_2->setObjectName("line_2");
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_8 = new QLabel(verticalLayoutWidget);
        label_8->setObjectName("label_8");
        label_8->setStyleSheet(QString::fromUtf8("image: url(:/file/img/f2.png);"));

        horizontalLayout_4->addWidget(label_8);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        label_9 = new QLabel(verticalLayoutWidget);
        label_9->setObjectName("label_9");
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Bookman Old Style")});
        font3.setPointSize(20);
        font3.setBold(true);
        label_9->setFont(font3);
        label_9->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(label_9);

        label_13 = new QLabel(verticalLayoutWidget);
        label_13->setObjectName("label_13");
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Bookman Old Style")});
        font4.setPointSize(12);
        label_13->setFont(font4);
        label_13->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(label_13);


        horizontalLayout_4->addLayout(verticalLayout_7);

        label_10 = new QLabel(verticalLayoutWidget);
        label_10->setObjectName("label_10");
        label_10->setStyleSheet(QString::fromUtf8("image: url(:/file/img/f1.png);"));

        horizontalLayout_4->addWidget(label_10);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_11 = new QLabel(verticalLayoutWidget);
        label_11->setObjectName("label_11");
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy1);
        label_11->setMinimumSize(QSize(320, 0));
        label_11->setMaximumSize(QSize(320, 16777215));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Book Antiqua")});
        font5.setPointSize(12);
        font5.setBold(true);
        font5.setItalic(true);
        label_11->setFont(font5);
        label_11->setScaledContents(false);
        label_11->setAlignment(Qt::AlignCenter);
        label_11->setWordWrap(true);

        horizontalLayout_6->addWidget(label_11);

        label_12 = new QLabel(verticalLayoutWidget);
        label_12->setObjectName("label_12");
        sizePolicy1.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy1);
        label_12->setMinimumSize(QSize(150, 0));
        label_12->setStyleSheet(QString::fromUtf8("image: url(:/file/img/m4.png);"));

        horizontalLayout_6->addWidget(label_12);


        verticalLayout_3->addLayout(horizontalLayout_6);

        line_3 = new QFrame(verticalLayoutWidget);
        line_3->setObjectName("line_3");
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        radioButton = new QRadioButton(verticalLayoutWidget);
        radioButton->setObjectName("radioButton");
        sizePolicy1.setHeightForWidth(radioButton->sizePolicy().hasHeightForWidth());
        radioButton->setSizePolicy(sizePolicy1);
        radioButton->setMaximumSize(QSize(229, 16777215));
        QFont font6;
        font6.setPointSize(10);
        radioButton->setFont(font6);

        verticalLayout_5->addWidget(radioButton);

        line_6 = new QFrame(verticalLayoutWidget);
        line_6->setObjectName("line_6");
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line_6);

        radioButton_3 = new QRadioButton(verticalLayoutWidget);
        radioButton_3->setObjectName("radioButton_3");
        sizePolicy1.setHeightForWidth(radioButton_3->sizePolicy().hasHeightForWidth());
        radioButton_3->setSizePolicy(sizePolicy1);
        radioButton_3->setMaximumSize(QSize(229, 16777215));
        radioButton_3->setFont(font6);

        verticalLayout_5->addWidget(radioButton_3);


        horizontalLayout_5->addLayout(verticalLayout_5);

        line_5 = new QFrame(verticalLayoutWidget);
        line_5->setObjectName("line_5");
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);

        horizontalLayout_5->addWidget(line_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        radioButton_2 = new QRadioButton(verticalLayoutWidget);
        radioButton_2->setObjectName("radioButton_2");
        sizePolicy1.setHeightForWidth(radioButton_2->sizePolicy().hasHeightForWidth());
        radioButton_2->setSizePolicy(sizePolicy1);
        radioButton_2->setMaximumSize(QSize(229, 16777215));
        radioButton_2->setFont(font6);

        verticalLayout_6->addWidget(radioButton_2);

        line_7 = new QFrame(verticalLayoutWidget);
        line_7->setObjectName("line_7");
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);

        verticalLayout_6->addWidget(line_7);

        radioButton_4 = new QRadioButton(verticalLayoutWidget);
        radioButton_4->setObjectName("radioButton_4");
        sizePolicy1.setHeightForWidth(radioButton_4->sizePolicy().hasHeightForWidth());
        radioButton_4->setSizePolicy(sizePolicy1);
        radioButton_4->setMaximumSize(QSize(229, 16777215));
        radioButton_4->setFont(font6);

        verticalLayout_6->addWidget(radioButton_4);


        horizontalLayout_5->addLayout(verticalLayout_6);


        verticalLayout_3->addLayout(horizontalLayout_5);

        progressBar = new QProgressBar(verticalLayoutWidget);
        progressBar->setObjectName("progressBar");
        sizePolicy.setHeightForWidth(progressBar->sizePolicy().hasHeightForWidth());
        progressBar->setSizePolicy(sizePolicy);
        progressBar->setValue(0);

        verticalLayout_3->addWidget(progressBar);

        line_4 = new QFrame(verticalLayoutWidget);
        line_4->setObjectName("line_4");
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line_4);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label_14 = new QLabel(verticalLayoutWidget);
        label_14->setObjectName("label_14");
        label_14->setStyleSheet(QString::fromUtf8("image: url(:/file/img/m1.png);"));

        horizontalLayout_7->addWidget(label_14);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName("verticalLayout_8");
        label_16 = new QLabel(verticalLayoutWidget);
        label_16->setObjectName("label_16");
        QFont font7;
        font7.setPointSize(16);
        label_16->setFont(font7);
        label_16->setAlignment(Qt::AlignCenter);

        verticalLayout_8->addWidget(label_16);

        pushButton_4 = new QPushButton(verticalLayoutWidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setFont(font1);

        verticalLayout_8->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(verticalLayoutWidget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setFont(font1);

        verticalLayout_8->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(verticalLayoutWidget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setFont(font1);

        verticalLayout_8->addWidget(pushButton_6);


        horizontalLayout_7->addLayout(verticalLayout_8);

        label_15 = new QLabel(verticalLayoutWidget);
        label_15->setObjectName("label_15");
        label_15->setStyleSheet(QString::fromUtf8("image: url(:/file/img/m3.png);"));

        horizontalLayout_7->addWidget(label_15);


        verticalLayout_3->addLayout(horizontalLayout_7);


        horizontalLayout_2->addLayout(verticalLayout_3);


        verticalLayout->addLayout(horizontalLayout_2);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Harry Potter Universe", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
        label_5->setText(QString());
        label_7->setText(QCoreApplication::translate("MainWindow", "\320\255\320\275\321\206\320\270\320\272\320\273\320\276\320\277\320\265\320\264\320\270\321\217\n"
"\320\262\320\276\320\273\321\210\320\265\320\261\320\275\321\213\321\205\n"
"\320\277\320\260\320\273\320\276\321\207\320\265\320\272", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\320\237\320\260\320\273\320\276\321\207\320\272\320\260", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\320\240\321\203\320\272\320\276\321\217\321\202\320\272\320\260", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "\320\241\320\265\321\200\320\264\321\206\320\265\320\262\320\270\320\275\320\260", nullptr));
        label_6->setText(QString());
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\321\201\320\277\321\200\320\260\320\262\320\272\320\260", nullptr));
        label_8->setText(QString());
        label_9->setText(QCoreApplication::translate("MainWindow", "\320\222\321\201\320\265\320\273\320\265\320\275\320\275\320\260\321\217\n"
"\320\223\320\260\321\200\321\200\320\270 \320\237\320\276\321\202\321\202\320\265\321\200\320\260", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "\320\277\321\200\320\276\321\205\320\276\320\266\320\264\320\265\320\275\320\270\320\265 \321\202\320\265\321\201\321\202\320\260", nullptr));
        label_10->setText(QString());
        label_11->setText(QCoreApplication::translate("MainWindow", "\320\222\320\276\320\277\321\200\320\276\321\201", nullptr));
        label_12->setText(QString());
        radioButton->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\262\320\265\321\202 1", nullptr));
        radioButton_3->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\262\320\265\321\202 3", nullptr));
        radioButton_2->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\262\320\265\321\202 2", nullptr));
        radioButton_4->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\262\320\265\321\202 4", nullptr));
        label_14->setText(QString());
        label_16->setText(QCoreApplication::translate("MainWindow", "\321\200\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\262\320\265\321\202", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "\320\224\320\260\320\273\320\265\320\265", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\262\320\265\321\200\321\210\320\270\321\202\321\214 \321\202\320\265\321\201\321\202", nullptr));
        label_15->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
