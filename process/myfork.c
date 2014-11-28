/*************************************************************************
  > 文件名  : myfork.c
  > 作者    : @wrj
  > 邮箱    : wrjvszq@163.com
  > 创建时间: Wed 26 Nov 2014 07:41:02 PM CST
  > 功能说明： 
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
