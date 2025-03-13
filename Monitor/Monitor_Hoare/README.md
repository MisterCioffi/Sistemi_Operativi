## 🔄 Soluzione di Hoare
La soluzione di Hoare è un caso particolare di Signal and Wait.

### 🛠️ Signal_and_Wait
La semantica *signal_and_wait* privilegia il processo segnalato rispetto a quello segnalante.

✔️ Il segnalato viene risvegliato immediatamente, al momento della `signal_cond`, e ottiene il possesso del mutex del monitor.

✔️ Al risveglio, il segnalato trova sicuramente vera la condizione per la quale era stato sospeso. Per questo motivo, lo schema tipico di una `wait_cond` è all'interno di un **if**:

```c
if (condizione == false) {
    x.wait_cond();
}
// Quando esco dalla wait, ho accesso sicuro alla risorsa
```

⚠️ Svantaggio: il processo che esegue la `signal` è penalizzato! Per continuare l'esecuzione, deve attendere che il segnalato esca dal monitor (*...and_wait*), ponendosi in attesa sul mutex del monitor. Inoltre, dovrà competere con altri processi sopraggiunti nel frattempo.

---

### 🔥 Soluzione di Hoare: Signal_and_Urgent_Wait
La **soluzione di Hoare** è un caso particolare di *signal_and_wait*, detta anche *signal_and_urgent_wait*.

✅ Prevede che il processo segnalato (P) venga eseguito immediatamente dopo la signal_cond(), mentre il segnalante (Q) si sospende in una coda speciale chiamata urgent_queue. Il segnalante riprenderà l’esecuzione solo dopo che il segnalato avrà terminato ed è uscito dal monitor.

💡 Come si ottiene?
- Sospendendo il processo segnalante (**Q**) in una coda speciale chiamata **urgent_queue**.
- Questa coda è separata dal mutex e assicura che **Q venga eseguito immediatamente, senza interferenze di altri processi.**

📌 Questo meccanismo evita il problema della competizione tra il segnalante e altri processi in attesa, garantendo una gestione più ordinata e prevedibile dell’accesso alle risorse condivise.


