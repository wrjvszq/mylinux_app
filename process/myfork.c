/*************************************************************************
  > �ļ���  : myfork.c
  > ����    : @wrj
  > ����    : wrjvszq@163.com
  > ����ʱ��: Wed 26 Nov 2014 07:41:02 PM CST
  > ����˵���� 
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

void main(void)
{
    pid_t pid;
    pid = fork();

    if(pid > 0)
    {
        wait(NULL);
        printf("this is father\n");
        exit(0);
    }else
    {
        execl("/bin/ls","ls","/home/wrj/",NULL);
        printf("this is child\n");
        exit(0);
    }
}
