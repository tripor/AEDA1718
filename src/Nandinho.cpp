/*#include "Header.h"
#include "Menu.h"
#include "Acidente.h"
#include "PostoSocorro.h"


void Menu::adicionaAcidente(Acidente *acidente){
	if(this->AcidenteExistente(acidente)){
		//lancar exececao
	}
	else{
		this->acidentes.push_back(acidente);
	}
}

// VIRTUAL!

void Florestal::infoUtilizador(){

	ClearScreen();

	u_int area,

	//std::cout << "\nQuantos carros de bombeiros necessita o acidente?" Nao pode perguntar, tem de ser o programa a calcular
	std::cout << "Área do incêndio: ";
	std::cin >> area;

	//testar se o input é valido!!!

	this->setNumeroCarrosBombeiros(nCarrosBombeirosArea(area));
	this->setNumeroBombeiros(nBombeirosArea(area));


}



void Menu::criarAcidente(){

	std::string opcao;

	std::cout << "Indique o tipo de acidente: \n";
	std::cout << "1 - Incendio Florestal\n";
	std::cout << "2 - Incendio Domestico\n";
	std::cout << "3 - Assalto\n";
	std::cout << "4 - Acidente de Viacao\n";
	std::cout << "0 - Voltar ao Menu Inicial\n";

	while (!(opcao == "1" || opcao == "2" || opcao == "3" || opcao == "4" || opcao == "0")) {
		std::cout << "\n(!) A opcao fornecida nao e valida (!)\n\n";
		std::cout << "Indique o tipo de acidente: ";
		std::cin >> opcao;
	}

	Acidente *a;

	if (opcao == "1") {
		a = new Florestal;
		a->infoUtilizador();
		std::cout << "Feito!\n";
	}
	/*
	if (opcao == "2") {
		a = new Domesticos;
	}
	if (opcao == "3") {
		a = new Assalto;
	}
	if (opcao == "4") {
		a = new AcidenteViacao;
	}
	if (opcao == "0") {
		return;
	}



	return;
}


*/
