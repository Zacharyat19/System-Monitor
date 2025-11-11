#include <memory>

#include "../Inc/Reader.h"

int main() 
{
  std::unique_ptr<Reader> reader = std::make_unique<Reader>();

  CpuTimes times = reader->readTimes();

  std::cout << times.user << " " << times.nice << " " << times.system << " " << times.idle << " " << times.iowait << " " << times.irq << " " << times.softirq << std::endl;

  return 0;
}
