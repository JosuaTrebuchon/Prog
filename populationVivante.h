#include "Cellule.h"
#include <iostream>
#define NMAX 100

class PopulationVivante{

private:
	Cellule T[NMAX];
	size_t alive;//nb cellules vivantes
	size_t N;// nb de cellules (vivantes+mortes)
	size_t nb_cellules(Cellule::Couleur) const;
	const Cellule* at(size_t i, size_t j) const;
	Cellule* at(size_t i, size_t j); 

public:
	void init(size_t n);
	size_t nb_vivantes()const;
	size_t nb_mortes() const;
	size_t nb_deces() const; // vont mourir
	size_t nb_naissances() const;
	size_t nb_voisins_vivants(size_t i, size_t j) const;

	PopulationVivante(size_t n);
	void updateColors();
	void print() const;
	void printCell(size_t i, size_t j) const;
	Cellule getCelluleCopie(size_t i, size_t j) const;
	void kill(size_t i, size_t j);
	void birth(size_t i, size_t j);
	PopulationVivante next() const;
};