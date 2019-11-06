#include "tabOption.h"
#include <iostream>
#include <string>

using namespace std;

TabOption::TabOption() : nb_options(0){}

void TabOption::addOption(const Option &opt){
    if(nb_options >= NMAX){
        cerr << "Tableau d'option plein" << endl;
        terminate();
    }
    bool found = (TabOption::getOptionIndex(opt.getNom()) != -1) || (TabOption::getOptionIndex(opt.getRaccourci()) != -1);
    if(found){
        cerr << "Avertissement : L'identifiant " << opt.getId() << " est déjà utilisé"<< endl;
    } else{
        tab[nb_options] = opt;
        setNbOptions(nb_options+1);
    }
}

void TabOption::setNbOptions(int n){
    nb_options = n;
}

/* Permet de connaitre l'index dans le tableau d'une option et renvoie -1 si elle n'est pas dedans
    @param : [string][Nom ou raccourci de l'option]
 */
int TabOption::getOptionIndex(const string &s) const{
    bool found = false;
    size_t i = 0;
    while(!found && (i<nb_options)){
        found = (s == tab[i].getNom()) || (s == tab[i].getRaccourci());
        i++;
    }
    return found ? i-1 : -1;
}

void TabOption::print() const{
    cout << "Options :"<< endl;
    for(size_t i = 0; i<nb_options; i++){
        tab[i].print();
    }
}

int TabOption::getOptionId(const string &opt) const{
    int i = getOptionIndex(opt);
    return (i>=0 ? tab[i].getId() : -1);
}

bool TabOption::optionHasArgument(const string &opt) const{
    int i = getOptionIndex(opt);
    return (tab[i].getType() != Option::AUCUN);
}

