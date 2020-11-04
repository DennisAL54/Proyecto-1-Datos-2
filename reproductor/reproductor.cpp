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
    //Define la interfaz a esta clase
    ui->setupUi(this);


    //Define la variable del reproductor
    reproductor = new QMediaPlayer(this);
    //Define la variable para la playlist
    playlist = new QMediaPlaylist;
    //Define el volumen del reproductor
    reproductor->setVolume(100);
    //Enlaza la playlist al reproductor
    reproductor->setPlaylist(playlist);

    //Conecta la posicion de las barra de progreso con la del volumen
    connect(reproductor,&QMediaPlayer::positionChanged,this, &Reproductor::on_position);
    //Conecta la posicion de las barra de progreso con la de la posicion de la de la cancion
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
    playlist->setCurrentIndex(ui->listWidget->currentRow());
    reproductor->play();
}
