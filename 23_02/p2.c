#include<stdio.h>
#include<unistd.h>
#define pf printf
int main()
{
	char *ap[]={"ls","-l",NULL};
	pf("a.out process startde executon\n");
	pf("before execv fun\n");
	execvp("/bin/ls",ap);
	pf("after execv\n");
}
