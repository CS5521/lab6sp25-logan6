#include "types.h"
#include "stat.h"
#include "user.h"
int
main(int argc, char * argv[])
{
   int numForks = fkc(1);
   printf(1, "%d\n", numForks);
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
   printf(1, "%d\n", numForks);
   exit();
}
