#include "reproductor.h"
#include "ui_reproductor.h"

Reproductor::Reproductor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Reproductor)
{
    ui->setupUi(this);
}

Reproductor::~Reproductor()
{
    delete ui;
}

