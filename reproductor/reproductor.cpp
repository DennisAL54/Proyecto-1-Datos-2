#include "reproductor.h"
#include "ui_reproductor.h"
#include <QMediaPlayer>
#include <QFileDialog>
#include <QMediaMetaData>
#include <QString>
#include <qmediaservice.h>
#include <qmediaplaylist.h>
#include <qvideoprobe.h>



Reproductor::Reproductor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Reproductor)
{
    ui->setupUi(this);

    reproductor = new QMediaPlayer(this);

    connect(reproductor,&QMediaPlayer::positionChanged,this, &Reproductor::on_position);
    connect(reproductor,&QMediaPlayer::durationChanged,this, &Reproductor::on_duration);

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

    reproductor->play();

}

void Reproductor::on_pushButton_3_clicked()
{
    reproductor->pause();
}

void Reproductor::on_position(qint64 position)
{
    ui->progess->setValue(position);
}

void Reproductor::on_duration(qint64 position)
{
    ui->progess->setMaximum(position);
}

void Reproductor::on_pushButton_clicked()
{
    QString song = QFileDialog::getOpenFileName(this,"Open");
    if(song.isEmpty()){
        return;
    }
    //QMediaMetaData::AlbumArtist

    ui->artistName->setText("Queen");
    reproductor->setMedia(QUrl::fromLocalFile(song));

    reproductor->setVolume(100);
    reproductor->play();
    reproductor->metaData(QMediaMetaData::Title).toString();
    ui->songName->setText(QMediaMetaData::Title);
}
