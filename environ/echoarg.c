#include "apue.h"

int
main(int argc, char *argv[])
{
	int i = 0;
	/* 打印所有在命令行中的参数 */
	for (; i < argc; i++)
		printf("avg[%d] : %s \n", i , argv[i]);
	
	exit(0);
}
