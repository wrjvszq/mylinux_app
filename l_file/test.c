/*************************************************************************
  > �ļ���  : test.c
  > ����    : @wrj
  > ����    : wrjvszq@163.com
  > ����ʱ��: Mon 24 Nov 2014 06:54:12 PM CST
  > ����˵���� 
 ************************************************************************/

#include<stdio.h>

void main(void)
{
    FILE * fp;
    char buf[20];

    fp = fopen("/home/wrj/my_linux/app/l_file/1.c","r+");

    fseek(fp,0,SEEK_END);
    fwrite("123456",1,6,fp);
    //fread(buf,1,10,fp);
    //buf[10] = '\0';
    //printf("data is :%s\n",buf);

    fclose(fp);
}
