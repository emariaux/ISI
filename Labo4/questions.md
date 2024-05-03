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

