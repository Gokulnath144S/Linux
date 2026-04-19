#include<stdio.h>
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
int main()
{		
	if(fork()==0)
	{	
		int id=msgget(2,IPC_CREAT|0664);
		printf("msgid %d\n",id);
		struct msgbuf v;
		v.mtype=2;
		while(1)
		{
			printf("write:");
			scanf(" %[^\n]",v.mtext);
			msgsnd(id,&v,strlen(v.mtext)+1,0);
		}
	}
	else
	{
		int id1=msgget(3,IPC_CREAT|0664);
		printf("msgid %d\n",id1);
		struct msgbuf v;
		//v.mtype=2;
		while(1)
		{	
			msgrcv(id1,&v,sizeof(v.mtext),2,0);
			printf("read:%s\n",v.mtext);
		}
	}
}

