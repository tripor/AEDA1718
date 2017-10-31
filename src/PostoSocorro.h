#ifndef POSTOSOCORRO_H_
#define POSTOSOCORRO_H_

#include "Header.h"

// Classe PostoSocorro e suas derivadas

class PostoSocorro{
	u_int numero_Socorristas;
	u_int numero_Veiculos;
	std::pair<int,int> local;
public:
	//Methods
	//...

};

class Bombeiros : public PostoSocorro{
	u_int numero_Ambulancias;
	u_int numero_Autotanques;
public:
	//Methods
	//...

};

class Policia : public PostoSocorro{
	std::string veiculo; // "Carro" ou "Moto"
public:
	//Methods
	//...

};

class Inem : public PostoSocorro{
	std::string veiculo; // "Ambulancia", "Carro" ou "Moto"
public:
	//Methods
	//...

};




#endif /* POSTOSOCORRO_H_ */
