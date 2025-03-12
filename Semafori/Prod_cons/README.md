# PRODUTTORI-CONSUMATORI

Questo documento presenta diverse strategie per la gestione del problema **Produttore-Consumatore**, utilizzando i **semafori** per la sincronizzazione tra processi. 
L'obiettivo è garantire un corretto accesso concorrente alle risorse condivise, evitando condizioni di **race condition**, **deadlock** o **starvation**.

## Approcci Implementativi

Sono analizzati tre approcci principali per la gestione della comunicazione tra produttori e consumatori:

### 📌 Singolo Buffer

In questa soluzione, esiste una sola cella di memoria condivisa tra produttore e consumatore. Il produttore scrive nel buffer e il consumatore legge da esso.

### 📌 Coda

L'uso di una **coda** permette di gestire più elementi in attesa, migliorando l'efficienza rispetto al singolo buffer. 

### 📌 Vettore di Stato

Il **vettore di stato** è una generalizzazione della coda, che consente un accesso più flessibile ai dati condivisi. 
Ogni posizione del vettore ha uno stato che indica se è **libera** o **occupata**, permettendo la gestione efficiente delle risorse.

## 🏁 Conclusione

Questi approcci offrono soluzioni diverse per il problema produttore-consumatore, con vantaggi e svantaggi a seconda del contesto. 
