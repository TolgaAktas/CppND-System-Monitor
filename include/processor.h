#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <vector>
#include <string>
#include "linux_parser.h"


class Processor {
 public:
  float Utilization();  // TODO: See src/processor.cpp

  // DONE: Declare any necessary private members
 private:
  
  long last_user, last_nice, last_system;
  long last_idle;
  long last_iowait;
  long last_irq;
  long last_softirq;
  long last_steal;
  
};

#endif