#include "Header.h"
#include "Menu.h"


void Menu::menuOpcoesIniciais(){

	ClearScreen();

	this->lerFicheiroAcidente();
	//this->lerFicheiroPostos();

	std::string opcao;

	std::cout << "//// Menu Inicial ////\n";

	std::cout << "Lista de Acoes: \n";
	std::cout << "1 - Acoes sobre Acidentes\n";
	std::cout << "2 - Acoes sobre Postos de Socorro\n";

	std::cout << "Indique o digito correspondente a opcao desejada: ";
	std::cin >> opcao;


	while (!(opcao == "1" || opcao == "2"))
	{
		std::cout << "\n(!) A opcao fornecida nao e valida (!)\n\n";
		std::cout << "Indique o digito correspondente a opção desejada: ";
		std::cin >> opcao;
	}


	if (opcao == "1")
	{
		ClearScreen();
		this->menuOpcoesAcidente();
	}

}

void Menu::menuOpcoesAcidente()
{
	ClearScreen();

	std::string opcao;

	std::cout << "//// Menu Opcoes de Acidentes ////\n";

	std::cout << "Lista de Acoes: \n";
	std::cout << "1 - Reportar um Acidente\n";
	std::cout << "2 - Remover um Acidente\n";
	std::cout << "3 - Alterar um Acidente\n";
	std::cout << "0 - Voltar ao menu inicial\n";

	std::cout << "Indique o digito correspondente a opcao desejada: ";
	std::cin >> opcao;

	while (!(opcao == "1" || opcao == "2" || opcao == "3" || opcao == "0"))
	{
		std::cout << "\n(!) A opcao fornecida nao e valida (!)\n\n";
		std::cout << "Indique o digito correspondente a opção desejada: ";
		std::cin >> opcao;
	}


	if (opcao == "1")
	{
		ClearScreen();
		// FALTA FUNCAO!
	}
	if (opcao == "2")
	{
		ClearScreen();
		// FALTA FUNCAO!
	}
	if (opcao == "3")
	{
		ClearScreen();
		// FALTA FUNCAO!
	}
	if (opcao == "0")
	{
		ClearScreen();
		return;
	}


}

void Menu::menuOpcoesPostosSocorro()
{
	ClearScreen();

	std::string opcao;

	std::cout << "//// Menu Opcoes de Postos de Socorro ////\n";

	std::cout << "Lista de Acoes: \n";
	std::cout << "1 - Adicionar um Posto\n";
	std::cout << "2 - Remover um Posto\n";
	std::cout << "3 - Modificar um Posto\n";
	std::cout << "0 - Voltar ao menu inicial\n";

	std::cout << "Indique o digito correspondente a opcao desejada: ";
	std::cin >> opcao;

	while (!(opcao == "1" || opcao == "2" || opcao == "3" || opcao == "0"))
	{
		std::cout << "\n(!) A opcao fornecida nao e valida (!)\n\n";
		std::cout << "Indique o digito correspondente a opção desejada: ";
		std::cin >> opcao;
	}


	if (opcao == "1")
	{
		ClearScreen();
		// FALTA FUNCAO!
	}
	if (opcao == "2")
	{
		ClearScreen();
		// FALTA FUNCAO!
	}
	if (opcao == "3")
	{
		ClearScreen();
		// FALTA FUNCAO!
	}
	if (opcao == "0")
	{
		ClearScreen();
		return;
	}

}


