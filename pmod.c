/*
* Name: Rose Zickefoose
 * Assignment: Lab 9- System Calls
 * Section: 111
 * File name: pmod.c
 */

#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
	nice(10);
	struct timespec ts, ts2 = {0, 1837272638};
	nanosleep(&ts, &ts2);
	if(nanosleep(&ts , &ts2) < 0)
   {
      printf("Nano sleep system call failed \n");
      return -1;
   }
	printf("Program finished, goodbye\n");
    return 0;
}
