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
	fd1=open("fifo1",O_WRONLY);
	fd2=open("fifo2",O_RDONLY);
	printf("fd1=%d fd2=%d\n",fd1,fd2);
	if(fork()==0)
	{	while(1)
		{
			printf("write:");
			scanf("%s",str1);
			write(fd1,str1,strlen(str1)+1);
		}
	}
	else
	{	
	while(1)
		{
			read(fd2,str2,sizeof(str2));
			for(int i=0;str2[i];i++)
				str2[i]=str2[i]^32;
			printf("read:%s\n",str2);
		}
	
	}






	}
