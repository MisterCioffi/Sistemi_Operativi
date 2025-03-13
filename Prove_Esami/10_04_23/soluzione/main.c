#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <time.h>

#include "prodcons.h"


void produttore_1(MonitorPC * m)
{
	srand(getpid());

	for(int i=0; i<4; i++) {

		int valore = rand() % 10;

		/* TBD: chiamare il metodo di produzione tipo 1 */
		produci_tipo_1(m, valore);

		sleep(1);
	}

}


void produttore_2(MonitorPC * m)
{
    srand(getpid());

	for(int i=0; i<4; i++) {

		int valore = rand() % 10;

		/* TBD: chiamare il metodo di produzione tipo 2 */
		produci_tipo_2(m, valore);

		sleep(1);
	}

}


void consumatore_1(MonitorPC * m)
{

	for(int i=0; i<8; i++) {

		int valore;

		/* TBD: chiamare il metodo di consumazione tipo 1 */
		consuma_tipo_1(m, &valore);

		sleep(1);
	}

}


void consumatore_2(MonitorPC * m)
{
	for(int i=0; i<8; i++) {

		int valore;

		/* TBD: chiamare il metodo di consumazione tipo 1 */
		consuma_tipo_2(m, &valore);

		sleep(1);
	}
}

int main(int argc, char *argv[])
{

	pid_t pid;
	/* TBD: creare e inizializzare l'oggetto monitor (metodo "inizializza") */
    
    key_t chiaveshm=IPC_PRIVATE;
	int id_shm= shmget(chiaveshm, sizeof(MonitorPC), IPC_CREAT|0664);
	if(id_shm<0){
		perror("errore shm");
		exit(1);
		}
		
	MonitorPC* m= (MonitorPC*) shmat(id_shm, 0, 0);
	if((void*) m == (void*)-1){
		perror("errore shm");
		exit(1);
		}
		

		inizializza(m);

	for(int i=0; i<2; i++) {
  
		/* TBD: avviare 2 produttori di tipo 1 */
		pid=fork();
		if(pid==0){
			
			produttore_1(m);
			exit(0);
			
			}
	}

	for(int i=0; i<2; i++) {

		/* TBD: avviare 2 produttori di tipo 2 */
		pid=fork();
		if(pid==0){
			
			produttore_2(m);
			exit(0);
			
			}
	}

	/* TBD: avviare consumatore di tipo 1 */
	pid=fork();
		if(pid==0){
			
			consumatore_1(m);
			exit(0);
			
			}

	/* TBD: avviare consumatore di tipo 2 */
	pid=fork();
		if(pid==0){
			
			consumatore_2(m);
			exit(0);
			
			}



	for(int i=0; i<2; i++) {

		/* TBD: attendere terminazione produttori di tipo 1 */
		printf("figlio consumatori 1 terminato \n");
		wait(NULL);
	}


	for(int i=0; i<2; i++) {

		/* TBD: attendere terminazione produttori di tipo 2 */
		printf("figlio produttori 2 terminato \n");
		wait(NULL);
	}

	/* TBD: attendere terminazione consumatori di tipo 1 */
	printf("figlio consumatori 1 terminato \n");
	wait(NULL);

	/* TBD: attendere terminazione consumatori di tipo 2 */
	printf("figlio consumatori 2 terminato \n");
	wait(NULL);

	

	/* TBD: rimuovere l'oggetto monitor */
	rimuovi(m);
	shmctl(id_shm, IPC_RMID, 0);

}
