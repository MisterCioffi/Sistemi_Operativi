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

		produci_tipo_1(m, valore);

		sleep(1);
	}

}


void produttore_2(MonitorPC * m)
{
    srand(getpid());

	for(int i=0; i<4; i++) {

		int valore = rand() % 10;

		produci_tipo_2(m, valore);

		sleep(1);
	}

}


void consumatore_1(MonitorPC * m)
{

	for(int i=0; i<8; i++) {

		int valore;

		consuma_tipo_1(m, &valore);

		sleep(1);
	}

}


void consumatore_2(MonitorPC * m)
{
	for(int i=0; i<8; i++) {

		int valore;

		consuma_tipo_2(m, &valore);

		sleep(1);
	}
}

int main(int argc, char *argv[])
{

	/* TBD: creare e inizializzare l'oggetto monitor (metodo "inizializza") */
   

   int id_shm = shmget(IPC_PRIVATE, sizeof(MonitorPC), IPC_CREAT | 0664);
	MonitorPC *m = (MonitorPC*)shmat(id_shm, NULL, 0);
	inizializza(m);


	for(int i=0; i<2; i++) {

		pid_t pid = fork();
		if(pid== 0){
			produttore_1(m);
			exit(0);
		}
		/* TBD: avviare 2 produttori di tipo 1 */
	}

	for(int i=0; i<2; i++) {


		pid_t pid = fork();
		if(pid == 0){
			produttore_2(m);
		}
		/* TBD: avviare 2 produttori di tipo 2 */
	}

	/* TBD: avviare consumatore di tipo 1 */

	pid_t pidCons1 = fork();

	if(pidCons1 == 0){
		consumatore_1(m);
		exit(0);
	}

	/* TBD: avviare consumatore di tipo 2 */
	pid_t pidCons2 = fork();

	if(pidCons2 == 0){
		consumatore_2(m);
		exit(0);
	}


	for(int i=0; i<2; i++) {
		wait(NULL);
		/* TBD: attendere terminazione produttori di tipo 1 */
	}


	for(int i=0; i<2; i++) {
		wait(NULL);
		/* TBD: attendere terminazione produttori di tipo 2 */
	}

	/* TBD: attendere terminazione consumatori di tipo 1 */
	wait(NULL);
	/* TBD: attendere terminazione consumatori di tipo 2 */
	wait(NULL);
	

	/* TBD: rimuovere l'oggetto monitor */
	rimuovi(m);
	shmctl(id_shm, IPC_RMID, NULL);
}
