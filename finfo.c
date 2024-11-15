/*
* Name: Rose Zickefoose
 * Assignment: Lab 9- System Calls
 * Section: 111
 * File name: finfo.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char* argv[])
{
	struct stat st;
	if(argc != 2)
	{
		printf("Too %s arguments\n", argc > 2 ? "many" : "few");
	}
	else
	{
		if(stat(argv[1], &st) != 0)
		{
			perror("stat fail\n");
			exit(1);
		}
		mode_t mode = st.st_mode;
		printf("Mode: %o\n", mode);

		printf("User ID: %d\n", st.st_uid);
		printf("Size of File: %ld\n", st.st_size);
		printf("Last time modified: %ld\n", st.st_mtime);
	}
    return 0;
}