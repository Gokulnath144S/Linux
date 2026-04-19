#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
	struct flock v1,v2;
	int fd1,ret;
	char a[20]="abcdefghijkl";

	fd1=open("temp",O_WRONLY|O_CREAT|O_APPEND,0664);
	if(fd1<0)
	{
		perror("open");
		return 0;
	}
	v1.l_type=F_WRLCK;
	v1.l_whence=0;
	v1.l_start=0;
	v1.l_len=0;
	ret=fcntl(fd1,F_SETLK,&v1);
	if(ret==-1)
	{
		fcntl(fd1,F_GETLK,&v2);
		printf("%d\n",v2.l_pid);
	}
	else
	{	
		printf("file writing\n");
		for(int i=0;a[i];i++)
		{
			write(fd1,a+i,1);
			sleep(2);
		}
	}
	printf("process 3 completed\n");
	sleep(5);
	printf("success\n");
}

