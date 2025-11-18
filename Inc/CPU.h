#include <string>
#include <cstdint>
#include <vector>

struct CpuTimes 
{
  std::string cpu;
  uint64_t user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;
};

class CpuCalc
{
    public:
        CpuCalc();
        ~CpuCalc();
    private:
        bool readFile(std::string& file);
        bool parseFile(std::string& file);

        std::vector<CpuTimes> m_CPUs;
};