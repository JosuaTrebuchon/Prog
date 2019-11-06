#include "Cellule.h"
#include <iostream>


Cellule::Cellule():vivante(true), x(0), y(0), color(noir) {}
Cellule::Cellule(bool etat, unsigned int _x, unsigned int _y): vivante(etat), x(_x), y(_y), color(etat ? bleu : noir), age(1){}

// Vérifie si la cellule donnée est voisine de la cellule courante
bool Cellule::estVoisine(const Cellule &cell) const {
	// Valeur absolue de la différence entre x1 et x2
	// Plus
	// Valeur absolue de la différence entre y1 et y2
	return ((x-cell.x)*(x-cell.x)+(y-cell.y)*(y-cell.y)) <= 2;
}

//getteurs (accsesseur lecture)
bool Cellule::getEtat() const{ return vivante;}
unsigned int Cellule::getX() const{ return x;}
unsigned int Cellule::getY() const{ return y;}
Cellule::Couleur Cellule::getColor() const{ return color;}

//setteurs (accesseur ecriture)
void Cellule::setEtat(bool etat) {
 	if(etat){
 		color=(age++ ? bleu : vert);
 	}else{
 		age=0;
 		color = noir;
 	}
}
void Cellule::setX(unsigned int a) { x = a;}
void Cellule::setY(unsigned int a) { y = a;}
void Cellule::setColor(Couleur nouv) { color = nouv;}
void Cellule::setAge(int n) { age = n;}

///////////////////////////////////
//Une cellule qui viens de naitre mais qui va mourrir devient jaune
void Cellule::mortPrematuree(){
	if(color != noir){
		color = (color == bleu ? jaune : rouge);
	}
}

//Permet un affichage des attributes de la Cellule
void Cellule::print(){
	std::cout << "Coordonnées : (" << x <<", "<<y<<") et est "<<couleur2String(color)<<std::endl;
}

///////////////////////////////////
// Vérifie si la cellule en paramètre est de la couleur donnée
bool estDeCouleur(Cellule::Couleur coul, const Cellule &c) {
	return c.getColor() == coul;
}

// Retourne un affichage de la couleur
string couleur2String(Cellule::Couleur c){
	string res;
	switch(c){
		case Cellule::noir:
			res="\033[1;30mNoire\033[0m\n";
			break;
		case Cellule::bleu:
			res="\033[1;34mBleue\033[0m\n";
			break;
		case Cellule::vert:
			res="\033[1;32mVerte\033[0m\n";
			break;
		case Cellule::rouge:
			res="\033[1;31mRouge\033[0m\n";
			break;
		case Cellule::jaune:
			res="\033[1;33mJaune\033[0m\n";
			break;
		default:
			res="Non-définie";
	}
	return res;
}
