/*************************************************************************
  > �ļ���  : fifo_write.c
  > ����    : @wrj
  > ����    : wrjvszq@163.com
  > ����ʱ��: Thu 27 Nov 2014 01:35:45 PM CST
  > ����˵���� 
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(void)
{
    int fd = 0;
    mkfifo("/tmp/myfifo",0666);
    fd = open("/tmp/myfifo",O_WRONLY);

    write(fd,"hello fifo",11);
    close(fd);
}
