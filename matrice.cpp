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
#include <iostream>
#include <numeric>
using namespace std;

/**
 * Nom          : compSortMatrice
 * Description  : comparaison entre v1 et v2 pour le tri de la matrice
 * Remarques    :
 * @param v1    : premier vecteur
 * @param v2    : deuxiême vecteur
 * @return      : si v1 < v2
 */
bool compSortMatrice(const Vecteur& v1, const Vecteur& v2);

bool estReguliere(const Matrice& m){
   if(m.empty())
      return true;
   size_t tailleLigne = m.at(0).size();
   return all_of(m.begin(),m.end(),
                 [&tailleLigne](const Vecteur& v){return tailleLigne == v.size();
   });
}

Vecteur sommeLigne(const Matrice& m){
   if(m.empty()){
      return {0};
   }
   Vecteur vOut;
   for(Matrice::const_iterator i = m.cbegin(); i != m.cend(); ++i){
      vOut.push_back(accumulate(i->cbegin(),i->cend(),0));
   }
   return vOut;
}

Vecteur vectSommeMin(const Matrice& m){
   if(m.empty()){
      return {};
   }
   Vecteur sommeLigne = ::sommeLigne(m);
   Vecteur::iterator minimum = min_element(sommeLigne.begin(), sommeLigne.end());
   return m.at(distance(sommeLigne.begin(), minimum));
}

Matrice sortMatrice(const Matrice& m){
   Matrice mOut = m;
   sort(mOut.begin(),mOut.end(), [](const Vecteur& v1, const Vecteur& v2)
   {return *min_element(v1.begin(), v1.end()) <= *min_element(v2.begin(), v2.end()
   );});
   return mOut;
}

ostream& operator << (ostream& os, const Vecteur& v) {
   cout << "(";
   for (Vecteur::const_iterator i = v.cbegin();i != v.cend(); ++i) {
      if (i != v.begin())
         os << ", ";
      os << *i;
   }
   cout << ")";
   return os;
}

ostream& operator << (ostream& os, const Matrice& m) {
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