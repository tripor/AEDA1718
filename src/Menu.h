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


	void LeFicheiro(){
		  string tipo;
		  std::ofstream ficheiro ("Acidente.txt");
		  while (!ficheiro.eof())
		  {
		  getline(ficheiro,data);



		  }
		  ficheiro.close();
	}


};








#endif /* MENU_H_ */
