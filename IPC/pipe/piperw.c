/*************************************************************************
  > 文件名  : piperw.c
  > 作者    : @wrj
  > 邮箱    : wrjvszq@163.com
  > 创建时间: Wed 26 Nov 2014 10:15:52 PM CST
  > 功能说明： 
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

void main()
{
    pid_t pid;
    int fd[2];
    char buf[10];

    pipe(fd);
    pid = fork();

    if(pid > 0)
    {
        /*父进程向管道写入数据*/
        write(fd[1],"12345",6);
        wait();
        close(fd[1]);

        exit(0);
    }else
    {
        /*子进程从管道读取数据*/
        read(fd[0],buf,6);
        printf("we read %s\n",buf);
        close(fd[0]);
        exit(0);
    }
}
