#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
	if(fork()==0)
	{
		execl("/bin/ls","ls","-l",NULL);
		printf("in child process\n");
		while(1);
	}
	else
	{
		//system("pwd");
		execl("/bin/pwd","pwd",NULL);
		printf("in parent process\n");
		while(1);
	}
}
