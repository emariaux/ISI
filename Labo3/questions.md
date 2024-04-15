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
Détournement de session en changeant l'url afin d'accéder à un autre utilisateur.

#### b)
> Quelle technique d’exploitation avez-vous utilisée ?


#### c)
> Détailler la méthode utilisée pour se connecter en tant que « admin ».
Il suffit simplement de modifier l'url en mettant l'id 1 qui correspond à l'utilisateur admin à la place de l'id 2 qui correspond à l'utilisateur test.

https://isi-labs.iict.ch/gr30/part1/member.php?id=1

### Question 4.2
> Quelle est/sont la/les vulnérabilité(s) du top10 de l’OWASP (2021) présente(s) ici (et
qui permet(tent) de se connecter en tant qu’admin) ?

