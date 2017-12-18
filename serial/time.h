#ifndef ROS_TIME_H_
#define ROS_TIME_H_

#include "duration.h"
#include <math.h>
#include <stdint.h>

namespace serial
{
  void normalizeSecNSec(uint32_t &sec, uint32_t &nsec);

  class Time
  {
    public:
      uint32_t sec, nsec;

      Time() : sec(0), nsec(0) {}
      Time(uint32_t _sec, uint32_t _nsec) : sec(_sec), nsec(_nsec)
      {
        normalizeSecNSec(sec, nsec);
      }

      inline double toSec() const { return (double)sec + 1e-9*(double)nsec; }
      inline void fromSec(double t) { sec = (uint32_t) floor(t); nsec = (uint32_t) round((t-sec) * 1e9); }
      inline uint32_t toNsec() { return (uint32_t)sec*1000000000ull + (uint32_t)nsec; }

      Time& fromNSec(int32_t t);
      Time& operator +=(const Duration &rhs);
      Time& operator -=(const Duration &rhs);

      static Time now();
      static void setNow( Time & new_now);
  };

}

#endif
