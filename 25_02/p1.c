#include<stdio.h>
#include<unistd.h>
#define pf printf
int main()
{
	pf("process under executiin\n");
	pf("id : %d\n",getpid());
	while(1);


}
