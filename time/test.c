/*************************************************************************
  > 文件名  : test.c
  > 作者    : @wrj
  > 邮箱    : wrjvszq@163.com
  > 创建时间: Tue 25 Nov 2014 07:24:21 PM CST
  > 功能说明： 
 ************************************************************************/

#include<stdio.h>
#include<time.h>

void main(void)
{
    time_t my_time;
    struct tm *my_tm = NULL;
    struct tm *pc_tm = NULL;
    char * str = NULL;

    my_time = time(NULL);
    pc_tm = localtime(&my_time);
    //my_tm = gmtime(&my_time);
    str = asctime(pc_tm);
    printf("%s\n",str);

    //printf("now is %d:%d\n",my_tm->tm_hour,my_tm->tm_min);
    printf("now is %d:%d\n",pc_tm->tm_hour,pc_tm->tm_min);
    printf("%d \n",my_time);

}
