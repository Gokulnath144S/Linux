#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
	printf("a.out process under execution\n");
	sleep(3);
	printf("pid:%d ppid:%d\n",getpid(),getppid());
	sleep(3);
	printf("going to replace\n");
	sleep(3);
	execl("./p1","p1",NULL);
	printf("after execl fun\n");
	printf("process termination\n");
}
