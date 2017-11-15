#include "Header.h"
#include "Menu.h"
#include "Acidente.h"
#include "PostoSocorro.h"


void Menu::adicionaAcidente(Acidente *acidente){

	std::string opcao;

	std::cout << "Indique o tipo de acidente: \n";
	std::cout << "1 - Incendio Florestal\n";
	std::cout << "2 - Incendio Domestico\n";
	std::cout << "3 - Assalto\n";
	std::cout << "4 - Acidente de Viacao\n";
	std::cout << "0 - Voltar ao Menu Inicial\n";

	while (!(opcao == "1" || opcao == "2" || opcao == "3" || opcao == "4" || opcao == "0"))
		{
			std::cout << "\n(!) A opcao fornecida nao e valida (!)\n\n";
			std::cout << "Indique o tipo de acidente: ";
			std::cin >> opcao;
		}

	Acidente *a;

	if (opcao == "1")
	{
		a = new Florestal;
	}
	if (opcao == "2")
	{
		a = new Domesticos;
	}
	if (opcao == "3")
	{
		a = new Assalto;
	}
	if (opcao == "4")
	{
		a = new AcidenteViacao;
	}
	if (opcao == "0")
	{
		return;
	}
	//falta a atribuicao, fazer por pointer?
	//falta testar se acidente já existe
	this->acidentes.push_back(a);

}

