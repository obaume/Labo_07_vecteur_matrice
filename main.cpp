
/*
-----------------------------------------------------------------------------------
Nom du fichier : <nom du fichier>.<xxx> (xxx = h ou cpp)
Auteur(s)      : Grégoire Guyot
Date creation  : <jj.mm.aaaa>

Description    : <à compléter>

Remarque(s)    : <à compléter>

Compilateur    : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/


#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <vector>
#include "matrice.h"

using namespace std;

void afficherMatrice(const vector<vector<int>> &matrice);

int main() {


	vector<vector<int>> matrice(4, vector<int>(2));

	vector<vector<int>> matrice2;

	matrice2.emplace_back(5); // utilise constructeur
	matrice2.emplace_back(3);
	matrice2.emplace_back(6);
	matrice2.emplace_back(4);

	vector<vector<int>> matrice3;
	matrice3.push_back(vector<int> {1});
	matrice3.push_back(vector<int> {4, 5});
	matrice3.push_back(vector<int> {7, 8, 9});

	cout << boolalpha << estCarree(matrice) << endl;
	cout << minCol(matrice2) << endl;

	for(int i : sommeColonne(matrice3)) {
		cout << i << " ";
	}
	cout << endl;

	afficherMatrice(shuffleMatrice(matrice3));

	return EXIT_SUCCESS;
}

void afficherMatrice(const vector<vector<int>> &matrice) {
	for (const vector<int> &ligne: matrice) {
		for (int i: ligne) {
			if (i > 9) {
				cout << i << " ";
			} else {
				cout << i << setw(2) << " ";
			}
		}
		cout << endl;
	}
	cout << endl;
}