#ifndef MENU_H
#define MENU_H

#include "Header.h"
#include "Acidente.h"
#include "PostoSocorro.h"



class Menu{

	std::vector<Acidente*> acidentes;
	std::vector<PostoSocorro*> postos_socorro;

	bool existe_ficheiro_acidentes() const {
		if(std::ifstream("Acidentes.txt"))return true;
		else return false;
	}
	std::ofstream & create_ficheiro_acidente(){
		std::ofstream file("Acidentes.txt");
		if(!file)
		{
			std::cout << "Aconteceu um erro a criar o ficheiro Acidentes.txt";
			//atirar uma exceção
		}
		return file;
	}
public:
	std::vector<Acidente*> getAcidentes();
	std::vector<PostoSocorro*> getPostosSocorro();

	void adicionaAcidente(Acidente *acidente);
	void adicionaPostosSocorro(PostoSocorro *posto);

	void menuOpcoesIniciais();
	void menuOpcoesAcidente();
	void menuOpcoesPostosSocorro();

	void lerFicheiroAcidente();
	void EscreveFicheiroAcidente();

};




#endif /* MENU_H_ */
