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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Reproductor
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_3;
    QSplitter *splitter;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QListWidget *listWidget_2;
    QPushButton *pushButton;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QListWidget *listWidget;
    QSlider *progess;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *songName;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QLabel *artistName;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_3;
    QProgressBar *progressBar;
    QCheckBox *checkBox;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Reproductor)
    {
        if (Reproductor->objectName().isEmpty())
            Reproductor->setObjectName(QString::fromUtf8("Reproductor"));
        Reproductor->resize(808, 587);
        centralwidget = new QWidget(Reproductor);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_3 = new QHBoxLayout(centralwidget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        verticalLayoutWidget = new QWidget(splitter);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        listWidget_2 = new QListWidget(verticalLayoutWidget);
        listWidget_2->setObjectName(QString::fromUtf8("listWidget_2"));

        verticalLayout->addWidget(listWidget_2);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        splitter->addWidget(verticalLayoutWidget);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        listWidget = new QListWidget(layoutWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout_2->addWidget(listWidget);

        progess = new QSlider(layoutWidget);
        progess->setObjectName(QString::fromUtf8("progess"));
        progess->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(progess);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        songName = new QLabel(layoutWidget);
        songName->setObjectName(QString::fromUtf8("songName"));

        gridLayout->addWidget(songName, 0, 1, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 2, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 1, 2, 1, 1);

        artistName = new QLabel(layoutWidget);
        artistName->setObjectName(QString::fromUtf8("artistName"));

        gridLayout->addWidget(artistName, 1, 1, 1, 1);

        pushButton_5 = new QPushButton(layoutWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        gridLayout->addWidget(pushButton_5, 0, 3, 1, 1);

        pushButton_6 = new QPushButton(layoutWidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        gridLayout->addWidget(pushButton_6, 1, 3, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout_2->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(layoutWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        horizontalLayout_2->addWidget(pushButton_4);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        progressBar = new QProgressBar(layoutWidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(24);

        horizontalLayout->addWidget(progressBar);

        checkBox = new QCheckBox(layoutWidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        horizontalLayout->addWidget(checkBox);


        verticalLayout_2->addLayout(horizontalLayout);

        splitter->addWidget(layoutWidget);

        horizontalLayout_3->addWidget(splitter);

        Reproductor->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Reproductor);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 808, 21));
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
        songName->setText(QString());
        label_4->setText(QCoreApplication::translate("Reproductor", "Artist: ", nullptr));
        artistName->setText(QString());
        pushButton_5->setText(QCoreApplication::translate("Reproductor", "Up", nullptr));
        pushButton_6->setText(QCoreApplication::translate("Reproductor", "Down", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Reproductor", "Play", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Reproductor", "Pause", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Reproductor", "Delete", nullptr));
        label_3->setText(QCoreApplication::translate("Reproductor", "Memory Usage", nullptr));
        checkBox->setText(QCoreApplication::translate("Reproductor", "Paginate", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Reproductor: public Ui_Reproductor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPRODUCTOR_H
