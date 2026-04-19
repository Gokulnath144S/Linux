#include<stdio.h>
#include<signal.h>
#define pf printf
void isr(int n)
{
	pf("in isr\n");
	pf("n=%d\n",n);
	signal(n,SIG_IGN);
	pf("isr completed\n");

}
int main()
{
	pf("process under executi9n\n");
	signal(2,isr);
	pf("after signal \n");
	while(1);

}
