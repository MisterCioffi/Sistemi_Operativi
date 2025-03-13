# 🟢 Signal and Continue (Mesa-Style Monitor)

## 📝 Descrizione
**Signal and Continue** (detto anche *Wait and Notify* o *Mesa-style Monitor*) è una strategia di sincronizzazione in cui viene privilegiato il processo che invia il segnale (`signal_cond`), piuttosto che quello che lo riceve.

### 🔄 Funzionamento
- Il processo **Q** (segnalante) invia `signal_cond()` per risvegliare il processo **P**.
- **Q** prosegue immediatamente la sua esecuzione, mantenendo l'accesso esclusivo al monitor 🔒.
- Il processo **P** (segnalato) non si attiva subito, ma viene trasferito nella coda associata all'ingresso del monitor 🕑.
- **P** dovrà competere per il mutex del monitor con eventuali altri processi sopraggiunti.
- Quando **P** ottiene il monitor, deve **verificare nuovamente** la condizione di sincronizzazione, poiché lo stato potrebbe essere cambiato ⏳.

## ⚠️ Importante
Poiché lo stato della condizione potrebbe essere mutato nel frattempo, il controllo della condizione di sincronizzazione deve essere effettuato all'interno di un **while**, e non di un semplice if:

```cpp
while (!B) {
    cv.wait_cond();
}
// 🔓 Accesso alla risorsa
```

Utilizzando un ciclo `while`, il processo **P** può rieseguire `wait_cond()` se la condizione non è più valida, garantendo la correttezza della sincronizzazione ✅.


