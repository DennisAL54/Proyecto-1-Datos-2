#include "reproductor.h"
#include "ui_reproductor.h"

Reproductor::Reproductor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Reproductor)
{
    ui->setupUi(this);

    reproductor = new QMediaPlayer(this);

    //connect(reproductor,&QMediaPlayer::position,this, &Reproductor::on_position);
    //connect(reproductor,&QMediaPlayer::duration,this, &Reproductor::on_duration);
}

Reproductor::~Reproductor()
{
    delete ui;
}


void Reproductor::on_progess_sliderMoved(int position)
{
    reproductor->setPosition(position);
}

void Reproductor::on_pushButton_2_clicked()
{
    reproductor->setMedia(QUrl::fromLocalFile("home/rootshell/test.mp3"));
    reproductor->play();
    qDebug() << reproductor->errorString();
}

void Reproductor::on_pushButton_3_clicked()
{
    reproductor->stop();
}

void Reproductor::on_position(qint64 position)
{
    ui->progess->setValue(position);
}

void Reproductor::on_duration(qint64 position)
{
    ui->progess->setMaximum(position);
}
