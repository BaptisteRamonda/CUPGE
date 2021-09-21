CUPGE is the new SNCF.


Information sur le réseau.

Le réseau de train est une structure composé de Lignes, de Trajets et de Villes.
- Les Villes sont des composées de int. La fonction returnNomDeVille(int v) permet de passer d'un int a VILLE.

- Les Trajets sont composés de deux Villes, une de départ (depart) et une d'arrivée (arrivee). Les Trajets sont uniquement entre deux Villes directement reliés entre elles, il n'y a pas d'étapes intermédiaires. Un Trajet contient aussi le temps que le train met pour aller d'une Ville depart a celle d'arrivee (temps) , et aussi du nombre de places restantes disponibles sur ce Trajet spécifique (nbPlacesRestantes) . Ce nombre de place max est indiqué par la constante NBPLACES. 

- Les Lignes sont composées d'un tableau contenant les Villes qu'elle dessert tEtapes[], un tableau contenant les Trajets reliant ces Villes tTrajetsPartiels[]. la sous-variable nbEtapes indique la taille de la ligne, le nombre de Ville qu'elle contient.

Le reseau est ainsi initialisé avec Lignes, Paris-Marseille, Paris-Toulouse, Bordeaux-Nice et Paris-Lyon, stockés dans la sous-variable tLignes[]. Le reseau a aussi des variables nbVille et nbTrajets qui indiquent le nombre de Villes et Trajets desservis.

La fonction matAdj(r) cree la matrice d'adjacence d'un reseau. Elle est utilisé pour Dijkstra.
