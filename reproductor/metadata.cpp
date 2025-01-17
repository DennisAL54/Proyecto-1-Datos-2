#include "metadata.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

metadata::metadata()
{

}
//Funcion para devolver los datos del csv
QString metadata::data(QString id){

    //Abre el archivo
    ifstream datos;
    datos.open("tracks.csv");

    bool found = false;

    //Variables necesarias
    string x = id.toStdString();
    string trackID;
    string title;
    string artist;
    string album;
    string genre;


    //Busca la informacion por el id
    while (getline(datos,trackID,',') && !found){
        getline(datos,title,',');
        getline(datos,artist,',');
        getline(datos,album,',');
        getline(datos,genre,'\n');
        if(trackID == x){
            QString dato = QString::fromStdString(title);
            return dato;
    }

}

    return 0;
}
