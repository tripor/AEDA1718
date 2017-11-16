#include "Header.h"
#include "Acidente.h"
#include "PostoSocorro.h"
#include "Menu.h"

// Incendios Florestais

u_int nCarrosBombeirosArea(u_int a){
	return ((a/1000) + 1);
}

u_int nBombeirosArea(u_int a){
	return (a/100) + 1;
}

// Incendios Domesticos

u_int numeroCarBombeirosApart(){
	return 2;
}

u_int numeroBombeirosApart(){
	return 10;
}

u_int numeroCarBombeirosMoradia(){
	return 3;
}

u_int numeroBombeirosMoradia(){
	return 15;
}

// Get methods

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


void Menu::adicionaPostosSocorro(PostoSocorro *posto){

	//falta testar se posto já existe
	postos_socorro.push_back(posto);
}

void Menu::adicionaAcidente(Acidente *acidente){
	if(this->AcidenteExistente(acidente)){
		//lancar exececao
	}
	else{
		this->acidentes.push_back(acidente);
	}
}


void Menu::menuOpcoesIniciais_0(){

	ClearScreen();

	this->lerFicheiroAcidente();
	this->lerFicheiroPostoSocorro();

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
		this->menuOpcoesAcidente_1();
	}


	// Escrever para ficheiro os vetores

	this->EscreveFicheiroAcidente();
	this->escreverFicheiroPostoSocorro();
}
void Menu::menuOpcoesAcidente_1()
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
		this->criarAcidente();
		return;
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
void Menu::menuOpcoesPostosSocorro_1()
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
	std::ifstream ficheiro;
	ficheiro.open("Acidente.txt");
	while (getline(ficheiro, linha)) {

		std::stringstream ss(linha);
		ss >> tipo;
		system("pause");
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

		else if (tipo == "AcidenteViacao") {
			Acidente* temp = new AcidenteViacao;
			temp->lerInfo(ss);
			this->adicionaAcidente(temp);

		}
	}
	ficheiro.close();

}

void Menu::EscreveFicheiroAcidente() {
	std::string linha;
	std::string tipo;
	std::stringstream ss;
	std::ofstream ficheiro("Acidente.txt",std::ofstream::out|std::ofstream::trunc);
	for (size_t i = 0; i < this->acidentes.size(); i++) {
		ficheiro << this->acidentes.at(i)->getTipoAcidente() << ' '
				<< this->acidentes.at(i)->getData() << ' '
				<< this->acidentes.at(i)->getLocal().first << ' '
				<< this->acidentes.at(i)->getLocal().second << ' '
				<< this->acidentes.at(i)->getAllInfo() << std::endl;
	}

	ficheiro.close();
}

void Menu::lerFicheiroPostoSocorro() {
	std::string linha;
	std::string tipo;
	std::ifstream ficheiro("PostoSocorro.txt");
	while (getline(ficheiro, linha)) {
		std::stringstream ss(linha);
		ss >> tipo;
		if (tipo == "Bombeiros") {
			PostoSocorro* temp = new Bombeiros;
			temp->guardarInformacao(ss);
			this->adicionaPostosSocorro(temp);
		} else if (tipo == "Policia") {
			PostoSocorro* temp = new Policia;
			temp->guardarInformacao(ss);
			this->adicionaPostosSocorro(temp);
		} else if (tipo == "Inem") {
			PostoSocorro* temp = new Inem;
			temp->guardarInformacao(ss);
			this->adicionaPostosSocorro(temp);
		}
	}
	ficheiro.close();

}
void Menu::escreverFicheiroPostoSocorro() {
	std::string linha;
	std::string tipo;
	std::stringstream ss;
	std::ofstream ficheiro("PostoSocorro.txt",
			std::ofstream::out | std::ofstream::trunc);
	for (size_t i = 0; i < this->acidentes.size(); i++) {
		ficheiro << this->postos_socorro.at(i)->getTipo() << ' '
				<< this->postos_socorro.at(i)->getAllInfo();
	}

	ficheiro.close();

}


void Menu::criarAcidente(){

	std::string opcao;

	std::cout << "Indique o tipo de acidente: \n";
	std::cout << "1 - Incendio Florestal\n";
	std::cout << "2 - Incendio Domestico\n";
	std::cout << "3 - Assalto\n";
	std::cout << "4 - Acidente de Viacao\n";
	std::cout << "0 - Voltar ao Menu Inicial\n";

	std::cout << "Indique o tipo de acidente: ";
	std::cin >> opcao;

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
	*/


	return;
}




void Menu::removerAcidente(){

	std::string opcao;

	std::cout << "Tipos de acidente: \n";
	std::cout << "1 - Incendio Florestal\n";
	std::cout << "2 - Incendio Domestico\n";
	std::cout << "3 - Assalto\n";
	std::cout << "4 - Acidente de Viacao\n";
	std::cout << "0 - Voltar ao Menu Inicial\n";

	std::cout << "Indique o tipo de acidente a remover: ";
	std::cin >> opcao;

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
	*/


	return;


}



