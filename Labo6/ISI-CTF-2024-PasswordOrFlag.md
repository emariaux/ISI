
# ISI-CTF-2024 – A password or a flag... that's the question

* **Auteurs:** 
	* Vasques Dario
	* Mariaux Ewan
	* Pollien Lionel
	* Lopes Dos Santos Rodrigo
* **Categorie:** choix : forensic
* **Points:** 266


## Challenge

**URL du challenge :** http://10.190.133.43/challenges#A%20password%20or%20a%20flag...%20that's%20the%20question-9

**Texte d'introduction du challenge :**

> L'Armée suisse vous demande de récupérer un mot de passe dans un fichier shadow trouvé sur l'ordinateur d'un hacker.

**Hints :** (si utilisés)

- Hint 1
- Hint 2


## Tentatives

1. J'ai d'abord chercher dans le trame SSH aux alentours des échanges de clé.
2. Chercher dans les trames TELNET. 



## Solution finale

```
labo:$6$0YJZLUI2$TeK5d8yCuoibo2wms3036tW5WNM3c0eawaEd52O8C.V83D8rII2UoOh4j8ZnIL0hIyqnXDsAmYcJSG.bh1WmC0:17689:0:99999:7:::
```

- $6$ nous permet de savoir que c'est du SHA-512 qui a été utilisé.
- 0YJZLUI2 est le sel utilisé.
- TeK5d8yCuoibo2wms3036tW5WNM3c0eawaEd52O8C.V83D8rII2UoOh4j8ZnIL0hIyqnXDsAmYcJSG.bh1WmC0 est le mot de passe haché.

Utilisation de l'outil **Johne the ripper** afin d'obtenir le mot de passe.




## Flag

Le flag était : 
> FLAG = ISI22{4ws0mePc4pfl4g}



## Mitigations possibles
La mitigation suivante est envisageable :

- bloquer la connexion telnet à la machine Kali




