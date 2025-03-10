void produttore(int * p, int ds_sem) {

	printf("produttore è fermo prima di wait\n");
	Wait_Sem(ds_sem, SPAZIO_DISPONIBILE);
	//Fa una wait su spazio disponibile
	//esce da questa wait può produrre
	printf("produttore si sblocca dopo la wait\n");


	sleep(2);

	*p = rand() % 100;

	printf("Il valore prodotto = %d\n", *p);


	Signal_Sem(ds_sem, MESSAGGIO_DISPONIBILE);
	//sveglia un processo consumatore informandolo ci sia un messaggio
}
