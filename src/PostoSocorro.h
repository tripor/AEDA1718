#ifndef POSTOSOCORRO_H_
#define POSTOSOCORRO_H_

#include "Header.h"

// Classe PostoSocorro e suas derivadas

class PostoSocorro{
	u_int numero_Socorristas;
	u_int numero_Veiculos;
	std::pair<int,int> local;
public:
	//construtor
	PostoSocorro(u_int numero_Socorristas,	u_int numero_Veiculos,std::pair<int,int> local);
	~PostoSocorro(){}
	//set
	void setSocorristas(u_int numero_Socorristas);
	void setVeiculos(u_int numero_Veiculos);
	//get
	u_int getSocorristas();
	u_int getVeiculos();
	std::pair<int,int> getPos();
};


class Bombeiros : public PostoSocorro{
	u_int numero_Ambulancias;
	u_int numero_Autotanques;
public:
	//construtor
	Bombeiros(u_int numero_Socorristas,std::pair<int,int> local,u_int numero_Ambulancias,u_int numero_Autotanques);
	~Bombeiros() {};
	//get
	u_int getAmbulancias();
	u_int getAutotanques();
};

class Policia : public PostoSocorro{
	std::string veiculo; // "Carro" ou "Moto"
public:
	//construtor
	Policia(u_int numero_Socorristas,u_int numero_Veiculos,std::pair<int,int> local,std::string veiculo);
	~Policia(){}
	//get
	std::string getVeiculo();

};

class Inem : public PostoSocorro{
	std::string veiculo; // "Ambulancia", "Carro" ou "Moto"
public:
	//contrutor
	Inem(u_int numero_Socorristas,u_int numero_Veiculos,std::pair<int,int> local,std::string veiculo);
	~Inem(){}
	//get
	std::string getVeiculo();

};

class NumeroIncorreto
{
	int numero;
public:
	NumeroIncorreto(int numero){this->numero=numero;}
	int getNumero(){return numero;}
};



#endif /* POSTOSOCORRO_H_ */
