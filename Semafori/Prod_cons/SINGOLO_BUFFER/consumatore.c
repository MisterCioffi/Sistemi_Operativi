void consumatore(int * p, int ds_sem) {

	printf("consumatore è fermo prima di wait\n");
	Wait_Sem(ds_sem, MESSAGGIO_DISPONIBILE);
	//aspetta che ci sia un messagggio disponibile
	printf("consumatore si sblocca dopo la wait\n");


	sleep(2);
	printf("Il valore consumato = %d\n", *p);


	Signal_Sem(ds_sem, SPAZIO_DISPONIBILE);
	//una volta consumato risveglia un processo produttore informandolo che c'è spazio
}
