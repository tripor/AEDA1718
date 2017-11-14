#ifndef ACIDENTE_H_
#define ACIDENTE_H_

#include "Header.h"

// Classe Acidente e suas derivadas

class Acidente{
protected:
	std::string data; // Formato YYYY-MM-DD-HH-MM
	std::pair<int,int> local; // Sistema de coordenadas (x,y)
public:
	//Construtores e destrutor
	Acidente(){this->data=" ";this->local=std::make_pair(0,0);}
	Acidente(std::string d, std::pair<int,int> local);
	virtual ~Acidente(){};
	//Metodos Get
	std::string getData() const;
	std::pair<int,int> getLocal() const;
	//Metodos Set
	void setData(std::string d);
	void setLocal(std::pair<int,int> par);
	//Outros Metodos
	virtual void lerInfo(std::stringstream &ss) =0;
	virtual std::string getTipoAcidente() const;
	bool operator== (const Acidente* & a) const;

};

class AcidenteDesconhecido{
	std::string tipo;

public:
	AcidenteDesconhecido(std::string tipo){
		this->tipo = tipo;
	}
	void tratamento_Tipo(){
	std::cout << "Erro: Tipo de acidente '" << tipo << "' invalido\n";
	}

};

class Incendios : public Acidente{
protected:
	u_int numero_CarrosBombeiros;
	u_int numero_Bombeiros;
public:
	//Construtores e destrutor
	Incendios():Acidente(){this->numero_Bombeiros=0;this->numero_CarrosBombeiros=0;};
	Incendios(u_int n_carros, u_int n_bombeiros, std::string d, std::pair<int,int> local);
	virtual ~Incendios(){};
	//Metodos Get
	u_int getNumeroCarrosBombeiros() const;
	u_int getNumeroBombeiros() const;
	//Metodos Set
	void setNumeroCarrosBombeiros(u_int n);
	void setNumeroBombeiros(u_int n);
	//Outros Metodos
	//virtual void lerInfo(std::stringstream ss);
	//virtual std::string getTipoAcidente() const{return  " ";}

};

class Florestal : public Incendios{
	u_int area_Chamas;
public:
	//Construtores e destrutor
	Florestal():Incendios(){this->area_Chamas=0;}
	~Florestal(){};
	//Metodos Get
	u_int getAreaChamas() const;
	//Metodos Set
	void setAreaChamas(u_int area);
	//Outros Metodos
	void lerInfo(std::stringstream &ss);
	std::string getTipoAcidente() const {return "Florestal";}

	class Area_Invalida{
	public:
		int area;
		Area_Invalida(int a){area = a;}
		void tratamento_Area(){
			if(area == 0){
				std::cout << "Erro: Tipo de vari�vel inserido inv�lido ou valor de �rea invalido\n";
			}
			else if (area < 0){
				std::cout << "Erro: �rea negativa inserida\n";
			}
		}
	};

};

class Domesticos : public Incendios{
	std::string tipo_casa; // "Apartamento" ou "Moradia"
public:
	//Construtores e destrutor
	Domesticos():Incendios(){this->tipo_casa=" ";}
	~Domesticos(){};
	//Metodos Get
	std::string getTipoCasa() const;
	//Metodos Set
	void setTipoCasa(std::string s);
	//Outros Metodos
	void lerInfo(std::stringstream &ss);
	std::string getTipoAcidente() const{return "Domestico";}

	class Tipo_Casa_Invalida{
		public:
			std::string tipo;
			Tipo_Casa_Invalida(std::string s){tipo = s;}
			void tratamento_Tipo(){
				std::cout << "Erro: Tipo de casa '" << tipo << "' inv�lido\n";
			}
		};


};


class Assalto : public Acidente{
	bool existe_Feridos;
	std::string tipo_casa; // "Particular" ou "Comercial"
public:
	//Construtores e destrutor
	Assalto():Acidente(){this->existe_Feridos=false;this->tipo_casa=" ";}
	virtual ~Assalto(){}

	//Metodos Get
	bool getExisteFeridos() const;
	std::string getTipoCasa() const;

	//Metodos Set
	void setExisteFeridos(bool n);
	void setTipoCasa(std::string s);

	//Outros Metodos
	void lerInfo(std::stringstream &ss);
	std::string getTipoAcidente() const{return "Assalto";}
};
class Tipo_Casa_Invalida {
public:
	std::string tipo;
	Tipo_Casa_Invalida(std::string s) {
		tipo = s;
	}
	void tratamento_Tipo() {
		std::cout << "Erro: Tipo de casa '" << tipo << "' inv�lido\n";
	}
};

class AcidenteViacao : public Acidente{
	u_int numero_FeridosGraves;
	u_int numero_VeiculosEnvolvidos;
	std::string tipo_Estrada; // "Nacional" ou "Auto-Estrada"
public:
	//Construtores e destrutor

	AcidenteViacao():Acidente(){this->numero_FeridosGraves=0;this->numero_VeiculosEnvolvidos=0;this->tipo_Estrada=" ";}
	virtual ~AcidenteViacao(){}
	//Metodos Get

	u_int getNumeroFeridosGraves() const;
	u_int getNumeroVeiculosEnvolvidos() const;
	std::string getTipoEstrada() const;

	//Metodos Set
	void setNumeroFeridosGraves(u_int n);
	void setNumeroVeiculosEnvolvidos(u_int n);
	void setTipoEstrada(std::string s);


	void lerInfo(std::stringstream &ss);
	std::string getTipoAcidente() const{return "Acidente_Viacao";}




};


class Tipo_Estrada_Invalida {
public:
	std::string tipo;
	Tipo_Estrada_Invalida(std::string s) {
		tipo = s;
	}
	void tratamento_Tipo() {
		std::cout << "Erro: Tipo de estrada '" << tipo << "' inv�lido\n";
	}
};



#endif /* ACIDENTE_H_ */
