# Il Monitor e la Sincronizzazione tra Processi 🚦

## Introduzione 📌
Il **monitor** è un ***costrutto sintattico*** che associa un insieme di operazioni a una struttura dati (risorsa) condivisa tra più processi.

E’ stato introdotto per ***facilitare la programmazione strutturata*** di problemi in cui è necessario controllare l’assegnazione di una o più risorse tra più processi concorrenti mediante apposite discipline di gestione.

Il costrutto Monitor è sintatticamente del tutto analogo al costrutto di `class`, ma mentre quest’ultimo viene utilizzato per definire tipi di risorse dedicate, il **monitor** viene utilizzato per definire tipi di risorse condivise.

Si configura come un «tipo di dato astratto», in cui:

- le ***variabili membro*** (private), dette anche variabili locali, descrivono lo stato della risorsa (condivisa) controllata dal monitor;
- le ***funzioni membro pubbliche*** costituiscono le uniche operazioni utilizzabili dai processi per "disciplinare" l’accesso alle variabili membro;
- le ***funzioni membro private***, non invocabili dall’esterno.

## Controllo dell'Assegnazione delle Risorse 🔄
L’obiettivo del monitor è garantire l’accesso alla risorsa secondo due livelli di controllo:

1. Un solo processo alla volta può accedere alle variabili locali (**competizione** ⚔️).
2. Una disciplina di scheduling stabilisce l’ordine con il quale i processi accedono alla risorsa (**cooperazione** 🤝).

---

## Problema della Competizione ⚔️
Per garantire che un solo processo alla volta acceda alle variabili locali (risorsa condivisa), si impone che:

- le funzioni di accesso al monitor vengano eseguite in modo ***mutuamente esclusivo***;
- i processi che invocano una funzione di un oggetto monitor mentre un altro processo è attivo nell’istanza, devono essere ***ritardati***.

---

## Problema della Cooperazione 🤝
Per garantire una ***disciplina*** che stabilisca l’***ordine di accesso*** alla risorsa:

1. Un processo accede alle variabili locali solo se è soddisfatta una condizione logica che assicura l’ordinamento di esecuzione.
2. Se la condizione non è verificata, il processo si sospende, permettendo ad altri processi di accedere all’istanza.

La sospensione avviene utilizzando una variabile interna al monitor, detta ***variabile di tipo condition***.

### Variabile Condition 🛑
```cpp
var_cond x;
```
Ha due metodi principali:

- `x.wait_cond()` ➡️ sospende il processo chiamante finché un altro processo esegue `x.signal_cond()`.
- `x.signal_cond()` ➡️ risveglia un processo sospeso sulla variabile `x`, se presente, altrimenti non fa nulla.

⚠️ **Attenzione**: Se nessun processo è in attesa su `x`, la `signal_cond()` non ha effetto!

**Esempio di Cooperazione:**
1. Il processo `P` accede al monitor ma trova la risorsa esaurita e si sospende con `wait`.
2. Arriva `Q`, che aggiorna lo stato della risorsa e invoca `signal`.
3. Problema: ora entrambi i processi potrebbero eseguire, violando la mutua esclusione!
4. Soluzione: solo uno dei due può continuare, l’altro si sospende.

---

## Semafori vs Variabili Condition 🚥
| **Caratteristica** | **Semaforo** 🚦 | **Variabile Condition** 🔄 |
|--------------------|----------------|--------------------------|
| **Sincronizzazione** | Basata su contatori | Basata su code di attesa |
| **Mutua esclusione** | Richiede `wait()` e `signal()` espliciti | Gestita automaticamente dal monitor |
| **Effetto di `signal()`** | Incrementa il valore del semaforo | Risveglia un processo sospeso (se presente) |
| **Effetto se nessun processo è in attesa** | Il valore del semaforo aumenta | `signal_cond()` non ha effetto |
| **Gestione della sospensione** | I processi aspettano su un semaforo | I processi aspettano su una variabile condition |

**Conclusione:**
- **I semafori** sono strumenti più generici e richiedono maggiore attenzione nella gestione manuale della sincronizzazione.
- **Le variabili condition** sono più strutturate e integrate nei monitor, facilitando la gestione della cooperazione tra processi.

🔍 **In sintesi:** I monitor e le variabili condition offrono un modo più strutturato e sicuro per gestire la concorrenza rispetto ai semafori tradizionali!


