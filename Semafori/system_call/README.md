# Gestione dei Semafori in C

## CREAZIONE SEMAFORO

```c
int semget( key_t key, int numero_semafori, int semflag);
```
>La semget definisce un array di semafori. Infatti, è possibile specificare quanti semafori vogliamo andare a istanziare.
Questo vuol dire che per un array di semafori, abbiamo un unico descrittore → per modificare tutti i semafori agiamo su quell’identificatore.
