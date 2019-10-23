#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char **argv){
	if(argc<2){
		cerr<<"error"<<endl;
		return 1;
	}
	for(int i=0; i< argc; i++){
		// Si le fichier n'existe pas le créer
		ofstream fich(argv[i]);
		// Vérification de l'ouverture
		if(!fich.is_open()){
			return 2;
		}

		while(!cin.eof()){
			string s;
			getLine(fich, s);
			if(!s.empty()){
				fich<<s<<endl;
				cout<<s<<endl;
			}
		}
		fich.close();
	}
}