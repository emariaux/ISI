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

Nous avons calculé le checksum pour le md5 et le sha1.
Cet outil sert à vérifier que nous avons le .exe originel.

#### Question 5.2
> Que peut-on déduire du fait que les empreintes ne correspondent pas ?

Nous pouvons déduire que le .exe a été modifié. Ce n'est donc pas le version original de l'exe.

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

Regshot est un logiciel permettant d'effectuer une capture du système d'exploitation à un instant T, puis un second.
Ensuite, nous pouvons comparer les modifications qui ont été apportées au système durant le laps de temps des deux shots.
Nous pouvons voir les nouvelles clé de registres ou les nouveaux fichiers.

#### Question 5.5
> Pourquoi utiliser un environnement de « test » cloisonné ?
Pourquoi utilise-t-on le « snapshot » dans les logiciels de virtualisation (Virtualbox,
VMware, . . .) ?

Cela nous permet d'excécuter des logiciels malveillant dans des environnements cloisonnés.
Donc, nous n'impactons pas notre système d'exploitation.
Les snapshots nous permettent de revenir à l'instant T de notre VM.
Cela est utile lorsque nous effectuons des tests afin de pouvoir revenir a un état non corrompu de la VM.

#### Question 5.6
> Illustrer et expliquer les manipulations effectuées

Dans un premier temps, nous avons effectué un regshot de notre VM.
Cela signifie que nous avons capturé notre système à ce moment là.

Ensuite, nous avons excectué le logiciel malveillant.

Nous avons effectué un second regshot.
Pour finir, nous avons comparé les modifications apportées au système entre les deux regshots.

#### Question 5.7
> Que constatez-vous dans le rapport généré par Regshot ?

Une nouvelle clé de registre a été créée et deux nouveaux fichiers.

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
Nous pouvons donc tracer les actions effectuées par le programme.

#### Question 5.10
> Illustrer et expliquer les manipulations effectuées.

Nous avons lancé strace afin qu'il suive les appels au système effectué par l'application excécutée avec wine.

#### Question 5.11
> Quel type de filtre a été utile et efficace pour réaliser la capture ?

le filtre -e trace=%file. Cela permet de capturer les appels systèmes relatifs aux fichiers.
Donc une ouverture, une modification, etc. 
Cela nous permet de visualiser si le programme accède à des fichiers dont il n'a pas besoin et de voir les fichiers qu'il crée.

#### Question 5.12
> Dans l’output de strace, qu’est-il possible de visualiser pour ce cas ? Expliquer en
détail.
Indice : Regarder la taille des fichiers

En effectuant un grep sur pas.txt dans le fichier d'output, nous pouvons voir qu'il a créé deux fois le fichier.
Cela est dû au fait que j'ai rentré deux fois les informations de connexions.
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
```txt
ISI16
0
0
-1
-1
0
0
-1
Please type in an error message
C:\Program Files\MSN Messenger\msnmsgr.exe
-1
gsmtp16.google.com
isi_lab16@gmail.com
0
0
0
C:/
```




#### Question 5.13
> Tenter de comprendre comment le maliciel traite le fichier « msnsettings.dat ».

C'est son fichier de paramètre lorsque l'on rentre un identifiant.
Il comprend de multiples paramètres.

#### Question 5.14
> Quels types d’informations le fichier comprend-il ?

La dernière ligne, c'est où le fichier pas.txt est créé.
La ligne c:\Program Files\MSN Messenger\msnmsgr.exe correspond au chemin d'accès au exe.
Comme l'application standard.
Nous avons également une adresse email ainsi qu'un serveur smtp de google.
Autrement, c'est plusieurs paramètres tous séparés par des retours à la ligne.

#### Question 5.15
> Quelles conclusions en tirez-vous ? Pouvez-vous affirmer ces conclusions ?

En modifiant la dernière ligne on peut caché le fichier pas.txt au lieu de le mettre à la racine.
Nous avons modifié et mis c:/test et le fichier est bien maintenant dans le fichier test.
Nous pourrions imaginer le cacher dans un dossier système afin que l'utilisateur ne puisse pas le voir.


### Scène 5 : analyse des communications réseau

#### Manipulation 5.8

Adresse IP :
```
192.168.142.128
```
Fichier resolv.conf
```txt
# Generated by NetworkManager
search localdomain
nameserver 192.168.142.128
```

```bash
sudo python3 fakedns.py 192.168.142.1
```
#### Manipulation 5.9
```bash
sudo wireshark
```
capture sur eth0

#### Manipulation 5.10
```bash
wine "Windows Live Messenger.exe"
```
#### Manipulation 5.11
![image](https://github.com/emariaux/ISI/assets/114927416/2ceae191-1c03-47a8-9795-0b59856e781b)

#### Question 5.16
> Comment fonctionne « fakedns » ?

fakedns simule un vrai dns. A chaque requête, il effectue la résolution en donnant l'IP passé en paramètre.

#### Question 5.17
> Illustrer et expliquer les manipulations effectuées.

Tout d'abord dans resolv.conf, nous avons indiquer que notre serveur DNS était nous même.
Ensuite, nous avons lancé fakedns en indiquant l'ip 192.168.142.1. Cela est l'IP que le DNS va indiquer à chaque requête.
Nous avons ensuite exécuté le programme avec wine. 

#### Question 5.18
> Quels types d’informations ont été capturées grâce à Wireshark ?

Nous pouvons visualiser une requête TCP vers le port 25.
Ce dernier correspond au port par défaut du SMTP.

#### Question 5.19
> Expliquer de manière détaillée le comportement du maliciel.

Nous pouvons déduire que le programme essaie d'envoyer un mail après que l'on ait rentré les informations de connexions.
Le mail doit surement contenir le nom d'utilisateur et le mot de passe.
Cela correspondrait au fichier pas.txt.


### Scène 6 : simulation de services Web

#### Manipulation 5.12
```bash
sudo mv Nameserver.pm /usr/share/perl5/Net/DNS/Nameserver.pm
```

#### Manipulation 5.13

```txt
# Generated by NetworkManager
search localdomain
```

lancement inetsim
```bash
sudo inetsim

sudo wireshark

```

#### Question 5.20
> Illustrer et expliquer les manipulations effectuées.

Nous avons enlevé le DNS que nous avions spécifié à l'étape précédente.
Nous avons exécuté inetsim
![image](https://github.com/emariaux/ISI/assets/114927416/cf2da41f-6db2-4e86-bd2f-368e6634c21a)

Wireshark a capturé un envoie de mail.
l'adresse d'envoi est yourpassword@password.com et la destination est isi_lab16@gmail.com.
Celle-ci correspond a l'adresse que l'on a mis dans le fichier msnsettings.dat.
On peut également voir le username et le mot de passe entrés.
![image](https://github.com/emariaux/ISI/assets/114927416/f1b3bd00-2f4a-4267-9ed4-b6ded3231946)


#### Question 5.21
> Après toutes ces analyses comportementales, pouvez-vous identifier à quel(s) type(s)
de maliciels « Windows Live Messenger » appartient ? Pourquoi ?

C'est un cheval de Troie. En effet, le malicien simule Windows Live Messenger. 
Mais il contient du code malicieux.

C'est également ce que l'on appelle un logiciel espion.
Il enregistre les informations de connexions de l'utilisateur.

### Scène 7 : analyse statique

#### Manipulation 5.14
![image](https://github.com/emariaux/ISI/assets/114927416/c0e93169-fb7c-4d73-801f-d294fd22ce14)


#### Question 5.22
> Que pouvez-vous en déduire ?

Une fenêtre avec de nombreux paramètres s'ouvre.
C'est l'ensemble des options qui sont spécifiées dans le fichier msnsettings.dat
ISI16 dans le fichier correspond à l'email qu'il faut rentrer pour voir cette option.
les 0,-1 dans le fichier correspondent à une option des radio button.

## Analyse à l’aide d’outils en ligne

#### Manipulation 5.15
Le hash md5 a7a75a56b4b960c8532c37d3c705f88f a été mis dans MetaDefender et Virustotal.
Cela nous permet de voir que le logiciel est connu comme malveillant.
Les deux sites le considère comme un cheval de Troie.

#### Question 5.23
> À quelle(s) catégorie(s) de codes malveillants appartient ce code malveillant ? (virus,
ver, spyware, etc.)

Virus Total et MetaDefender le considère comme un cheval de Troie.

#### Question 5.24
> Quelle est l’utilité d’un tel code malveillant ?

Pouvoir accèder aux comptes MSN de plusieurs personnes.
Ensuite, le but est de soutirer de l'argent aux proches de la victime en se faisant passer pour elle sur MSN.

#### Question 5.25
> Comment se propage ce code malveillant ?

Il se propage avec le partage de l'exe.
L'exe peut être placé sur des sites web et les utilisateurs le téléchargent en penssant télécharger MSN.

#### Question 5.26
> Comment l’infection par ce code malveillant est-elle réalisée ?

En lançant le .exe et en rentrant ses informations de connexions.
