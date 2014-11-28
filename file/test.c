/*************************************************************************
  > 文件名  : test.c
  > 作者    : @wrj
  > 邮箱    : wrjvszq@163.com
  > 创建时间: Sun 23 Nov 2014 04:50:33 PM CST
  > 功能说明：练习open等文件操作函数 
 ************************************************************************/

#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

void main(void)
{
    int fd1 = -1,fd2 = -1;
    char buf[10];
    char buf1[10];

    fd1 = open("/home/wrj/my_linux/app/file/2.c",O_RDWR|O_CREAT,0666);

    fd2 = open("/home/wrj/my_linux/app/file/1.c",O_RDWR|O_CREAT,0666);
    if(fd1 < 0)
    {
        printf("error \n");
    }

    read(fd1,buf,5);
    buf[5] = '\0';

    write(fd2,buf,5);

    if(0 == close(fd2))
    {
        printf("close success\n");
    }
    fd2 = open("/home/wrj/my_linux/app/file/1.c",O_RDWR|O_CREAT,0666);
    read(fd2,buf1,5);

    printf("  %s \n",buf1);

    if(0 == close(fd1))
    {
        printf("close success\n");
    }

    if(0 == close(fd2))
    {
        printf("close success\n");
    }
}

