#include "serial/time.h"

namespace serial
{
  void normalizeSecNSec(uint32_t& sec, uint32_t& nsec){
    uint32_t nsec_part= nsec % 1000000000UL;
    uint32_t sec_part = nsec / 1000000000UL;
    sec += sec_part;
    nsec = nsec_part;
  }

  Time& Time::fromNSec(int32_t t)
  {
    sec = t / 1000000000;
    nsec = t % 1000000000;
    normalizeSecNSec(sec, nsec);
    return *this;
  }

  Time& Time::operator +=(const Duration &rhs)
  {
    sec += rhs.sec;
    nsec += rhs.nsec;
    normalizeSecNSec(sec, nsec);
    return *this;
  }

  Time& Time::operator -=(const Duration &rhs){
    sec += -rhs.sec;
    nsec += -rhs.nsec;
    normalizeSecNSec(sec, nsec);
    return *this;
  }
}
