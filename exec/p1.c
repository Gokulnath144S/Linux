#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
int main()
{
	printf("Hi\n");
	system("ls");
	printf("pid:%d ppid: %d\n",getpid(),getppid());
	sleep(3);
	//execl("/ls","ls","-l",NULL);
	printf("hello\n");
}
