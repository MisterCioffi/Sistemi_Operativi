
# 📌SINGOLO BUFFER  

Il problema **Produttore-Consumatore** con **buffer unico** e **un solo produttore e un solo consumatore** impone i seguenti **vincoli**:  

### 🔴 SPAZIO DISPONIBILE  
Il produttore non può produrre un messaggio se il consumatore non ha ancora consumato il messaggio precedente, ovvero **il buffer deve essere libero**.  

### 🔵 MESSAGGIO DISPONIBILE  
Il consumatore non può prelevare un messaggio se prima il produttore non l'ha depositato (**il buffer non può essere vuoto**).  

> 🛠 **Questo è un problema di cooperazione**, in quanto è necessario che produttore e consumatore si **coordinino** per indicare rispettivamente **l’avvenuto deposito e il prelievo**.

---

## 🔄 Sincronizzazione con i Semafori  

Per sincronizzare produttore e consumatore, si usano **due semafori**:

### 1️⃣ `SPAZIO_DISP` 🟢  
- **Bloccato dal produttore** prima della produzione.  
- **Sbloccato dal consumatore** dopo il consumo.  
- **Valore iniziale: `1`** (buffer libero all'inizio).  

### 2️⃣ `MSG_DISP` 🔴  
- **Sbloccato dal produttore** dopo la produzione.  
- **Bloccato dal consumatore** prima del consumo.  
- **Valore iniziale: `0`** (nessun messaggio inizialmente).  

---

## 🖥 Funzioni Principali  

La **produzione** e il **consumo** avvengono rispettivamente all'interno delle funzioni:  

```c
void Produttore(msg *, int);
void Consumatore(msg *, int);

