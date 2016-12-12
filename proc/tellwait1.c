#include "apue.h"

static void charatatime(char *);

// this program is not good to handle the race condition
// we can see the tellwait2.c address problem
int
main(int argc, char const *argv[])
{
	
	pid_t pid;
	char *str;

	if ((pid = fork()) < 0)
	{
		err_sys("fork error");
	}
	else if (pid == 0) // child
	{
		str = "output from child\n";
	}
	else
	{
		str = "output from parent\n";
	}

	charatatime(str);
	return 0;
}

static void
charatatime(char *str)
{
	char *ptr;
	int c;

	setbuf(stdout, NULL);

	for (ptr = str; (c = *ptr++) != 0;)
	{
		putc(c, stdout);
	}

}