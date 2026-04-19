#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#define pf printf
void* thread1(void* p)
{
	pf("1st thread\n");
	pf("%s",(char*)p);
	pf("%u\n",pthread_self());
	pf("thread execution\n");
	while(1);
}
void* thread2(void* p)
{
	pf("2nd thread\n");
	pf("%s",(char*)p);
	pf("%u\n",pthread_self());
	pf("thread2 execution\n");
	while(1);
}
int main()
{
	pthread_t t1,t2;
	int*p;
	pf("main thread execution\n");
	sleep(5);
	pthread_create(&t1,0,thread1,"hello");
	sleep(5);
	pthread_create(&t2,0,thread2,"hell");
	pf("%u\n",pthread_self());
	while(1);
	{pf("main execution\n");}
	
}


