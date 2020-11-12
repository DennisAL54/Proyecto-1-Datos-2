#include "memoria.h"

memoria::memoria()
{

}

//std::string extractFile(const char *filename, size_t bufferSize=512)
//{
//    int fd = open(filename, O_RDONLY);
//    std::string output;

//    if (fd==-1)
//        return "";      /* error opening */

//    char *buffer = (char*)malloc(bufferSize);
//    if (buffer==NULL)
//        return "";      /* Can't allocate memory */

//    int datalength;
//    while ((datalength = read(fd, buffer, bufferSize)) > 0)
//        output.append(buffer, datalength);

//    close(fd);
//    return output;
//}

//float memoria::usedMemory(){
//    std::string memInfo = extractFile("/proc/self/statm");

//    if (memInfo.empty()) {
//        std::cerr << "Error al leer información\n";
//        std::terminate();
//    }
//    //while (true) {
//        unsigned long size;

//        std::stringstream ss(memInfo);

//        ss >> size;

//        float x = size * getpagesize() / 1048576.0;

//        std::cout << "Tamaño total: " << x << "\n";

//        return x;

//    //}
//}
