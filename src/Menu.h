#ifndef MENU_H
#define MENU_H

#include "Header.h"
#include "Acidente.h"
#include "PostoSocorro.h"



class Menu{

	std::vector<Acidente*> acidentes;
	std::vector<PostoSocorro*> postos_socorro;

public:
	std::vector<Acidente> getAcidentes(){
		return acidentes;
	}

	std::vector<PostoSocorro> getPostosSocorro(){
		return postos_socorro;
	}

	void adicionaAcidente(Acidente *acidente){
		acidentes.push_back(acidente);
	}

	void adicionaPostosSocorro(PostoSocorro *posto){
		postos_socorro.push_back(posto);
	}
	void menuOpcoesIniciais();


	void lerFicheiroAcidente(){
		  std::string linha;
		  std::string tipo;
		  std::stringstream ss;
		  std::ifstream ficheiro ("Acidente.txt");
		  while (!ficheiro.eof())
		  {

		  getline(ficheiro,linha);
		  ss << tipo;


		  	 switch(tipo){

		  	 case("Incendio_Florestal"):
		  		Acidente* temp = new Florestal();
		  		temp->lerInfo(ss);
		  		this->adicionaAcidente(temp);

		  		break;

		  	 case("Incendio_Domesticos"):
				Acidente* temp = new Domesticos();
				temp->lerInfo(ss);
				this->adicionaAcidente(temp);

				break;

		  	 case("Assalto"):
				Acidente* temp = new Assalto();
				temp->lerInfo(ss);
				this->adicionaAcidente(temp);

				break;

		  	 case("Acidente_Viacao"):
				Acidente* temp = new Acidente_Viacao();
				temp->lerInfo(ss);
				this->adicionaAcidente(temp);

				break;

		  	 default:
		  		 throw AcidenteDesconhecido(tipo);

		  	 }


		  }
		  ficheiro.close();
	}



	void EscreveFicheiroAcidente(){
		  std::string linha;
		  std::string tipo;
		  std::stringstream ss;
		  std::ifstream ficheiro ("Acidente.txt");
		  while (!ficheiro.eof())
		  {

	for(int i = 0; acidentes.size(), i++){

		  	 switch(tipo){

		  	 case("Incendio_Florestal"):
		  		Acidente* temp = new Florestal();
		  		temp->lerInfo(ss);
		  		this->adicionaAcidente(temp);

		  		break;

		  	 case("Incendio_Domesticos"):
				Acidente* temp = new Domesticos();
				temp->lerInfo(ss);
				this->adicionaAcidente(temp);

				break;

		  	 case("Assalto"):
				Acidente* temp = new Assalto();
				temp->lerInfo(ss);
				this->adicionaAcidente(temp);

				break;

		  	 case("Acidente_Viacao"):
				Acidente* temp = new Acidente_Viacao();
				temp->lerInfo(ss);
				this->adicionaAcidente(temp);

				break;

		  	 default:
		  		 throw AcidenteDesconhecido(tipo);

		  	 }


		  }

		  ficheiro.close();
	}


};




#endif /* MENU_H_ */
