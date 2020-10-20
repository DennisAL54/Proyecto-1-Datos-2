/********************************************************************************
** Form generated from reading UI file 'reproductor.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPRODUCTOR_H
#define UI_REPRODUCTOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Reproductor
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Reproductor)
    {
        if (Reproductor->objectName().isEmpty())
            Reproductor->setObjectName(QString::fromUtf8("Reproductor"));
        Reproductor->resize(800, 600);
        centralwidget = new QWidget(Reproductor);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Reproductor->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Reproductor);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        Reproductor->setMenuBar(menubar);
        statusbar = new QStatusBar(Reproductor);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Reproductor->setStatusBar(statusbar);

        retranslateUi(Reproductor);

        QMetaObject::connectSlotsByName(Reproductor);
    } // setupUi

    void retranslateUi(QMainWindow *Reproductor)
    {
        Reproductor->setWindowTitle(QCoreApplication::translate("Reproductor", "Reproductor", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Reproductor: public Ui_Reproductor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPRODUCTOR_H
