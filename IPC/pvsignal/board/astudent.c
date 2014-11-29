/*************************************************************************
  > 文件名  : astudent.c
  > 作者    : @wrj
  > 邮箱    : wrjvszq@163.com
  > 创建时间: Fri 28 Nov 2014 07:23:42 PM CST
  > 功能说明： 
 ************************************************************************/

#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/sem.h>

int main(void)
{
    int fd = 0;
    key_t key;
    int semid = 0;
    struct sembuf sops;
    int ret = 0;

    key = ftok("/home",1);

    fd = open("./board.txt",O_RDWR|O_APPEND);
    /*创建信号量*/
    semid = semget(key,1,IPC_CREAT);
    semctl(semid,0,SETVAL,1);

    printf("value is %d\n",(int)semctl(semid,0,GETVAL));
    /*1、打开文件*/


    /*2、获取信号量*/
    sops.sem_num = 0;
    sops.sem_op = -1;
    semop(semid,&sops,1);

    printf("value is %d\n",(int)semctl(semid,0,GETVAL));

    /*3、写入数据*/
    write(fd,"123456",6);

    /*4、休息*/
    sleep(10);

    /*5、继续写入数据*/
    write(fd,"789",3);

    /*6、释放信号量*/
    sops.sem_num = 0;
    sops.sem_op = 1;
    semop(semid,&sops,1);

    close(fd);
}
