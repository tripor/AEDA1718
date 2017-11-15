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
	bool operator< (const PostoSocorro & p) const;
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


// CENAS!

bool Acidente::operator== (const Acidente* & a) const{
	if(this->getTipoAcidente() != a->getTipoAcidente()){
		return false;
	}

	if(this->getData() != a->getData() || this->getLocal() != a->getLocal()){
		return false;
	}

	if(this->getAllInfo() != a->getAllInfo()){
		return false;
	}

	return true;
}

///////// Parte do Fernando A Copiar

bool Menu::AcidenteExistente(Acidente* aci) const{
	for(u_int i = 0; i < this->acidentes.size();i++){

		// Acho que não dá por overload, porque queremos comparar os pointers. Criar funcao isEqual em vez de ==
		if(aci == acidentes.at(i)){
			return true;
		}
	}
	return false;
}


//////// Parte Fernando A Copiar!


std::string Florestal::getAllInfo() const{
	std::stringstream ss;

	ss << this->numero_CarrosBombeiros << ' ' << this->numero_Bombeiros << ' ' << this->area_Chamas;

	std::string ret;
	ss.str(ret);

	return ret;
}

std::string Domesticos::getAllInfo() const{
	std::stringstream ss;

	ss << this->numero_CarrosBombeiros << ' ' << this->numero_Bombeiros << ' ' << this->tipo_casa;

	std::string ret;
	ss.str(ret);

	return ret;
}

std::string Assalto::getAllInfo() const{
	std::stringstream ss;

	ss << this->existe_Feridos << ' ' << this->tipo_casa;

	std::string ret;
	ss.str(ret);

	return ret;
}

std::string AcidenteViacao::getAllInfo() const{
	std::stringstream ss;

	ss << this->numero_FeridosGraves << ' ' << this->numero_VeiculosEnvolvidos << ' ' << this->tipo_Estrada;

	std::string ret;
	ss.str(ret);

	return ret;
}







#endif /* POSTOSOCORRO_H_ */
