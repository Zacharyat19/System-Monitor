#include "../Inc/Reader.h"

Reader::Reader() {}

Reader::~Reader() {}

CpuTimes Reader::readTimes()
{
  std::ifstream file("/proc/stat");
  std::string cpu;
  CpuTimes times;
    
  file >> cpu >> times.user >> times.nice >> times.system >> times.idle >> times.iowait >> times.irq >> times.softirq;
  
  return times;
}
