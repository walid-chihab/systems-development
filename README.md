# 🖥️ Programmation Système sous Linux en C

[![C](https://img.shields.io/badge/Language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Linux](https://img.shields.io/badge/Platform-Linux-FCC624?logo=linux)](https://www.linux.org/)
[![License](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)
[![GitHub last commit](https://img.shields.io/github/last-commit/walid-chihab/Programmation_systeme)](https://github.com/walid-chihab/Programmation_systeme-)

## 📋 Description

Ce dépôt contient mes travaux pratiques et projets en **programmation système** sous Linux/Unix. J'y explore les concepts fondamentaux du systeme d'exploitation à travers des exemples concrets en C.

### Objectifs pédagogiques :
- Maîtriser la creation et la gestion des processus (`fork`, `exec`, `wait`)
- Comprendre la communication inter-processus (IPC) avec les tubes (`pipe`)
- Apprendre à gerer les signaux et les interruptions
- Developper des outils systeme simples

## 👨‍💻 Auteur

**Walid Chihab**



## 📂 Structure du dépôt
Programmation_systeme/
│
├── 01-processus/ # Création et gestion de processus
│ ├── fork-simple.c # Création basique avec fork()
│ ├── fork-wait.c # Attente de la fin du fils
│ └── fork-exec.c # Lancement d'un autre programme
│
├── 02-communication/ # Communication inter-processus
│ ├── pipe-simple.c # Tube de communication
│ └── pipe-pere-fils.c # Dialogue père-fils
│
├── 03-signaux/ # Gestion des signaux
│ ├── signal-simple.c # Attraper un signal
│ └── kill-demo.c # Envoyer un signal
│
└── 04-projets/ # Projets complets
└── mini-shell/ # Mini interpréteur de commandes
