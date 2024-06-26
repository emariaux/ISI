
# ISI-CTF-2024 – OTP

* **Auteurs:** 
	* Vasques Dario
	* Mariaux Ewan
	* Pollien Lionel
	* Lopes Dos Santos Rodrigo
* **Categorie:** choix : Web
* **Points:** 212


## Challenge

**URL du challenge :** http://10.190.133.43/challenges#One%20Time%20Password-17
**Texte d'introduction du challenge :**

> Aujourd'hui en cette belle journée ensoleillée, vous décidez d'en profiter pour aller à la piscine avec votre ami Robert. Mais ce dernier n'arrête pas de dire que son string "borat" est plus stylé que le vôtre. Vous décidez alors d'aller chercher le vôtre dans votre casier de vestaire, protégé par un OTP. Malheureusement, votre device de validation d'accès ne fonctionne plus...

Trouvez une attaque pour contourner l'OTP et ouvrir votre casier.

Comme ça vous pourriez comparer votre string avec celui de Robert.

**Hints :** (si utilisés)

Aucun hint utilisé


## Tentatives

1. Nous avons essayer plusieurs jetons banal du style 000000, 111111, etc...
2. Injection SQL
3. Brute force du mot de passe, ce qui n'était pas concluant vu le nombre élevé de possibilité.

## Solution finale

Dans la consigne, il était indiqué en **gras** :  **comparer votre string avec celui de Robert.**

De ce fait, nous avons utilisé un proxy.
Dans notre cas BurpSuite.

Le champ de la page web est limité aux chiffres et à 6 caractères.
Il est donc essentiel d'utiliser un proxy pour modifier la requête.

Afin de réussi le challenge, il faut modifier la requête http comme ci-dessous :
```http
GET /index.php?otp[]=123456&otp[]=1 HTTP/1.1
```

Cela permet de manipuler le traitement de la variable 'otp' comme un tableau en PHP.
Le tableau contiendrait donc deux valeurs : 123456 et 1.
Le serveur va comparer la première valeur (1234566) avec la valeur valide.
Cela va être faux. Cependant avec la deuxième valeur vu que le serveur est mal configuré pour contrer cette attaque, il interpète l'authentification comme valide.


## Flag

Le flag était : 
> FLAG = ISI22{c2E0NTY0OGRzYWRzYWFzZH}



## Mitigations possibles
La mitigation suivante est envisageable :

- Limiter les paramètres acceptés : Configurer sur le serveur qu'il y a que le type nombre qui est valide et uniquement un seul paramètre.
- Modification de la comparaison du OTP entrée et du OTP valide : Remplacer la condition par `===` afin que le type soit aussi comparé.
- Refuser la connexion si le nombre ne correspond pas : Mise en place d'un if else par exemple.


