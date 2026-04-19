#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<string.h>
#include<sys/types.h>
#include<sys/msg.h>
struct msgbuf
{
	long mtype;
	char mtext[20];
};
int main(int argc,char**argv)
{
	int id=msgget(2,IPC_CREAT|0664);
	if(id<0)
	{
		perror("open");
		return 0;
	}
	printf("msgid %d\n",id);
	struct msgbuf v;
	//v.mtype=1;
	v.mtype=1;
	while(1)
	{
//	printf("\n");
	printf("write:");
	scanf(" %[^\n]",v.mtext);
	msgsnd(id,&v,strlen(v.mtext)+1,0);
	sleep(2);
	msgrcv(id,&v,sizeof(v.mtext),1,0);
//	printf("\n");
	printf("read:%s",v.mtext);
	}
}

