# Ignore SIGINT

Exercice 1
Ecrire le programme C qui permet d'ignorer le signal SIGINT
(ctrl^C) pour un certain nombre de seconde passé en paramètre.
Appels Système : signal(), kill(), sleep()
Indication
-Redéfinir le signal SIGINT en utilisant SIG_IGN
-Mettre le processus en attente par la fonction sleep()
-Revenir au comportement initial de SIGINT en utilisant
SIG_DFL