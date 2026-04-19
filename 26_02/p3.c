#include<stdio.h>
#include<signal.h>
#define pf printf
void isr(int n)
{
	pf("in isr\n");

}
int main()
{
	int n;
	void (*ptr)(int);
	signal(2,SIG_IGN);
	signal(3,isr);
	pf("enter number\n");
	scanf("%d",&n);
	ptr=signal(n,SIG_DFL);
	signal(n,ptr);
		pf("%p\n",(void*)(char*)ptr);
	if(ptr==SIG_DFL)
		pf("default\n");
	else if(ptr==SIG_IGN)
		pf("ignore\n");
	else
		pf("in isr\n");



}
