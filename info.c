/*
 * Name: Rose Zickefoose
 * Assignment: Lab 9- System Calls
 * Section: 111
 * File name: info.c
 */

#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <sys/utsname.h>

int main(int argc, char* argv[])
{
	/* Prints out current time in nanoseconds */
	struct timespec time;
	clock_gettime(CLOCK_REALTIME, &time);
	printf("Time: %ld\n", time.tv_nsec);

	/* Prints out the system's network name */
	char host[512];
	if(gethostname(host, sizeof(host)) == 0) {
		printf("Network Name: %s\n", host);
	} else {
		perror("Error getting hostname");
	}

	/* Prints out the system's name */
	struct utsname system_data;
	uname(&system_data);
	printf("System's Name: %s\n", system_data.sysname);

	/* Prints out the system release and version */
	printf("System Release: %s\n", system_data.release);
	printf("System Version: %s\n", system_data.version);

	/* Prints out the system's hardware type */
	printf("System's Hardware Type: %s\n", system_data.machine);

	/* Prints out the number of CPUs on a system */
	long cpus = sysconf(_SC_NPROCESSORS_CONF);
	printf("CPU Count: %ld\n", cpus);

	/* Prints out the total physical memory in bytes */
	long phys_mem = sysconf(_SC_PHYS_PAGES);
	printf("Physical Memory: %ld\n", phys_mem);

	/* Prints out the total free memory in bytes */
	long free_mem = sysconf(_SC_AVPHYS_PAGES);
	printf("Free Memory: %ld\n", free_mem);


    return 0;
}