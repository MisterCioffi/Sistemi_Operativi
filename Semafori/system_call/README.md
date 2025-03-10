# Gestione dei Semafori in C

## CREAZIONE SEMAFORO

```c
int semget( key_t key, int numero_semafori, int semflag);
```
>La semget definisce un array di semafori. Infatti, è possibile specificare quanti semafori vogliamo andare a istanziare.
Questo vuol dire che per un array di semafori, abbiamo un unico descrittore → per modificare tutti i semafori agiamo su quell’identificatore.


## INIZIALIZZAZIONE SEMAFORO

``` c
int semctl(int semid, int numero_semaforo, int cmd);

```
> Nella semctl devo andare a specificare su quale semaforo voglio andare ad effettuare una modifica(l’array parte da 0)

## RIMOZIONE SEMAFORO

``` c
semctl(id_sem, num_sem, IPC_RMID);
``` 
