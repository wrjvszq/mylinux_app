/*************************************************************************
  > �ļ���  : cpfile.c
  > ����    : @wrj
  > ����    : wrjvszq@163.com
  > ����ʱ��: Mon 24 Nov 2014 05:26:14 PM CST
  > ����˵����ʵ���ļ��Ŀ������� 
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
    /*1����Դ�ļ���Ŀ���ļ�*/
    fd_s = open(argv[1],O_RDONLY);
    fd_m = open(argv[2],O_RDWR|O_CREAT,0666);
    if((fd_s < 0)||(fd_m < 0))
    {
        printf("���ļ�����\n");
    }else
    {
        /*2����ȡԴ�ļ�*/
        while((count = read(fd_s,buff,512)) > 0)
        {
            /*3��д��Ŀ���ļ�*/
            write(fd_m,buff,count);
        }
        /*4���ر��ļ��ļ�*/
        close(fd_s);
        close(fd_m);

    }

}
