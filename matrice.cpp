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

bool estReguliere(const Matrice& m){
   if(m.empty())
      return true;
   size_t tailleLigne = m.at(0).size();
   for(Matrice::const_iterator ligne = m.cbegin() + 1; ligne != m.cend(); ++ligne){
      if(tailleLigne != ligne->size())
         return false;
   }
   return true;
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
   Vecteur tmp;
   Matrice ::const_iterator posMin;
   for(Matrice::const_iterator i = mOut.cbegin(); i != mOut.cend(); ++i){
      posMin = min_element(i, mOut.cend());
      tmp = *i;
      mOut.at(distance(mOut.cbegin(),i)) = mOut.at(distance(mOut.cbegin(), posMin));
      mOut.at(distance(mOut.cbegin(), posMin)) = tmp;
   }
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