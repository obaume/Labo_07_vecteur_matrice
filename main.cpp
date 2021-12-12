/*
-----------------------------------------------------------------------------------
Nom du fichier : main.cpp
Nom du labo    : Labo07_vecteur_matrice

Auteur(s)      : Baume Oscar & Guyot Grégoire
Date creation  : 08.12.2021

Description    : Quelques matrice pour tester les fonctions de la bibliothèque
                 matrice.

Remarque(s)    :

Modification:       ---
                    Date   :
                    Auteur :
                    Raison :

Compilateur    : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/

#include <cstdlib>
#include <iostream>
#include "matrice.h"

using namespace std;

void testerMatrice(const Matrice& m);

int main() {
   // Quelques tests pour montrer le fonctionnement de matrice.h
	Matrice m;
	testerMatrice(m);

   m = {{4,4}, {1,3},{2}};
   testerMatrice(m);

   m = {{1,0,0}, {0,1,0},{0,0,1}};
   testerMatrice(m);

   m = {{1,2,3}, {1,2,3}, {1,2}, {1,2,3}};
   testerMatrice(m);

   m = {{1,2,3,4,5}, {1,2,3}, {12}, {1,2,0,0}, {1,2,3}};
   testerMatrice(m);

   m = {{9,8,7}, {6,5,4}, {3,2,1}};
   testerMatrice(m);

	return EXIT_SUCCESS;
}

void testerMatrice(const Matrice& m){
   cout << "-------------------------" << boolalpha << endl
	     << m << endl
		  << "La matrice est carree                  : " << estCarree(m)      << endl
		  << "La matrice est reguliere               : " << estReguliere(m)   << endl
		  << "Taille min d'une ligne                 : " << minCol(m)         << endl
		  << "Somme des lignes                       : " << sommeLigne(m)     << endl
		  << "Somme des colonnes                     : " << sommeColonne(m)   << endl
		  << "Vecteur des sommes minimal d'une ligne : " << vectSommeMin(m)   << endl
		  << "Shuffle Matrice                        : " << shuffleMatrice(m) << endl
		  << "Sort                                   : " << sortMatrice(m)    << endl;
}

