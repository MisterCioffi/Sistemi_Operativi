#define MUTEXL 0 
#define SYNCH 1 // gestiamo il vincolo di mutua esclusione tra lettori e scrittore
#define NUM_VOLTE 6


typedef long  msg;

typedef struct {

        int numlettori; // devono poter accedere a questo valore tutti i processi lettori
        msg messaggio;
    
} Buffer;


void Lettore(int,Buffer*);
void Scrittore(int,Buffer*);753968062.570081@[8875727904916] (UTM):* SLSGetNextEventRecordInternal: loc (612.4, 609.1) conn 0x6ed0b Scroll Wheel win 0x55 Axis1 6 Phase MomentumBegin
