#Explications du Fonctionnement du Projet

## Répartition des Modules:

- Baptiste RAMONDA : Module de base Utils + Module avancé Activation
- Robin DUTRIAUX : Module de base Matrice_Accesseurs + Module avancé Réseau
- Pierre PINCON : Module avancé Matrice_Opérations
- Titouan COUVRAT--PAILLE : Module de base Matrice

Les modules qui ont été attribués à chaque membre du groupe ci-dessus ne sont qu'une indication de la personne qui a push le module.
En réalité les modules ont été réalisés en duo/trio grâce au partage d'écran. Ainsi tout le monde pouvait corriger le code d'un autre membre
et cela nous a permis d'être plus efficaces et de moins faire d'erreurs.

### Commentaires sur les méthodes de travail de chacun

Pour ma part j'ai hésité à travailler sur Cloud 9, mais le fait que l'on ait organisé déjà tout cet IDE pour les TP m'a poussé à continuer à
travailler sur AWS. La plus grande difficulté au départ a été de réussir à faire compiler le Makefile, et c'est pour ça que tant que ce
problème n'avait pas été réglé, j'ai été contraint de faire un premier jet de mes fonctions sur le logiciel CodeBlocks qui me permettait de 
voir si mon travail été cohérent. Lorsque le problème du Makefile a été résolu, nous avons pu commencer à travailler dans le dur du sujet.
J'ai commencé par me pencher sur le module de base Utils, qui, je l'avoue, a été assez difficile car je trouve que l'on avait pas
suffisamment d'explications sur ce que devait précisément faire les fonctions. Ce module nous a donc pris pas mal de temps. Une fois ce travail
terminé. J'ai décidé de travailler sur le module avancé Activation, car Titouan et Pierre avaient déjà travaillé ensemble sur les modules 
matrices et ont donc souhaité continuer pour poursuivre dans leur lancée. Avec Robin nous avons commencé le module activation ensemble et après
avoir un peu éclairci les rôles de chaque fonction (un peu grâce à l'aide de la professeur du TPA31) nous avons réussi à facilement trouver
le pattern principal de chaque fonction. Et dans les jours qui suivaient j'ai fini de compléter et de fignoler les derniers détails afin que ces
deux modules compilent parfaitement sans erreur ni avertissement. Si nous avions eu un peu plus de temps nous aurions adoré nous pencher sur les
autres modules avancés (et même les "au delà du raisonnable" pourquoi pas ?), même si la diificulté de ceux-ci nous a déjà pas mal posé
problème.
                Baptiste RAMONDA.
                
En ce qui me concerne travailler sur Cloud9 n'a pas fait l'objet beaucoup de doutes car tous les autres environnements m'avaient paru moins clair
dans leur utilisation et les TP avaient déjà été commencés sur Cloud9 la majeure difficulté rencontréee au début du projet fut de faire marcher 
le Makefile, difficulté résolue non sans mal par Baptiste RAMONDA. Au niveau de la répartition des tâches il était prévu que je commence par le
module matrice, m'étant penché dessus le premier, mais finalement Titouan s'en occupera en partage d'écran avec moi. Le module matrice bien assimilé 
j'ai pu me lancer dans le module matrice.operation en partageant mon écran avec Titouan COUVRAT--PAILLE afin d'être plus efficace et d'éviter des 
erreurs de syntaxe et d'inattention. Pour le module matrices.operations la principale difficulté fut de ne pas s'emmêler parmi toutes les variables 
et les boucles. Néanmoins la difficulté algorithmique du module restait très abordable surtout dû au fait que les dimensions des matrices étaient 
convenantes. Le défaut principal des fonctions faites dans ce module est leur complexité puisque tout ou presque en n cube ce qui fait que pour des 
matrices de taille très grande les fonctions seront très lentes. Cependant avec nos connaissances actuelles de l'algorithmique il était difficile 
de faire mieux que trois boucles for imbriquées. Les modules les plus avancés nous paraissaient fort intéressants à traiter, mais notre plus gros 
problème était que nous avions l'impression d'être imperméables aux problèmes: nous ne savions ni par où commencer, ni vers quoi nous diriger. 
Je pense que ce qui nous manquait n'était pas de la connaissance du langage mais de l'aisance avec les raisonnements algorithmiques.
                Pierre PINCON.
