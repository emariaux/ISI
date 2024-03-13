# Labo 1 - Craquage de mot de passes

## Calculs de sécurité théorique
### Question 2.1 - Exactement 1 caractère numérique ?
Il y a 10 possibilités.

### Question 2.2 - Exactement 2 caractères numériques ?
Il y a 10^2 possibilités.

### Question 2.3 - Exactement 6 caractères numériques ?
Il y a 10^6 possibilités.

### Question 2.4 - Entre 0 et 6 caractères numériques ?
Il y a 1 + 10^2 + 10^3 + 10^4 + 10^5 + 10^6 possibilités.

### Question 2.5 - Exactement 1 caractère alphanumérique (non sensible à la casse) ?
Il y a 36 possibilités.

### Question 2.6 - Exactement 8 caractères alphanumériques (non sensible à la casse) ?
Il y a 282.11 * 10^10 possibilité.

### Question 2.7 - Entre 0 et 8 caractères alphanumériques (non sensible à la casse) ?
Il y a 1 (36^0) + 36 (36^1) + 1296 (36^2) + 46656 (36^3) + 167 * 10^4 (36^4) + 604 * 10^3 (36^5) + 217 * 10^5 (36^6) + 783 * 10^10 (36^7) + 282 * 10^12 (36^8) possibilités.

### Question 2.8 - Exactement 1 caractère alphanumérique (sensible à la casse) ?
Il y a 62 possibilités.

### Question 2.9 - Exactement 8 caractères alphanumériques (sensible à la casse) ?
62^8 possibilités 
### Question 2.10 - Entre 0 et 8 caractères alphanumériques (sensible à la casse) ?
1 + 62 + 62^2 + 62^3 + 62^4 + 62^5 + 62^6 + 62^7 + 62^8
### Question 2.11 - Exactement 1 caractère ASCII (7 bits) ?
128
### Question 2.12 - Exactement 8 caractères ASCII ?
128^8 possibilités 
### Question 2.13 - Entre 0 et 8 caractères ASCII ?
1 + 128 + 128^2 + 128^3 + 128^4 + 128^5 + 128^6 + 128^7 + 128^8

### Question 2.14 Combien de temps faudra-t-il « en moyenne » pour casser un mot de passe de la question 2.6 ?
Il faut la moitié donc 0.5 jours = 12 heures

### Question 2.15 Toujours avec la même base, combien de temps faudra-t-il « au maximum » pour casser un mot de passe de la question 2.12 ?
282.11 * 10^10 = 1 jour
128^8 = 25542.37 jour
### Question 2.16 Combien de temps faudra-t-il « en moyenne » pour casser un mot de passe de la question 2.12 ?
25542.37 jour / 2 = 12771.19 jours


### Question 2.17 En considérant des attaques « hors ligne », décrire trois manières de freiner (soit bloquer, soit ralentir) l’attaquant ?


### Question 2.18 En considérant des attaques « en ligne », décrire deux manières de freiner (soit bloquer, soit ralentir) l’attaquant ?

### Question 2.19 Les mots de passe ne sont pas stockés en clair, pourquoi ?

### Question 2.20 Les mots de passe ne sont pas stockés en clair, mais pourtant ils ne sont pas chiffrés, pourquoi ?

### Question 2.21 Sous quelle forme sont stockés les mots de passe ?

## 3 Identification des empreintes des mots de passe

### Question 3.1
#### Fichier KaliHash.txt
```
eve:$1$4sj69SxM$5Hh9C.gRF7UT17Wz3HIqF/:17053:0:99999:7:::
mallory:$1$ymwtXJQY$e8tMKmtotzkYLFqKgP/6q0:17053:0:99999:7:::
alice:$1$iQlQrcnz$qmUTfRdy7A.aEWFbxaCks1:17053:0:99999:7:::
bob:$1$0N.qY.ZR$3C.cM68sYQMpvRqrli2R60:17053:0:99999:7:::
dave:$1$a.YWY6/x$wm/D7ev3eS5jC3VbRYjg5.:17053:0:99999:7:::
carol:$1$5kT6bbgA$k7yAdihlsyqwwqIr3ffsG/:17053:0:99999:7:::
oscar:$1$HoxVfeez$iyJuR/nnBvUxs8TgvdDhU/:17053:0:99999:7:::
trudy:$1$HeZRtVDU$sXnJlrlXkp5WijAJ4bswg.:17053:0:99999:7:::
```
C'est tous du MD5 car le hash début par '$1'$ qui correspond à l'identifiant du MD5 pour le hash dans Linux


##### Fichier XPHash.txt
```
Eve:1001:c31a24469a55166faad3b435b51404ee:04b365a8953171d1e9decf74feb7ecac:::
Mallory:1002:99194A696E6DEDE07EB75CA3794CB4A9:78817779602482E0219A0C97D71DDE90:::
Alice:1003:4738b39ea1ebbf44aad3b435b51404ee:82cf6feab03795ff1e1b7e3b43e9764e:::
Bob:1004:3D8C2EB1357B87C425AD3B83FA6627C7:A3A776245051E861E35D0A172FE0BC34:::
Dave:1005:C1665B7DB2F988E8F8690B0965ADA5B0:B295D7DD10B0AFE1B6BBCE24B74B8663:::
Carol:1006:ADBF7A1FB75875C8AAD3B435B51404EE:F57300698A5B0B55234837D920EAA3EE:::
Oscar:1007:36AB09A9560E3372AAD3B435B51404EE:46599A6541E638A90AFBA723AD58DF81:::
Trudy:1008:7110B4ED1C72AA241AA818381E4E281B:2D909D6BD6282076B6F0B5ABBC40BB96:::
```
C'est du  NTLM car sur Windows XP c'est NT LAN Manager Hash qui est utilisé et ce dernier se base sur le MD4.

## 4 Hashcat

### Manipulation 4.1
``` bash
sudo gzip -d /usr/share/wordlists/rockyou.txt.gz
sudo cp /usr/share/wordlists/rockyou.txt Documents/rockyou.txt
``` 
hashcat -m 1000 -a 0 -o Documents/output.txt Documents/XPHash.txt Documents/rockyou.txt

### Question 4.1
(https://hashcat.net/wiki/doku.php?id=example_hashes)
NTLM = 1000 pour XP Hash
Pour l'option -m nous avons des codes qui représentent chaque type de hachage.
Pour le NTLM c'est 1000.
Concernant le MD5 il y en a plusieurs.
Dans notre cas, nous avons le MD5 unix qui a le code 500

### Question 4.2

C'est l'option a qui définit le type d'attaque que ne souhaitons réalisé.
Voici les différentes solutions.

0 : Attaque par dictionnaire. Utilise une liste de mots (un dictionnaire) comme mots de passe potentiels.

1 : Attaque combinée. Combine des mots de deux listes de mots différentes de manière à créer de nouveaux mots de passe potentiels.

3 : Attaque par force brute. Génère toutes les combinaisons possibles de caractères jusqu'à ce que le mot de passe soit trouvé.

6 : Attaque hybride Dictionnaire + Masque. Commence par un mot du dictionnaire et ajoute des combinaisons de caractères à la fin.

7 : Attaque hybride Masque + Dictionnaire. Commence par des combinaisons de caractères et ajoute un mot du dictionnaire à la fin.

### Question 4.3
Le mode d'attaque par défaut est l'attaque dictionnaire donc le code 0.

### Manipulation 4.2
On peut voir qu'on n'a pas obtenu tous les mot de passes, cela est dû au faite qu'ils n'ont pas été trouvés dans le dictionnaire.

#### XPHash
``` bash
hashcat -m 1000 -o Documents/output.txt shares/ISI/labo/Labo1/ISI23_labo1_craquage_files/XPHash.txt /usr/share/wordlists/rockyou.txt --force
```

Contenu du fichier output.txt :
```               
82cf6feab03795ff1e1b7e3b43e9764e:funtime
```

#### KALIHash
``` bash
hashcat -m 1000 -o Documents/output.txt shares/ISI/labo/Labo1/ISI23_labo1_craquage_files/KALIHash.txt /usr/share/wordlists/rockyou.txt --force
```

Contenu du fichier output.txt :
```               
$1$iQlQrcnz$qmUTfRdy7A.aEWFbxaCks1:funtime
```

### Question 4.4
Un masque permet de réduire le nombre de possibilité à tester.
Par exemple nous pouvons dire que le premier du caractère sera une majuscule car cela est plus fréquent.
Nous évitons donc de tester 62 possibilités au première emplacement. Nous en avons plus que 26 à faire.

Ils sont utiles dans les modes 3, 6 et 7 de hashcat. Ces derniers essayent des combinaisons de caractères.

### Question 4.5
Ci-dessous, la liste des charsets prédéfinis :
- ?l = abcdefghijklmnopqrstuvwxyz
- ?u = ABCDEFGHIJKLMNOPQRSTUVWXYZ
- ?d = 0123456789
- ?h = 0123456789abcdef
- ?H = 0123456789ABCDEF
- ?s = «space»!"#$%&'()*+,-./:;<=>?@[\]^_`{|}~
- ?a = ?l?u?d?s
- ?b = 0x00 - 0xff

### Question 4.6
Par défaut, le bruteforce utilise 3 types de charsets :
1 - ?l?d?u (lowercase, digits, and uppercase)
2 - ?l?d (lowercase and digits)
3 - ?l?d*!$@_ (lowercase, digits, and five selected special characters)
?1?2?2?2?2?2?2?3?3?3?3?d?d?d?d

En combinaison à cela, il utilise ce masque :
?1?2?2?2?2?2?2?3?3?3?3?d?d?d?d

### Manipulation 4.3

``` bash
hashcat -m 1000 -a 3 -o Documents/output.txt  Documents/XPHash.txt --force
```

Contenu du fichier output.txt :
```               
04b365a8953171d1e9decf74feb7ecac:nceipo
```

### Question 4.7
Afin de tester plusieurs longueur pendnant le brutefoce nous avons plusieurs possiblitiés.
En faisait de l'incrémentation. Tester tous les mots de passes selon un masque entre 5 et 7 caractères.
```bash
hashcat -m 1000 -a 3 -o Documents/output.txt  Documents/XPHash.txt ?a?a?a?a?a --increment --increment-min 5 --increment-max 7  --force
```

### Question 4.8
Nous pouvons définir un nouveau alphabet donc un ensemble de caractères pesonalisé.
Pour cela, nous pouvons rajouter les options -1,-2,-3 chacun correspoond à un nouvel alphabet.
Par exemple si on veut dans notre alphabet abcdef1234 on effectuer la commande suivante.
```bash
hashcat -m 1000 -a 3 -o Documents/output.txt  Documents/XPHash.txt -1 abcdef1234 ?1?1?1

```

### Manipulation 4.4
``` bash
hashcat -m 1000 -a 3 -o Documents/output.txt Documents/XPHash.txt -1 ?l?u ?1?1?1?1 --increment --increment-min 4 --increment-max 7 --force
```
Aucun résultat de trouvé

### Manipulation 4.5

```bash
hashcat -m 1000 -a 3 -o Documents/output.txt  Documents/XPHash.txt ?s?a --increment --increment-max 6 --force
```
Aucun résultat de trouvé

### Manipulation 4.6
```bash
TODO
```

### Manipulation 4.7
```bash
hashcat -m 1000 -a 6  -o Documents/output.txt Documents/XPHash.txt Documents/rockyou.txt  ?a?a
```
#### output.txt
```
78817779602482e0219a0c97d71dde90:juliette173
```

```bash
hashcat -m 1000 -a 7  -o Documents/output.txt Documents/XPHash.txt ?a  Documents/rockyou.txt
```
Aucun résultat

### Question 4.9
Les "rules" sont utilisées pour modifier les entrées de mot de passe lors d'une attaque par dictionnaire. Cela permet de tester plus de mot de passe. En mettant une majuscule au début des chiffres à la fin. Remplacement d'un "e" par "3".
C'est utilisé avec les modes 0 et 1. Les règles sont spécifiées dans un fichier de règles.

### Question 4.10
Il en exite plusieurs.
Letspeak.rule qui remplace les e par un 3 les a par 4 etc...
best64.rule un ensemble de règle pour un large choix de mot de passe.
dive.rule fichier pour des attaques en profondeur
generated.rule règle généré automatiquement avec un beaucoup de transformation.

### Question 4.11
letspeak.rule transfrorme les mots avec des substitutions les e remplacé par 3, a par 4 

### Manipulation 4.8
```bash
hashcat -m 1000 -a 0  -o Documents/output.txt Documents/XPHash.txt -r /usr/share/hashcat/rules/leetspeak.rule
```
Aucun résultat

### Question 4.12
Non, Il y a plusieurs possiblités. Les mots de passe était trop complexe ou nous avons pas utilisé les bon paramètres à certaines étapes avec la commande hashcat.

### Manipulation 5.1
![image](https://github.com/emariaux/ISI/assets/114927416/a67d6c94-b344-4cc9-b3ad-c4899879761d)

### Question 5.1
Le sel rend inutilisable rainbow table car chaque hash est unique selon l'utilisateur. Car chaque utilisateur à un sel unique. Il n'est donc pas possible de comparer les hash. Par exemple si deux utilisateurs mettent le mot de passe "1234" le hach sera différent pour chacun d'entre eux. Donc les rainbow table ne peuvent pas comparer le hash.

## Résultat :
### Question 6.1
|            | Mot de passe  | Outil   | Méthode |
|------------|---------------|---------|---------|
|Eve         | nceipo        | hashcat | -a 3 bruteforce |
|Mallory     | juliette173   | hashcat | -a 6 dictionnaire + mask|
|Alice       | funtime       | hascat  | -a default dictionnaire|
|Bob         | !XS8D?@ | rainbow table  | |
|Dave        | 57R4WB3 | rainbow table| |
|Carol       | RDQOM|  rainbow table| |
|Oscar       | ?XA1W| rainbow table | |
|Trudy       | 9823029 | rainbow table| |

### Question 7.1
|    | Hashcat | Rainbow talbes | Explications |
|------------|---------------|---------|---------|
| Méthode(s) de craquage | + | - | Le hashcat est mieux car il fonctionne même un sel si on bruteforce. Rainbow table fonctionne uniquement sans sel. |
|Temps de craquage | - | + | Rainbow table est plus rapide lorsque l'on a déjà les hash. Hashcat peut prendre long afin de tester les multiples posssibilités. |
|Temps de préparation avant craquage| + | - | Haschat est rapide à préparer il nous suffit d'avoir le/les hash et un dictionnaire si nécessaire. Rainbow tables peut être long si on doit créer une table. Cependant si elle est déjà calculé cela est rapide. |
|Craquage sur tous les OS| +| + | Les deux sont multi OS. Après on ne peut pas crack un mot de passe Linux avec Rainbow tables|

### Manipulation 8.1
Impossible d'utiliser l'outil. TODO
### Question 8.1
TODO
### Question 8.2
Rainbow tables il a un map entre les hash et les mots de passe en clair. Il regarde dans toute la base de données afin de voir s'il y a une correspondance.

### Question 8.3
Si ce n'est pas un mot de passe qui est dans la base de données, CrackStation ne pourra pas le retrouver. 

