#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdlib.h> // Added for exit()

int main() {
    key_t key = ftok("shmfile", 65);
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    char *str = (char *)shmat(shmid, NULL, 0);
    printf("Write data: ");
    fgets(str, 1024, stdin);
    printf("Data written to memory: %s\n", str);
    /*if (shmdt(str) == -1) {
        perror("shmdt");
        exit(EXIT_FAILURE);
    }*/
    return 0;
}

