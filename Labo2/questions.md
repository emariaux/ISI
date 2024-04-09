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
Cela est un outil de vérification afin de vérifier que nous avons le .exe originel.

#### Question 5.2
> Que peut-on déduire du fait que les empreintes ne correspondent pas ?

Cela signifie que le .exe a été modifié. Ce n'est donc pas le version originel de l'exe.

#### Question 5.3
> À votre avis, pourquoi est-il utile de vérifier l’intégrité d’un programme téléchargé ?

Cela nous permet de vérifier l'intégrité du programme. Si le checksum ne correspond pas, nous devons nous méfier du .exe.

### Scène 2 : analyse par snapshots
### Scène 3 : analyse comportementale
### Scène 4 : étude du fichier de configuration
### Scène 5 : analyse des communications réseau
### Scène 6 : simulation de services Web
### Scène 7 : analyse statique

## Analyse à l’aide d’outils en ligne


