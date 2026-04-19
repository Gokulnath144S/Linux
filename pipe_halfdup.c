#include<stdio.h>
#include<unistd.h>
#include<string.h>
int main()
{
	int fd[2];
	int i;
	pipe(fd);
	if(fork()==0)
	{
		char a[20];
	while(1)
		{
			printf("enter the data in child\n");
			scanf(" %[^\n]",a);
			write(fd[1],a,strlen(a)+1);
			sleep(3);
			printf("child process wait for recieve\n");
			read(fd[0],a,sizeof(a));
			printf("%s\n",a);
		}
	}
	else
	{
		char b[20];
		while(1)
		{
			printf("reading the data recieved\n");
			read(fd[0],b,sizeof(b));
			printf("%s\n",b);
			for(i=0;b[i];i++)
			{	
				if(b[i]!=' ')
					b[i]=b[i]^32;
			}
			printf("%s\n",b);
			printf("enter the data in parent\n");
			scanf(" %[^\n]",b);
			write(fd[1],b,strlen(b)+1);
			sleep(2);
		}
	}
}
