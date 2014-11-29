/*************************************************************************
  > �ļ���  : consume.c
  > ����    : @wrj
  > ����    : wrjvszq@163.com
  > ����ʱ��: Sat 29 Nov 2014 04:14:01 PM CST
  > ����˵���� 
 ************************************************************************/

#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/sem.h>
#include<sys/ipc.h>

int main(void)
{
    int semid = 0;
    key_t key;
    struct sembuf sops;

    key = ftok("/home",2);

    semid = semget(key,1,IPC_CREAT);
    sops.sem_num = 0;
    sops.sem_op = -1;
    sops.sem_flg = SEM_UNDO;
    printf("ret is %d\n",semop(semid,&sops,1));

    system("cp ./test.txt ./test/");
}
