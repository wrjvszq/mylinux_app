/*************************************************************************
  > 文件名  : cpfile.c
  > 作者    : @wrj
  > 邮箱    : wrjvszq@163.com
  > 创建时间: Mon 24 Nov 2014 05:26:14 PM CST
  > 功能说明：实现文件的拷贝工作 
 ************************************************************************/

#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc,char **argv)
{
    char buff[512];
    int fd_s = -1,fd_m = -1;
    int count = 0;
    /*1、打开源文件和目标文件*/
    fd_s = open(argv[1],O_RDONLY);
    fd_m = open(argv[2],O_RDWR|O_CREAT,0666);
    if((fd_s < 0)||(fd_m < 0))
    {
        printf("打开文件出错\n");
    }else
    {
        /*2、读取源文件*/
        while((count = read(fd_s,buff,512)) > 0)
        {
            /*3、写入目标文件*/
            write(fd_m,buff,count);
        }
        /*4、关闭文件文件*/
        close(fd_s);
        close(fd_m);

    }

}
