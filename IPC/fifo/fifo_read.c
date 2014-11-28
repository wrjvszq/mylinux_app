/*************************************************************************
  > 文件名  : fifo_read.c
  > 作者    : @wrj
  > 邮箱    : wrjvszq@163.com
  > 创建时间: Thu 27 Nov 2014 01:39:54 PM CST
  > 功能说明： 
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main(void)
{
    int fd = 0;
    char buf[20];

    fd = open("/tmp/myfifo",O_RDONLY);
    read(fd,buf,11);
    printf("the data is:%s\n",buf);
    close(fd);
    unlink("/tmp/myfifo");
}
