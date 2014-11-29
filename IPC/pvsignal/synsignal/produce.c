/*************************************************************************
  > 文件名  : produce.c
  > 作者    : @wrj
  > 邮箱    : wrjvszq@163.com
  > 创建时间: Sat 29 Nov 2014 04:13:35 PM CST
  > 功能说明： 
 ************************************************************************/

#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/sem.h>
#include<sys/ipc.h>

int main(void)
{
    int fd = 0;
    int semid = 0;
    key_t key;
    struct sembuf sops;

    key = ftok("/home",2);
    semid = semget(key,1,IPC_CREAT);
    semctl(semid,0,SETVAL,0);

    fd = open("./test.txt",O_RDWR|O_CREAT,0666);

    sleep(10);

    write(fd,"123456",7);

    sops.sem_num = 0;
    sops.sem_op = 1;
    sops.sem_flg = SEM_UNDO;
    semop(semid,&sops,1);

    close(fd);
}
