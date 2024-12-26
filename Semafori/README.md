Il semafoto è una struttura dati fornita dal kernel che incapsula un contatore intero s.
I semafori sono variabili speciali (sostanzialmente dei contatori) utilizzate per la cooperazione e la competizione tra processi. Due o più processi competono o cooperano attraverso l’uso di segnali, in modo tale che un processo può essere forzato a sospendersi in un determinato punto finché non riceve un segnale.





Sono definite le seguenti operazioni:

| WAIT                                                      | ![image](https://github.com/user-attachments/assets/2e741edf-9fa5-45cf-bd4b-09290d8884da)  |
|-----------------------------------------------------------|----------------------------------------------|
| che ha l’effetto di decrementare il valore del semaforo. Se il valore del semaforo diventa negativo, inserisce il processo nella coda dei processi sospesi e il processo viene sospeso; |
                
                                             

  - Inizializzazione della variabile ad un valore non negativo
    - Il valore iniziale è scelto dal programmatore in base al tipo di interazione che si vuole realizzare(mutua esclusione, cooperazione)

  - Operazione di wait, che ha l’effetto di decrementare il valore del semaforo.  Se il valore del semaforo diventa negativo, inserisce il processo nella coda dei processi sospesi e il processo viene sospeso;

  - L’operazione di signal che ha l’effetto di incrementare il valore del semaforo. 
    - Se il valore del semaforo diventa minore o uguale a zero(significa che c’è almeno un processo sospeso) viene “sbloccato” un     processo che si era sospeso durante l’esecuzione della wait;
