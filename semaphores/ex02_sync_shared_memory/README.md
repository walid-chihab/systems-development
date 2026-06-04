# Semaphore Sync Shared Memory

Soit P1 et P2 deux processus qui partagent un segment de mémoire représentant un entier N et
s'exécutant en parallèle. On désire avoir l'affichage suivant :
Terminal 1 Terminal 2

On s'arrête quand n > 100. Ecrire les deux programmes C sous Unix implémentant P1 et P2 en
utilisant le module permettant la gestion des sémaphores (semaphore.h, semaphore.c).
Indication :
Les deux processus se synchronisenten utilisant des sémaphores. Au début le processus P2 est
bloqué, P1 affiche sa première série débloque le P2 et se bloque. P2 affiche sa première série
débloque le P1 et se bloque, et ainsi de suite. Pour la mémoire partagée, reprendre l'exercice
de synchronisation de la série 4.
pas encore a comprendre  semaphore(.h/.c)
 