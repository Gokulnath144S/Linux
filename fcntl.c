#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
	struct flock v;
	char a[20]="iesembeddedengineer";
	int fd=open("temp",O_WRONLY|O_CREAT|O_APPEND,0644);
	v.l_type=F_WRLCK;
	v.l_whence=SEEK_SET;
	v.l_start=0;
	v.l_len=0;
	printf("process 1 starts\n");
	printf("%d\n",getpid());
	sleep(5);
	fcntl(fd,F_SETLKW,&v);
	printf("process 1 acquire lock\n");
	printf("writes data\n");
	for(int i=0;a[i];i++)
		write(fd,a+i,1);
	sleep(2); 
	
	printf("write complete\n");
	sleep(5);
	v.l_type=F_UNLCK;
	fcntl(fd,F_SETLKW,&v);
	printf("process lock release\n");
	sleep(2);
	printf("process 1terminated\n");
}
