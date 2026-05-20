# Custom Signal

1. Ecrire le programme C "Boucle.c" qui permet de redéfinir le
comportement d'un signal passé en paramètre. Le nouveau
comportement consiste à afficher le numéro du signal. Le
programme affiche son pid et rentre dans une boucle infinie.
2. Ecrire le programme C "Envoi.c" qui permet d'envoyer un
signal à un processus. Le numéro du signal et le pid du
processus sont passés en paramètres.
Appels Système : kill(), signal(), getpid()
Indication
-Exécuter le programme "Boucle" dans un terminal en lui
passant un numéro du signal en paramètre
-Récupérer le pid du programme "Boucle"
-Lancer un deuxième terminal
-Exécuter le programme "Envoi" dans le nouveau terminal en lui
passant en paramètre le pid de "Boucle" et le même signal
redéfini par "Boucle"