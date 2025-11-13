#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#include "../Inc/CPU.h"

CpuCalc::CpuCalc() {}

CpuCalc::~CpuCalc() {}

bool CpuCalc::readFile(std::string& file)
{
    file.clear();
    file.reserve(8192);

    int fd = open("/proc/stat", O_RDONLY | O_CLOEXEC);

    if(fd < 0)
    {
        return false;
    }

    char buff[4096];
    while(true)
    {
        ssize_t n = read(fd, buff, sizeof(buff));
        if(n > 0)
        {
            file.append(buff,  static_cast<size_t>(n));
        }
        else if(n == 0)
        {
            break;
        }
        else
        {
            if(errno == EINTR) continue;
            close(fd);
            return false;
        }
    }

    close(fd);
    return true;
}

bool CpuCalc::parseFile(std::string& file)
{
    std::string buff;

    if(readFile(buff))
    {
        std::string_view sv{buff};

        while(!sv.empty())
        {
            size_t n = sv.find('\n');

            std::string_view line = (n == std::string_view::npos) ? sv : sv.substr(0, n);

            CpuTimes time;

            if(n == std::string_view::npos) break;

            sv.remove_prefix(n + 1);
        }
    }
    else
    {
        return false;
    }

    return true;
}