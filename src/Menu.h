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

	Menu();
	bool getTerminar() const;

	bool AcidenteExistente(Acidente* aci) const;

	//std::ofstream & create_ficheiro_acidente();
	bool existe_ficheiro_acidentes() const;

	std::vector<Acidente*> getAcidentes();
	std::vector<PostoSocorro*> getPostosSocorro();

	void adicionaAcidente(Acidente *acidente);
	void adicionaPostosSocorro(PostoSocorro *posto);

	void menuOpcoesIniciais_0();
	void menuOpcoesAcidente_1();
	void menuOpcoesPostosSocorro_1();

	//Funcoes ler e escrever
	void lerFicheiroAcidente();
	void EscreveFicheiroAcidente();

	void lerFicheiroPostoSocorro();
	void escreverFicheiroPostoSocorro();

	//Funcoes menu acidente
	void criarAcidente();
	void removerAcidente();

	//Funcoes print dos vetores
	void printAcidentes();
	void printPostos();

};




#endif /* MENU_H_ */
