#include "option.h"
#include <iostream>

using namespace std;

Option::Option(): id(-1), nom(""), raccourci(""), description(""), type(AUCUN){}

Option::Option(int _id, const string &_nom, const string &_raccourci, const string &_description, Option::Type _type):id(_id), nom(_nom), raccourci(_raccourci), description(_description), type(_type){}

// Getters
int Option::getId() const{
    return id;
}
string Option::getDescription() const{
    return description;
}
string Option::getNom() const{
    return nom;
}
string Option::getRaccourci() const{
    return raccourci;
}
Option::Type Option::getType() const{
    return type;
}

// Setters

void Option::setId(int i){ id=i;}
void Option::setDescription(string s){description=s;}
void Option::setNom(string s){nom=s;}
void Option::setRaccourci(string s){raccourci=s;}
void Option::setType(Type t){type=t;}

// Méthodes
void Option::print() const{
    cout << "- Option : " << nom << " (id = "<< id << " )" << endl;
    cout << "\tDescription : " << description << endl;
    cout << "\tRaccourci : " << raccourci << endl;
    cout << "\tType : " << type2String(type) << endl;
}

//Fonctions
string type2String(Option::Type t){
    string tmp;
    switch(t){
        case Option::AUCUN : tmp=""; break;
        case Option::BOOLEEN : tmp="Booléen"; break;
        case Option::CHAINE : tmp="Chaine de caractère"; break;
        case Option::CHAR : tmp="Caractère"; break;
        case Option::REEL : tmp="Réel"; break;
        case Option::ENTIER : tmp="Entier"; break;
    }
    return tmp;
}