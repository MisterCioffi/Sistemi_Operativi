# LETTORI E SCRITTORI CON STARVATION PER ENTRAMBI 🚶‍♂️✍️

Con questo sistema, possono risentire di starvation sia i lettori che gli scrittori, infatti se  un numero elevato di lettori accede costantemente alla risorsa, o se gli scrittori sono troppo frequenti, potrebbero verificarsi situazioni di starvation per uno dei due gruppi. 

In questa soluzione vengono utilizzati **4 semafori**, tutti inizializzati a 1:

- **MUTEXL**: Semaforo per gestire l'accesso alla variabile `NUM_LETTORI` in mutua esclusione da parte dei lettori.
- **MUTEXS**: Semaforo per gestire l'accesso alla variabile `NUM_SCRITTORI` in mutua esclusione da parte degli scrittori.
- **MUTEX**: Semaforo per gestire l'accesso in mutua esclusione alla risorsa condivisa da parte degli scrittori.
- **SYNCH**: Semaforo per garantire la mutua esclusione tra i processi lettori e scrittori.

### DESCRIZIONE DELLA SOLUZIONE

- **NUM_LETTORI**: Variabile condivisa che tiene traccia del numero di lettori attivi (inizializzata a 0).
- **NUM_SCRITTORI**: Variabile condivisa che tiene traccia del numero di scrittori attivi (inizializzata a 0).

### COMPORTAMENTO IN BREVE

1. **Lettori**: I lettori incrementano `NUM_LETTORI` per segnalare che stanno leggendo. L'accesso a `NUM_LETTORI` è gestito in mutua esclusione(tra lettori) tramite il semaforo `MUTEXL`.
2. **Scrittori**: Gli scrittori incrementano `NUM_SCRITTORI` per segnalare che stanno scrivendo. L'accesso alla variabile `NUM_SCRITTORI` è gestito in mutua esclusione(tra scrittori) tramite il semaforo `MUTEXS`. Inoltre, l'accesso alla risorsa condivisa è protetto dal semaforo `MUTEX`.
3. **SYNCH**: Garantisce la mutua esclusione tra lettori e scrittori, impedendo che entrambi possano accedere alla risorsa contemporaneamente.
