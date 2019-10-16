#include "population.h"
#include <exception>
#define CHECK_BOUND(i,j)\
	if(i>=N || j>=N){\
		std::cout << "Accès à la cellule en ("<<i<<","<<j\
		<<"). Endehors de la limite.Abort."<<std::endl;\
		std::terminate();\
	}

Population::printCell(size_t i, size_t j){
	CHECK_BOUND(i, j);
	T[i][j].print();
}

Population Population::next() const{
	Population pop(*this);
	for(size_t i=0; i<N; i++){
		for(size_t j=0; j<N; j++){
			size_t voisin = nb_voisins_vivants(i, j);
			(pop[i][j]).setVivante(voisin==3 || (voisin==2 && T[i][j].getVivante()));
		}
	}
	
	return pop;
}

Population::Population(){
	for(size_t i=0; i<N; i++){
		for(size_t j =0; j<N; j++){
			T[i][j].setX(i);
			T[i][j].setX(j);
			T[i][j].setVivante(false);
		}
	}
}

int Population::nb_cellules(Cellule::Couleur c) const{
	int cpt = 0;
	for(size_t i=0; i<N; i++){
		for(size_t j=0; j<N; j++){
			cpt += (estdeCouleur(c, &T[i][j]) ? 1 : 0);
		}
	}
	return cpt;
}

size_t Population::nb_deces()const{
	return nb_cellules(Cellule::rouge)+nb_cellules(Cellule::jaune);
}

size_t Population::nb_vivantes() const{
	return N*N - nb_mortes();
}

size_t Population::nb_mortes() const{
	return nb_cellules(Cellule::noir);
}
/*
Compte le nb de cellules qui viennent de naitre et qui ne vont pas mourire.

Remarque:
Si on veut compter aussi les cellules qui viennent de naitre mais qui 
vont mourire (cellule jaune), on regarde l'attribut "age" = 0 
*/
size_t Population::nb_naissances() const{
	return nb_cellules(Cellule::bleu);
}

Cellule Population::getCelluleCopie(size_t i, size_t j) const{
	CHECK_BOUND(i, j);
	return T[i][j];
}

const Cellule& Population::getCellule(size_t i, size_t j) const{
	CHECK_BOUND(i, j);
	return T[i][j];
}



