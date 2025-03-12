#define NUM_VOLTE 3
#define SYNCH 0 //mutua esclusione tra scrittore e lettore
#define MUTEXS 1 // permette di modificare il numero di scrittori in maniera mutamente esclusiva.
#define MUTEXL 2 // mutex per poter modificare il numero di lettori in maniera mutamente esclusiva
#define MUTEX  3 

typedef long msg;

            
typedef struct {
 	  	 int numlettori;
 	  	 int numscrittori;
 	  	 msg messaggio;
} Buffer;



void InizioLettura (int, Buffer*);
void FineLettura(int, Buffer*);
void InizioScrittura(int, Buffer*);
void FineScrittura(int, Buffer*);
void Lettore(int, Buffer*);
void Scrittore(int, Buffer*);
