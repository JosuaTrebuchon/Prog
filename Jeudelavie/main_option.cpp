#include "tabOption.h"
#include <iostream>

using namespace std;

#define HELP_ID 1
#define VERSION_ID 2
#define DIMENSION_ID 4
#define PROBABILITY_ID 10
#define CONFIG_ID 16

int main (int argc, char** argv){
    
  TabOption opts;
  
    opts.addOption( Option (HELP_ID, "--help", "-h",
			"Affiche l'aide du programme", Option::AUCUN));
    opts.addOption(Option(VERSION_ID, "--version", "-v",
			"Affiche la version du programme", Option::AUCUN));
    opts.addOption(Option(DIMENSION_ID, "--dimension", "-N",
			"Initialise une matrice carrée de la dimension spécifiée",Option::ENTIER));
    opts.addOption(Option(PROBABILITY_ID, "--probability", "-p",
			"Probabilité d'une cellule d'être en vie au démarrage",Option::REEL));
    opts.addOption(Option(CONFIG_ID, "--config", "-f",
			"Charge la configuration initiale du jeu à partir du fichier passé en paramètre",Option::CHAINE));

    cout << "Options passées en ligne de commande au programme "
       << argv[0] << " :" << endl;

    for(int i=1; i<argc; i++){
        if(opts.getOptionId(argv[i]) != -1){
            cout << "L'option " << argv[i] << " a été trouvée !";
            if(opts.optionHasArgument(argv[i])){
                cout << "Elle attend un argument de type " << type2String(opts.optionArgumentType(argv[i]));
                cout << "-> " << (++i>argc ? argv[i] : "Erreur");
            }
            cout << endl;
        }else{
            cout << "Usage : " << argv[0] << "[Oprtions" << endl;
            opts.print();
        }
    }
        
    // Option o(1, "test", "t", "option test", Option::ENTIER);
    // Option o2, o3(2,"test2", "t2", "option test2");
    // o.print();
    // o2.print();
    // o3.print();

    // TabOption t;
    // t.addOption(o);
    // t.print();
    return 0;
}