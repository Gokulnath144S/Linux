#include<stdio.h>
#include<sys/sem.h>
#include<stdlib.h>
int main(int argc,char **argv)
{
	int index,value,id=semget(5,3,IPC_CREAT|0664);
	if(id<0)
	{
		perror("semget");
		return 0;
	}
	index=atoi(argv[1]);

	int ret=semctl(id,index,GETVAL);
	printf("%d",ret);
}

