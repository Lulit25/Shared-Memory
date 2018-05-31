#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/types.h>
int main(){
int shmid;
int *num;
int key;
key = 1234;
	if((shmid = shmget(key, sizeof(int), IPC_CREAT | 0444)) < 0){
		printf("error creating shared memory segment\n");
		exit(1);
	}
	if ((num = shmat(shmid, NULL, 0)) == (int *) -1) {
		printf("error attaching shared memory segment\n");
		exit(1);
	}
	int x = *num;
	printf("The Random number sent from process1: %d ", x);
	shmdt(num);
	shmctl(shmid, IPC_RMID, 0);

}
