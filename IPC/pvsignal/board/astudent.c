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
    /*�����ź���*/
    semid = semget(key,1,IPC_CREAT);
    semctl(semid,0,SETVAL,1);

    printf("value is %d\n",(int)semctl(semid,0,GETVAL));
    /*1�����ļ�*/


    /*2����ȡ�ź���*/
    sops.sem_num = 0;
    sops.sem_op = -1;
    semop(semid,&sops,1);

    printf("value is %d\n",(int)semctl(semid,0,GETVAL));

    /*3��д������*/
    write(fd,"123456",6);

    /*4����Ϣ*/
    sleep(10);

    /*5������д������*/
    write(fd,"789",3);

    /*6���ͷ��ź���*/
    sops.sem_num = 0;
    sops.sem_op = 1;
    semop(semid,&sops,1);

    close(fd);
}
