# Labo 5 - Manipulations Mémoire

## Partie 1 : Application de test
### Question 3.1
> Quelle est la valeur de la variable x affichée à la fin du programme principal ?

x = 2

### Question 3.2
> La première incrémentation de x

### Question 3.3
> La seconde incrémentation de x

### Question 3.4
> L'appel à l'affichage de la variable x


### Question 3.5
> Calculer l'offset entre l'adresse de retour de la fonction function() et le code de la
première incrémentation de x. Détailler le calcul.

### Question 3.6
> Calculer l'offset entre l'adresse de retour de la fonction function() et le code de la
seconde incrémentation de x. Détailler le calcul.

### Question 3.7
> Calculer l'oset entre l'adresse de retour de la fonction function() et le code de l'appel
à l'affichage de la variable x. Détailler le calcul.


### Question 3.8
> Fournir une capture du code désassemblé de la fonction function().


### Question 3.9
> Donner la valeur des registres dénissant la pile, à savoir ESP et EBP (ou RSP et
RBP).

### Question 3.10
> À l'aide du code C++ et assembleur, donner l'adresse de la variable locale  classe ,
sachant que cette variable est un pointeur sur un tableau d'entiers.

### Question 3.11
> À partir de ce pointeur sur le tableau  classe , donner les adresses de classe[0],
classe[1], classe[2], et classe[3].

### Question 3.12
> À l'aide du code C++ et assembleur, donner l'adresse de la variable locale  grade ,
sachant que cette variable est un pointeur sur un tableau d'entiers.

### Question 3.13
> À partir de ce pointeur sur le tableau grade, donner les adresses de grade[0],grade[1],
grade[2], et grade[3].

### Question 3.14
> À partir des informations précédentes, dessiner la pile (cela inclut les variables locales
 classe  et  grade , la sauvegarde du registre EBP (ou RBP) et la sauvegarde
du registre EIP (ou RIP)). Indiquer aussi par une èche à quelle adresse pointent
EBP (RBP) et ESP (RSP) respectivement. Représenter la pile juste avant de sortir
de la fonction. Votre représentation de la pile doit comprendre, pour chaque élément
mentionné ci-avant, son adresse, sa description (ex : nom de la variable) et sa valeur

### Question 3.15
> Enlever les commentaires devant l'instruction classe[7] += 10 ; puis expliquer ce
qu'il se passe et pourquoi.


### Question 3.16
> Modifier grade[1] à partir du tableau  classe . Pour cela, calculer les indices pour
tomber juste ! Indiquer la ligne à ajouter juste avant l'instruction modiée précédemment et prouver, à l'aide d'une capture d'écran de la représentation de la mémoire, que
la mémoire a bien été changée comme souhaité. Commenter et expliquer le phénomène.

### Question 3.17
> Modier cette instruction pour eectuer un stack overow et pour que le programme
ache x=1. Justier en indiquant la valeur de saut d'adresse, la méthode employée et
l'instruction C++ qui remplace le code précédent


### Question 3.18
> Quelle est la valeur d'EIP/RIP stockée en mémoire avant la dernière instruction de
la fonction ? Quelle est sa valeur après la dernière instruction (juste avant de sortir de
la fonction) ? Illustrer la réponse avec deux captures d'écran représentant la mémoire
avant et après la modication de la valeur EIP.

### Question 3.19
> Comment modier le stack overow pour acher x=0 ? Justifier en indiquant la
valeur de saut d'adresse, la méthode employée et l'instruction C++.

### Question 3.20
> Enlever les commentaires devant l'instruction classe[7] += 10 ; puis expliquer ce
qu'il se passe et pourquoi.

## Partie  2 : feuille-caillou-ciseaux

### Question 4.1
> Indiquer comment utiliser la faille fonctionnelle permettant de gagner à tous les coups.
Illustrer la réussite par une capture d'écran du programme.


### Question 4.2
> Expliquer, au niveau du code, comment cette attaque fonctionne. Décrire les modi-
cations à apporter au programme pour xer cette faille.

### Question 4.3
> Représenter la pile de la fonction evalue_fcc() lorsque toutes les variables locales
sont déclarées a
. Cette étape est importante car elle vous permet de savoir comment
la pile est organisée (en 32 ou 64 bits) et cela vous aidera grandement pour réaliser le
 stack overow .
a. Utiliser la même représentation de la pile et les mêmes éléments que demandés à la question
3.14


### Question 4.4
> Chercher un moyen de modier la pile. Étant donné que le joueur n'a que peu d'entrées
possibles (identiant, choix feuille-caillou-ciseaux), cela ne doit pas être compliqué.
Quel paramètre permet de modier la pile ? Quelle valeur faut il lui donner pour
atteindre la valeur sauvegardée d'EIP/RIP ?

### Question 4.5
> Grâce à la question précédente, il est donc possible de modier l'adresse de retour.
Quel paramètre contrôle l'incrément de la valeur d'EIP/RIP ?

### Question 4.6
> Donner la logique de l'attaque (par rapport au code C++). Quelles instructions devraient être sautées ?

### Question 4.7
> Quelle serait la valeur de l'incrément d'EIP/RIP permettant de gagner ? Justier la
réponse.


### Question 4.8
> EL'attaque ayant été analysée, il reste à la réaliser. Fournir une capture d'écran prouvant
"la triche" (en ayant le score de 0 à la n). Le déroulement du programme ainsi que
le message de bienvenue au score nal doivent bien évidemment y gurer.

