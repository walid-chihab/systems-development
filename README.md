# 🖥️ Programmation Système sous Linux en C

[![C](https://img.shields.io/badge/Language-C-blue.svg?style=for-the-badge&logo=c)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Linux](https://img.shields.io/badge/Platform-Linux-FCC624?style=for-the-badge&logo=linux)](https://www.linux.org/)
[![License](https://img.shields.io/badge/License-MIT-green.svg?style=for-the-badge)](LICENSE)
[![GitHub last commit](https://img.shields.io/github/last-commit/walid-chihab/Programmation_systeme-?style=for-the-badge)](https://github.com/walid-chihab/Programmation_systeme-)

## 📋 Description

Ce dépôt contient mes travaux pratiques et projets en **programmation système** sous Linux/Unix. J'y explore les concepts fondamentaux du système d'exploitation à travers des exemples concrets en C.

### Objectifs pédagogiques :
- Maîtriser la création et la gestion des processus (`fork`, `exec`, `wait`)
- Comprendre la communication inter-processus (IPC) avec les tubes (`pipe`)
- Apprendre à gérer les signaux et les interruptions
- Développer des outils système simples

## 👨‍💻 Auteur

**Walid Chihab**

Programmation_systeme/
├── 📁 01-processus/           # Gestion des processus (fork, wait, exec)
│   ├── 📄 fork-simple.c       ![Status](https://img.shields.io/badge/Status-Completed-success?style=flat-square)
│   ├── 📄 fork-wait.c
│   └── 📄 fork-exec.c
├── 📁 02-communication/       # IPC (Inter-Process Communication)
│   ├── 📄 pipe-simple.c       ![Status](https://img.shields.io/badge/Status-In--Progress-orange?style=flat-square)
│   └── 📄 pipe-pere-fils.c
├── 📁 03-signaux/             # Signaux et interruptions système
│   ├── 📄 signal-simple.c
│   └── 📄 kill-demo.c
└── 📁 04-projets/             # Projets de synthèse
    └── 📁 mini-shell/         ![Project](https://img.shields.io/badge/Project-Mini--Shell-blueviolet?style=for-the-badge)
        └── 📄 shell.c

