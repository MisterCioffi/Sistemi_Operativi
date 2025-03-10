# SEMAFORI

Il semaforo è una struttura dati fornita dal kernel che incapsula un contatore intero `s`.

Due o più processi competono o cooperano attraverso l’uso dei segnali, in modo tale che un processo può essere forzato a sospendersi in un determinato punto finché non riceve un segnale.

- I processi condividono una istanza di semaforo `s`.
- Usando la variabile semaforo, un processo può inviare un segnale sul semaforo `s` tramite una procedura `signal(s)`.
- Per ricevere un segnale sul semaforo si esegue la primitiva `wait(s)`: se il segnale non è stato ancora ricevuto, il processo si sospende.

## Struttura del Semaforo

Un tipo di dato astratto `s` incapsula:

- Una variabile di tipo intero (`s.value`).
- Una coda (`s.queue`), per tenere traccia dei processi che si sono sospesi con `wait(s)`, nell’attesa di un `signal(s)`.

## Operazioni Definite

### 1. Inizializzazione
La variabile viene inizializzata ad un valore non negativo. Il valore iniziale è scelto dal programmatore in base al tipo di interazione che si vuole realizzare (ad esempio, **mutua esclusione** o **cooperazione**).

### 2. Operazione di `wait`
L'operazione di `wait(s)` ha l’effetto di decrementare il valore del semaforo. Se il valore del semaforo diventa negativo, il processo viene inserito nella coda dei processi sospesi e il processo stesso viene sospeso finché non riceve un segnale.

### 3. Operazione di `signal`
L'operazione di `signal(s)` ha l’effetto di incrementare il valore del semaforo. Se il valore del semaforo diventa minore o uguale a zero (significa che c’è almeno un processo sospeso), viene "sbloccato" un processo che si era sospeso durante l’esecuzione della `wait`.

## Considerazioni

- **ATTENZIONE** → Le procedure di `wait` e `signal` eseguono in modo mutuamente esclusivo.
- **ATTENZIONE** → La coda dei processi sospesi viene gestita e schedulata dal sistema operativo.


Il semafoto è una struttura dati fornita dal kernel che incapsula un contatore intero s.
I semafori sono variabili speciali (sostanzialmente dei contatori) utilizzate per la cooperazione e la competizione tra processi. Due o più processi competono o cooperano attraverso l’uso di segnali, in modo tale che un processo può essere forzato a sospendersi in un determinato punto finché non riceve un segnale.





Sono definite le seguenti operazioni:

| WAIT, che ha l’effetto di decrementare il valore del semaforo. Se il valore del semaforo diventa negativo, inserisce il processo nella coda dei processi sospesi e il processo viene sospeso;                                                    | ![image]([https://github.com/MisterCioffi/Images/Immagine_wait_sem.jpeg](https://github.com/MisterCioffi/Sistemi_Operativi/blob/main/Images/Immagine_wait_sem.jpeg?raw=true))  |
|-----------------------------------------------------------|----------------------------------------------|

                
                                             

  - Inizializzazione della variabile ad un valore non negativo
    - Il valore iniziale è scelto dal programmatore in base al tipo di interazione che si vuole realizzare(mutua esclusione, cooperazione)

  - Operazione di wait, che ha l’effetto di decrementare il valore del semaforo.  Se il valore del semaforo diventa negativo, inserisce il processo nella coda dei processi sospesi e il processo viene sospeso;

  - L’operazione di signal che ha l’effetto di incrementare il valore del semaforo. 
    - Se il valore del semaforo diventa minore o uguale a zero(significa che c’è almeno un processo sospeso) viene “sbloccato” un     processo che si era sospeso durante l’esecuzione della wait;
