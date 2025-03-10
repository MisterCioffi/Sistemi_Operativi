//PROCEDURE.C
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <time.h>

#include "procedure.h"
#include "semafori.h"


void produttore(struct prodcons * p, int ds_sem) {
    
    //printf("produttore è fermo prima di wait\n");
    Wait_Sem(ds_sem, SPAZIO_DISPONIBILE); //INIZIO COOPERAZIONE TRA PRODUTTORE E CONSUMATORI
    //printf("produttore si sblocca dopo la wait\n");
    
    
    Wait_Sem(ds_sem, MUTEX_P); //INIZIO COMPTEZIONE TRA PRODUTTORE E PRODUTTORI
    
    sleep(2);
    
    // genera valore tra 0 e 99
    p->buffer[p->testa] = rand() % 100;
    
    printf("Il valore prodotto = %d\n", p->buffer[p->testa]);
    
    p->testa = (p->testa+1) % DIM_BUFFER;
    
    
    Signal_Sem(ds_sem, MUTEX_P); //FINE COMPTEZIONE TRA PRODUTTORE E PRODUTTORI
    
    Signal_Sem(ds_sem, MESSAGGIO_DISPONIBILE); //FINE COOPERAZIONE TRA PRODUTTORE E CONSUMATORI
}

void consumatore(struct prodcons * p, int ds_sem) {
    
    //printf("consumatore è fermo prima di wait\n");
    Wait_Sem(ds_sem, MESSAGGIO_DISPONIBILE); //INIZIO COOPERAZIONE TRA PRODUTTORE E CONSUMATORI
    //printf("consumatore si sblocca dopo la wait\n");
    
    Wait_Sem(ds_sem, MUTEX_C); //INIZIO COMPTEZIONE TRA CONSUMATORI E CONSUMATORI
    
    
    sleep(2);
    
    printf("Il valore consumato = %d\n", p->buffer[p->coda]);
    
    p->coda = (p->coda + 1) % DIM_BUFFER;
    
    
    Signal_Sem(ds_sem, MUTEX_C); //FINE COMPTEZIONE TRA CONSUMATORI E CONSUMATORI
    
    Signal_Sem(ds_sem, SPAZIO_DISPONIBILE); //FINE COOPERAZIONE TRA PRODUTTORE E CONSUMATORI
}
