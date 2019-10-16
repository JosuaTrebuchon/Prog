#include <iostream>
#include "Cellule.h"
#define N 20 

class Population{
	
	private:
		int nb_cellules(Cellule::Couleur) const;
		Cellule T[N][N];

	public:
		Population();
		void init(size_t i);//srand(time(NULL)); i=rand()%taille; y=rand()%taille;

		size_t nb_vivantes()const;
		size_t nb_deces() const; // vont mourir
		size_t nb_morts() const;
		size_t nb_naissances() const;
		/*Cellule getCelluleCopie(size_t i, size_t j) const;
		const Cellule& getCellule(size_t i, size_t j) const;
		void updateColors();// après initialisation, changement des couleurs des cellules vivantes.
		*/

		Cellule getCelluleCopie(size_t i, size_t j) const;
		const Cellule& getCellule(size_t i, size_t j) const;
};