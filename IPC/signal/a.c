/*************************************************************************
  > �ļ���  : a.c
  > ����    : @wrj
  > ����    : wrjvszq@163.com
  > ����ʱ��: Thu 27 Nov 2014 09:47:58 PM CST
  > ����˵�����źŵķ��ͽ��� 
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
