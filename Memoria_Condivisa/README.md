# 📝 Memoria Condivisa (SHM)

Una memoria condivisa (SHM) è una porzione di memoria accessibile da più processi.  

## 🔄 Modalità di Condivisione  

Due modalità principali:  

1. **Richiesta esplicita**   
   - Se un processo vuole usare una SHM esistente e ne conosce la chiave, può richiederla esplicitamente.  

2. **Tramite `fork()`**  
   - Un processo può collegarsi alla SHM e successivamente generare figli tramite `fork()`.  
   - I processi figli erediteranno automaticamente una copia del descrittore della SHM.  
   - Se il padre ha già ottenuto il puntatore alla memoria condivisa, i figli vi avranno accesso direttamente.  

## 📖 Lettura e Scrittura  

- Le operazioni di lettura e scrittura su una SHM non richiedono chiamate di sistema speciali.  
- La memoria condivisa può essere utilizzata come una qualsiasi variabile nello spazio di indirizzamento del processo.  
- La quantità massima di dati che un processo può leggere/scrivere in una singola istruzione dipende dall'architettura del sistema.  

## 📌 Header Necessari  

Per utilizzare la memoria condivisa in C, è necessario includere i seguenti header:  

```c
#include <sys/shm.h>  // Gestione memoria condivisa
#include <sys/ipc.h>  // Creazione chiavi IPC
```
# 🛠️ Creazione e Gestione della Memoria Condivisa (SHM)

## 📌 Creazione di una SHM  

```c
int shmget(key_t key, int size, int flag);
```

- **`key`** 🔑 → Chiave univoca per identificare la SHM nel sistema.  
- **`size`** 📏 → Dimensione in byte della memoria condivisa.  
- **`flag`** 🚦 → Specifica modalità di creazione e permessi di accesso (`IPC_CREAT`, `IPC_EXCL`, permessi).  

🔹 **Ritorno**: Un identificatore numerico (`shmid`) se ha successo, `-1` in caso di fallimento.  

---

## 🔗 Collegamento alla SHM  

```c
void* shmat(int shmid, const void *shmaddr, int flag);
```

- **`shmid`** 🏛️ → Identificatore del segmento di memoria.  
- **`shmaddr`** 📌 → Indirizzo del processo in cui collegare la SHM. Se `0`, il sistema sceglie automaticamente.  
- **`flag`** ⚙️ → Opzioni (es. `IPC_RDONLY` per collegare in sola lettura).  

🔹 **Ritorno**: Puntatore al segmento collegato oppure `-1` in caso di errore.  

### 🖨️ Stampa dell'indirizzo della memoria collegata  

```c
void* ptr = shmat(shmid, 0, 0);
printf("Indirizzo SHM collegata: %p\n", ptr);
```

---

## ⚙️ Operazioni di Controllo  

```c
int shmctl(int shmid, int cmd, struct shmid_ds *buff);
```

- **`shmid`** 🏛️ → Identificatore della memoria condivisa.  
- **`cmd`** 📚 → Comando da eseguire sulla SHM:  
  - `IPC_STAT` 📊 → Ottiene informazioni sulla SHM.  
  - `IPC_SET` 🛠️ → Modifica parametri della SHM.  
  - `IPC_RMID` 🗑️ → Marca per eliminazione (rimossa quando nessun processo è collegato).  
  - `SHM_LOCK` 🔒 → Evita lo swap/paging del segmento.  
- **`buff`** 📦 → Puntatore a una struttura `shmid_ds`.  

🔹 **Ritorno**: `0` in caso di successo, `-1` in caso di errore.  

---

Con questa sintassi e i comandi sopra, puoi creare, gestire e rimuovere segmenti di memoria condivisa in modo efficiente! 🚀  


