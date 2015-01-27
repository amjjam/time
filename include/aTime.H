/******************************************************************************
 * This is class aTime which implements a time with nanoosecond resolution    *
 ******************************************************************************/

#ifndef _ATIME_H_
#define _ATIME_H_

#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define BILLION 1000000000

class aTime{
public:
  aTime(); // Constructor sets time to current time
  ~aTime(); // Destructor
  void set(); // Set to current time
  void set(struct timespec &t); // Set the time as a struct timeval
  void set(double t); // Set the time as a double
  void set(int yr, int mo, int dy, int hr=0, int mn=0, int se=0, long ns=0); 
  double get(); // Get the time as a double
  void get(struct timespec &t); // Get the time as a struct timeval
  void get(int &yr, int &mo, int &dy, int &hr, int &mn, int &se, long &ns);
  void get(int &yr, int &mo, int &dy, int &hr, int &mn, int &se);
  void get(int &yr, int &mo, int &dy, int &hr, int &mn);
  void get(int &yr, int &mo, int &dy, int &hr);
  void get(int &yr, int &mo, int &dy);
  int size(); // Get the size of time as written to memory
  void operator=(struct timespec &t); // Set equal to this time
  void operator=(double t); // Set equal to this time
  void operator=(aTime &t); // Set equal to this time
  void operator+=(double t); // Add this many seconds
  void operator+=(aTime &t); // Add this time time value
  void operator-=(double t); // Subtract this many seconds
  void operator-=(aTime &t); // Subtrct this time value
  double operator-(aTime &t); // Return this - t as a double
  bool operator==(aTime &t); // Return true if this is same time as t
  bool operator>(aTime &t); // Return true of this is later than t;
  bool operator>=(aTime &t); // Return true if this is later or equal to t
  bool operator<(aTime &t); // Return true if this is earlier than t
  bool operator<=(aTime &t); // Return true if this is earlier or equal to t
private:
  struct timespec t;
};
  
#endif