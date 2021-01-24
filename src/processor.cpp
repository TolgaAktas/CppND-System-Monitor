#include "processor.h"


using std::vector;
using std::string;

// DONE: Return the aggregate CPU utilization
float Processor::Utilization() {
  vector<string> utilizations = LinuxParser::CpuUtilization();
  long user = stol(utilizations[0]);
  long nice = stol(utilizations[1]);
  long system = stol(utilizations[2]);
  long idle = stol(utilizations[3]);
  long iowait = stol(utilizations[4]);
  long irq = stol(utilizations[5]);
  long softirq = stol(utilizations[6]);
  long steal = stol(utilizations[7]);

  long PrevIdle = last_idle + last_iowait;
  long Idle = idle + iowait;
  long PrevNonIdle = last_user + last_nice + last_system + last_irq +
                     last_softirq + last_steal;
  long NonIdle = user + nice + system + irq + softirq + steal;

  long PrevTotal = PrevIdle + PrevNonIdle;
  long Total = Idle + NonIdle;

  // differentiate: actual value minus the previous one
  float totald = Total - PrevTotal;
  float idled = Idle - PrevIdle;

  last_user = user;
  last_nice = nice;
  last_system = system;
  last_idle = idle;
  last_iowait = iowait;
  last_irq = irq;
  last_softirq = softirq;
  last_steal = steal;

  return (totald - idled) / totald;

}