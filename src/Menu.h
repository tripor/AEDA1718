#ifndef MENU_H
#define MENU_H

#include "Header.h"
#include "Acidente.h"
#include "PostoSocorro.h"

class Menu{

	std::vector<Acidente*> acidentes;
	std::vector<PostoSocorro*> postos_socorro;
public:

	//std::ofstream & create_ficheiro_acidente();
	bool existe_ficheiro_acidentes() const;

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
