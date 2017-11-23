#ifndef MENU_H
#define MENU_H

#include "Header.h"
#include "Acidente.h"
#include "PostoSocorro.h"

void eNumero(std::string testar);
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
	void retirarAcidente(u_int posicao);
	void retirarPosto(u_int posicao);

	//ATRIBUICAO DE ACIDENTES
	void atribuiAcidentes();

	//Ordenar vetores
	void ordenaVetorAcidentes();
	void ordenaVetorPostosSocorro(std::vector<PostoSocorro*> &v1);

	//Varios menus
	void menuOpcoesIniciais_0();
	void menuOpcoesAcidente_1();
	void menuOpcoesPostosSocorro_1();


	//Funcoes menu acidente
	void criarAcidente();
	void removerAcidente();

	void criarPosto();
	void removerPosto();

	void printAcidentesAlocados();

	//Funcoes print dos vetores
	void printAcidentes();
	void printPostos();

	//Outros

};




#endif /* MENU_H_ */
