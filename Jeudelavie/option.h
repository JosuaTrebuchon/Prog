#include <iostream>
#include <string>

class Option{
	public:
		enum Type{
			BOOLEEN,
			CHAINE,
			CHAR,
			REEL,
			ENTIER,
			AUCUN
		};

	private:
		int id;
		std::string description, nom, raccourci;
		Type type;

	public:
		Option();
		Option(int _id, const std::string &_nom, const std::string &_raccourci, const std::string &_description, Type _type = AUCUN);
		
		//Getters
		int getId() const;
		std::string getDescription() const;
		std::string getNom() const;
		std::string getRaccourci() const;
		Type getType() const;

		// setters
		void setId(int i);
		void setDescription(std::string s);
		void setNom(std::string s);
		void setRaccourci(std::string s);
		void setType(Type t);

		// Méthodes
		void print() const;
};

std::string type2String(Option::Type t);