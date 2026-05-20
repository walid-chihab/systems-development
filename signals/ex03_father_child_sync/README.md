# Father-Child Sync Signal

Exercice 3 : Synchronisation Père/Fils
Ecrire le programme C sous Unix qui permet à un processus père
de créer un processus Fils. Le père et le Fils doivent
s'exécuter en parallèle en cordonnant leurs exécutions et en
permettent l'affichage suivant :

Fils: 2 4 6 8 10
Père: 3 6 9 12 15
Fils: 12 14 16 18 20
Père: 18 21 24 27 30
........ ...........
........ ...........
Père: ..............99
Appels Systèmes : fork(), signal(), Kill(), pause()
Indication : Chaque fois qu'un processus affiche un multiple
de 5 il se bloque et envoi un signal à l'autre processus pour
le réveiller