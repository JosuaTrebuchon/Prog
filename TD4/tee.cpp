#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Pour ./a.out arg1 arg2 arg3
// Copie dans arg1 l'entrée standard (ce que l'user écrit)
// Puis on copie le conetenue de arg1 dans tous les autres arg

int main(int argc, char **argv){
	if(argc<2){
		cerr<<"error 1"<<endl;
		return 1;
	}
	string s = "";
	string exit = "FIN\0";
	// Si le fichier n'existe pas le créer
	ofstream fich(argv[1]);
	// Vérification de l'ouverture
	if(!fich.is_open()){
		cerr<<"error 2"<<endl;
		return 2;
	}
	while(!cin.eof()){
		getline(cin, s);
		if(s.compare(exit)==0){break;}
		if(!cin.eof() || !s.empty()){
			fich<<s<<endl;
			cout<<s<<endl;
		}
	}
	fich.close();

	for(int i=2; i< argc; i++){
		ifstream fich1(argv[1]);
		ofstream fich2(argv[i]);
		if(!fich1.is_open()){
			cerr<<"pas ouvrable"<<endl;
			return 401;
		}if(!fich2.is_open()){
			cerr<<"pas ouvrable"<<endl;
			return 402;
		}
		while(!fich1.eof()){
			string s;
			getline(fich1,s);
			//if(s.compare(exit)==0){break;}
			if(!s.empty()){
				fich2<<s<<endl;
			}
		}
		fich1.close();
		fich2.close();
	}
	return 0;
}