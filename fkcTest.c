#include "types.h"
#include "stat.h"
#include "user.h"
int
main(int argc, char * argv[])
{
  int numForks = fkc(1);
  printf(1, "number of forks when program starts: %d\n", numForks);
  if(fork() == 0)
  {
    exit();
  }
  if(fork() == 0)
  {
    exit();
  }
  wait();
  wait();
  numForks = fkc(1);                      
  printf(1, "number of forks after two more forks: %d\n", numForks);
  
  numForks = fkc(0);
  printf(1, "number of forks after fork count cleared: %d\n", numForks);

  if(fork() == 0)
  {
    exit();
  }
  wait();

  if(fork() == 0)
  {
    exit();
  }
  wait();
  if(fork() == 0)
  {
    exit();
  }
  wait();
  numForks = fkc(1);
  printf(1, "number of forks after 3 more forks: %d\n", numForks);
  exit();

}
