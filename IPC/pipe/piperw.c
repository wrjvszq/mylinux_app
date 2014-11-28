/*************************************************************************
  > �ļ���  : piperw.c
  > ����    : @wrj
  > ����    : wrjvszq@163.com
  > ����ʱ��: Wed 26 Nov 2014 10:15:52 PM CST
  > ����˵���� 
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
        /*��������ܵ�д������*/
        write(fd[1],"12345",6);
        wait();
        close(fd[1]);

        exit(0);
    }else
    {
        /*�ӽ��̴ӹܵ���ȡ����*/
        read(fd[0],buf,6);
        printf("we read %s\n",buf);
        close(fd[0]);
        exit(0);
    }
}
