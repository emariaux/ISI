#include <iostream>
#include <ctime>

using namespace std;

void evalue_fcc(int id, int in, int* res){
  int vote[3]={0, 0, 0}; // vote[0]-feuille, vote[1]-caillou, vote[2]-ciseaux 
  int ordi[3]={0, 0, 0}; // ordi[0]-feuille, ordi[1]-caillou, ordi[2]-ciseaux 
  int i, alea;

  vote[in]+=id;

  alea = time(0) % 3;
  ordi[alea]+=id;
  cout << "L'ordi a mise sur ";
  if ( ordi[0] )
    cout << "Feuille";
  else if ( ordi[1] )
    cout << "Caillou";
  else 
    cout << "Ciseaux";
  cout << ". ";

  *res = 0; // égal
  for (i=0; i<3; i++){
     if ( vote[i] )
     {
        switch (i)
        {
           case 0: // vote feuille
              if (ordi[2]) // ordi vote ciseaux
                 *res = 1; // perdu
              else
                 *res = 0; // gagne
              break;
           case 1: // vote caillou
              if (ordi[0]) // ordi vote feuille
                 *res = 1; // perdu
              else
                 *res = 0; // gagne
              break;
           case 2: // vote ciseaux
              if (ordi[1]) // ordi vote caillou
                 *res = 1; // perdu     
              else
                 *res = 0; // gagne              
        }
     }
  }

  if (*res != 0){
    cout << "Perdu :-(" << endl;	    
  }
  else
    cout << "Gagne :-)" << endl;	    
}

int main(){
	int score=0;
	int vote, id, i, res;
        
        // message de bienvenue
	cout << "Bienvenue dans le jeu Feuille-Caillou-Ciseaux" << endl
             << "----------------------------------------------" << endl
             << endl
             << "Vous devez gagner un maximum de fois." << endl
             << "Chaque fois que vous perdez, votre score augmente d'un point." << endl
             << "L'objectif est de terminer avec un score de 0." << endl
             << endl;

        // choix de l'identifiant
	cout << "Entrez votre identifiant entre 1 et 1000 : ";
	while ( ! ( cin >> id ) )
	  {
	    cerr << "Erreur de saisie.\n";
	  }
	cout << endl;

        // deroulement des 10 rounds de jeu
	for (i=0; i<10; i++){
	  cout << "--- Round " << i+1 << " ---" << endl;
	  cout << "Choisissez "
               << "[0] Feuille, "
               << "[1] Caillou, "
               << "[2] Ciseaux : ";
	  while ( ! ( cin >> vote ) )
	    {
	      cerr << "Erreur de saisie.\n";
	    }
	  cout << endl;

	  evalue_fcc(id,vote,&res);     // evaluation du resultat du round

	  if (res != 0 || vote < 0 || vote > 2)
	    score++;

	  cout << "Score actuel est : " << score << endl;	    
	}
	
        // affichage du score final
	cout << endl;
	cout << "Votre score final est :" << score << endl;

	return 0;
}
