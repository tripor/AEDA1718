#include "Header.h"
#include "Acidente.h"
#include "PostoSocorro.h"
#include "Menu.h"

std::vector<Acidente*> Menu::getAcidentes(){
	return this->acidentes;
}
std::vector<PostoSocorro*> Menu::getPostosSocorro(){
	return postos_socorro;
}

bool Menu::AcidenteExistente(Acidente* aci) const{
	for(u_int i = 0; i < this->acidentes.size();i++){
		if(aci->acidenteIgual(acidentes.at(i))){
			return true;
		}
	}
	return false;
}



bool Menu::existe_ficheiro_acidentes() const {
	if(std::ifstream("Acidente.txt"))return true;
	else return false;
}
/*std::ofstream & Menu::create_ficheiro_acidente(){
	std::ifstream file("Acidente.txt");
	if(!file)
	{
		std::cout << "Aconteceu um erro a criar o ficheiro Acidentes.txt";
		//atirar uma exceção
	}
	return file;
}*/

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
void Menu::adicionaPostosSocorro(PostoSocorro *posto){



	//falta testar se posto já existe
	postos_socorro.push_back(posto);
}

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

void Menu::lerFicheiroAcidente() {
	std::string linha;
	std::string tipo;
	std::ifstream ficheiro("Acidente.txt");
	while (!ficheiro.eof()) {

		std::stringstream ss;
		getline(ficheiro, linha);
		ss << linha;
		ss >> tipo;

		if (tipo == "Incendio_Florestal") {
			Acidente *temp= new Florestal;
			temp->lerInfo(ss);
			this->adicionaAcidente(temp);

		}

		else if (tipo == "Incendio_Domesticos") {
			Acidente* temp = new Domesticos;
			temp->lerInfo(ss);
			this->adicionaAcidente(temp);

		}

		else if (tipo == "Assalto") {
			Acidente* temp = new Assalto;
			temp->lerInfo(ss);
			this->adicionaAcidente(temp);

		}

		else if (tipo == "Acidente_Viacao") {
			Acidente* temp = new AcidenteViacao;
			temp->lerInfo(ss);
			this->adicionaAcidente(temp);

		}

		else
			throw AcidenteDesconhecido(tipo);


	}
	ficheiro.close();

}

void Menu::EscreveFicheiroAcidente() {
	std::string linha;
	std::string tipo;
	std::stringstream ss;
	std::ofstream ficheiro("Acidente.txt");

	if (!this->existe_ficheiro_acidentes())
	{
	}
	else
		ficheiro.open("Acidente.txt");
	for (size_t i = 0; i < this->acidentes.size(); i++) {

	}

	ficheiro.close();
}

