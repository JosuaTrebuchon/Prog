#include <string>

using namespace std;

class Cellule{
	public:
		enum Couleur{
			noir,
			bleu,
			vert,
			rouge,
			jaune
		};

	private:
		bool vivante;
		unsigned int x,y;
		Couleur color;
		int age;

	public:
		//bool vivante;
		Cellule();
		Cellule(bool etat, unsigned int x, unsigned int y);
		
		//getteurs et setteurs
		bool getEtat() const;
		unsigned int getX() const;
		unsigned int getY() const;
		Couleur getColor() const;
		int getAge() const;
		void setEtat(bool etat);
		void setX(unsigned int a);
		void setY(unsigned int b);
		void setColor(Couleur nouv);
		void setAge(int a);

		// méthodes
		bool estVoisine(const Cellule &c) const; 
		void mortPrematuree();
		void print();
};
//void testCell();
bool estDeCouleur(Cellule::Couleur coul, const Cellule &c);
string couleur2String(Cellule::Couleur c);