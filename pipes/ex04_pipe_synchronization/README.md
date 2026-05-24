# Pipe Synchronization

Ecrire le programme C sous Unix qui permet à un processus père de créer un processus Fils.
Le père et le Fils doivent s'exécuter en parallèle en cordonnant leurs exécutions et en
permettent l'affichage suivant :
Fils : 2 4 6 8 10
Père : 13 16 19 22 25
Fils : 27 29 31 33 35
Père : 38 41 44 47 50
........ ...........
........ ...........
Père : ..............
On s'arrête quand n > 100