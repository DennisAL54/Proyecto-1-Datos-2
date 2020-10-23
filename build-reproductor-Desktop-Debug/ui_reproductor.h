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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Reproductor
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton;
    QListWidget *listWidget;
    QSlider *progess;
    QLabel *label_2;
    QPushButton *pushButton_2;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QProgressBar *progressBar;
    QCheckBox *checkBox;
    QPushButton *pushButton_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Reproductor)
    {
        if (Reproductor->objectName().isEmpty())
            Reproductor->setObjectName(QString::fromUtf8("Reproductor"));
        Reproductor->resize(800, 600);
        centralwidget = new QWidget(Reproductor);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 160, 531));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(185, 11, 601, 431));
        progess = new QSlider(centralwidget);
        progess->setObjectName(QString::fromUtf8("progess"));
        progess->setGeometry(QRect(190, 450, 591, 20));
        progess->setOrientation(Qt::Horizontal);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(190, 480, 51, 31));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(370, 480, 91, 31));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(510, 530, 291, 26));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(horizontalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        progressBar = new QProgressBar(horizontalLayoutWidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(24);

        horizontalLayout->addWidget(progressBar);

        checkBox = new QCheckBox(horizontalLayoutWidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        horizontalLayout->addWidget(checkBox);

        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(480, 480, 81, 31));
        Reproductor->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Reproductor);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
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
        label->setText(QCoreApplication::translate("Reproductor", "Library", nullptr));
        pushButton->setText(QCoreApplication::translate("Reproductor", "Load LIbrary", nullptr));
        label_2->setText(QCoreApplication::translate("Reproductor", "Playing:", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Reproductor", "Play", nullptr));
        label_3->setText(QCoreApplication::translate("Reproductor", "Memory Usage", nullptr));
        checkBox->setText(QCoreApplication::translate("Reproductor", "Paginate", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Reproductor", "Pause", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Reproductor: public Ui_Reproductor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPRODUCTOR_H
