#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>

int c;   // global variable

void isr(int n)
{
    printf("starts\n");

    c--;

    if(c > 0)
    {
        alarm(c);   // trigger every 1 sec
    }
    else
    {
        printf("Done\n");
        exit(0);
    }
}

int main(int argc, char **argv)
{
    if(argc < 2)
    {
        printf("Usage: %s <seconds>\n", argv[0]);
        return 0;
    }

    c = atoi(argv[1]);

    signal(SIGALRM, isr);

    alarm(c);  // start after 1 second

    printf("alarm set for %d seconds\n", c);

    while(1);
       // pause();   // wait for signal

    //return 0;
}
