/*
* Name: Rose Zickefoose
 * Assignment: Lab 9- System Calls
 * Section: 111
 * File name: pinfo.c
 */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <sched.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
	if(argc > 2) // checks if there are too many args
	{
		printf("Entered too many arguments");
		return 0;
	}

	pid_t pid;

	if(argc == 1)
	{
		pid = getpid();
	}
	else
	{
		pid = (pid_t) strtol(argv[1], NULL, 10);
		if(kill(pid, 0) == -1) {
			perror("ERROR: pid does not exist\n");
			exit(1);
		}
	}
	int priority = getpriority(PRIO_PROCESS, pid);
	printf("Priority: %d\n", priority);
	int schedule = sched_getscheduler(pid);
	printf("Scheduler: %d\n", schedule);

    return 0;
}
