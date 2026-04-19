#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#define pf printf
int main(int argc,char* argv[])
{
	int ret;
	if(argc!=3)
	{
		pf("./a.out signal pid\n");
		return 0;

	}
	ret=kill(atoi(argv[2]),atoi(argv[1]));
	if(ret==-1)
	{
		perror("kill");
		return 0;
	}



}
