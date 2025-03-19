#include <sys/shm.h> 
#include <sys/ipc.h>  
#include <stdio.h> 
#include <stdlib.h> 

int main() {
    key_t shm_key = IPC_PRIVATE;
    int ds_shm = shmget(shm_key, sizeof(int), IPC_CREAT | 0664);

    if (ds_shm < 0) { 
        perror("errore shmget!");
        exit(1); 
    }

    int *p = (int*) shmat(ds_shm, NULL, 0);
    if (p == (void*)-1) { 
        perror("errore shmat!");
        exit(1); 
    }

    // parte di codice che utilizza la memoria condivisa

    shmctl(ds_shm, IPC_RMID, NULL);

    return 0;
}
