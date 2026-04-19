#include<stdio.h>
#include<signal.h>
void isr(int n)
{
	printf("%d\n ",n);
}
int main()
{	
	int n;
	void (*ptr)(int);
	signal(2,SIG_IGN);
	signal(3,isr);
	signal(14,isr);
	printf("enter number\n");
	scanf("%d",&n);
	ptr=signal(n,SIG_DFL);
	//signal(n,ptr);
	if(ptr==SIG_DFL)
		printf("default\n");
	else if(ptr==SIG_IGN)
		printf("ignore\n");
	else
		printf("in isr\n");
}


