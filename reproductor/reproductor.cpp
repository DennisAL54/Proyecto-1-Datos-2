#include "reproductor.h"
#include "ui_reproductor.h"
#include "memoria.h"
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
#include <fstream>
#include <QCheckBox>

using namespace std;

int globalCounter = 0;//Para recorrer checksums
int listCounter = 100;//Para evitar que funcione up/down si se llego al final

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
void setupList(Node** list1, Node** list2, Node** list3, int totalSize){

    int size = totalSize * 0.01;//Calcula el 1% del total de archivos del dataset

    int counter = 0;//Contador para recorrer el dataset

    bool rightword = false;//Boolean para diferenciar entre direccion e id

    fstream input;// Carga un archivo

    string word, name;

    name = "../fma_small/checksums";// Asigna el archivo al checksum

    input.open(name.c_str());// Abre el archivo

    /**
     * Este while se encarga de recorrer el dataset recolectando las direcciones del primer 3% del
     * mismo. Adicionalmente asigna cada porcentaje a cada una de las listas que se van a utilizar
     * al inicio
    */
    while(counter <= size*3){
        if(counter <= size and rightword == true){
            input >> word;
            insert2(list1, "../fma_small/"+word);
            rightword = false;
            counter++;
        }
        else if(counter <= size*2 and rightword == true){
            input >> word;
            insert2(list2, "../fma_small/"+word);
            rightword = false;
            counter++;
        }
        else if(counter <= size*3 and rightword == true){
            input >> word;
            insert2(list3, "../fma_small/"+word);
            rightword = false;
            counter++;
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

long getMemAvailable() {
    std::string token;
    std::ifstream file("/proc/meminfo");
    while(file >> token) {
        if(token == "MemAvailable:") {
            unsigned long mem;
            if(file >> mem) {
                return mem;
            } else {
                return 0;
            }
        }
    }
    return 0; // nothing found
    }


Node* lista1 = NULL;
Node* lista2 = NULL;
Node* lista3 = NULL;
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
    int counterTrack = 0;


    setupList(&lista1, &lista2, &lista3, calculateSize("../fma_small/checksums"));
    insertEnd(&listaG, &lista1);
    insertEnd(&listaG, &lista2);
    insertEnd(&listaG, &lista3);

    Node* pivot = listaG;


    while(pivot != NULL){
        while(pivot->data != NULL){
            if(counterTrack >= 0 and counterTrack <= sizeofList){
                playlist->addMedia(QMediaContent(QUrl::fromLocalFile(QFileInfo(QString::fromStdString(pivot->data->info2)).absoluteFilePath())));
                ui->listWidget->addItem(QString::fromStdString(pivot->data->info2));
                pivot->data = pivot->data->next;
                counterTrack++;
            }
            else{
               pivot->data = pivot->data->next;
            }
        }
        pivot = pivot->next;
    }

    float x = getMemAvailable()/1048576.00;
    QString b = QString::number(x);
    qDebug() << b;
    ui->mem->setText(b + " mb");
}

void Reproductor::on_listWidget_activated()
{
    playlist->setCurrentIndex(ui->listWidget->currentRow());
    reproductor->play();
}

void Reproductor::on_pushButton_4_clicked()
{
    //playlist->removeMedia(0);
    playlist->removeMedia(0,3);
    int i = 0;
    while(i<10){
        i++;
        ui->listWidget->takeItem(i);

    }
//    for (int i = 0;i<3;i++ ) {
//        ui->listWidget->takeItem(i);
//    }

}

void Reproductor::on_pushButton_5_clicked()
{
    if(listCounter == 1){
        qDebug()<<"Action not permited";
    }
    else if(listCounter == 2){

    }
    else if(listCounter == 100){
        listCounter = listCounter - 1;
        Node* pivot2 = listaG;
        int counterTrack = 0;

        while(pivot2 != NULL){
            while(pivot2->data != NULL){
                if(counterTrack >= 0 and counterTrack <= sizeofList){
                    playlist->addMedia(QMediaContent(QUrl::fromLocalFile(QFileInfo(QString::fromStdString(pivot2->data->info2)).absoluteFilePath())));
                    ui->listWidget->addItem(QString::fromStdString(pivot2->data->info2));
                    pivot2->data = pivot2->data->next;
                    counterTrack++;
                }
                else{
                   pivot2->data = pivot2->data->next;
                }
            }
            pivot2 = pivot2->next;
        }
    }
    else{
        listCounter = listCounter - 1;
        qDebug()<<"Success";
    }
}

void Reproductor::on_pushButton_6_clicked()
{
    if(listCounter == 100){
        qDebug()<<"Action not permited";
    }
    else if(listCounter == 99){
        listCounter = listCounter + 1;
        qDebug()<<"Returned to begining";
    }
    else if(listCounter == 1){
        listCounter = listCounter + 1;
        Node* pivot = listaG;
        int counterTrack = 0;

        while(pivot != NULL){
            while(pivot->data != NULL){
                if(counterTrack >= 0 and counterTrack <= sizeofList){
                    playlist->addMedia(QMediaContent(QUrl::fromLocalFile(QFileInfo(QString::fromStdString(pivot->data->info2)).absoluteFilePath())));
                    ui->listWidget->addItem(QString::fromStdString(pivot->data->info2));
                    pivot->data = pivot->data->next;
                    counterTrack++;
                }
                else{
                   pivot->data = pivot->data->next;
                }
            }
            pivot = pivot->next;
        }
    }
    else{
        listCounter = listCounter + 1;
        qDebug()<<"Success";
    }
}


