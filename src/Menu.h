#ifndef MENU_H
#define MENU_H

#include "Header.h"
#include "Acidente.h"
#include "PostoSocorro.h"

class Menu{

	std::vector<Acidente*> acidentes;
	std::vector<PostoSocorro*> postos_socorro;
	bool terminar;
public:
	//Construtores
	Menu();


	//Get methods
	bool getTerminar() const;
	std::vector<Acidente*> getAcidentes();
	std::vector<PostoSocorro*> getPostosSocorro();


	//Operacoes com ficheiros
	//std::ofstream & create_ficheiro_acidente();
	bool existe_ficheiro_acidentes() const;
	void lerFicheiroAcidente();
	void EscreveFicheiroAcidente();

	void lerFicheiroPostoSocorro();
	void escreverFicheiroPostoSocorro();


	//Operacoes com os vetores
	bool AcidenteExistente(Acidente* aci) const;
	// falta bool PostoSocorroExsitente(PostoSocorro *posto)
	void adicionaAcidente(Acidente *acidente);
	void adicionaPostosSocorro(PostoSocorro *posto);


	//Varios menus
	void menuOpcoesIniciais_0();
	void menuOpcoesAcidente_1();
	void menuOpcoesPostosSocorro_1();


	//Funcoes menu acidente
	void criarAcidente();
	void removerAcidente();


	//Funcoes print dos vetores
	void printAcidentes();
	void printPostos();

};




#endif /* MENU_H_ */
