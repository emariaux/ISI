# Labo 3 - Web

## Partie 1 - Application mail 1
### Manipulation 4.2
> Tenter une escalation de privilèges. L’objectif est d’être réellement connecté en tant
que l’utilisateur « admin », avec son rôle (et privilèges), son login et son identifiant
(id) !
Il est important de ne pas compromettre l’utilisation de l’application, c’est-à-dire de
ne modifier aucune donnée

Il suffit simplement de modifier l'url en mettant l'id 1 qui correspond à l'utilisateur admin à la place de l'id 2 qui correspond à l'utilisateur test.

https://isi-labs.iict.ch/gr30/part1/member.php?id=1

### Question 4.1
#### a) 
> Quel type d’attaque est effectuée ici ?

Une tentative d'escalade de privilèges, visant à obtenir des privilèges d'administrateur sur l'application Web (détournement de session).

#### b)
> Quelle technique d’exploitation avez-vous utilisée ?
La technique d'exploitation utilisé est une faille dans l'application donnant accès aux autres comptes, et cela grâce à une injection SQL.

#### c)
> Détailler la méthode utilisée pour se connecter en tant que « admin ».

Il suffit simplement de modifier l'url en mettant l'id 1 qui correspond à l'utilisateur admin à la place de l'id 2 qui correspond à l'utilisateur test.

https://isi-labs.iict.ch/gr30/part1/member.php?id=1

### Question 4.2
> Quelle est/sont la/les vulnérabilité(s) du top10 de l’OWASP (2021) présente(s) ici (et
qui permet(tent) de se connecter en tant qu’admin) ?

Plusieurs vulérabilités de ce site sont relatées dans le rapport.
Voici la liste :
- A04:2021-Insecure Design
- A05:2021-Security Misconfiguration
- A06:2021-Vulnerable and Outdated Components
- A07:2021-Identification and Authentication Failures

### Question 4.3
>Comment pourrait-on remédier à cette faille ? Justifiez

En ne spécifiant pas l'id d'un user directement dans l'URL.
Cela permettrait de ne pas pouvoir uniquement modifier l'URL afin de se connecter avec un autre compte.


