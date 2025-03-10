
# PROD-CONS SINGOLO BUFFER

I vincoli imposti da un problema di tipo Produttore- Consumatore, nel caso che il ***buffer*** sia ***unico*** e che vi siano ***un solo produttore ed un solo consumatore***, sono i seguenti:

- SPAZIO DISPONIBILE → il produttore non può produrre un messaggio se il consumatore non ha consumato il messaggio precedente, ovvero il buffer è libero.
- MESSAGGIO DISPONIBILE → Il consumatore non può prelevare un messaggio se prima il produttore non l'ha depositato(ci deve essere qualcosa nel buffer altrimenti il consumatore non può consumare)

Quindi abbiamo un ***problema di cooperazione*** in quanto è necessario che produttori e consumatori si coordinino per indicare rispettivamente l’avvenuto deposito e prelievo.

Per la sincronizzazione dei processi produttore e consumatore si utilizzano ***due semafori***:

1. ***SPAZIO_DISP***: semaforo bloccato da un produttore prima di una produzione, e sbloccato da un consumatore in seguito ad un consumo (VALORE INIZIALE: 1)

2. ***MSG_DISP***: semaforo sbloccato da un produttore in seguito ad una produzione, e bloccato da un consumatore prima del consumo (VALORE INIZIALE: 0)

La produzione ed il consumo avvengono rispettivamente all'interno delle procedure

- ***void Produttore(msg*, int);***
- ***void Consumatore(msg *, int);***

all'interno delle quali si effettuano anche le operazioni di ***Wait_Sem*** e ***Signal_Sem*** necessarie per la sincronizzazione
