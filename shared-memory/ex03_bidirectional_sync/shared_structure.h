/* shared_structure.h */
/*
Si l'on souhaite partager plusieurs données entre les processus, il est préférable de définir une structure représentant l'organisation de la zone mémoire partagée. Cette structure sera placée dans un fichier commun (par exemple shared_structure.h) et la taille du segment sera obtenue avec sizeof(Structure). Chaque processus pourra alors accéder aux mêmes champs via un pointeur retourné par shmat().

Ou plus court :

La mémoire partagée peut contenir non seulement une variable simple (int), mais aussi une structure (struct) regroupant plusieurs informations. La structure décrit alors le contenu de la zone mémoire partagée.

Exemple :
*//*
    typedef struct
    {
        int N;
        int compteur;
        char message[100];
    } SharedData;
*//*
Puis :
*//*    
    shmget(key, sizeof(SharedData), IPC_CREAT | 0666);
*/