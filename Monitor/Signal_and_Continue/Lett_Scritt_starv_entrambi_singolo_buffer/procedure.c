#include "procedure.h"

#include <unistd.h>
#include <stdio.h>


int Leggi(struct LettScritt * ls) {

	int valore;

	enter_monitor( &(ls->m) );

	printf("Lettura - ingresso monitor\n");

//ACHTUNG --> abbiamo un while perché deve verificare la condizione ripetutamente
while( ls->numero_scrittori > 0 ) { // perché è un signal_and_continue

		printf("Sospensione - lettura\n");
        // Nel caso di signal_and_continue, sarò segnalato da uno scrittore prima
        // o poi, quindi posso lasciare il monitor senza segnalare nessun lettore
		wait_condition( &(ls->m), VARCOND_LETTORI );
		printf("Riattivazione - lettura\n");
	}

	ls->numero_lettori++;

	printf("Numero lettori ++ : %d\n", ls->numero_lettori);

//ACHTUNG --> Questa volta non deve segnalare lui gli altri lettori

	leave_monitor( &(ls->m) );


// ACHTUNG --> lettura fuori la zona critica come nel caso signal_and_wait
	// ...operazione lenta...
	sleep(2);
	valore = ls->buffer;

	printf("Lettura - valore [%d]\n", valore);



	enter_monitor( &(ls->m) );

	ls->numero_lettori--;

	printf("Numero lettori -- : %d\n", ls->numero_lettori);


	if( ls->numero_lettori == 0 ) {

		printf("Lettura - signal su scrittori\n");

		signal_condition( &(ls->m), VARCOND_SCRITTORI );
	}

	leave_monitor( &(ls->m) );

	printf("Lettura - uscita monitor\n");

	return valore;

}


void Scrivi(struct LettScritt * ls, int valore) {

	enter_monitor( &(ls->m) );

	printf("Scrittura - ingresso monitor\n");

	while (ls->numero_lettori > 0 || ls->numero_scrittori > 0) {

		printf("Scrittura - sospensione\n");
		wait_condition( &(ls->m), VARCOND_SCRITTORI );
		printf("Scrittura - riattivazione\n");
	}

	ls->numero_scrittori++;

	printf("Numero scrittori ++ : %d\n", ls->numero_scrittori);

	leave_monitor( &(ls->m) );// esco per dare la possibilità ad un altro processo di mettersi in attesa sulla variabile condition


	// ...operazione lenta...
	sleep(1);
	ls->buffer = valore;

	printf("Scrittura - valore [%d]\n", valore);



	enter_monitor( &(ls->m) );

	ls->numero_scrittori--;

	printf("Numero scrittori -- : %d\n", ls->numero_scrittori);


	if( queue_condition( &(ls->m), VARCOND_SCRITTORI ) ) {

		printf("Scrittura - signal su scrittori\n");

		signal_condition( &(ls->m), VARCOND_SCRITTORI );

	} else {

		/*
		 *  NOTA: questa soluzione è applicabile solo al caso di
		 *  monitor con semantica signal-and-continue (signal all).
         *  Questo perchè lo scrittore dopo aver fatto la prima signal
         *  CONTINUA la sua esecuzione!
		 */
		printf("Scrittura - signal all su lettori\n");
		
		signal_all( &(ls->m), VARCOND_LETTORI ); // sveglio tutti i lettori e aspettano che io finisca 
	 }
	

	leave_monitor( &(ls->m) );

	printf("Scrittura - uscita monitor\n");
}

