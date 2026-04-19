#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/shm.h>
struct shm{
	int flag1;
	char a[50];
	int flag2;
	char b[50];
};
int main()
{
	int id;
	struct shm*p;
	char buf[50];
	id=shmget(10,sizeof(struct shm),IPC_CREAT|0664);
	if(id<0)
	{
		perror("shmget");
		return 0;
	}
	p=shmat(id,0,0);
	//p->flag1=0;
	//p->flag2=0;
	while(1)
	{
		if(p->flag1==1)
		{
			printf("receive:%s\n",p->a);
			p->flag1=0;
		}
		if(p->flag2==0)
		{
			printf("write:");
			scanf(" %[^\n]",buf);
			strcpy(p->b,buf);
			p->flag2=1;
		}
	}
	shmdt(p);
}

