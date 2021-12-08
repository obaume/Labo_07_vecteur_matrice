/*
-----------------------------------------------------------------------------------
Nom du fichier      : <nom du fichier>.<xxx>
Nom du laboratoire  :
Auteur(s)           : Baume Oscar
Date creation       : <jj.mm.aaaa>
Description         : <à compléter>
Remarque(s)         : <à compléter>
Modification:       ---
                    Date   :
                    Auteur :
                    Raison :
Compilateur         : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/

#ifndef LABO_07_VECTEUR_MATRICE_MATRICE_H
#define LABO_07_VECTEUR_MATRICE_MATRICE_H
#include <vector>

using Vecteur = std::vector<int>;
using Matrice = std::vector<Vecteur>;


std::ostream& operator << (std::ostream& os, const Vecteur& v);
std::ostream& operator << (std::ostream& os, const Matrice& m);

bool estCarree(Matrice m);

bool estReguliere(Matrice m);

size_t minCol(Matrice m);

Vecteur sommeLigne(Matrice m);

Vecteur sommeColonne(Matrice m);

Vecteur vectSommeMin(Matrice m);

Matrice shuffleMatrice(Matrice m);

Matrice sortMatrice(Matrice m);

#endif //LABO_07_VECTEUR_MATRICE_MATRICE_H
