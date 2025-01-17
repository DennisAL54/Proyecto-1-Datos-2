#include "reproductor.h"
#include "ui_reproductor.h"
#include "memoria.h"
#include "metadata.h"
#include <QMediaPlayer>
#include <QFileDialog>
#include <QMediaMetaData>
#include <QString>
#include <QDebug>
#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include <QFileInfo>
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <unistd.h>
#include <fcntl.h>
#include <QCheckBox>


using namespace std;

int globalCounter = 0;//Para recorrer checksums
int listCounter = 1;//Para evitar que funcione up/down si se llego al final
bool listLoaded = false;

class Node
{
    public:
    string info2;
    Node *data;
    Node *next;
};

/**
 * Funcion para insertar un elemento al inico de la lista (util para el scroll back)
 */
void insertBeg(Node** head, Node** info)
{
    Node* nodo = new Node(); //Crea un nodo
    nodo->data = *info; //Le asigna su data
    nodo->next = *head; //Mueve la anterior cabeza al elemento siguiente
    *head = nodo;// Hace que el head apunte al nuevo nodo
}
/**
 * Funcion para insertar un elemento al final de la lista (Util para el scroll foward)
*/
void insertEnd(Node** head, Node** info)
{

    Node* nodo = new Node(); //Crea un nodo

    Node *last = *head; //Crea un nodo "cola" o "final"

    nodo->data = *info; //Se le asigna la info al nodo creado al inicio

    nodo->next = NULL; //Se crea el nodo next (para moverse por la lista)

    //Si la lista esta vacia, el nuevo nodo es head (el inicio)
    if (*head == NULL)
    {
        *head = nodo;
        return;
    }

    //Si no, entonces ir al final de la lista
    while (last->next != NULL)
        last = last->next;

    //poner el nodo despues del final (nueva ultima posicion)
    last->next = nodo;
    return;
}
/**
 * Version modificada del insertEnd. Esta funcion permite insertar elementos dentro de las listas enlazadas
 * que ya estan dentro de la lista mas grande
*/
void insert2(Node** head, string file)
{
    Node* nodo = new Node();

    Node *last = *head;

    nodo->info2 = file;

    nodo->next = NULL;

    if (*head == NULL)
    {
        *head = nodo;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = nodo;
    return;
}
/**
 * Funcion hecha para calcular la cantidad de canciones en el archivo checksum adjunto al dataset (el archivo
 * se selecciona por nombre)
*/
int calculateSize(string name){

    bool isfile = false; // Debido a que el checksum tiene 2 partes (id y direccion) se usa este boolean para
                         // diferenciar id de direccion
    fstream fileTM; //carga el archivo

    string word;//este string se coloca en cada palabra. Es usado para leer el archivo palabra a palabra

    int Size = 0; //cantidad de archivos

    fileTM.open(name.c_str());//abre el archivo y lee su contenido como string

    while(fileTM >> word){// este while funciona mientras el archivo tenga palabras para leer

        if(isfile == true){//Si la palabra es la correcta aumenta el size en 1
            Size += 1;
            isfile = false;// Debido a la forma como se estructura el checksum se asume que la palabra
                           // siguiente a la correcta es incorrecta
        }

        else{
            isfile = true;// Si no es la correcta la ignora
        }
    }

    return Size; //retorna la cantidad de archivos
}
/**
 * Esta inicializa las listas y las carga con el primer 3% del dataset
 */
void generateList(Node** list, int totalSize, int position){

    int Sfrom = 0;

    int size = totalSize * 0.01;//Calcula el 1% del total de archivos del dataset

    int counter = 0;//Contador para recorrer el dataset

    bool rightword = false;//Boolean para diferenciar entre direccion e id

    fstream input;// Carga un archivo

    string word, name;

    name = "../fma_small/checksums";// Asigna el archivo al checksum

    input.open(name.c_str());

    while(counter <= size){
        if(rightword == true and Sfrom >= position){
            input >> word;
            insert2(list, "../fma_small/" + word);
            rightword = false;
            counter++;
        }
        else if(Sfrom < position and rightword == true){
            input >> word;
            rightword = false;
            Sfrom++;
        }
        else{
           input >> word;
           rightword = true;
        }
    }

}

/*
Esta funcion inserta todas las direcciones del dataset seleccionado
Es usada para cargar todas las canciones de una vez
*/
void insertAll(Node** listaG){

    bool rightword = false;//Boolean para diferenciar entre direccion e id

    fstream input;// Carga un archivo

    string word, name;

    name = "../fma_small/checksums";// Asigna el archivo al checksum

    input.open(name.c_str());// Abre el archivo

    while(input >> word)//Este while recorre el dataset agregando todas las direcciones sin excepcion
    {
        if(rightword == true){
            insert2(listaG, word);
            rightword = false;
        }
        else{
            rightword = true;
        }
    }
}

/*
Funcion para borrar nodos en cualquier posicion de la lista
*/
void deleteNode(Node **head, int pos)
{
   // Comprueba que la lista no este vacia
   if (*head == NULL)
      return;

   // Guarda el primer nodo
   Node* temp = *head;

    //Comprueba si head necesita ser reemplazado
    if (pos == 0)
    {
        *head = temp->next;// Cambia head
        free(temp);//Libera la antigua head
        return;
    }

    //Encuentra el nodo anterior a ser borrado
    for (int i=0; temp!=NULL && i<pos-1; i++)
         temp = temp->next;

    //Si la posicion es mayor que el size de la lista el programa falla
    if (temp == NULL || temp->next == NULL)
         return;

    // El nodo temp->next sera borrado
    // Apunta el puntero al nodo siguiente al borrado
    Node *next = temp->next->next;

    // Desenlaza el nodo
    free(temp->next);// Libera la memora

    temp->next = next;//Desenlaza el nodo borrado
}

using namespace std;

std::string extractFile(const char *filename, size_t bufferSize=512)
{
    int fd = open(filename, O_RDONLY);
    std::string output;

    if (fd==-1)
        return "";      /* error opening */

    char *buffer = (char*)malloc(bufferSize);
    if (buffer==NULL)
        return "";      /* Can't allocate memory */

    int datalength;
    while ((datalength = read(fd, buffer, bufferSize)) > 0)
        output.append(buffer, datalength);

    close(fd);
    return output;
}

float usage(){

    std::string memInfo = extractFile ("/proc/self/statm");

    if (memInfo.empty())
    {
        std::cerr << "Error al leer información\n";
        std::terminate();
    }
    unsigned long size;

    std::stringstream ss (memInfo);

    ss >> size;

    cout << "Tamaño total: "<<size * getpagesize() <<"\n";

    float mem = size * getpagesize()*0.0000000095367432;
    return mem;

}

Node* listaG = NULL;
int sizeofList = calculateSize("../fma_small/checksums")*0.01;

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
    float x = usage();
    QString b = QString::number(x);
    qDebug() << b;
    ui->mem->setText(b + " mb");

    //ui->songName->setText()


}

void Reproductor::on_pushButton_3_clicked()
{
    reproductor->pause();
    float x = usage();
    QString b = QString::number(x);
    qDebug() << b;
    ui->mem->setText(b + " mb");
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
    if(listLoaded == false){
        Node* lista1 = NULL;
        if(ui->checkBox->isChecked()){
            generateList(&lista1, calculateSize("../fma_small/checksums"), globalCounter);
            insertEnd(&listaG, &lista1);
            while (listaG != NULL)
                {
                    while(listaG->data != NULL){
                        playlist->addMedia(QMediaContent(QUrl::fromLocalFile(QFileInfo(QString::fromStdString(listaG->data->info2)).absoluteFilePath())));
                        ui->listWidget->addItem(QString::fromStdString(listaG->data->info2));
                        listaG->data = listaG->data->next;
                    }
                    listaG = listaG->next;
                }
        }
        else{
            insertAll(&listaG);
            while(listaG != NULL){
                playlist->addMedia(QMediaContent(QUrl::fromLocalFile(QFileInfo(QString::fromStdString(listaG->data->info2)).absoluteFilePath())));
                ui->listWidget->addItem(QString::fromStdString(listaG->data->info2));
                listaG = listaG->next;
            }
        }
        listLoaded = true;
        float x = usage();
        QString b = QString::number(x);
        qDebug() << b;
        ui->mem->setText(b + " mb");
    }
    else{
        qDebug() << "Library Already Loaded";
    }
}

void Reproductor::on_listWidget_activated()
{
    playlist->setCurrentIndex(ui->listWidget->currentRow());
    reproductor->play();
    QString name = ui->listWidget->currentItem()->text();
    QString fileName = QFileInfo(name).fileName();
    ui->songName->setText(fileName);
}

void Reproductor::on_pushButton_4_clicked()
{
    ui->listWidget->clear();
    playlist->removeMedia(0,sizeofList);
    listLoaded = false;
}

void Reproductor::on_pushButton_5_clicked()
{
    if(listLoaded == true){
        if(listCounter == 1){
            qDebug()<<"Action not permited";
        }
        else{
            Node* lista1 = NULL;
            globalCounter -= 80;

            playlist->removeMedia(0,sizeofList);

            ui->listWidget->clear();

            deleteNode(&listaG, 1);

            listCounter = listCounter - 1;

            generateList(&lista1, calculateSize("../fma_small/checksums"), globalCounter);

            insertEnd(&listaG, &lista1);

            while (listaG != NULL)
                {
                    while(listaG->data != NULL){
                        playlist->addMedia(QMediaContent(QUrl::fromLocalFile(QFileInfo(QString::fromStdString(listaG->data->info2)).absoluteFilePath())));
                        ui->listWidget->addItem(QString::fromStdString(listaG->data->info2));
                        listaG->data = listaG->data->next;
                    }
                    listaG = listaG->next;
                }
            qDebug()<<"Success";
        }
    }
    else{
        qDebug() << "Please Load Library First";
    }

    float x = usage();
    QString b = QString::number(x);
    qDebug() << b;
    ui->mem->setText(b + " mb");
}

void Reproductor::on_pushButton_6_clicked()
{
    if(listLoaded == true){
        if(listCounter == 100){
            qDebug()<<"Action not permited";
        }
        else{
            Node* lista1 = NULL;

            globalCounter += 80;

            playlist->removeMedia(0,sizeofList);

            ui->listWidget->clear();

            deleteNode(&listaG, 1);

            listCounter = listCounter + 1;

            generateList(&lista1, calculateSize("../fma_small/checksums"), globalCounter);

            insertEnd(&listaG, &lista1);

            while (listaG != NULL)
                {
                    while(listaG->data != NULL){
                        playlist->addMedia(QMediaContent(QUrl::fromLocalFile(QFileInfo(QString::fromStdString(listaG->data->info2)).absoluteFilePath())));
                        ui->listWidget->addItem(QString::fromStdString(listaG->data->info2));
                        listaG->data = listaG->data->next;
                    }
                    listaG = listaG->next;
                }
            qDebug()<<"Success";
        }

    }
    else{
        qDebug() << "Please Load Library First";
    }

    float x = usage();
    QString b = QString::number(x);
    qDebug() << b;
    ui->mem->setText(b + " mb");
}


