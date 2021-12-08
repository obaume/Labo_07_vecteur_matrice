//
// Created by oscar on 08.12.2021.
//

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
