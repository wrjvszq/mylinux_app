/*************************************************************************
  > �ļ���  : creat.c
  > ����    : @wrj
  > ����    : wrjvszq@163.com
  > ����ʱ��: Sun 23 Nov 2014 05:09:52 PM CST
  > ����˵���� 
 ************************************************************************/

#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

void main(void)
{
    int fd = -1;

    fd = creat("./3.c",0666);

    if(fd < 0)
    {
        printf("error \n");
    }
}

