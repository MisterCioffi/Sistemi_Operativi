Questa volta abbiamo un problema di competizione perché tutti i consumatori vogliono accedere alla variabile coda mentre tutti i produttori vogliono accedere alla variabile testa.

### GESTIONE COMPTEZIONE

Nell’ipotesi in cui vi siano più produttori e più consumatori che accedono allo stesso buffer, le operazioni di deposito e prelievo devono essere eseguite rispettivamente in mutua esclusione, ed essere quindi programmate come sezioni critiche.

A tal fine, bisogna introdurre due nuovi semafori:

- ***MUTEX_C*** per le operazioni di consumo → disciplina l’accesso alle variabili condivise.
- ***MUTEX_P*** per le operazioni di produzione

ACHTUNG → Entrambi inizializzati a 1

### <span style="color:red">GESTIONE COOPERAZIONE</span>

Per la sincronizzazione dei processi sono stati utilizzati due semafori,

***SPAZIO_DISP*** → indica la presenza di spazio disponibile in coda per la produzione di

un messaggio( in questo caso lo spazio disponibile sarà DIM(dimensione della coda))

***NUM_MESS*** → indica il numero di messaggi presenti in coda (Inizialmente sarà zero).


### CODA

La coda è implementata mediante i seguenti campi:

- ***buffer[DIM]*** → array di elementi di tipo msg (tipo del messaggio depositato dai produttori) contenente i valori prodotti
- ***testa-*** tipo intero. Indica la posizione del primo buffer libero in testa, buffer[testa], ossia il primo buffer disponibile per la memorizzazione di un messaggio. L'elemento prodotto più recentemente è alla posizione buffer[testa-1](lo usa il produttore)
- ***coda***– tipo intero. Indica la posizione dell’elemento prodotto meno recentemente, buffer[coda], da accedere alla prossima consumazione(lo usa il consumatore)

ACHTUNG → Anche le variabili testa e coda devono essere condivise!
```c 
struct prodcons {
          int buffer[DIM_BUFFER];
          int testa;
          int coda; };
```
