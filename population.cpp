#include "population.h"
#include <exception>
#define CHECK_BOUND(i,j)\
	if(i>=N || j>=N){\
		std::cout << "Accès à la cellule en ("<<i<<","<<j\
		<<"). Endehors de la limite.Abort."<<std::endl;\
		std::terminate();\
	}

void Population::printCell(size_t i, size_t j){
	CHECK_BOUND(i, j);
	T[i][j].print();
}

Population Population::next() const{
	Population pop(*this);
	for(size_t i=0; i<N; i++){
		for(size_t j=0; j<N; j++){
			size_t voisin = nb_voisins_vivants(i, j);
			(pop.T[i][j]).setEtat(voisin==3 || (voisin==2 && T[i][j].getEtat()));
		}
	}

	return pop;
}

Population::Population(){
	for(size_t i=0; i<N; i++){
		for(size_t j =0; j<N; j++){
			T[i][j].setX(i);
			T[i][j].setX(j);
			T[i][j].setEtat(false);
		}
	}
}

int Population::nb_cellules(Cellule::Couleur c) const{
	int cpt = 0;
	for(size_t i=0; i<N; i++){
		for(size_t j=0; j<N; j++){
			cpt += (estDeCouleur(c, T[i][j]) ? 1 : 0);
		}
	}
	return cpt;
}

size_t Population::nb_deces()const{
	return nb_cellules(Cellule::rouge)+nb_cellules(Cellule::jaune);
}

size_t Population::nb_mortes() const{
	return nb_cellules(Cellule::noir);
}
size_t Population::nb_vivantes() const{
	return N*N - nb_mortes();
}

/*
On peut utiliser la méthode estVoisine mais est plus longue à l'éxecution.
*/
size_t Population::nb_voisins_vivants(size_t i, size_t j) const{
	size_t cmpt = 0;
	size_t imin, imax, jmin, jmax;
	imin = i==0 ? i : i-1;
	imax = i==0 ? i : i+1;
	jmin = j==0 ? j : j-1;
	jmax = j==0 ? j : j+1;
	for(size_t k=imin; k<imax; k++){
		for(size_t l=jmin; l<jmax; l++){
			if(T[k][l].getEtat()){
				cmpt++;
			}
		}
	}
	return cmpt - (T[i][j].getEtat() ? 1 : 0);
}

void Population::updateColors(){
	for(size_t k=0; k<N; k++){
		for(size_t l=0; l<N; l++){
			size_t voisin = nb_voisins_vivants(k,l);

			if(voisin !=3 && voisin != 2 && T[k][l].getEtat()){
				T[k][l].mortPrematuree();
			}
		}
	}
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



