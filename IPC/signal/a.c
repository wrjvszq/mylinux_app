/*************************************************************************
  > 文件名  : a.c
  > 作者    : @wrj
  > 邮箱    : wrjvszq@163.com
  > 创建时间: Thu 27 Nov 2014 09:47:58 PM CST
  > 功能说明：信号的发送进程 
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<sys/signal.h>

int main(int argc,int argv[])
{
    pid_t pid;
    
    pid = atoi(argv[1]);

    kill(pid,SIGINT);

}
