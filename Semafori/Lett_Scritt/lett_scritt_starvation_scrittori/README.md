# Gestione Lettori e Scrittori con Semafori 🚶‍♂️📚

Per la gestione di questo problema viene utilizzata una variabile condivisa `NUM_LETTORI`, che viene usata per contare il numero di lettori che contemporaneamente accedono alla risorsa.
Solo quando NUM_LETTORI = 0, gli scrittori possono accedere (uno alla volta) alla risorsa.

⚠️ **Attenzione!** Poiché a questa variabile possono accedere più lettori deve essere protetta.

### Descrizione della Soluzione

- **NUM_LETTORI**: Variabile condivisa che conta il numero di lettori attivi (inizializzata a 0).
- **MUTEXL**: Semaforo utilizzato per l'accesso mutua esclusione alla variabile `NUM_LETTORI` (inizializzato a 1).
- **SYNCH**: Semaforo per la mutua esclusione tra lettori e scrittori e tra scrittori stessi (inizializzato a 1).

### Comportamento

1. I lettori incrementano `NUM_LETTORI` per segnalare che stanno leggendo, ma devono prima acquisire il semaforo `MUTEXL` per farlo in mutua esclusione.
2. Gli scrittori possono accedere alla risorsa solo quando `NUM_LETTORI == 0`, quindi aspettano che non ci siano lettori.
3. Solo uno scrittore può accedere alla risorsa alla volta, grazie al semaforo `SYNCH`.


