#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main (int argc, char ** argv) {
    int shmid;
    char c ;
    char * shm , *s;

    key_t key = ftok("/tmp/shm", 'a');

    shmid = shmget(key, 128 , IPC_CREAT| 0666 ) ;
    shm = ( int*) shmat( shmid ,NULL, 0 ) ;
    for(s = shm; * s != NULL; s++) {
        printf("%c\n", *s);
    }

    *shm = '*';
    
    return 0;
    
}
