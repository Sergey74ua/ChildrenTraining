# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file 'in.ui'
##
## Created by: Qt User Interface Compiler version 5.15.2
##
## WARNING! All changes made in this file will be lost when recompiling UI file!
################################################################################

from PySide2.QtCore import *
from PySide2.QtGui import *
from PySide2.QtWidgets import *


class Ui_Form(object):
    def setupUi(self, Form):
        if not Form.objectName():
            Form.setObjectName(u"Form")
        Form.resize(300, 200)
        icon = QIcon()
        icon.addFile(u"Python/ProjectPyCharm/images/icon.ico", QSize(), QIcon.Normal, QIcon.Off)
        Form.setWindowIcon(icon)
        self.pushButton = QPushButton(Form)
        self.pushButton.setObjectName(u"pushButton")
        self.pushButton.setGeometry(QRect(80, 60, 151, 71))
        font = QFont()
        font.setPointSize(32)
        self.pushButton.setFont(font)

        self.retranslateUi(Form)

        QMetaObject.connectSlotsByName(Form)
    # setupUi

    def retranslateUi(self, Form):
        Form.setWindowTitle(QCoreApplication.translate("Form", u"\u0422\u0435\u0441\u0442 \u0438\u043d\u0442\u0435\u0440\u0444\u0435\u0439\u0441\u0430", None))
        self.pushButton.setText(QCoreApplication.translate("Form", u"START", None))
    # retranslateUi