# Labo 4 - Cryptographie

## RC4 / découverte du « keystream »
### Question 2.1
> Donnez le nom de la variable contenant l’état interne, ainsi que son type.

L'état interne est stocké dans la variable `s`, cette dernière est un tableau de type int avec une taille de 256.

### Question 2.2 
> Donnez le nom de la variable contenant la clé secrète, ainsi que son type.

La clé secrète est stocké dans la variable `lpkey`, cette dernière est un pointeur sur char constant (const char*).

### Question 2.3 
> Donnez le bloc de code qui initialise l’état interne.

```
for (a = 0; a < 256; a++) {
     s[a] = a;
}
```

### Question 2.4 
> Donnez le bloc de code qui effectue le mélange de l’état interne en fonction de la clé.

```
for (a = 0; a < 256; a++) {
  c = (c + s[a] + lpKey[a % dwKeyLen]) % 256;
  swap = s[a];
  s[a] = s[c];
  s[c] = swap;
}
```

### Question 2.5
> Donnez le bloc de code qui génère le keystream et effectue le chiffrement ou déchiffrement.

```
a = 0;
c = 0;
for (dwCount = 0; dwCount < dwBufLen; dwCount++) {
  a = (a + 1) % 256;
  c = (c + s[a]) % 256;
  swap = s[a];
  s[a] = s[c];
  s[c] = swap;
  lpBuf[dwCount] ^= s[(s[a] + s[c]) % 256];
}
```

### Question 2.6
> En possédant à la fois un document clair (soit P) et son équivalent chiffré (soit C),
> expliquez comment il est possible de retrouver le keystream (KS) utilisé pour le chiffrement.

En effectuant la différence entre le document clair et son équivalent chiffré, cette dernière correspond à un nombre qu'on a ajouté ou soustrait à notre texte en clair pour le chiffrer.

Ce nombre constitue le keystream.

### Question 2.7
> Si deux fichiers de même taille sont chiffrés avec la même clé, que pouvons-nous dire
> des deux keystream utilisés pour chiffrer ces deux documents ?

Etant donné que les keystreams ont été générés depuis la clé, ils sont identiques.

### Question 2.8
> Quel problème de cette implémentation nous a permis de décrypter cette seconde
> image ? Donnez la formule mathématique qui vous a permis de déchiffrer la 2ème
> image dans la manipulation 2.1.
> Insérez également une copie de l’image montrant le résultat.

Etant donné que les deux images ont été chiffrées avec la même clé RC4, cela signifie que le keystream généré par RC4 pour chiffrer la première image est le même que celui utilisé pour la deuxième.

En effectuant l'opération XOR entre les deux images cryptées, il se possible de récupérer l'image en clair.

Ci-dessous, l'image résultant de cette opération :
![](./sources/RC4-1/part1_02.bmp)

### Question 2.9
> Nous avons utilisé le keystream pour déchiffrer la seconde image. Serait-il possible
> d’également retrouver la clé utilisée ? Si oui, décrire comment.

Même en ayant le keystream utilisé, il sera compliqué voire impossible de récupérer la clé, sauf si cette dernière est de mauvaise qualité.

## RC4 / Deux images chiffrées avec la même clé
### Question 3.1
> On peut noter que le keystream utilisé pour le chiffrement des deux images est identique. Avec cette information, que peut-on obtenir comme > > information sur les images en clair ?

Les images ne seront pas identiques, cependant elles auront des similarités structurelles.

### Question 3.2
> Quel est le texte caché dans ces images ? Insérez également une copie des images superposées.

Le texte caché dans ces images est LABO Crypto.

![](./sources/RC4-2/part2_mix.bmp)

### Question 3.3
