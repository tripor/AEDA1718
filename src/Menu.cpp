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

//Construtor
Menu::Menu() {
	this->terminar = false;
	this->acidentes.clear();
	this->postos_socorro.clear();
}

// Get methods

bool Menu::getTerminar() const {
	return this->terminar;
}

std::vector<Acidente*> Menu::getAcidentes(){
	return this->acidentes;
}
std::vector<PostoSocorro*> Menu::getPostosSocorro(){
	return postos_socorro;
}

// Outros metodos

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
		//atirar uma exce��o
	}
	return file;
}*/


// Metodos para adicionar acidentes/postos socorro ao vetor

void Menu::adicionaPostosSocorro(PostoSocorro *posto){

	//falta testar se posto j� existe
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

////////////////////////
// MENUS
////////////////////////


void Menu::menuOpcoesIniciais_0(){

	//ClearScreen();
	this->lerFicheiroAcidente();
	this->lerFicheiroPostoSocorro();

	std::string opcao;

	std::cout << "//// Menu Inicial ////\n";

	std::cout << "Lista de Acoes: \n";
	std::cout << "1 - Acoes sobre Acidentes\n";
	std::cout << "2 - Acoes sobre Postos de Socorro\n";
	std::cout << "0 - Sair\n";

	std::cout << "Indique o digito correspondente a opcao desejada: ";
	std::cin >> opcao;


	while (!(opcao == "1" || opcao == "2" || opcao == "0"))
	{
		std::cout << "\n(!) A opcao fornecida nao e valida (!)\n\n";
		std::cout << "Indique o digito correspondente a op��o desejada: ";
		std::cin >> opcao;
	}


	if (opcao == "1")
	{
		//learScreen();
		this->menuOpcoesAcidente_1();
	}
	if (opcao == "0") {
		this->terminar=true;
	}
	// Escrever para ficheiro os vetores
	this->EscreveFicheiroAcidente();
	this->escreverFicheiroPostoSocorro();
}


void Menu::menuOpcoesAcidente_1()
{
	//ClearScreen();

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
		std::cout << "Indique o digito correspondente a op��o desejada: ";
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
		std::cout << "Indique o digito correspondente a op��o desejada: ";
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


/////////////////////////////////
// OPERACOES COM FICHEIROS
/////////////////////////////////

void Menu::lerFicheiroAcidente() {

	std::string linha;
	std::string tipo;
	std::ifstream ficheiro;
	ficheiro.open("src/Acidente.txt");
	while (getline(ficheiro, linha)) {

		std::stringstream ss(linha);
		ss >> tipo;
		if (tipo == "Florestal") {
			Acidente *temp= new Florestal;
			temp->lerInfo(ss);
			this->adicionaAcidente(temp);

		}

		else if (tipo == "Domestico") {
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
	std::ofstream ficheiro("src/Acidente.txt",std::ofstream::out|std::ofstream::trunc);
	for (size_t i = 0; i < this->acidentes.size(); i++) {
		ficheiro << this->acidentes.at(i)->getTipoAcidente() << ' '
				<< this->acidentes.at(i)->getData() << ' '
				<< this->acidentes.at(i)->getLocal().first << ' '
				<< this->acidentes.at(i)->getLocal().second << ' '
				<< this->acidentes.at(i)->getAllInfo() << std::endl;
	}
	ficheiro.close();
	//Limpar os vetores
	this->acidentes.clear();
	this->postos_socorro.clear();
}

void Menu::lerFicheiroPostoSocorro() {

	std::string linha;
	std::string tipo;
	std::ifstream ficheiro("src/PostoSocorro.txt");
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
	std::ofstream ficheiro("src/PostoSocorro.txt",
			std::ofstream::out | std::ofstream::trunc);
	for (size_t i = 0; i < this->postos_socorro.size(); i++) {
		ficheiro << this->postos_socorro.at(i)->getTipo() << ' '
				<< this->postos_socorro.at(i)->getAllInfo();
	}
	ficheiro.close();

	//Limpar os vetores
	this->acidentes.clear();
	this->postos_socorro.clear();
}


/////////////////////////////////////
// FUNCOES MENU ACIDENTE
/////////////////////////////////////

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
		a->infoUtilizadorGeral();
		a->infoUtilizador();
		this->adicionaAcidente(a);
		std::cout << "Feito!" << std::endl;
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
		a->infoUtilizadorGeral();
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




void Menu::printAcidentes(){

		std::stringstream ss;
	for(unsigned int i = 0; i<acidentes.size(); i++){

		std::cout << "<" << acidentes.at(i)->getTipoAcidente()<< std::endl;
		std::cout << "<" << "[" << acidentes.at(i)->getLocal().first<<",";
		std::cout <<acidentes.at(i)->getLocal().second <<"]"<<std::endl;
		(acidentes.at(i)->getData()).printDate();
		std::cout << std::endl;
		std::string a = acidentes.at(i)->getTipoAcidente();//para as condi��es

		ss << acidentes.at(i)->getAllInfo();

		if(a=="Incendio_Florestal"){

			std::string n_carros;
			ss >> n_carros;
			std::cout<<"Numero de carros de bombeiros: "<<n_carros<<std::endl;

			std::string n_bombeiros;
			ss >> n_bombeiros;
			std::cout<<"Numero de bombeiros: "<<n_bombeiros<<std::endl;

			std::string area_chamas;
			ss >> area_chamas;
			std::cout<<"area em chamas: "<<area_chamas<<std::endl;
		}

		else if (a=="Incendio_Domestico"){
			std::string n_carros;
			ss >> n_carros;
			std::cout<<"Numero de carros de bombeiros: "<<n_carros<<std::endl;

			std::string n_bombeiros;
			ss >> n_bombeiros;
			std::cout<<"Numero de bombeiros: "<<n_bombeiros<<std::endl;

			std::string tipo_casa;
			ss>>tipo_casa;
			std::cout<<"Tipo de casa: "<<tipo_casa<<std::endl;

		}

		else if(a=="Assalto"){
			std::string feridos;
			ss>>feridos;
			if(feridos=="0")
				std::cout<<"Nao existem feridos"<<std::endl;
			else
				std::cout<<"Existem feridos"<<std::endl;

			std::string tipo_casa;
			ss>>tipo_casa;
			std::cout<<"Tipo de casa: " << tipo_casa << std::endl;


		}


		else if(a=="AcidenteViacao"){

			std::string n_feridosGraves;
			ss>>n_feridosGraves;
			std::cout<<"Numero de feridos graves: " << n_feridosGraves << std::endl;

			std::string n_veiculos;
			ss>>n_veiculos;
			std::cout<<"Numero de veiculos envolvidos: " << n_veiculos << std::endl;

			std::string tipo_estrada;
			ss>>tipo_estrada;
			std::cout<<"Tipo de estrada: " << tipo_estrada << std::endl;


		}
	}
}

void Menu::printPostos(){

		std::stringstream ss;
	for(unsigned int i = 0; i<postos_socorro.size(); i++){
		ss << postos_socorro.at(i)->getAllInfo();
		std::string n_socorristas;
		ss >> n_socorristas;
		std::cout << "< Numero de socorristas: " << n_socorristas<< std::endl;

		std::string n_veiculos;
		ss >> n_veiculos;
		std::cout << "< Numero de veiculos: " << n_veiculos<< std::endl;

		std::string corX;
		std::string corY;
		ss >> corX;
		ss >> corY;
		std::cout << "<" << "[" << corX<<",";
		std::cout << corY <<"]"<<std::endl;

		std::string TipoPosto;
		TipoPosto = postos_socorro.at(i)->getTipo();

		if(TipoPosto=="Bombeiros"){
			std::string n_ambulancia;
			ss >> n_ambulancia;
			std::cout << "Numero de ambulancias: " << n_ambulancia << std::endl;
			std::string n_autotanques;
			ss >> n_autotanques;
			std::cout << "Numero de autotanques: " << n_autotanques << std::endl;
		}
		else if(TipoPosto=="Policia"){
			std::string veiculo;
			std::cout << "Veiculo: " << veiculo << std::endl;
		}

		else if(TipoPosto=="Inem"){
			std::string Veiculo;
			std::cout << "Veiculo: " << Veiculo << std::endl;
		}

	}
}




