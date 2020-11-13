#include "memoria.h"

memoria::memoria()
{

}

long memoria::getMemAvailable() {
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
