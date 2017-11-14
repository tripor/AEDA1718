#ifndef ACIDENTE_H_
#define ACIDENTE_H_

#include "Header.h"

// Classe Acidente e suas derivadas

class Acidente{
	std::string data; // Formato YYYY-MM-DD-HH-MM
	std::pair<int,int> local; // Sistema de coordenadas (x,y)
public:
	//Construtores e destrutor
	Acidente() {};
	Acidente(std::string d, std::pair<int,int> local);
	~Acidente() {};
	//Metodos Get
	std::string getData() const;
	std::pair<int,int> getLocal() const;
	//Metodos Set
	void setData(std::string d);
	void setLocal(std::pair<int,int> par);
	//Outros Metodos
	virtual void lerInfo(std::stringstream ss) = 0;
	virtual std::string getTipoAcidente() const = 0;
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
	u_int numero_CarrosBombeiros;
	u_int numero_Bombeiros;
public:
	//Construtores e destrutor
	Incendios():Acidente(){};
	Incendios(u_int n_carros, u_int n_bombeiros, std::string d, std::pair<int,int> local);
	~Incendios();
	//Metodos Get
	u_int getNumeroCarrosBombeiros() const;
	u_int getNumeroBombeiros() const;
	//Metodos Set
	void setNumeroCarrosBombeiros(u_int n);
	void setNumeroBombeiros(u_int n);
	//Outros Metodos
	virtual void lerInfo(std::stringstream ss){}
	virtual std::string getTipoAcidente() const{return  " ";}

};

class Florestal : public Incendios{
	u_int area_Chamas;
public:
	//Construtores e destrutor
	Florestal():Incendios(){}
	~Florestal();
	//Metodos Get
	u_int getAreaChamas() const;
	//Metodos Set
	void setAreaChamas(u_int area);
	//Outros Metodos
	void lerInfo(std::stringstream ss);
	std::string getTipoAcidente() const {return "Florestal";}

	class Area_Invalida{
	public:
		int area;
		Area_Invalida(int a){area = a;}
		void tratamento_Area(){
			if(area == 0){
				std::cout << "Erro: Tipo de variável inserido inválido ou valor de área invalido\n";
			}
			else if (area < 0){
				std::cout << "Erro: Área negativa inserida\n";
			}
		}
	};

};

class Domesticos : public Incendios{
	std::string tipo_casa; // "Apartamento" ou "Moradia"
public:
	//Construtores e destrutor
	Domesticos():Incendios(){}
	~Domesticos();
	//Metodos Get
	std::string getTipoCasa() const;
	//Metodos Set
	void setTipoCasa(std::string s);
	//Outros Metodos
	void lerInfo(std::stringstream ss);
	std::string getTipoAcidente() const{return "Domestico";}

	class Tipo_Casa_Invalida{
		public:
			std::string tipo;
			Tipo_Casa_Invalida(std::string s){tipo = s;}
			void tratamento_Tipo(){
				std::cout << "Erro: Tipo de casa '" << tipo << "' inválido\n";
			}
		};


};


class Assalto : public Acidente{
	bool existe_Feridos;
	std::string tipo_casa; // "Particular" ou "Comercial"
public:
	//Construtores e destrutor
	Assalto(): Acidente(){}
	~Assalto();
	//Metodos Get
	bool getExisteFeridos() const;
	std::string getTipoCasa() const;
	//Metodos Set
	void setExisteFeridos(bool n);
	void setTipoCasa(std::string s);
	//Outros Metodos
	void lerInfo(std::stringstream ss);
	std::string getTipoAcidente() const{return "Assalto";}

	class Tipo_Casa_Invalida{
		public:
			std::string tipo;
			Tipo_Casa_Invalida(std::string s){tipo = s;}
			void tratamento_Tipo(){
				std::cout << "Erro: Tipo de casa '" << tipo << "' inválido\n";
			}
		};



};

class Acidente_Viacao : public Acidente{
	u_int numero_FeridosGraves;
	u_int numero_VeiculosEnvolvidos;
	std::string tipo_Estrada; // "Nacional" ou "Auto-Estrada"
public:
	//Construtores e destrutor
	Acidente_Viacao(): Acidente(){}
	~Acidente_Viacao();
	//Metodos Get
	u_int getNumeroFeridosGraves() const;
	u_int getNumeroVeiculosEnvolvidos() const;
	std::string getTipoEstrada() const;
	//Metodos Set
	void setNumeroFeridosGraves(u_int n);
	void setNumeroVeiculosEnvolvidos(u_int n);
	void setTipoEstrada(std::string s);
	//Outros Metodos
	void lerInfo(std::stringstream ss);
	std::string getTipoAcidente() const{return "Acidente_Viacao";}

	class Tipo_Estrada_Invalida{
		public:
			std::string tipo;
			Tipo_Estrada_Invalida(std::string s){tipo = s;}
			void tratamento_Tipo(){
				std::cout << "Erro: Tipo de estrada '" << tipo << "' inválido\n";
			}
		};


};





#endif /* ACIDENTE_H_ */
