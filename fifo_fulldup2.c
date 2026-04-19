#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
int main()
{
	int fd1,fd2;
	char str1[20],str2[20];
	mkfifo("fifo1",0664);
	mkfifo("fifo2",0664);
	fd1=open("fifo1",O_RDONLY);
	fd2=open("fifo2",O_WRONLY);
	printf("fd1=%d fd2=%d\n",fd1,fd2);
	if(fork()==0)
	{	while(1)
		{
			read(fd1,str1,sizeof(str1));
			printf("read:%s\n",str1);
		}
	}
	else
	{	
	while(1)
		{
			printf("write:");
			scanf("%s",str2);
			write(fd2,str2,strlen(str2)+1);
		}

	}
}
