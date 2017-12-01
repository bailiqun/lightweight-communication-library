#include <math.h>
#include "serial/duration.h"

namespace serial
{

/*
     usage : normalisze time of int32 to second + millsecond
*/
  void normalizeSecNSecSigned(int32_t &sec, int32_t &msec)
  {
    int32_t nsec_part = msec;
    int32_t sec_part = sec;

    while (nsec_part > 1000000000L)
    {
      nsec_part -= 1000000000L;
      ++sec_part;
    }
    while (nsec_part < 0)
    {
      nsec_part += 1000000000L;
      --sec_part;
    }
    sec = sec_part;
    msec = nsec_part;
  }

  Duration& Duration::operator+=(const Duration &rhs)
  {
    sec += rhs.sec;
    nsec += rhs.nsec;
    normalizeSecNSecSigned(sec, nsec);
    return *this;
  }

  Duration& Duration::operator-=(const Duration &rhs){
    sec += -rhs.sec;
    nsec += -rhs.nsec;
    normalizeSecNSecSigned(sec, nsec);
    return *this;
  }

  Duration& Duration::operator*=(double scale){
    sec *= scale;
    nsec *= scale;
    normalizeSecNSecSigned(sec, nsec);
    return *this;
  }

}
