#include "reproductor.h"
#include "ui_reproductor.h"
#include <QMediaPlayer>
#include <QFileDialog>
#include <QMediaMetaData>
#include <QString>
#include <QDebug>




Reproductor::Reproductor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Reproductor)
{
    ui->setupUi(this);

    reproductor = new QMediaPlayer(this);
    playlist = new QMediaPlaylist;
    reproductor->setVolume(100);
    reproductor->setPlaylist(playlist);

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

    QStringList filenames = QFileDialog::getOpenFileNames(this, "Open a File");
    for(const QString & filename: filenames){
        playlist->addMedia(QMediaContent(QUrl::fromLocalFile(filename)));
         ui->listWidget->addItem(filename);
    }

//    QString song = QFileDialog::getOpenFileName(this,"Open");
//    if(song.isEmpty()){
//        return;
//    }
//    reproductor->setMedia(QUrl::fromLocalFile(song));
//    reproductor->play();
}

void Reproductor::on_listWidget_activated()
{
    //ui->songBar->setRange(0, player->duration() / 1000);
    playlist->setCurrentIndex(ui->listWidget->currentRow());
    ui->pushButton->setIcon(QIcon(":/new/prefix1/Resource/media_playback_pause.png"));
    //playPauseCounter =2;
    reproductor->play();
}
