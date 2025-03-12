# 📖 Problema Lettori-Scrittori

## Due categorie di processi:

- 📚 **Lettori**: leggono un messaggio su una risorsa condivisa.
- ✍️ **Scrittori**: scrivono il messaggio sulla risorsa condivisa.

## Vincoli:

-  I **processi lettori** possono accedere contemporaneamente alla risorsa, poiché effettuano solo operazioni di lettura.
-  I **processi scrittori** devono avere accesso esclusivo alla risorsa, in quanto modificano il contenuto.
-  **Lettori e scrittori si escludono mutuamente** dall'uso della risorsa.

## 🔥 Problemi di sincronizzazione:

- ⚔️ **Competizione**: più scrittori possono voler accedere alla stessa area contemporaneamente.
- 🤝 **Cooperazione**: un lettore non può leggere se prima uno scrittore non ha scritto.

## 🔐 Operazioni protette:

- 📖 Le operazioni di lettura sono gestite dalle procedure:
  - 🟢 `Inizio_Lettura()`
  - 🔴 `Fine_Lettura()`

- ✍️ Le operazioni di scrittura sono gestite dalle procedure:
  - 🟢 `Inizio_Scrittura()`
  - 🔴 `Fine_Scrittura()`

## 🚦 Politica di accesso alla risorsa:

-  Un **processo lettore attende** solo se la risorsa è occupata da un processo scrittore.
-  Un **processo scrittore può accedere** alla risorsa solo se questa è libera.

## ⚠️ Problema della starvation:

Questa strategia di sincronizzazione può causare **attesa indefinita (starvation)** per gli scrittori:

-  La presenza di un lettore permette solo ad altri lettori di accedere, ma **non permette l'ingresso agli scrittori**.
-  Finché nel sistema vi è almeno un lettore attivo, **lo scrittore subisce starvation**.

## ℹ️ Nota:

-  I lettori **leggono in parallelo**.
-  Lo scrittore **deve attendere** per ottenere accesso esclusivo.
-  Il lettore si **sospende** se uno scrittore sta scrivendo.

