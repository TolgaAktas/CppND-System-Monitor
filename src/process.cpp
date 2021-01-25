#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "process.h"

using std::string;
using std::to_string;
using std::vector;

// DONE: Return this process's ID
int Process::Pid() { return pid; }

// DONE: Return this process's CPU utilization
float Process::CpuUtilization() { return cpu_utilization; }

// DONE: Return the command that generated this process
string Process::Command() { return command; }

// DONE: Return this process's memory utilization
string Process::Ram() { return ram; }

// DONE: Return the user (name) that generated this process
string Process::User() { return user; }

// DONE: Return the age of this process (in seconds)
long int Process::UpTime() { return upTime; }

// DONE: Overload the "less than" comparison operator for Process objects
// REMOVE: [[maybe_unused]] once you define the function
bool Process::operator<(Process const& a) const {
	return cpu_utilization < a.cpu_utilization;
}


Process::Process(int _pid) {
  pid = _pid;
  user = LinuxParser::User(pid);
  command = LinuxParser::Command(pid);
  ram = LinuxParser::Ram(pid);
  upTime = LinuxParser::UpTime(pid) - LinuxParser::UpTime();
  cpu_utilization = LinuxParser::CpuUtilization(pid);
}



