# Gestion-des-processus-sous-Linux

Un processus est un programme en cours d'exécution. Par exemple, chaque fois que l'on lance
la commande ls, un processus est créé durant l'exécution de la commande. Un processus est
identifié par un numéro unique que l'on appelle le PID (Process IDentifiant).

La fonction fork fait partie des appels système standard d'UNIX (norme POSIX1). Cette fonction permet à un processus de donner naissance à un nouveau processus qui est sa copie conforme, par exemple en vue de réaliser un second traitement parallèlement au premier. Un bon moyen de visualiser l'effet d'un fork sur un processus est d'imaginer une division cellulaire.

donc ce projet consiste à :

  - donner un exemple type d’exploitation du potentiel de la commande fork() sous Linux.
  - faire passer un processus, et son fils, par tous les états dpossible, en examinant le contenu du
    fichier spécial /proc/<pid>/status.
