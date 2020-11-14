#include <iostream>
#include <fstream>
#include <string>

#ifndef MEMORIA_H
#define MEMORIA_H


class memoria
{
private:

public:
    memoria();
    /** @brief getMemAvailable() Funcion para calcular y devolver la cantidad de RAM utilizada por la aplicacion
      * @param La unica entrada es el archivo que contiene los datos para analizar
      * @return Devuelve la cantidad de RAM que usa la aplicacion
      */
    long getMemAvailable();
};

#endif // MEMORIA_H
