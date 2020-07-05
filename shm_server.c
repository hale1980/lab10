#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

int main (int argc, char ** argv) {
    int shmid;
    char c ;
    char * shm , *s;

    key_t key = ftok("/tmp/shm", 'a');

    shmid = shmget(key, 128 , IPC_CREAT| 0666) ;
    shm = ( int*) shmat( shmid ,NULL, 0 ) ;
    s = shm;
    for(c='a'; c <= 'z'; c++) {
        *s++ = c;
    } 
    *s = NULL;

    while (*shm != '*')
    {
        sleep(1);
    }
    shmctl ( shmid , IPC_RMID, (struct shmid_ds*)0 ) ;

    return 0;
    
}
