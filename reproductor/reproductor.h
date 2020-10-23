#ifndef REPRODUCTOR_H
#define REPRODUCTOR_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QDebug>

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
    void on_progess_sliderMoved(int position);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_position(qint64 position);

    void on_duration(qint64 position);

private:
    Ui::Reproductor *ui;
    QMediaPlayer* reproductor;

};
#endif // REPRODUCTOR_H
