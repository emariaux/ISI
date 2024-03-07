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

### Question 2.10 - Entre 0 et 8 caractères alphanumériques (sensible à la casse) ?

### Question 2.11 - Exactement 1 caractère ASCII (7 bits) ?

### Question 2.12 - Exactement 8 caractères ASCII ?

### Question 2.13 - Entre 0 et 8 caractères ASCII ?


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
NTLM = 1000 pour XP Hasch
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
Le mode d'attaque par défaut est l'attaque dictionnaire.

### Manipulation 4.2


