/*************************************************************************
  > 文件名  : b.c
  > 作者    : @wrj
  > 邮箱    : wrjvszq@163.com
  > 创建时间: Thu 27 Nov 2014 09:51:29 PM CST
  > 功能说明： 
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
