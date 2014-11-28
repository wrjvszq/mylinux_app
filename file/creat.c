/*************************************************************************
  > 文件名  : creat.c
  > 作者    : @wrj
  > 邮箱    : wrjvszq@163.com
  > 创建时间: Sun 23 Nov 2014 05:09:52 PM CST
  > 功能说明： 
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

