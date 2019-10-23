#include "Itv.h"
#include <iostream> //std::cout
#include <stdlib.h>

/*Constructeurs
  Initialise un intervale null si aucun paramètre 
*/
Itv::Itv():bi(0),bs(0){}
/*
  Initialise un intervale avec les bornes passées en paramètre
*/
Itv::Itv(double _bi, double _bs): bi(_bi), bs(_bs){
  if(bi>bs){
    std::cout << "borne inferieur > borne supérieur" << std::endl;
    bi= _bs;
    bs= _bi;
  }
}
// getters
double Itv::getBi() const { return bi;}
double Itv::getBs() const { return bs;}
//setters
void Itv::setBi(double modif_i){
  if(modif_i < getBs()){
    bi = modif_i;
  }else{ std::cout << "Nouvelle borne inférieur >  la borne supérieur" << std::endl;}
}
void Itv::setBs(double modif_s){
  if(modif_s > getBi()){
    bs = modif_s;
  }else{ std::cout << "Nouvelle borne supérieur < borne inférieur" << std::endl;}
}
// méthodes
void Itv::afficher ()const{
  std::cout << "Intervalle : [" << getBi() << ";" << getBs() << "]" << std::endl;
}

double Itv::longueur(){
  return abs(getBs()-getBi());
}

bool Itv::appartient(double v) const{
	return (v<=bs && v>=bi);
}

bool Itv::estEgal(const Itv &intervalle) const {
	return (intervalle.getBi() == bi) && (intervalle.getBs() == bs);
}
bool Itv::estInclus(const Itv &intervalle) const {
	return (intervalle.getBi()>=bi && intervalle.getBs()<=bs) && !estEgal(intervalle);
}
bool Itv::estDisjoint(const Itv &intervalle) const {
	return intervalle.getBi()>bs || intervalle.getBs()<bi;
}
bool Itv::estAccole(const Itv &intervalle) const {
	return intervalle.getBs()==bi || intervalle.getBi()==bs;
}
bool Itv::estImbrique(const Itv &intervalle) const {
	return !estEgal(intervalle) && !estInclus(intervalle) && !estDisjoint(intervalle) && !estAccole(intervalle);
}

void Itv::move(double x){
	bi += x;//setBs(getBs()+x);
	bs += x;//setBi(getBi()+x); 	
}

void translate(Itv &intervalle, double v){
	intervalle.move(v);
}