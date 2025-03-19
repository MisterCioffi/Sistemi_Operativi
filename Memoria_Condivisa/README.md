# 📝 Memoria Condivisa (SHM)

Una memoria condivisa (SHM) è una porzione di memoria accessibile da più processi.  

## 🔄 Modalità di Condivisione  

Due modalità principali:  

1. **Richiesta esplicita** 🏷️  
   - Se un processo vuole usare una SHM esistente e ne conosce la chiave, può richiederla esplicitamente.  

2. **Tramite `fork()`** 👶  
   - Un processo può collegarsi alla SHM e successivamente generare figli tramite `fork()`.  
   - I processi figli erediteranno automaticamente una copia del descrittore della SHM.  
   - Se il padre ha già ottenuto il puntatore alla memoria condivisa, i figli vi avranno accesso direttamente.  

## 📖 Lettura e Scrittura  

✅ Le operazioni di lettura e scrittura su una SHM non richiedono chiamate di sistema speciali.  
✅ La memoria condivisa può essere utilizzata come una qualsiasi variabile nello spazio di indirizzamento del processo.  
✅ La quantità massima di dati che un processo può leggere/scrivere in una singola istruzione dipende dall'architettura del sistema.  

## 📌 Header Necessari  

Per utilizzare la memoria condivisa in C, è necessario includere i seguenti header:  

```c
#include <sys/shm.h>  // Gestione memoria condivisa
#include <sys/ipc.h>  // Creazione chiavi IPC

