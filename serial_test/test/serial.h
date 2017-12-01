#ifndef _SERIAL_H_
#define _SERIAL_H_

#include "serial/node_handle.h"
#include "driver.h"

//typedef serial::NodeHandle<HardwareSerial> NodeHandleSerial;
typedef serial::NodeHandle<HardwareTCPServer> NodeHandleTCP;

#endif
