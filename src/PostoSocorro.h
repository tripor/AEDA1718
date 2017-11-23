#ifndef POSTOSOCORRO_H_
#define POSTOSOCORRO_H_

#include "Header.h"
#include "Acidente.h"

// Classe PostoSocorro e suas derivadas

class PostoSocorro {
	u_int numero_Socorristas;
	u_int numero_Veiculos;
	std::pair<int, int> local;
	std::vector<Acidente*> acidenteAtribuidos;
	std::vector<Acidente*> acidenteATratar;
public:
	//construtores
	PostoSocorro() {
		this->numero_Socorristas = 0;
		this->numero_Veiculos = 0;
		this->acidenteATratar.clear();
		this->acidenteAtribuidos.clear();
		std::pair<int, int> temp;
		temp = std::make_pair(0, 0);
		this->local = temp;
	}
	PostoSocorro(u_int numero_Socorristas, u_int numero_Veiculos,
			std::pair<int, int> local);
	virtual ~PostoSocorro() {
	}

	//set
	void setSocorristas(u_int numero_Socorristas);
	void setVeiculos(u_int numero_Veiculos);
	void setPosicao(std::pair<int, int> local);
	void setAcidentesTratar(std::vector<Acidente*> v1);
	void setAcidentesAtribuidos(std::vector<Acidente*> v1);

	//get
	u_int getSocorristas();
	u_int getVeiculos();
	std::pair<int, int> getPos();
	void printAcidentesAtribuidos();
	std::vector<Acidente*> getAcidentesTratar(){return this->acidenteATratar;}
	std::vector<Acidente*> getAcidentesAtribuidos(){return this->acidenteAtribuidos;}


	//outros metodos
	bool operator<(const PostoSocorro & p) const;
	virtual std::string getTipo()=0;
	virtual std::string getAllInfo()=0;
	virtual std::string getAllInfoFormatoPrint()  = 0;
	virtual void guardarInformacao(std::stringstream &receber)=0;
	virtual void infoUtilizador() = 0;
	virtual void setAllInfo(std::string s) = 0;

	void infoUtilizadorGeral();


};

class Bombeiros: public PostoSocorro {
	u_int numero_Ambulancias;
	u_int numero_Autotanques;
public:
	//construtor
	Bombeiros() :
			PostoSocorro() {
		this->numero_Ambulancias = 0;
		this->numero_Autotanques = 0;
	}
	Bombeiros(u_int numero_Socorristas, std::pair<int, int> local,
			u_int numero_Ambulancias, u_int numero_Autotanques);
	~Bombeiros() {
	}
	;
	//get
	u_int getAmbulancias();
	u_int getAutotanques();
	std::string getTipo() {
		return "Bombeiros";
	}
	std::string getAllInfo();
	std::string getAllInfoFormatoPrint() ;

	void setAllInfo(std::string s){}
	//set
	void guardarInformacao(std::stringstream &receber);
	void infoUtilizador();


};

class Policia: public PostoSocorro {
	std::string veiculo; // "Carro" ou "Moto"
public:
	//construtor
	Policia() :
			PostoSocorro() {
		this->veiculo.clear();
	}
	Policia(u_int numero_Socorristas, u_int numero_Veiculos,
			std::pair<int, int> local, std::string veiculo);
	~Policia() {
	}
	//get
	std::string getVeiculo();
	std::string getTipo() {
		return "Policia";
	}
	std::string getAllInfo();
	std::string getAllInfoFormatoPrint() ;
	void setAllInfo(std::string s){}
	//set
	void guardarInformacao(std::stringstream &receber);
	void infoUtilizador();

};

class Inem: public PostoSocorro {
	std::string veiculo; // "Ambulancia", "Carro" ou "Moto"
public:
	//contrutor
	Inem() :
			PostoSocorro() {
		this->veiculo.clear();
	}
	Inem(u_int numero_Socorristas, u_int numero_Veiculos,
			std::pair<int, int> local, std::string veiculo);
	~Inem() {
	}
	//get
	std::string getVeiculo();
	std::string getTipo() {
		return "Inem";
	}
	std::string getAllInfo();
	std::string getAllInfoFormatoPrint() ;
	void setAllInfo(std::string s){}
	//set
	void guardarInformacao(std::stringstream &receber);
	void infoUtilizador();

};



#endif /* POSTOSOCORRO_H_ */
