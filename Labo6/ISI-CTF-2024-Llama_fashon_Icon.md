
# ISI-CTF-2024 – Llama Fashon Icon

* **Auteurs:** 
	* Vasques Dario
	* Mariaux Ewan
	* Pollien Lionel
	* Lopes Dos Santos Rodrigo
* **Categorie:** choix : Web
* **Points:** 100 points


## Challenge

**URL du challenge :** http://10.190.133.43:4005/

**Texte d'introduction du challenge :**

> Bienvenue dans la Time Machine.
> Essayez de récupérer le fichier comportant le flag !

**Hints :** (si utilisés)

- Hint 1
- Hint 2


## Tentatives

1. Navigation à travers la page afin de trouver comment accéder au flag
2. Découverte que lorsqu'on clique sur un bouton un paramètre ?page est rajouté
3. Teste d'afficher un fichier nommé flag.txt


## Solution finale

Explication de la solution.

Il fallait rajouter ?page=flag.txt pour afficher le fichier contenant le flag.


## Flag

Le flag était : 
> FLAG = ctf22{P@stFutur3Pr3s3nt}


## Mitigations possibles

Les mitigations suivantes sont envisageables :

- Rendre les paramètres des URLs invisible pour les clients



