# 🏭 PROD-CONS CODA  

In questo caso abbiamo un problema di **competizione**, perché:  
- **Tutti i consumatori** vogliono accedere alla variabile `coda`.  
- **Tutti i produttori** vogliono accedere alla variabile `testa`.  

---

## ⚔️ GESTIONE COMPETIZIONE  

Se ci sono **più produttori** e **più consumatori** che accedono allo stesso buffer,  
le operazioni di **deposito** e **prelievo** devono essere eseguite in **mutua esclusione**  
e quindi programmate come **sezioni critiche**.  

🔹 Per questo motivo, vengono introdotti **due nuovi semafori**:  

- 🟢 **`MUTEX_C`** → Controlla le operazioni di **consumo** (disciplina l’accesso alle variabili condivise).  
- 🔴 **`MUTEX_P`** → Controlla le operazioni di **produzione**.  

> ⚠️ **Attenzione!** Entrambi devono essere **inizializzati a `1`** per garantire l’accesso esclusivo.  

---

## 🔄 GESTIONE COOPERAZIONE  

Per la **sincronizzazione** dei processi vengono utilizzati **due semafori**:

- **`SPAZIO_DISP`** 🏗️ → Indica la **presenza di spazio disponibile** nella coda per la produzione di un messaggio.  
  *(Il valore iniziale è pari alla dimensione della coda `DIM_BUFFER`).*  

- **`NUM_MESS`** 📦 → Indica il **numero di messaggi presenti in coda**.  
  *(Il valore iniziale è `0`, perché all’inizio la coda è vuota).*  

---

## 📥📤 STRUTTURA DELLA CODA  

La **coda** è implementata attraverso i seguenti campi:  

- **`buffer[DIM]`** 📂 → Un array di elementi di tipo `msg`, che contiene i valori prodotti.  
- **`testa`** 🔼 → Indica la posizione del **primo buffer libero** in testa, `buffer[testa]`.  
  - L’elemento prodotto **più recentemente** si trova in `buffer[testa - 1]` *(utilizzato dal produttore)*.  
- **`coda`** 🔽 → Indica la posizione dell’elemento **meno recente**, `buffer[coda]`, da accedere alla prossima consumazione *(utilizzato dal consumatore)*.  

> ⚠️ **Attenzione!** Anche le variabili `testa` e `coda` devono essere **condivise**!  

Ecco la struttura dati in **C**:  

```c
struct prodcons {
    int buffer[DIM_BUFFER];
    int testa;
    int coda;
};
