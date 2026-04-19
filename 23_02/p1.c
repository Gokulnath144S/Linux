#include<stdio.h>
#include<unistd.h>
int main()
{
	printf("process under execution\n");
	execl("/usr/cal","cal",NULL);
	perror("execlp");
	printf("after execl fun call\n");
	printf("process terminated\n");




}
