  #include<stdio.h>
  #include<unistd.h>
  #include<fcntl.h>
  #include<sys/sem.h>
  int main()
  {
          int fd = open("temp",O_CREAT|O_WRONLY|O_APPEND,0644);
          if(fd < 0)
          {
                  perror("open");
                  return 0;
          }
          char s[] = "Vector India";
          int i;
          int id = semget(5,3,IPC_CREAT|0664);
          if(id < 0) {
          perror("semget");
          return 0;
         }
        struct sembuf v[2] = { {0,0,0},{1,-1,SEM_UNDO} };
          printf("Process is in waiting state...\n");
          semop(id,v,2);  //binaray & counting semaphores testing
          printf("Process is allowed to access a resource\n");
          semctl(id,0,SETVAL,1);
          printf("Process-1 writing the data into a file\n");
          for(i=0;s[i];i++)
          {
                  write(fd,s+i,1);
                  sleep(1);
          }
          semctl(id,0,SETVAL,0);
          printf("Process-1 is completed to write the data in a file\n");
          close(fd);
          sleep(3);
          printf("Process-1 is terminated...\n");
 }

