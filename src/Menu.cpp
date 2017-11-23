#include "Header.h"
#include "Acidente.h"
#include "PostoSocorro.h"
#include "Menu.h"
#include "erros.h"

using namespace std;
void eNumero(std::string testar) {
	std::string::iterator it = testar.begin();
	while (it != testar.end() && std::isdigit(*it))
		it++;
	if (!(!testar.empty() && it == testar.end()))
		throw new Nao_e_numero(testar);
	if(testar.size()>10)
	{
		throw new Numero_Demasiado_Grande(testar);
	}
	else if(testar.size()==10 && "2147483647"<testar)
	{
		throw new Numero_Demasiado_Grande(testar);
	}
}
// Incendios Florestais



u_int nCarrosBombeirosArea(u_int a){
	return ((a/100) + 1);
}

u_int nBombeirosArea(u_int a){
	return (a/10) + 1;
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

vector<Acidente*> Menu::getAcidentes(){
	return this->acidentes;
}
vector<PostoSocorro*> Menu::getPostosSocorro(){
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
	if(ifstream("Acidente.txt"))return true;
	else return false;
}



// Metodos para adicionar acidentes/postos socorro ao vetor

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

void Menu::retirarAcidente(u_int posicao)
{
	if(posicao> this->acidentes.size())throw new Acidente_Nao_Existente(posicao);
	u_int ondeEstou=0;
	for(vector<Acidente*>::iterator it=this->acidentes.begin();it!=this->acidentes.end();it++)
	{
		if(ondeEstou==posicao-1)
		{
			this->acidentes.erase(it);
			return;
		}
		ondeEstou++;
	}
	throw new Acidente_Nao_Existente(posicao);
}
void Menu::retirarPosto(u_int posicao)
{
	if(posicao> this->postos_socorro.size())throw new Acidente_Nao_Existente(posicao);
	u_int ondeEstou=0;
	for(vector<PostoSocorro*>::iterator it=this->postos_socorro.begin();it!=this->postos_socorro.end();it++)
	{
		if(ondeEstou==posicao-1)
		{
			this->postos_socorro.erase(it);
			return;
		}
		ondeEstou++;
	}
	throw new Posto_Nao_Existente(posicao);
}

//-----------------------------------------------------------------
//----------------------------MENUS--------------------------------
//-----------------------------------------------------------------


void Menu::menuOpcoesIniciais_0(){

	string opcao;
	cout << endl;
	cout << "+------------Menu Inicial-------------+" << endl;
	cout << "|   Lista de Acoes:                   |" << endl;
	cout << "|   1 - Acoes sobre Acidentes         |" << endl;
	cout << "|   2 - Acoes sobre Postos de Socorro |" << endl;
	cout << "|   3 - Listar Acidentes Atribuidos   |" << endl;
	cout << "|   4 - Listar Acidentes              |" << endl;
	cout << "|   5 - Listar Postos de Socorro      |" << endl;
	cout << "|   0 - Sair                          |" << endl;
	cout << "+-------------------------------------+" << endl;

	cout << endl << "Indique o digito correspondente a opcao desejada: ";

	getline(cin,opcao);

	if(opcao.size()!=1)
	{
		throw new Tamanho_Input_Invalido(opcao.size());
	}

	if (opcao == "1")
	{
		this->menuOpcoesAcidente_1();
	}
	else if(opcao=="2")
	{
		this->menuOpcoesPostosSocorro_1();
	}
	else if(opcao == "3")
	{
		this->printAcidentesAlocados();
	}
	else if(opcao == "4")
	{
		this->printAcidentes();
	}
	else if(opcao == "5")
	{
		this->printPostos();
	}
	else if (opcao == "0")
	{
		this->terminar=true;
	}
	else
	{
		throw new Opcao_Nao_Valida(opcao);
	}
	this->ordenaVetorAcidentes();

}


void Menu::menuOpcoesAcidente_1() {

	string opcao;
	cout << endl;
	cout << "+--------Menu Opcoes de Acidentes-------+" << endl;
	cout << "|   Lista de Acoes:                     |" << endl;
	cout << "|   1 - Reportar um Acidente            |" << endl;
	cout << "|   2 - Remover um Acidente             |" << endl;
	cout << "|   0 - Voltar ao menu inicial          |" << endl;
	cout << "+---------------------------------------+" << endl;

	cout << "Indique o digito correspondente a opcao desejada: ";

	getline(cin,opcao);

	if (opcao.size() != 1)
	{
		throw new Tamanho_Input_Invalido(opcao.size());
	}
	if (opcao == "1") {
		try {
			this->criarAcidente();
		} catch (Erro *e) {
			cout << e->getInfoErro() << endl;
		}
	} else if (opcao == "2") {
		try {
			this->removerAcidente();
		} catch (Erro *e) {
			cout << e->getInfoErro() << endl;
		}
	} else if (opcao == "0") {
		return;
	} else {
		throw new Opcao_Nao_Valida(opcao);
	}

}


void Menu::menuOpcoesPostosSocorro_1(){

	string opcao;
	cout << endl;
	cout << "+---------Menu Opcoes de Postos de Socorro------+" << endl;
	cout << "|    Lista de Acoes:                            |" << endl;
	cout << "|    1 - Adicionar um Posto                     |" << endl;
	cout << "|    2 - Remover um Posto                       |" << endl;
	cout << "|    0 - Voltar ao menu inicial                 |" << endl;
	cout << "+-----------------------------------------------+" << endl;

	cout << "Indique o digito correspondente a opcao desejada: ";

	getline(cin,opcao);

	if (opcao.size() != 1)
	{
		throw new Tamanho_Input_Invalido(opcao.size());
	}
	if (opcao == "1") {
		try {
			this->criarPosto();
		} catch (Erro *e) {
			cout << e->getInfoErro() << endl;
		}
	} else if (opcao == "2") {
		try {
			this->removerPosto();
		} catch (Erro *e) {
			cout << e->getInfoErro() << endl;
		}
	} else if (opcao == "0") {
		return;
	} else {
		throw new Opcao_Nao_Valida(opcao);
	}

}


/////////////////////////////////
// OPERACOES COM FICHEIROS
/////////////////////////////////

void Menu::lerFicheiroAcidente() {

	string linha,tipo;
	ifstream ficheiro;
	ficheiro.open("src/Acidente.txt");
	while (getline(ficheiro, linha)) {

		stringstream ss(linha);
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
	//Abrir o ficheiro e também apagar o que lá esta
	stringstream ss;
	ofstream ficheiro("src/Acidente.txt",ofstream::out|ofstream::trunc);

	//Escrever no ficheiro
	for (size_t i = 0; i < this->acidentes.size(); i++) {
		ficheiro << this->acidentes.at(i)->getTipoAcidente() << ' '
				<< this->acidentes.at(i)->getData().getDataString() << ' '
				<< this->acidentes.at(i)->getLocal().first << ' '
				<< this->acidentes.at(i)->getLocal().second << ' '
				<< this->acidentes.at(i)->getAllInfo() << endl;
	}
	ficheiro.close();

	//Limpar os vetores
	this->acidentes.clear();
}

void Menu::lerFicheiroPostoSocorro() {

	string linha,tipo;
	ifstream ficheiro("src/PostoSocorro.txt");

	while (getline(ficheiro, linha)) {

		stringstream ss(linha);
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
	//Abrir o ficheiro e também apagar o que lá esta
	stringstream ss;
	ofstream ficheiro("src/PostoSocorro.txt",ofstream::out | ofstream::trunc);


	for (size_t i = 0; i < this->postos_socorro.size(); i++) {
		ficheiro << this->postos_socorro.at(i)->getTipo() << ' '
				<< this->postos_socorro.at(i)->getAllInfo() << endl;
	}
	ficheiro.close();

	//Limpar os vetores
	this->postos_socorro.clear();
}


/////////////////////////////////////
// FUNCOES MENU ACIDENTE
/////////////////////////////////////

void Menu::criarAcidente(){
	string opcao;
	cout << endl;
	cout << "+----------------------------------------+" << endl;
	cout << "|   Indique o tipo de acidente:          |" << endl;
	cout << "|   1 - Incendio Florestal               |" << endl;
	cout << "|   2 - Incendio Domestico               |" << endl;
	cout << "|   3 - Assalto                          |" << endl;
	cout << "|   4 - Acidente de Viacao               |" << endl;
	cout << "|   0 - Voltar ao Menu Inicial           |" << endl;
	cout << "+----------------------------------------+" << endl;

	cout << "Indique o tipo de acidente: ";
	getline(cin,opcao);

	if (opcao.size() != 1) {
		throw new Tamanho_Input_Invalido(opcao.size());
	}

	Acidente *a;

	if (opcao == "1") {
		try {
			a = new Florestal;
			a->infoUtilizadorGeral();
			a->infoUtilizador();
			this->adicionaAcidente(a);
		} catch (Erro *e) {
			cout << e->getInfoErro() << endl;
		}
	}

	else if (opcao == "2") {
		try {
			a = new Domesticos;
			a->infoUtilizadorGeral();
			a->infoUtilizador();
			this->adicionaAcidente(a);
		} catch (Erro *e) {
			cout << e->getInfoErro() << endl;
		}
	}
	else if (opcao == "3") {
		try {
			a = new Assalto;
			a->infoUtilizadorGeral();
			a->infoUtilizador();
			this->adicionaAcidente(a);
		} catch (Erro *e) {
			cout << e->getInfoErro() << endl;
		}
	}
	else if (opcao == "4") {
		try {
			a = new AcidenteViacao;
			a->infoUtilizadorGeral();
			a->infoUtilizador();
			this->adicionaAcidente(a);
		} catch (Erro *e) {
			cout << e->getInfoErro() << endl;
		}
	}
	else if (opcao == "0") {
		return;
	}
	else throw Opcao_Nao_Valida(opcao);



}

void Menu::criarPosto(){
	string opcao;
	cout << endl;
	cout << "+----------------------------------------+" << endl;
	cout << "|   Indique o tipo de posto:             |" << endl;
	cout << "|   1 - Bombeiros                        |" << endl;
	cout << "|   2 - Policia                          |" << endl;
	cout << "|   3 - INEM                             |" << endl;
	cout << "|   0 - Voltar ao Menu Inicial           |" << endl;
	cout << "+----------------------------------------+" << endl;

	cout << "Indique o tipo de acidente: ";
	getline(cin,opcao);

	if (opcao.size() != 1) {
		throw new Tamanho_Input_Invalido(opcao.size());
	}

	PostoSocorro *a;

	if (opcao == "1") {
		try {
			a = new Bombeiros;
			a->infoUtilizadorGeral();
			a->infoUtilizador();
			this->adicionaPostosSocorro(a);
		} catch (Erro *e) {
			cout << e->getInfoErro() << endl;
		}
	}

	else if (opcao == "2") {
		try {
			a = new Policia;
			a->infoUtilizadorGeral();
			a->infoUtilizador();
			this->adicionaPostosSocorro(a);
		} catch (Erro *e) {
			cout << e->getInfoErro() << endl;
		}
	} else if (opcao == "3") {
		try {
			a = new Inem;
			a->infoUtilizadorGeral();
			a->infoUtilizador();
			this->adicionaPostosSocorro(a);
		} catch (Erro *e) {
			cout << e->getInfoErro() << endl;
		}
	} else if (opcao == "0") {
		return;
	} else
		throw new Opcao_Nao_Valida(opcao);


}

void Menu::removerAcidente(){

	if(this->acidentes.size()==0) throw new Nao_existem_acidentes();

	string opcao;

	this->printAcidentes();

	cout << "Indique o numero do acidente a remover: ";
	getline(cin, opcao);
	if (opcao == "0") {
		return;
	}
	eNumero(opcao);

	int numero=stoi(opcao);
	if(numero<0) throw new Numero_negativo(numero);
	this->retirarAcidente(numero);



	return;

}
void Menu::removerPosto(){

	if(this->postos_socorro.size()==0) throw new Nao_existem_postos();

	string opcao;

	this->printPostos();

	cout << "Indique o numero do posto a remover: ";
	getline(cin, opcao);
	if (opcao == "0") {
		return;
	}
	eNumero(opcao);

	int numero=stoi(opcao);
	if(numero<0) throw new Numero_negativo(numero);
	this->retirarPosto(numero);

	return;

}

void Menu::printAcidentesAlocados(){

	if(this->postos_socorro.size()==0) throw new Nao_existem_postos();

	string opcao;

	this->printPostos();

	cout << "Indique o tipo de posto a remover: ";
	getline(cin, opcao);
	if (opcao == "0") {
		return;
	}
	eNumero(opcao);

	int numero=stoi(opcao);
	if(numero<0) throw new Numero_negativo(numero);
	this->postos_socorro.at(numero - 1)->printAcidentesAtribuidos();

	return;


}





void Menu::printAcidentes() {

	for (unsigned int i = 0; i < acidentes.size(); i++) {

		cout << "=====================" << endl;
		cout << i+1 << "- ";
		cout << "Tipo: " << acidentes.at(i)->getTipoAcidente() << " | ";
		cout << "Local: x=" << acidentes.at(i)->getLocal().first << " | ";
		cout << " y= " << acidentes.at(i)->getLocal().second << " | ";
		cout << " Data: " << acidentes.at(i)->getData().getDataFormato() << " | ";

		cout << this->acidentes.at(i)->getAllInfoFormatoPrint() << endl;


	}
}

void Menu::printPostos(){
	for(unsigned int i = 0; i<postos_socorro.size(); i++){
		cout << "=====================" << endl;
		cout << i+1 << "- ";
		cout << "Tipo de posto: " << this->postos_socorro.at(i)->getTipo() << " |";
		cout << " " << this->postos_socorro.at(i)->getAllInfoFormatoPrint()<< endl;

	}
}




