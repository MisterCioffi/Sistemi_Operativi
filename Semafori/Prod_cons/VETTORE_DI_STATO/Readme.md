# 🚀 VETTORE DI STATO 

Nella soluzione precedente, i **produttori o consumatori "veloci"**  
possono essere penalizzati dalla presenza di **produttori o consumatori "lenti"**.  
Questo problema si verifica, ad esempio, quando i messaggi prodotti hanno **dimensione variabile**.  
*(Vedi [CODA](#coda-circolare) e [SINGOLO BUFFER]([SINGOLO BUFFER](https://github.com/MisterCioffi/Sistemi_Operativi/tree/main/Semafori/Prod_cons/SINGOLO_BUFFER)
)
 per maggiori dettagli).*


---

## 🛠️ SOLUZIONE: UTILIZZO DI UN POOL DI BUFFER  

Per evitare il problema, si utilizza un **pool di buffer**, gestito attraverso un **vettore ausiliario di stato**.  

🔹 **Vantaggi di questa soluzione**:
- L’**accesso al vettore di stato** (per acquisire un buffer) è in **mutua esclusione**.  
- Dopo aver acquisito un buffer, **produttori e consumatori possono procedere in concorrenza**.  

📌 **Importante**:  
Oltre al **buffer**, abbiamo un **vettore di stato** con la **stessa cardinalità** del buffer.  

---

## 🔒 MUTUA ESCLUSIONE  

⚠️ **Attenzione!** La **mutua esclusione** è applicata **solo** al **vettore di stato** (operazione veloce).  
- Una volta assegnato un buffer al produttore, **quest'ultimo lavora in autonomia**, senza interferire con altri produttori.  
- Stesso discorso vale per i consumatori.  

✅ **Risultato**:  
Un processo **"lento"** non penalizza i processi **"veloci"**.  

📌 **Nota**: L'ordine di produzione e consumo **non è più circolare**, ma dipende dalla velocità dei processi.  

---

## 🔑 SINCRONIZZAZIONE E SEMAFORI  

Per la mutua esclusione sul **vettore di stato**, si utilizzano **due `mutex`**:  

- **`MUTEX_P`** 🔒 → Per l’accesso dei **produttori**.  
- **`MUTEX_C`** 🔒 → Per l’accesso dei **consumatori**.  
*(Entrambi inizializzati a `1` per garantire l'accesso esclusivo).*  

I **soliti due semafori**, **`SPAZIO_DISP`** e **`MSG_DISP`**, vengono utilizzati per la sincronizzazione:  

- **`SPAZIO_DISP`** 🏗️ → Indica la **presenza di spazio disponibile** nel buffer.  
  - *(Inizializzato a `DIM_BUFFER`, o al numero di produttori se minore o uguale a `DIM_BUFFER`).*  

- **`MSG_DISP`** 📦 → Indica il **numero di messaggi disponibili** nel buffer.  
  - *(Inizializzato a `0`, perché all'inizio il buffer è vuoto).*  

---

## 🏗️ GESTIONE DEL POOL DI BUFFER  

La gestione del **pool di buffer** avviene mediante **due vettori**:

- **`buffer[DIM]`** → Array di elementi di tipo `msg` (tipo del messaggio depositato dai produttori) contenente i valori prodotti.  
- **`stato[DIM]`** → Array di interi, dove ogni valore `stato[i]` può assumere tre stati:  

  1. **`VUOTO`** → La cella `buffer[i]` **non** contiene alcun valore prodotto.  
  2. **`PIENO`** → La cella `buffer[i]` **contiene un valore prodotto**, non ancora consumato.  
  3. **`IN_USO`** → La cella `buffer[i]` è **attualmente in uso** da un produttore o un consumatore.  

💾 **Struttura dati in C**:

```c
struct prodcons {
    int buffer[DIM_BUFFER];
    int stato[DIM_BUFFER];
};
```
---

## 🏁 IN DEFINITIVA  

Questa soluzione **ottimizza l'efficienza** del sistema:  
✔️ I **processi veloci non vengono bloccati da quelli lenti**.  
✔️ **Migliora il parallelismo**, riducendo il tempo in mutua esclusione.  
✔️ L'ordine **non è più circolare**, ma dipende dalla velocità dei processi.  


