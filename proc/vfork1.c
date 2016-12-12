#include "apue.h"

int globvar = 6;

int
main(int argc, char const *argv[])
{
	int var = 88;
	pid_t pid;

	printf("before vfork\n");

	if ((pid = vfork()) < 0)
	{
		err_sys("vfork error");
	}
	else if (pid == 0) /* child */
	{
		globvar++;
		var++;
		// before exit child has the same address space 
		// with parent.
		_exit(0);
	}

	// we can see the parent will change the value because child and parent 
	// share the same address space
	printf("pid = %ld, glob = %d, var = %d\n", (long)getpid(), globvar, var);

	exit(0);
}