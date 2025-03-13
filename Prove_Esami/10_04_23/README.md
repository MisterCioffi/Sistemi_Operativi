# 📌 Programma Multiprocesso: Produttore-Consumatore con Monitor (Signal and Continue)

## 📖 Descrizione
Si realizzi in linguaggio **C/C++** un programma multiprocesso basato sul costrutto **Monitor** (di tipo _signal and continue_) per implementare lo schema **produttore-consumatore** con **vettore di stato**.

🔹 I **produttori** possono inserire elementi di **due tipi differenti**.<br>
🔹 Il **vettore di buffer** può assumere **4 possibili stati**:
   - `LIBERO` ➝ buffer disponibile
   - `IN_USO` ➝ buffer temporaneamente occupato
   - `OCCUPATO1` ➝ buffer con un elemento di tipo 1
   - `OCCUPATO2` ➝ buffer con un elemento di tipo 2

## 🛠️ Specifiche di Implementazione
I produttori chiamano uno fra **due metodi** differenti per la produzione:
- `produci_tipo_1()`: produzione di elementi di tipo **1**
- `produci_tipo_2()`: produzione di elementi di tipo **2**

Analogamente, i consumatori chiamano uno fra **due metodi** per il consumo:
- `consuma_tipo_1()`: consumazione di elementi di tipo **1**
- `consuma_tipo_2()`: consumazione di elementi di tipo **2**

## 👥 Struttura dei Processi
Per verificare il funzionamento del programma, saranno creati:
- **2 processi produttori** per il **tipo 1**, che effettuano **4 produzioni ciascuno**
- **2 processi produttori** per il **tipo 2**, che effettuano **4 produzioni ciascuno**
- **1 processo consumatore** per il **tipo 1**, che effettua **8 consumazioni**
- **1 processo consumatore** per il **tipo 2**, che effettua **8 consumazioni**

Il vettore di buffer conterrà al **massimo 4 elementi** (`DIM = 4`).

## 📝 Struttura della Struttura `MonitorPC`
```cpp
#define DIM 4

typedef struct {
    int vettore[DIM];          // Buffer dei dati
    int stato[DIM];            // Stato dei buffer
    int num_liberi;            // Numero di buffer liberi
    int num_occupati_tipo1;    // Numero di buffer occupati dal tipo 1
    int num_occupati_tipo2;    // Numero di buffer occupati dal tipo 2
    // ... Aggiungere ulteriori variabili per la sincronizzazione
} MonitorPC;
```

## ⚙️ Funzioni Disponibili
```cpp
void inizializza(MonitorPC * m);
void rimuovi(MonitorPC * m);
void produci_tipo_1(MonitorPC * m, int valore);
void produci_tipo_2(MonitorPC * m, int valore);
void consuma_tipo_1(MonitorPC * m, int &valore);
void consuma_tipo_2(MonitorPC * m, int &valore);
```

📌 **Nota:** La sincronizzazione tra produttori e consumatori verrà gestita mediante il meccanismo di **Monitor con signal and continue** per garantire un corretto accesso concorrente ai dati.

🚀 **Pronti a implementarlo?**

