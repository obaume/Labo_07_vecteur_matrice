/*
-----------------------------------------------------------------------------------
Nom du fichier      : matrice.h
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

#ifndef LABO_07_VECTEUR_MATRICE_MATRICE_H
#define LABO_07_VECTEUR_MATRICE_MATRICE_H
#include <vector>
#include <iostream>

using Vecteur = std::vector<int>;
using Matrice = std::vector<Vecteur>;

/**
 * Nom          : <<
 * Description  : opérateur de flux pour un Vecteur,
 *                affiche un Vecteur comme ceci (v1, v2, ... , vn)
 * Remarques    :
 * @param os    : flux
 * @param v     : vecteur à afficher
 * @return      : retourne le flux
 */
std::ostream& operator << (std::ostream& os, const Vecteur& v);

/**
 * Nom          : <<
 * Description  : opérateur de flux pour une Matrice
 *                affiche une Matrice comme ceci [(Vecteur1), ... ,(Vecteurn)] *
 * Remarques    :
 * @param os    : flux
 * @param m     : matrice à afficher
 * @return      : retourne le flux
 */
std::ostream& operator << (std::ostream& os, const Matrice& m);
/**
 * Nom          :
 * Description  :
 *
 * Remarques    :
 * @param m
 * @return
 */
bool estCarree(const Matrice& m);

/**
 * Nom          : estReguliere
 * Description  : Retourne un booléen indiquant si la matrice est régulière 2
 *                (toutes les lignes de même taille)
 * Remarques    : -
 * @param m     : La matrice a évaluer
 * @return      : si la matrice est régulière
 */
bool estReguliere(const Matrice& m);

size_t minCol(const Matrice& m);

/**
 * Nom          : sommeLigne
 * Description  : Retourne un vecteur contenant la somme des valeurs de
 *                chacune des lignes.
 * Remarques    :
 * @param m     : La matrice a évaluer
 * @return      : Somme des lignes de la matrice en vecteur
 */
Vecteur sommeLigne(const Matrice& m);

Vecteur sommeColonne(const Matrice& m);

/**
 * Nom          : vectSommeMin
 * Description  : Retour le vecteur d’une matrice dont la somme des valeurs est la
 *                plus faible.
 * Remarques    : Si plusieurs vecteurs présentent la même somme, la fonction
 *                retourne celui d’indice le plus faible
 * @param m     : La matrice a évaluer
 * @return      : Le vecteur de la matrice ayant la somme minimum
 */
Vecteur vectSommeMin(const Matrice& m);

Matrice shuffleMatrice(Matrice& m);

/**
 * Nom          : sortMatrice
 * Description  : Trier dans l’ordre croissant une matrice en fonction de
 *                l’élément min d’un vecteur.
 * Remarques    :
 * @param m     : La matrice à trier
 * @return      : La matrice triée
 */
Matrice sortMatrice(const Matrice& m);

#endif //LABO_07_VECTEUR_MATRICE_MATRICE_H
