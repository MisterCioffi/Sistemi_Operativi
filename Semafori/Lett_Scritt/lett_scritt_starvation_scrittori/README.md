# Gestione Lettori e Scrittori con Semafori 🚶‍♂️📚

Per la gestione di questo problema viene utilizzata una variabile condivisa `NUM_LETTORI`, che viene usata per contare il numero di lettori che contemporaneamente accedono alla risorsa.
Solo quando NUM_LETTORI = 0, gli scrittori possono accedere (uno alla volta) alla risorsa.

⚠️ **Attenzione!** Poiché a questa variabile possono accedere più lettori deve essere protetta.

### DESCRIZIONE DELLA SOLUZIONE

- **NUM_LETTORI**: Variabile condivisa che conta il numero di lettori attivi (inizializzata a 0).
- **MUTEXL**: Semaforo utilizzato per l'accesso mutua esclusione alla variabile `NUM_LETTORI` (inizializzato a 1).
- **SYNCH**: Semaforo per la mutua esclusione tra lettori e scrittori e tra scrittori stessi (inizializzato a 1).

### COMPORTAMENTO IN BREVE

1. I lettori incrementano `NUM_LETTORI` per segnalare che stanno leggendo.
2. L'accesso alla variabile `NUM_LETTORI` è gestita in mutua esclusione attraverso un semaforo MUTEXL(valore iniziale pari a 1).
3. Gli scrittori possono accedere alla risorsa solo quando `NUM_LETTORI == 0`, quindi aspettano che non ci siano lettori. Non appena tutti i lettori hanno finito, lo scrittore può entrare.
4. Solo uno scrittore può accedere alla risorsa alla volta, grazie al semaforo SYNCH, che gestisce l'accesso esclusivo tra scrittori.


