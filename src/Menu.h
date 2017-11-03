#ifndef MENU_H
#define MENU_H

#include "Header.h"
#include "Acidente.h"
#include "PostoSocorro.h"



class Menu{

	std::vector<Acidente*> acidentes;
	std::vector<PostoSocorro*> postos_socorro;

public:
	std::vector<Acidente> GetAcidentes(){
		return acidentes;
	}

	std::vector<PostoSocorro> GetPostosSocorro(){
		return postos_socorro;
	}

	void AdicionaAcidente(Acidente *acidente){
		acidentes.push_back(acidente);
	}

	void AdicionaPostosSocorro(PostoSocorro *posto){
		postos_socorro.push_back(posto);
	}


	void LeFicheiroAcidente(){
		  std::string linha;
		  std::string tipo;
		  sstream ss;
		  std::ifstream ficheiro ("Acidente.txt");
		  while (!ficheiro.eof())
		  {

		  getline(ficheiro,linha);


		  	 switch(tipo){

		  	 case("Incendio_Florestal"):
		  			 Acidente* temp = new Florestal();
		  			 temp->lerInfo();

		  		break;

		  	 case("Incendio_Domesticos"):
				Acidente* temp = new Domesticos();
				temp->lerInfo();

				break;

		  	 case("Assalto"):
				break;

		  	 case("Acidente_Viação"):
				break;

		  	 default:
		  		 throw AcidenteDesconhecido(tipo);

		  	 }


		  }
		  ficheiro.close();
	}


};








#endif /* MENU_H_ */
