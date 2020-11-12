#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <fcntl.h>

#ifndef MEMORIA_H
#define MEMORIA_H


class memoria
{
private:
    std::string extractFile(const char *filename, size_t bufferSize=512);
public:
    memoria();
    float usedMemory();
};

#endif // MEMORIA_H
