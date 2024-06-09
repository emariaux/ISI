
# ISI-CTF-2024 – 64 jours après et toujours pas déchiffré...

* **Auteurs:** 
	* Vasques Dario
	* Mariaux Ewan
	* Pollien Lionel
	* Lopes Dos Santos Rodrigo
* **Categorie:** choix : Web
* **Points:** 100


## Challenge

**URL du challenge :** http://10.190.133.43:4000/?i=admin&l=admin&h=10&H=1
**Texte d'introduction du challenge :**

> Vous êtes tombé sur cette page secrète... Arriverez-vous à vous connecter en tant qu'admin ?

**Hints :** (si utilisés)

- Hint 1
- Hint 2


## Tentatives

1. 



## Solution finale

Dans l'URL, on retrouve les paramètres utilisé "user" et "mot de passe".
Dans le code de la fenêtre HTML on peut voir qu'il y a des paramètres cachés : h et H.

- i = username
- l = mot de passe
- h = 10
- H = 1

```html
<input type="text" name="i" placeholder="username"/>
<input type="password" name="l" placeholder="password"/>
<input type="hidden" name="h" value="10">
<input type="hidden" name="H" value="1">
```

Nous avons ensuite des fonctions javascripts.

```js
function ab(){
	var w = document.forms["b"]["h"].value;
	var x = document.forms["b"]["i"].value;
	var y = document.forms["b"]["l"].value;
	var z = document.forms["b"]["H"].value;
	var k = '61646d696e';
	aa(ba(w,z,y,x),x,y,k);
}
function ba(s,t,u,v){
	var e = s*t/2;
	var f = e;
	e = e*(t-1);
	for(j=0;j<f;j++){
		e *= s+t+1;
		e += t*2;
	}
	return e - 3;
}
function aa(o,n,m,p){
    if(n==bb(p) && m==o){
		alert("Félicitations, vous pouvez utiliser ce mot de passe pour valider le challenge!");
	}
	else{
		alert("Le mot de passe ou le nom d'utilisateur est erroné.");
	}
}
function bb(a)
 {
	var d  = a.toString();
	var b = '';
	for (var c=0;c< d.length;c+=2){b += String.fromCharCode(parseInt(d.substr(c,2),16));}
	return b;
 }

```

Si nous décortiquons cela : 
Lorsque nous appuyons sur login on va dans la fonction "ab()".
```html
<div class="login-page" onsubmit="ab()">
```

```js
function ab(){
	var w = document.forms["b"]["h"].value;
	var x = document.forms["b"]["i"].value;
	var y = document.forms["b"]["l"].value;
	var z = document.forms["b"]["H"].value;
	var k = '61646d696e';
	aa(ba(w,z,y,x),x,y,k);
}
```

- w = h = 10
- x = i = username
- y = l = password
- z = H = 1
- k = '61646d696e'

Nous pouvons déterminer que le username sera admin car :
pour vérifier le mot de passe et le username à la fin on regarde si le résultat de la fonction bb = username.
La fonctione bb prend en paramètre k.
Le retour de la fonction = admin.

Ensuite, on passe dans ba
```js
ba(w,z,y,x)

function ba(s,t,u,v){
	var e = s*t/2;
	var f = e;
	e = e*(t-1);
	for(j=0;j<f;j++){
		e *= s+t+1;
		e += t*2;
	}
	return e - 3;
}
```

- s = 10
- t = 1
- u = password
- v = admin

- e = 10*1/2 = 5
- f = e = 5
- e = 5*(1-1) = 0

boucle : j = 0. j < 5 ; j++
1. 
 - e = 0 * (10+1+1) = 0
 - e = 0 + 1*2 = 2
2. j=1 f=5
 - e = 2 * (10+1+1) = 24
 - e = 24 + 1*2 = 26
3. j=2 f=5
 - e = 26 * (10+1+1) = 312
 - e = 312 + 1*2 = 314
4. j=3 f=5
 - e = 314 * 12 = 3'768
 - e = 3'768 + 2 = 3'770
5. j=4 f=5
 - e = 3'770 * 12 = 45'240
 - e = 45'240 + 2 = 45'242

return e - 3 = 45'242 - 3 = 45'239

Ensuite, on va dans la fonction aa :

```js
 function aa(o,n,m,p){
    if(n==bb(p) && m==o){
		alert("Félicitations, vous pouvez utiliser ce mot de passe pour valider le challenge!");
	}
	else{
		alert("Le mot de passe ou le nom d'utilisateur est erroné.");
	}
}
```

- o = 45239
- n = admin
- m = password
- p = k = 61646d696e

ASCII
- 61 = a
- 64 = d
- 6d = m
- 69 = i
- 6e = n

## Flag

Le flag était : 
> FLAG = ISI21{Base64NestPasDeLaCrypto}



## Mitigations possibles
La mitigation suivante est envisageable :

- Ne pas utiliser BASE64 pour chiffrer quelque chose.




