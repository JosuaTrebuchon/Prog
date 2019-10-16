#include "Cellule.h"
#include <iostream>


int main (int argc, char** argv){
	Cellule c(true, 1, 0);
	std::cout << couleur2String(c.getColor()) << std::endl;
	c.mortPrematuree();
	std::cout << couleur2String(c.getColor()) << std::endl;

	Cellule c_1(false, 0, 0);
	std::cout << couleur2String(c_1.getColor()) << std::endl;
	c_1.mortPrematuree();
	std::cout << couleur2String(c_1.getColor()) << std::endl;

	c.setColor(Cellule::vert);
	std::cout << couleur2String(c.getColor()) << std::endl;
	c.mortPrematuree();
	std::cout << couleur2String(c.getColor()) << std::endl;


	std::cout << c.estVoisine(c_1) << std::endl;

	//Pour empecher la modification, on rajoute le mot clef "const" avant la déclaration 
	/*const */Cellule pop3[3][3]={
		Cellule(false, 0, 0),	//[noire, bleue, noire]
		Cellule(true, 0, 1),	//[bleue, noire, bleue]
		Cellule(false, 0, 2),	//[noire, bleue, noire]
		Cellule(true, 1, 0),	
		Cellule(false, 2, 0),
		Cellule(true, 1, 1),
		Cellule(false, 1, 2),
		Cellule(true, 2, 1),
		Cellule(false, 2, 2),
	};

	pop3[1][2].print();
	size_t x,y;
	for(int i=0; i<3; i++){
		std::cout << "Coordonnées des cellules ? ";
		std::cin >> x >> y;

		pop3[x][y].setEtat(!pop3[x][y].getEtat());
	}
	for(x=0; x<3;x++){
		for(y=0; y<3; y++){
			pop3[x][y].print();
		}
	}

	return 0;
}