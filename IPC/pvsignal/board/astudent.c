/*************************************************************************
  > �ļ���  : astudent.c
  > ����    : @wrj
  > ����    : wrjvszq@163.com
  > ����ʱ��: Fri 28 Nov 2014 07:23:42 PM CST
  > ����˵���� 
 ************************************************************************/

#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main(void)
{
    int fd = 0;

    fd = open("./board.txt",O_RDWR|O_APPEND);

    write(fd,"123456",6);

    sleep(10);

    write(fd,"789",3);

    close(fd);
}
