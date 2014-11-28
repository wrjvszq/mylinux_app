/*************************************************************************
  > 文件名  : bstudent.c
  > 作者    : @wrj
  > 邮箱    : wrjvszq@163.com
  > 创建时间: Fri 28 Nov 2014 07:28:10 PM CST
  > 功能说明： 
 ************************************************************************/

#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main(void)
{
    int fd = 0;

    fd = open("./board.txt",O_RDWR|O_APPEND);

    write(fd,"qwer",4);

    close(fd);
}
