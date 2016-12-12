#include "apue.h"
#include <sys/wait.h>


int
main(int argc, char const *argv[])
{
	
	int status;

	if ((status = system("date")) < 0)
	{
		err_sys("system() error");
	}
	pr_exit(status);

	if ((status = system("nosuchcommand")) < 0)
	{
		err_sys("system() error");
	}
	pr_exit(status);

	if ((status = system("who; exit 44")) < 0)
	{
		err_sys("system() error");
	}
	pr_exit(status);


	return 0;
}

void
pr_exit(int status)
{
	if (WIFEXITED(status))
	{
		printf("normal termination, exit status = %d\n", WEXITSTATUS(status));
	}
	else if (WIFSIGNALED(status))
	{
		printf("abnormal termination, signal number = %d%s\n", WTERMSIG(status), 
		#ifdef	WCOREDUMP
			WCOREDUMP(status) ? " (core file generated)" : "");
		#else
			"");
		#endif
	}
	else if (WIFSTOPPED(status))
	{
		printf("child stopped, signal number = %d\n", WSTOPSIG(status));
	}
	
}