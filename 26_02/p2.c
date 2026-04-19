#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#define pf printf
void isr1(int n)
{
	pf("in isr1\n");
	//pf("n=%d\n",n);
	signal(2,SIG_DFL);
	signal(3,SIG_DFL);
	pf("isr completed\n");


}
/*void isr2(int n)
{
	pf("in isr2\n");
	pf("n=%d\n",n);
	signal(n,SIG_IGN);
	pf("isr completed\n");
}*/
int main()
{
	pf("process under exexutoon\n");
	signal(2,SIG_IGN);
	signal(3,SIG_IGN);
	signal(SIGALRM,isr1);
	alarm(10);
	pf("after completetion\n");
	while(1);



}
