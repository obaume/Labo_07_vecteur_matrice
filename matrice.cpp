/*
-----------------------------------------------------------------------------------
Nom du fichier      : matrice.cpp
Auteur(s)           : Baume Oscar & Guyot Grégoire
Date creation       : 08.12.2021
Description         : Déclaration des fonctions de la bibliothèque matrice
Remarque(s)         : 
Modification:       ---
                    Date   :
                    Auteur :
                    Raison :
Compilateur         : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/
#include "matrice.h"
#include <algorithm>
#include <numeric>
#include <chrono>
#include <random>

using namespace std;

/**
 * Nom          : compSortMatrice
 * Description  : Compare le plus petit élément de v1 avec le plus petit élément
 *                de v2
 * Remarques    : Utiliser pour la fonction sortMatrice
 * @param v1    : premier vecteur
 * @param v2    : deuxiême vecteur
 * @return      : si min_element(v1) < min_element(v2)
 */
bool compSortMatrice(const Vecteur& v1, const Vecteur& v2);

/**
 * Nom          : vecteurPlusGrand
 * Description  : Compare si v1 et plus grand que v2
 * Remarques    : Utiliser pour les fonctions estReguliere et estCarree
 * @param v1    : premier vecteur
 * @param v2    : deuxiême vecteur
 * @return      : si v1.size() > v2.size()
 */
bool vecteurPlusGrand(const Vecteur &v1, const Vecteur &v2);

/**
 * Nom          : vecteurPlusPetit
 * Description  : Compare si v1 et plus petit que v2
 * Remarques    : Utiliser pour les fonctions estReguliere et estCarree
 * @param v1    : premier vecteur
 * @param v2    : deuxiême vecteur
 * @return      : si v1.size() < v2.size()
 */
bool vecteurPlusPetit(const Vecteur &v1, const Vecteur &v2);

bool estCarree(const Matrice& m) {
   return (*min_element(m.begin(), m.end(), vecteurPlusPetit)).size() == m.size() &&
          (*max_element(m.begin(), m.end(), vecteurPlusPetit)).size() == m.size();
}

bool estReguliere(const Matrice& m){
   if(m.empty())
      // retourne vrai si la matrice est vide
      return true;
   // retourne si le plus petit vecteur à la même taille que le plus grand
   return   (*min_element(m.begin(), m.end(), vecteurPlusPetit)).size() ==
            (*max_element(m.begin(), m.end(), vecteurPlusPetit)).size();
}

// pointe sur vecteur le plus petit et retourne ca taille
size_t minCol(const Matrice& m) {
   return (*min_element(m.begin(), m.end(), vecteurPlusPetit)).size();
}

Vecteur sommeLigne(const Matrice& m){
   if(m.empty()){
      return {0};
   }
   Vecteur vOut;
   for(Matrice::const_iterator i = m.cbegin(); i != m.cend(); ++i){
      // pour chaque vecteur de la matrice
      // on utilise accumulate pour additionner tout les éléments du vecteur
      // et on push_back le résultat de accumulate dans le vecteur
      vOut.push_back(accumulate(i->cbegin(),i->cend(),0));
   }
   return vOut;
}

Vecteur sommeColonne(const Matrice& m) {
   Vecteur sommeColonne;

   for (const auto & i : m) {
      for (size_t j = 0; j < i.size(); j++) {
         if (sommeColonne.size() < j + 1) {
            sommeColonne.push_back(0);
         }
         sommeColonne[j] += i[j];
      }
   }
   return sommeColonne;
}

Vecteur vectSommeMin(const Matrice& m){
   if(m.empty()){
      return {};
   }
   // on prend le vecteur de la somme des ligne de la matrice
   Vecteur sommeLigne = ::sommeLigne(m);
   // on retourne le vecteur à la position entre le début de sommeLigne et
   // l'élément minimum de sommeLigne
   return m.at(distance(sommeLigne.begin(), min_element(sommeLigne.begin(), sommeLigne.end())));
}

Matrice shuffleMatrice(const Matrice& m) { // verifier par copie ou reference
   unsigned seed = (unsigned)chrono::system_clock::now().time_since_epoch().count();
   Matrice mOut = m;
   shuffle(mOut.begin(), mOut.end(), default_random_engine(seed));

   return mOut;
}

Matrice sortMatrice(const Matrice& m){
   Matrice mOut = m;
   // on tri mOut avec compSortMatrice
   sort(mOut.begin(),mOut.end(), compSortMatrice);
   return mOut;
}

bool vecteurPlusGrand(const Vecteur &v1, const Vecteur &v2) {
   return v1.size() > v2.size();
}

bool vecteurPlusPetit(const Vecteur &v1, const Vecteur &v2) {
   return v1.size() < v2.size();
}

bool compSortMatrice(const Vecteur& v1, const Vecteur& v2){
   // on retourne
   // si le plus petit élément de v1 est plus petit que le plus petit élément de v2
   return *min_element(v1.begin(), v1.end()) < *min_element(v2.begin(), v2.end());
}

ostream& operator<< (ostream& os, const Vecteur& v) {
   cout << "(";
   for (Vecteur::const_iterator i = v.cbegin();i != v.cend(); ++i) {
      if (i != v.begin())
         os << ", ";
      os << *i;
   }
   cout << ")";
   return os;
}

ostream& operator<< (ostream& os, const Matrice& m) {
   cout << "[";
   for(Matrice::const_iterator i = m.cbegin();i != m.cend(); ++i){
      if(i != m.begin())
         cout << ", ";
      cout << "(";
      for(Vecteur::const_iterator j = i->cbegin(); j != i->cend(); ++j){
         if(j != i->begin())
            cout << ", ";
         cout << *j;
      }
      cout << ")";
   }
   cout << "]";
   return os;
}

bool estCarreeold(const Matrice& m) {
// min element max element au lieu du lambda
	return all_of(m.begin(), m.end(),
					  [&m](const Vecteur &v) { return v.size() == m.size(); });
}
