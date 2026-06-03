# Basic Semaphore

Le module permettant la gestion des sémaphores composé des deux fichiers (semaphore.h,
semaphore.c) permettant la création, l'initialisation et les opérations sur les sémaphores (P et
V).


Soit P1 et P2 deux processus sans lien de parenté qui s'exécutent en parallèle. On vent
programmer la synchronisation suivante:
-P2 est bloqué au départ
-P1 s'exécute, affiche la série : 2 4 6 8 10

et il se bloque

-P2 reprend son exécution et affiche la série : 3 6 9 12 15
En utilisant le module permettant la gestion des sémaphores (semaphore.h, semaphore.c)
décrit en cours permettant la création, l'initialisation et les opérations sur les sémaphores (P et
V) implémenter les programmes P1 et P2.