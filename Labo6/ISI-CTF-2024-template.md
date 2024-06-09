
# ISI-CTF-2024 – Nom du Challenge

* **Auteurs:** 
	* Vasques Dario
	* Mariaux Ewan
	* Pollien Lionel
	* Lopes Dos Santos Rodrigo
* **Categorie:** choix : crypto, pwn, reverse, stegano, forensic, ...
* **Points:** points


## Challenge

**URL du challenge :** http://blibla.ch/

**Texte d'introduction du challenge :**

> The text of 
> the challenge.

**Hints :** (si utilisés)

- Hint 1
- Hint 2


## Tentatives

1. On voit un champ nom, probablement testé par l'alogrithme en C. Testé de faire un buffer overflow sur le champ nom. Pas fonctionné.
2. On voit un champ nom, probablement envoyé à une base de données. Testé de faire une injection SQL sur le champ nom. Pas fonctionné.
3. Le hint nous guide vers...


## Solution finale

Explication de la solution.

Décrire les outils. **Mettre des captures.**

 ~~~clike
 void main(){
	 int i;
	 for (i=0; i<4;i++){
   		printf(i);
	}
  }
 ~~~

The `ping` command is launched via shell...

For example `127.0.0.1; ls -al` gives ...

```
PING 127.0.0.1 (127.0.0.1) 56(84) bytes of data.
64 bytes from 127.0.0.1: icmp_seq=1 ttl=64 time=0.019 ms
--- 127.0.0.1 ping statistics ---
1 packets transmitted, 1 received, 0% packet loss, time 0ms
rtt min/avg/max/mdev = 0.019/0.019/0.019/0.000 ms
total 28
drwxr-xr-x 3 root root 4096 Jan 17 09:57 .
drwxr-xr-x 3 root root 4096 Jan 7 16:52 ..
drwxr-xr-x 4 root root 4096 Jan 17 09:57 _res_
-rw-r--r-- 1 root root 1367 Jan 16 15:30 index.php
-rw-r--r-- 1 root root 6128 Jan 16 13:10 print-flag
-rw-r--r-- 1 root root 42 Jan 16 15:35 robots.txt 
```





## Flag

Le flag était : 
> FLAG



## Mitigations possibles

Les mitigations suivantes sont envisageables :

- pour éviter le buffer overflow, utiliser une librairie sécurisée contrôlant les entrées
- pour éviter l'injection SQL, utiliser des "prepared statements"



