# Labo 2 - Malware

## Les maliciels
### Question 2.1 
> Décrire ce qu’est un maliciel ainsi que ses caractéristiques.

Un maliciel est logiciel malveillant se faisant passer pour un programme légitime qui a pour but d'exécuter un code malveillant.

Ses caractéristiques sont les suivantes :
- Capacité de propagation
- Intrusion à travers une source infectée

### Question 2.2 
> Quelles sont les différentes catégories et fonctionnalités des maliciels.

Nous retrouvons ces différentes catégories.

#### Ver
Un ver est un programme qui se reproduit automatiquement et qui se propage de manière autonome à travers le réseau.

#### Cheval de troie 
Un cheval de troie est un programme qui apparaît comme utile, mais en réalité il cache des fonctionnalités malveillantes.

Il permet l'installation d'autres maliciels tel qu'une porte dérobée, un ransomware, etc.

#### Porte dérobée
Une porte dérobée est un logiciel qui permet à des attaquant d'accéder à un système en contournant les contrôles de sécurité, c'est à dire de se connecter, de gérer, d'espioner à distance le système compromis. 

Par exemple un key logging, screen dump, accès à la webcam ou au micro, lecture/écriture/suppresion de fichiers, etc.

#### Botnet
Un botnet est un groupe de bots contrôlant un système.

Ces bots sont utilisés pour mener des attaques depuis l'intérieur d'un réseau tels qu'un DDos, un vol d'identité, un phising, etc.

#### Rootkit
Un rootkit est un code malveillant qui modifie le système d'exploitation dans le but de dissimuler un autre maliciel. 

Il permet de cacher des fichiers, des processus ou des connexions malveillantes.

#### Ransomware
Un ransomware est un logiciel qui a pour but de chiffrer les données d'un système et d'exiger une rançon à la victime en échange de la clé de déchiffrement.

### Question 2.3 
> Tenter de trouver des fonctionnalités non données en cours, faire travailler son imagination !

On pourrait rajouter l'export des mots de passe sauvegardés dans un naviguateur.

## Analyse du Malware « Live Messenger »
### Scène 1 : analyse de l'exécutable

#### Manipulation 5.1
```bash
$ md5sum "Windows Live Messenger.exe" 
a7a75a56b4b960c8532c37d3c705f88f  Windows Live Messenger.exe
```

```bash
$ sha1sum "Windows Live Messenger.exe" 
e69d26db431e383131826fab5db213559ee68814  Windows Live Messenger.exe
```

#### Question 5.1
> Illustrer et expliquer les manipulations effectuées.

Nous avons calculer le checksum pour le md5 et le sha1.
C'est un outil de vérification afin de vérifier que nous avons le .exe originel.

#### Question 5.2
> Que peut-on déduire du fait que les empreintes ne correspondent pas ?

Nous pouvons déduire que le .exe a été modifié. Ce n'est donc pas le version originel de l'exe.

#### Question 5.3
> À votre avis, pourquoi est-il utile de vérifier l’intégrité d’un programme téléchargé ?

Cela nous permet de vérifier l'intégrité du programme. Si le checksum ne correspond pas, nous devons nous méfier du .exe.

### Scène 2 : analyse par snapshots

#### Manipulation 5.2
```bash
$ wine regshot_x64.exe
```

#### Manipulation 5.3
```bash
$ wine " Windows Live Messenger.exe"
```

#### Question 5.4
> À quoi sert l’outil « Regshot » ?

Regshot est un logiciel permettant d'effectuer une capture du système d'eploitation à un instant T, puis un second.
Ensuite, nous pouvons comparer les modifications qui ont été apportés au système durant le laps de temps des deux shots.
Nous pouvons voire les nouvelles clé de registres ou de nouveaux fichiers.

#### Question 5.5
> Pourquoi utiliser un environnement de « test » cloisonné ?
Pourquoi utilise-t-on le « snapshot » dans les logiciels de virtualisation (Virtualbox,
VMware, . . .) ?

Cela nous permet d'excécuter des logiciels malveillant dans des environnement cloisonné.
Donc nous n'impactons pas notre système d'exploitation.
Les snapshots nous permettent de revenir à l'instant T de notre VM.
Cela est utilile lorsque nous effectuons des tests afin de pouvoir revenir a un état non corrompu de la VM.

#### Question 5.6
> Illustrer et expliquer les manipulations effectuées

Dans un premier temps nous avons effectué un regshot de notre VM.
Cela signifie que nous avons capturé notre système à ce moment là.

Ensuite, nous avons excectué le logiciel malveillant.

Nous avons effectué un second regshot.
Pour finir, nous avons comparé les modifications apportées au système entre les deux regshots

#### Question 5.7
> Que constatez-vous dans le rapport généré par Regshot ?

Une nouvelle clé de registe a été créée et deux nouveaux fichiers.

#### Question 5.8
> Que contiennent les fichiers créés par le maliciel ?
Indice : Pour rappel, le dossier C :\ se trouve à l’emplacement
"/home/<username>/.wine/drive_c"

Le fichier c:\pas.txt contient les identificants que j'ai rentré.
```txt
www.ourgodfather.com
Username: wefweiuf
Password: �weiufiwueohfwieufweiufiwebfiuwebf
www.ourgodfather.com
```

Le second correspond à un message d'erreur.
c:\Windows\msnsettings.dat

```txt
hello
0
0
-1
-1
0
0
-1
Please type in an error message
C:\Program Files\MSN Messenger\msnmsgr.exe
0


0
0
0
C:/

```


### Scène 3 : analyse comportementale

#### Manipulation 5.6
```bash
$ strace -e trace=%file wine Windows\ Live\ Messenger.exe 1>output_file 2>&1
```

#### Question 5.9
> À quoi sert « strace » ?

Strace permet de suivre les appels effectués au système par une application. 
Nous pouvons donc ensuite tracer les actions effectuées par le programme.

#### Question 5.10
> Illustrer et expliquer les manipulations effectuées.

Nous avons lancer strace afin qu'il suivent les appels au système effectué par l'application en l'excécutant avec wine.

#### Question 5.11
> Quel type de filtre a été utile et efficace pour réaliser la capture ?

le filtre -e trace=%file. Cela permet de capturer les appels systèmes relatifs aux fichiers.
Donc une ouverture, modification. 
Cela nous permet de visualiser si le programme accède à des fichiers dont il n'a pas besoin et de voir les fichiers qu'il crée.

#### Question 5.12
> Dans l’output de strace, qu’est-il possible de visualiser pour ce cas ? Expliquer en
détail.
Indice : Regarder la taille des fichiers

En effectuant un grep sur pas.txt dans le fichier d'output, nous pouvons voir q'il a créé deux fois le fichier.
Cela est du au fait que j'ai rentré deux fois les informations de connexions.
Cependant, dans le fichier pas.txt on voit que les identifiants du deuxième essai.

```bash
 $ cat output_file | grep pas.txt
stat64("/home/kali/.wine/dosdevices/c:/pas.txt", {st_mode=S_IFREG|0644, st_size=85, ...}) = 0
stat64("/home/kali/.wine/dosdevices/c:/pas.txt", {st_mode=S_IFREG|0644, st_size=99, ...}) = 0
```

```txt
www.ourgodfather.com
Username: wfuiewf
Password: llllllllll
www.ourgodfather.com
```


### Scène 4 : étude du fichier de configuration

#### Manipulation 5.7
```bash

```



#### Question 5.13
> Tenter de comprendre comment le maliciel traite le fichier « msnsettings.dat ».


#### Question 5.14
> Quels types d’informations le fichier comprend-il ?

#### Question 5.15
> Quelles conclusions en tirez-vous ? Pouvez-vous affirmer ces conclusions ?



### Scène 5 : analyse des communications réseau
### Scène 6 : simulation de services Web
### Scène 7 : analyse statique

## Analyse à l’aide d’outils en ligne


