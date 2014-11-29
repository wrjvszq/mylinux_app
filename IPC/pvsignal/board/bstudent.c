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
#include<sys/ipc.h>
#include<sys/sem.h>

int main(void)
{
    int fd = 0;
    int semid = 0;
    key_t key;
    struct sembuf sops;
    int ret;


    key = ftok("/home",1);

    fd = open("./board.txt",O_RDWR|O_APPEND);
 
    semid = semget(key,1,IPC_CREAT);

    printf("value is %d\n",(int)semctl(semid,0,GETVAL));

    sops.sem_num = 0;
    sops.sem_op = -1;
    sops.sem_flg = SEM_UNDO;
    semop(semid,&sops,1);

    printf("the value is %d\n",(int)semctl(semid,0,GETVAL));


    write(fd,"qwer",4);

    sops.sem_num = 0;
    sops.sem_op = 1;
    semop(semid,&sops,1);

    close(fd);
}
