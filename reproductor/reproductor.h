#ifndef REPRODUCTOR_H
#define REPRODUCTOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Reproductor; }
QT_END_NAMESPACE

class Reproductor : public QMainWindow
{
    Q_OBJECT

public:
    Reproductor(QWidget *parent = nullptr);
    ~Reproductor();

private:
    Ui::Reproductor *ui;
};
#endif // REPRODUCTOR_H
