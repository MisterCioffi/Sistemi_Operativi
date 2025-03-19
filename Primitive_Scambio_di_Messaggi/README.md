# Comunicazione tra processi in UNIX System V 🖥️📡

## Messaggi e Mailbox 📬

UNIX (System V) mette a disposizione primitive per la comunicazione tra processi (anche indipendenti) basata sullo scambio di messaggi.

Un messaggio è un blocco di informazioni senza un formato predefinito. L'unico vincolo è che il tipo del messaggio deve essere di tipo `long`.

### Mailbox 📥

UNIX supporta un modello di comunicazione indiretta, dove lo scambio di messaggi avviene attraverso una mailbox.

Una mailbox può essere vista come una **coda di messaggi** ed è caratterizzata da:
- **Una chiave** (analoga alla memoria condivisa);
- **Un proprietario** (utente che la istanzia);
- **Un gruppo di appartenenza**;
- **Un insieme di protezioni** (indicate dalla solita stringa con 3 numeri a 3 bit).

---

## Primitive principali 🔧

### 📌 `msgget`
Primitiva per istanziare una coda di messaggi:
```c
int msgget(key_t chiave, int modo);
```
- Restituisce l'identificativo della coda o `-1` in caso di errore.
- `modo` può essere `IPC_CREAT | permessi` (se il processo crea la coda) oppure `0` (se si vuole accedere a una coda già esistente).

### 📌 `msgsnd`
Consente di inviare e accodare un messaggio a una mailbox:
```c
int msgsnd(int msqid, struct msgbuf *msgp, size_t msgsz, int msgflg);
```
La struttura dati del messaggio:
```c
struct msgbuf {
    long message_type;  // Deve essere sempre di tipo long
    char message_text[MAX_SIZE];
};
```
**Note importanti:**
- `message_type` è fondamentale per funzioni di receive selettive.
- `msgsz` è la dimensione del messaggio senza il campo `message_type` (`sizeof(msgbuf) - sizeof(long)`).
- `msgflg` può essere:
  - `0`: se la mailbox è piena, il processo viene bloccato.
  - `IPC_NOWAIT`: se la mailbox è piena, la funzione restituisce `-1`.

### 📌 `msgrcv`
Primitiva per la ricezione di un messaggio:
```c
int msgrcv(int msqid, void *msgp, int msgsz, long msgtyp, int msgflg);
```
- `msgtyp` permette di specificare il messaggio da ricevere:
  - `msgtyp = 0`: preleva il primo messaggio nella coda.
  - `msgtyp > 0`: preleva il primo messaggio con quel tipo.
  - `msgtyp < 0`: preleva il primo messaggio con tipo `≤ |msgtyp|`.
- `msgflg`:
  - `0`: ricezione bloccante.
  - `IPC_NOWAIT`: ricezione non bloccante (ritorna `-1` se non ci sono messaggi).

### 📌 `msgctl`
Per operazioni avanzate sulla coda:
```c
int msgctl(int msqid, int cmd, struct msqid_ds *buf);
```
- **Deallocazione:** `msgctl(msqid, IPC_RMID, 0);`
- **Lettura senza consumo:** `IPC_STAT`
- **Modifica caratteristiche:** `IPC_SET`

---

## Esempio: Richiesta/Risposta tra Client e Server 💬

Un mittente può inviare una richiesta a un server e aspettarsi una risposta inserendo il proprio `PID` nel messaggio:

```c
struct msgbuf {
    long message_type;
    int sender_pid;
    char message_text[MAX_SIZE];
};
```
Il server può usare `msgrcv()` per leggere solo i messaggi destinati a lui e poi rispondere con `msgsnd()` usando il `PID` del client come `message_type`.

---

### 📌 Conclusione

Le **code di messaggi** offrono una potente forma di comunicazione inter-processo in UNIX System V. La loro gestione richiede attenzione ai dettagli, specialmente nella struttura del messaggio e nella gestione degli errori. 🎯


