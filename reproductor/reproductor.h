/**
  * @file funciones.h
  * @version 1.0
  * @author Roy Chavarria
  * @title Funciones interfaz
  * @brief Funciones de la interfaz
  */

#ifndef REPRODUCTOR_H
#define REPRODUCTOR_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QDebug>
#include <QMediaPlaylist>
#include <QListWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui { class Reproductor; }
QT_END_NAMESPACE

class Reproductor : public QMainWindow
{
    Q_OBJECT

public:
    Reproductor(QWidget *parent = nullptr);
    ~Reproductor();

private slots:

    /** @brief on_progess_sliderMoved Define la posicion de la cancion mediante una barra de progreso
      * @param La barra equivale a enteros entre 0 y 100
      * @return Reproduce la cancion en la posicion determiada
      */

    void on_progess_sliderMoved(int position);

    /** @brief on_pushButton_clicked Abre un buscador de archivos que inserta la cancion que se va a reporducir
      * @param Una direccion donde se encuentra la musica que se desea reproducir
      * @return La direccion agregada para que el reproductor reproduzca la cancion
      */

    void on_pushButton_clicked();

    /** @brief on_pushButton_2_clicked Boton que reproduce la musica si esta pausada
      * @return Inicia la musica
      */

    void on_pushButton_2_clicked();

    /** @brief on_pushButton_3_clicked Boton que pausa la musica si se esta reproduciendo
      * @return Detiene la musica pero la deja en la posicion en la que se encuentra
      */

    void on_pushButton_3_clicked();

    /** @brief on_position Funcion complementaria para poder determinar la posicion de la cancion
      * @param Posicion del la barra de progreso
      * @return Posicion relativa a la cancion
      */

    void on_position(qint64 position);

    void on_duration(qint64 position);

    void on_listWidget_activated();

    void on_pushButton_4_clicked();

private:
    Ui::Reproductor *ui;
    QMediaPlayer* reproductor;
    QMediaPlaylist *playlist;

};
#endif // REPRODUCTOR_H
