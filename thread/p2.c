#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>
void* thread1(void*p)
{
	int fd;
	char buf[20];
	fd=open("f1",O_WRONLY);
	if(fd<0)
	{
		perror("open");
		pthread_exit(0);
	}
	while(1)
	{
	scanf(" %s",buf);
	write(fd,buf,strlen(buf)+1);
	}
}
void * thread2(void*p)
{
	int fd;
	char buf[20];
	fd=open("f2",O_RDONLY);
	if(fd<0)
	{
		perror("open");
		pthread_exit(0);
	}
	while(1)
	{
		int ret=read(fd,buf,sizeof(buf));
		if(ret<=0)
		{
			perror("read");
			pthread_exit(0);
		}
		printf("%s",buf);
	}
}
int main()
{
	pthread_t t1,t2;
	mkfifo("f1",0644);
	mkfifo("f2",0644);
	pthread_create(&t1,0,thread1,0);
	pthread_create(&t2,0,thread2,0);
	while(1);
}
