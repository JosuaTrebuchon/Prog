#include "populationVivante.h"
#include <exception>
#define CHECK_BOUND(i,j)\
	if(i>=NMAX || j>=NMAX){\
		std::cout << "Accès à la cellule en ("<<i<<","<<j\
		<<"). Endehors de la limite.Abort."<<std::endl;\
		std::terminate();\
	}


PopulationVivante::PopulationVivante(size_t n):alive(0), N(n){}

const Cellule* PopulationVivante::at(size_t i, size_t j) const{
	for(size_t k = 0; k<alive;k++){
		if(T[k].getX() == i && T[k].getY() == j){
			return T+k;
		}
	}
	return NULL;
} 

/*
Retourne un pointeur sur la cellule qui possède les coordonnée (i, j)
*/
Cellule* PopulationVivante::at(size_t i, size_t j){
	for(size_t k=0; k<alive; k++){
		if(T[k].getX()==i && T[k].getY()==j){
			return T+k;
		}
	}
	return NULL;
}

/*
Génère n cellules vivantes à des coordonnées aléatoire entre 0 et n.

*/
void PopulationVivante::init(size_t n){
	srand(time(NULL));
	if(nb_vivantes()==0){
		size_t i, j;
		for(size_t k=0; k<n; k++){
			do{
				i=rand()%n;
				j=rand()%n;
			}while(at(i,j) != NULL);

			T[k] = Cellule(true,i , j);
			alive++;
		}
		updateColors();
	}
}

Cellule PopulationVivante::getCelluleCopie(size_t i, size_t j) const{
	CHECK_BOUND(i, j);
	const Cellule* ptr = at(i, j);
	if(ptr==NULL){
		return Cellule(false, i, j);
	}else{
		return *ptr;
	}
}
/*
Deplace le reste du tableau pour écraser une cellule

Si le tableau est plein, laisse une case vide à la fin
*/
void PopulationVivante::kill(size_t i, size_t j){
	CHECK_BOUND(i,j);
	Cellule* ptr=at(i,j);
	if(ptr != NULL){
		size_t k = ptr - T;
		for( ;k<alive;k++){
			T[k] = T[k+1];
		}
		alive--;
	}
}

void PopulationVivante::birth(size_t i, size_t j){
	if(alive+1<NMAX){
		CHECK_BOUND(i,j);
		Cellule* ptr= at(i,j);
		if(ptr==NULL){
			T[alive] = Cellule(true, i, j);
			alive++;
		}else{
			ptr->setEtat(true);// -> évite les syntaxes galère et permet d'acceder à l'objet derrière le pointeur
		}
	}else{
		std::cerr << "Erreur: Trop de cellules vivantes pour NMAX = "<<NMAX<<std::endl;
		std::terminate();
	}
}

PopulationVivante PopulationVivante::next() const{
	PopulationVivante pop(*this);
	for(size_t i=0; i<N; i++){
		for(size_t j=0; j<N;j++){
			size_t voisin = nb_voisins_vivants(i,j);
			if(voisin==3 || (voisin==2 && at(i,j)!=NULL)){
				pop.birth(i,j);
			}else{
				pop.kill(i,j);
			}
		}
	}
}


// TO DO
size_t PopulationVivante::nb_voisins_vivants(size_t i, size_t j) const{
	for(size_t k=0; k<NMAX; k++){
		T[k].estVoisine()
	}
}