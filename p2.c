#include<stdio.h>
#include<signal.h>
void isr(int n)
{
	printf("%d\n ",n);
}
int main()
{	
	int n;
	struct sigaction v;
	void (*ptr)(int);
	signal(2,SIG_IGN);
	signal(3,isr);
	signal(14,isr);
	printf("enter number\n");
	scanf("%d",&n);
	sigaction(n,0,&v);
	//signal(n,ptr);
	if(v.sa_handler==SIG_DFL)
		printf("default\n");
	else if(v.sa_handler==SIG_IGN)
		printf("ignore\n");
	else
		printf("in isr\n");
}


