/********************************************************************************
** Form generated from reading UI file 'SevenWonderUI.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEVENWONDERUI_H
#define UI_SEVENWONDERUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SevenWonderUI
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SevenWonderUI)
    {
        if (SevenWonderUI->objectName().isEmpty())
            SevenWonderUI->setObjectName("SevenWonderUI");
        SevenWonderUI->resize(800, 600);
        centralwidget = new QWidget(SevenWonderUI);
        centralwidget->setObjectName("centralwidget");
        SevenWonderUI->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SevenWonderUI);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 20));
        SevenWonderUI->setMenuBar(menubar);
        statusbar = new QStatusBar(SevenWonderUI);
        statusbar->setObjectName("statusbar");
        SevenWonderUI->setStatusBar(statusbar);

        retranslateUi(SevenWonderUI);

        QMetaObject::connectSlotsByName(SevenWonderUI);
    } // setupUi

    void retranslateUi(QMainWindow *SevenWonderUI)
    {
        SevenWonderUI->setWindowTitle(QCoreApplication::translate("SevenWonderUI", "SevenWonderUI", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SevenWonderUI: public Ui_SevenWonderUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEVENWONDERUI_H
