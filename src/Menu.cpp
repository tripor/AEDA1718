#include "Header.h"
#include "Menu.h"


void Menu::menuOpcoesIniciais(){

	ClearScreen();

	this->lerFicheiroAcidente();
	//this->lerFicheiroPostos();

	std::string opcao;

	std::cout << "//// Menu Inicial ////\n";

	std::cout << "Lista de Acoes: \n";
	std::cout << "1 - Reportar um Acidente\n";
	std::cout << "2 - Adicionar um novo Posto de Socorro\n";

	std::cout << "Indique o digito correspondente a opcao desejada: ";
	std::cin >> opcao;


	while (!(opcao == "1" || opcao == "2"))
	{
		std::cout << "\n(!) A opcao fornecida nao e valida (!)\n\n";
		std::cout << "Indique o digito correspondente a opção desejada: ";
		std::cin >> opcao;
	}

}

void Menu::menuOpcoesAcidente()
{


}



