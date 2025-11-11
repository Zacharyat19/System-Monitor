#include <fstream>
#include <string>
#include <thread> 
#include <chrono>
#include <iostream>
#include <cstdint>

struct CpuTimes 
{
    int64_t user, nice, system, idle, iowait, irq, softirq;
};

class Reader
{
    public:
      Reader();
      ~Reader();

      CpuTimes readTimes();
};
