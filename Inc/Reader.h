#include <fstream>
#include <string>
#include <thread> 
#include <chrono>
#include <iostream>
#include <stdint>

struct CpuTimes 
{
    int64_t user, nice, system, idle, iowait, irq, softirq;
};

class Reader
{
    public:
        CPUTimes readTimes()
        {
            std::ifstream file("/proc/stat");
            std::string cpu;
            CpuTimes times;
            
            file >> cpu >> times.user >> times.nice >> times.system >> times.idle >> times.iowait >> times.irq >> times.softirq;
            
            return times;
        }
};
