/*************************************************************************
  > �ļ���  : b.c
  > ����    : @wrj
  > ����    : wrjvszq@163.com
  > ����ʱ��: Thu 27 Nov 2014 09:51:29 PM CST
  > ����˵���� 
 ************************************************************************/

#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void my_func(int a)
{
    printf("i'm ok ha ha ha ``````\n");
}

int main(void)
{
    signal(SIGINT,my_func);
    pause();

}
