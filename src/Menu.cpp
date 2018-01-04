#include "Header.h"
#include "Acidente.h"
#include "Oficina.h"
#include "PostoSocorro.h"
#include "Menu.h"
#include "erros.h"

using namespace std;

//Preciso de globais

int x_glob;
int y_glob;


bool dif_maior_5_anos(Data d1, Data d2){

	if(d2.getAno() - d1.getAno() > 5){
		return true;
	}
	else if(d2.getAno() - d1.getAno() < 5){
		return false;
	}
	else if(d2.getMes() > d1.getMes()){
		return true;
	}
	else if((d2.getMes() == d1.getMes()) && (d2.getDia() > d1.getDia())){
		return true;
	}
	return false;

}


bool menorDistancia(PostoSocorro* a, PostoSocorro* b){
	return (sqrt(pow((a->getPos().first - x_glob),2) + pow((a->getPos().second - y_glob),2)) < sqrt(pow((b->getPos().first - x_glob),2) + pow((b->getPos().second - y_glob),2)));
}


bool CompareAcidentesData(Acidente* a1, Acidente* a2){
	return (a1->getData()) < (a2->getData());
}

bool CompareAcidentesAll(Acidente* a1, Acidente* a2){
	return (a1->getData() == a2->getData() && a1->getLocal() == a2->getLocal() && a1->getAllInfo() == a2->getAllInfo());
}


void Menu::ordenaVetorAcidentes(){
	std::sort(this->acidentes.begin(), acidentes.end(), CompareAcidentesData);
}

void Menu::ordenaVetorPostosSocorro(std::vector<PostoSocorro*> &v1){
	//Ordena por distancia a um acidente
	std::sort(v1.begin(), v1.end(), menorDistancia);
}


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
Menu::Menu(){
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

void Menu::inicializaOficinas(){
	vector<Oficina*> temp;
	while(!oficinas.empty()){
		temp.push_back(oficinas.top());
		oficinas.pop();
	}
	Data date (0,1,1,0,0);
	for(unsigned int i = 0; i < temp.size(); i++){
		temp.at(i)->setData(date);
	}

}

void Menu::menuOpcoesIniciais_0(){

	inicializaOficinas();
	this->clearVetoresDosPostos();
	this->atribuiAcidentes();
	string opcao;
	cout << endl;
	cout << "+------------Menu Inicial-------------+" << endl;
	cout << "|   Lista de Acoes:                   |" << endl;
	cout << "|   1 - Acoes sobre Acidentes         |" << endl;
	cout << "|   2 - Acoes sobre Postos de Socorro |" << endl;
	cout << "|   3 - Acoes sobre Condutores        |" << endl;
	cout << "|   4 - Acoes sobre Oficinas          |" << endl;
	cout << "|   5 - Acoes sobre Veiculos          |" << endl;
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
		this->menuOpcoesCondutores_1();
		//system("pause");
	}
	else if(opcao == "4")
	{
		this->menuOpcoesOficinas_1();
		//system("pause");
	}
	else if(opcao == "5")
	{
		this->menuOpcoesVeiculo_1();
		//system("pause");
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
	cout << "|   3 - Listar todos os Acidentes       |" << endl;
	cout << "|   4 - Listar os Postos Atribuidos     |" << endl;
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
	} else if (opcao == "3") {
		try {
			this->printAcidentes();
		} catch (Erro *e) {
			cout << e->getInfoErro() << endl;
		}
	} else if (opcao == "4") {
		try {
			this->printPostosComAcidenteAlocado();
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
	cout << "+---------Menu Opcoes de Postos de Socorro---------+" << endl;
	cout << "|    Lista de Acoes:                               |" << endl;
	cout << "|    1 - Adicionar um Posto                        |" << endl;
	cout << "|    2 - Remover um Posto                          |" << endl;
	cout << "|    3 - Listar todos os Postos                    |" << endl;
	cout << "|    4 - Listar Acidentes Atribuidos a um Posto    |" << endl;
	cout << "|    0 - Voltar ao menu inicial                    |" << endl;
	cout << "+--------------------------------------------------+" << endl;

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
	} else if (opcao == "3") {
		try {
			this->printPostos();
		} catch (Erro *e) {
			cout << e->getInfoErro() << endl;
		}
	} else if (opcao == "4") {
		try {
			this->printAcidentesAlocados();
		} catch (Erro *e) {
			cout << e->getInfoErro() << endl;
		}
	} else if (opcao == "0") {
		return;
	} else {
		throw new Opcao_Nao_Valida(opcao);
	}

}

void Menu::menuOpcoesCondutores_1(){

	string opcao;
	cout << endl;
	cout << "+-----------Menu Opcoes de Condutores-----------+" << endl;
	cout << "|    Lista de Acoes:                            |" << endl;
	cout << "|    1 - Adicionar um Condutor                  |" << endl;
	cout << "|    2 - Remover um Condutor                    |" << endl;
	cout << "|    3 - Remover Condutores com mais de 5 anos  |" << endl;
	cout << "|    4 - Listar todos os Condutores             |" << endl;
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
			this->criarCondutor();
		} catch (Erro *e) {
			cout << e->getInfoErro() << endl;
		}
	} else if (opcao == "2") {
		try {
			this->removerCondutor();
		} catch (Erro *e) {
			cout << e->getInfoErro() << endl;
		}
	} else if (opcao == "3") {
		try {
			this->remover_condutores_antigos();
		} catch (Erro *e) {
			cout << e->getInfoErro() << endl;
		}
	} else if (opcao == "4") {
		try {
			this->printCondutores();
		} catch (Erro *e) {
			cout << e->getInfoErro() << endl;
		}
	} else if (opcao == "0") {
		return;
	} else {
		throw new Opcao_Nao_Valida(opcao);
	}

}



void Menu::menuOpcoesOficinas_1(){

	string opcao;
	cout << endl;
	cout << "+------------Menu Opcoes de Oficinas------------+" << endl;
	cout << "|    Lista de Acoes:                            |" << endl;
	cout << "|    1 - Adicionar uma Oficina                  |" << endl;
	cout << "|    2 - Remover uma Oficina                    |" << endl;
	cout << "|    3 - Listar todas as Oficinas               |" << endl;
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
			//this->criarPosto();
		} catch (Erro *e) {
			cout << e->getInfoErro() << endl;
		}
	} else if (opcao == "2") {
		try {
			//this->removerPosto();
		} catch (Erro *e) {
			cout << e->getInfoErro() << endl;
		}
	} else if (opcao == "3") {
		try {
			//this->removerPosto();
		} catch (Erro *e) {
			cout << e->getInfoErro() << endl;
		}
	} else if (opcao == "0") {
		return;
	} else {
		throw new Opcao_Nao_Valida(opcao);
	}

}

void Menu::menuOpcoesVeiculo_1()
{
	string opcao;
	cout << endl;
	cout << "+------------Menu Opcoes de Veiculos------------+" << endl;
	cout << "|    Lista de Acoes:                            |" << endl;
	cout << "|    1 - Adicionar um Veiculo num Acidente      |" << endl;
	cout << "|    2 - Remover um Veiculo                     |" << endl;
	cout << "|    3 - Listar todos os Veiculos               |" << endl;
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
			this->criarVeiculo();
		} catch (Erro *e) {
			cout << e->getInfoErro() << endl;
		}
	} else if (opcao == "2") {
		try {
			this->removerVeiculo();
		} catch (Erro *e) {
			cout << e->getInfoErro() << endl;
		}
	} else if (opcao == "3") {
		try {
			this->printVeiculo();
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


void Menu::lerFicheiroCondutores() {

	string linha,nome,data;
	ifstream ficheiro;
	ficheiro.open("src/Condutor.txt");
	while (getline(ficheiro, linha)) {
		stringstream ss(linha);
		ss >> nome >> data;
		Condutor c;
		c.setName(nome);
		c.setData(data);
	}
	ficheiro.close();

}

void Menu::escreveFicheiroCondutores() {
	//Abrir o ficheiro e também apagar o que lá esta
	stringstream ss;
	ofstream ficheiro("src/Condutor.txt",ofstream::out|ofstream::trunc);

	//Escrever no ficheiro
	for (auto it = this->condutores.begin(); it != condutores.end(); it++) {
		ficheiro << (*it).getName() << ' ' << (*it).getData() << endl;
	}
	ficheiro.close();

	//Limpar os vetores
	this->condutores.clear();
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

void Menu::criarCondutor(){

	string nome;
	Condutor a;

	cout << "\nNome do condutor: ";

	getline(cin,nome);

	string anot, mest, diat, horat, minutot;
	u_int ano, mes, dia, hora, minuto;
	cout << "\nAno: ";
	getline(cin,anot);
	eNumero(anot);
	ano = stoi(anot);
	if(ano<=0)throw new Data_Invalida(ano,"ano");

	cout << "\nMes: ";
	getline(cin, mest);
	eNumero(mest);
	mes = stoi(mest);
	if(mes>12 || mes<=0)throw new Data_Invalida(mes,"mês");

	cout << "\nDia: ";
	getline(cin, diat);
	eNumero(diat);
	dia = stoi(diat);
	if(dia>31 || dia<=0)throw new Data_Invalida(dia,"dia");

	cout << "\nHora: ";
	getline(cin, horat);
	eNumero(horat);
	hora = stoi(horat);
	if(hora>23 || hora<=0)throw new Data_Invalida(hora,"hora");

	cout << "\nMinuto: ";
	getline(cin, minutot);
	eNumero(minutot);
	minuto = stoi(minutot);
	if(minuto>=60 || minuto<=0)throw new Data_Invalida(minuto,"minuto");

	a.setName(nome);
	a.setData(Data(ano, mes, dia, hora, minuto));
	this->adiciona_condutor(a);

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

	cout << "Indique o numero do posto a visualizar: ";
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


void Menu::printPostosComAcidenteAlocado(){

	if(this->acidentes.size()==0) throw new Nao_existem_acidentes();

	string opcao;

	this->printAcidentes();

	cout << "Indique o numero do acidente a visualizar: ";
	getline(cin, opcao);
	if (opcao == "0") {
		return;
	}
	eNumero(opcao);

	int numero=stoi(opcao);
	if(numero<0) throw new Numero_negativo(numero);

	int cnt = 1;

	cout << endl;
	for(unsigned int i = 0; i < this->postos_socorro.size(); i++){

		for(unsigned int j = 0; j < this->postos_socorro.at(i)->getAcidentesAtribuidos().size(); j++){
			if(CompareAcidentesAll(acidentes.at(numero - 1), (postos_socorro.at(i)->getAcidentesAtribuidos().at(j)))){
				cout << "=====================" << endl;
				cout << cnt << "- ";
				cout << "Tipo de posto: " << this->postos_socorro.at(i)->getTipo() << " |";
				cout << " " << this->postos_socorro.at(i)->getAllInfoFormatoPrint()<< endl;
				cnt++;
			}

		}

	}
	cout << "=====================" << endl;


	return;
}





void Menu::printAcidentes() {
	cout << endl;
	for (unsigned int i = 0; i < acidentes.size(); i++) {

		cout << "=====================" << endl;
		cout << i+1 << "- ";
		cout << "Tipo: " << acidentes.at(i)->getTipoAcidente() << " | ";
		cout << "Local: X=" << acidentes.at(i)->getLocal().first << " | ";
		cout << "Y=" << acidentes.at(i)->getLocal().second << " | ";
		cout << "Data: " << acidentes.at(i)->getData().getDataFormato() << " | ";

		cout << this->acidentes.at(i)->getAllInfoFormatoPrint() << endl;

	}
	cout << "=====================" << endl;
}

void Menu::printPostos(){
	cout << endl;
	for(unsigned int i = 0; i<postos_socorro.size(); i++){
		cout << "=====================" << endl;
		cout << i+1 << "- ";
		cout << "Tipo de posto: " << this->postos_socorro.at(i)->getTipo() << " | ";
		cout << this->postos_socorro.at(i)->getAllInfoFormatoPrint()<< endl;

	}
	cout << "=====================" << endl;
}


void Menu::clearVetoresDosPostos(){
	for(unsigned int i = 0; i < this->postos_socorro.size();i++){
		postos_socorro.at(i)->clearAcidentesATratar();
		postos_socorro.at(i)->clearAcidentesAtribuidos();
	}
}

void Menu::atualizaDisponibilidade(Data date){
	vector<Oficina*> temp;
	while(!oficinas.empty()){
		temp.push_back(oficinas.top());
		oficinas.pop();
	}
	int disp = 0;
	for(unsigned int i = 0; i < temp.size(); i++){
		disp = date - temp.at(i)->getUltimaData();
		if((temp.at(i)->getDisponibilidade() - disp) <= 0){
			temp.at(i)->setDisponibilidade(0);
		}
		else {
			temp.at(i)->setDisponibilidade((temp.at(i)->getDisponibilidade() - disp));
		}
	}

	for(unsigned int i = 0; i < temp.size(); i++){
		oficinas.push(temp.at(i));
	}
}



void Menu::atribuiAcidentes(){
	//Ordenar o vetor de acidentes por data

	//////FOR//////

	//Verificar que tipo de postos é que o acidente vai necessitar de chamar

	//Criar um vetor para cada tipo necessário

	//Ordenar cada vetor em funcao da distancia ao acidente

	//Verificar se, na data do acidente não existem já acidentes liberados do vetor "a tratar"

	//Verificar cada elemento desse vetor a ver qual é o primeiro que possui os recursos para tratar o acidente

	//Adicionar o acidente (objeto ou pointer?) ao vetor de acidentes por tratar (somando o tempo) e atribuidos

	for(unsigned int i = 0; i < this->acidentes.size(); i++){

		std::string tipo = this->acidentes.at(i)->getTipoAcidente();

		if(tipo == "Florestal"){
			//Precisa de posto de bombeiros
			std::vector<PostoSocorro*> temp_bombeiros;

			for(unsigned int j = 0; j < this->postos_socorro.size(); j++){
				if(this->postos_socorro.at(j)->getTipo() == "Bombeiros"){
					temp_bombeiros.push_back(postos_socorro.at(j));
				}
			}


			//Ordenar em relacao a distancia ao acidente
			x_glob = this->acidentes.at(i)->getLocal().first;
			y_glob = this->acidentes.at(i)->getLocal().second;
			this->ordenaVetorPostosSocorro(temp_bombeiros);


			//Obter info dos recursos necessarios pelo acidente
			std::string allInfo_A = this->acidentes.at(i)->getAllInfo();
			std::stringstream ss;
			ss << allInfo_A;
			u_int n_bombeiros_precisos, n_carros_precisos;
			ss >> n_carros_precisos >> n_bombeiros_precisos;


			//Correr o vetor de postos
			for(unsigned int k = 0; k < temp_bombeiros.size(); k++){

				std::string allInfo_Posto = temp_bombeiros.at(k)->getAllInfo();
				std::stringstream ss_disponivel;
				ss_disponivel << allInfo_Posto;

				//eliminar info desnecessária
				u_int n_bombeiros_disp, n_carros_disp;
				u_int elim;
				std::string elim_pos;

				ss_disponivel >> n_bombeiros_disp >> elim >> elim_pos >> elim >> n_carros_disp;


				if(n_bombeiros_disp >= n_bombeiros_precisos && n_carros_disp >= n_carros_precisos){
					std::vector<Acidente*> v1 = temp_bombeiros.at(k)->getAcidentesAtribuidos();
					v1.push_back(this->acidentes.at(i));
					temp_bombeiros.at(k)->setAcidentesAtribuidos(v1);
					break;
				}

			}

		}




		if(tipo == "Domestico"){
			//Precisa de posto de bombeiros (+ 1 ambulancia)

			std::vector<PostoSocorro*> temp_bombeiros;

			for(unsigned int j = 0; j < this->postos_socorro.size(); j++){
				if(this->postos_socorro.at(j)->getTipo() == "Bombeiros"){
					temp_bombeiros.push_back(postos_socorro.at(j));
				}
			}

			//Ordenar em relacao a distancia ao acidente
			x_glob = this->acidentes.at(i)->getLocal().first;
			y_glob = this->acidentes.at(i)->getLocal().second;
			this->ordenaVetorPostosSocorro(temp_bombeiros);


			//Obter info dos recursos necessarios pelo acidente
			std::string allInfo_A = this->acidentes.at(i)->getAllInfo();
			std::stringstream ss;
			ss << allInfo_A;
			u_int n_bombeiros_precisos, n_carros_precisos;
			ss >> n_carros_precisos >> n_bombeiros_precisos;


			//Correr o vetor de postos
			for(unsigned int k = 0; k < temp_bombeiros.size(); k++){

				std::string allInfo_Posto = temp_bombeiros.at(k)->getAllInfo();
				std::stringstream ss_disponivel;
				ss_disponivel << allInfo_Posto;

				//eliminar info desnecessária
				u_int n_bombeiros_disp, n_tanques_disp, n_ambul_disp;
				u_int elim;
				std::string elim_pos;

				ss_disponivel >> n_bombeiros_disp >> elim >> elim_pos >> n_ambul_disp >> n_tanques_disp;


				if(n_bombeiros_disp >= n_bombeiros_precisos && n_tanques_disp + 1 >= n_carros_precisos && n_ambul_disp >= 1){
					std::vector<Acidente*> v1 = temp_bombeiros.at(k)->getAcidentesAtribuidos();
					v1.push_back(this->acidentes.at(i));
					temp_bombeiros.at(k)->setAcidentesAtribuidos(v1);
					break;
				}

			}

		}



		if(tipo == "Assalto"){
			//Precisa de policia (qualquer tipo) e se houver feridos, um veiculo INEM qualquer

			std::vector<PostoSocorro*> temp_policia;
			std::vector<PostoSocorro*> temp_inem;


			//Obter info dos recursos necessarios pelo acidente
			std::string s_aci = this->acidentes.at(i)->getAllInfo();
			std::stringstream ss;
			ss << s_aci;
			bool existeFeridos;
			std::string tipo_casa;
			ss >> existeFeridos >> tipo_casa;

			// POLICIA

			for(unsigned int j = 0; j < this->postos_socorro.size(); j++){
				if(this->postos_socorro.at(j)->getTipo() == "Policia"){
					temp_policia.push_back(postos_socorro.at(j));
				}
			}

			//Ordenar em relacao a distancia ao acidente
			x_glob = this->acidentes.at(i)->getLocal().first;
			y_glob = this->acidentes.at(i)->getLocal().second;
			this->ordenaVetorPostosSocorro(temp_policia);


			//Correr o vetor de postos
			for(unsigned int k = 0; k < temp_policia.size(); k++){

				std::string allInfo_Posto = temp_policia.at(k)->getAllInfo();
				std::stringstream ss_disponivel;
				ss_disponivel << allInfo_Posto;

				//eliminar info desnecessária
				u_int n_policias_disp, n_veiculos_disp;
				//u_int elim;
				std::string elim_pos, tipo_veiculo;

				ss_disponivel >> n_policias_disp >> n_veiculos_disp >> elim_pos >> tipo_veiculo;


				if((n_policias_disp > 0 && n_veiculos_disp > 0 && tipo_veiculo == "Moto") || (n_policias_disp > 1 && n_veiculos_disp > 0 && tipo_veiculo == "Carro")){
					std::vector<Acidente*> v1 = temp_policia.at(k)->getAcidentesAtribuidos();
					v1.push_back(this->acidentes.at(i));
					temp_policia.at(k)->setAcidentesAtribuidos(v1);
					break;
				}

			}


			// INEM

			if (existeFeridos == true) {

				for (unsigned int j = 0; j < this->postos_socorro.size(); j++) {
					if (this->postos_socorro.at(j)->getTipo() == "Inem") {
						temp_inem.push_back(postos_socorro.at(j));
					}
				}

				//Ordenar em relacao a distancia ao acidente
				this->ordenaVetorPostosSocorro(temp_inem);

				//Correr o vetor de postos
				for (unsigned int k = 0; k < temp_inem.size(); k++) {

					std::string allInfo_Posto = temp_inem.at(k)->getAllInfo();
					std::stringstream ss_disponivel;
					ss_disponivel << allInfo_Posto;

					//eliminar info desnecessária
					u_int n_socorristas_disp, n_veiculos_disp;
					//u_int elim;
					std::string elim_pos, tipo_veiculo;

					ss_disponivel >> n_socorristas_disp >> n_veiculos_disp
							>> elim_pos >> tipo_veiculo;

					if ((n_socorristas_disp > 0 && n_veiculos_disp > 0 && tipo_veiculo == "Moto") || (n_socorristas_disp > 1 && n_veiculos_disp > 0 && (tipo_veiculo == "Carro" || tipo_veiculo == "Ambulancia"))) {
						std::vector<Acidente*> v1 = temp_inem.at(k)->getAcidentesAtribuidos();
						v1.push_back(this->acidentes.at(i));
						temp_inem.at(k)->setAcidentesAtribuidos(v1);
						break;
					}

				}

			}




		}
		if(tipo == "AcidenteViacao"){
			//Se só houver 1 ferido grave, mota INEM
			//Se houver 2 a 4, 1 a 2 carros INEM
			//Se houver 5 ou mais, (NºFeridos graves/2) = NºAmbulancias
			//Policia, Carro se for estrada nacional, (nºveiculos envolvidos/2)
			//Policia, Mota se for auto estrada, (nºveiculos envolvidos/2)

			std::vector<PostoSocorro*> temp_policia;
			std::vector<PostoSocorro*> temp_inem;


			//Obter info dos recursos necessarios pelo acidente
			std::string s_aci = this->acidentes.at(i)->getAllInfo();
			std::stringstream ss;
			ss << s_aci;
			u_int n_feridos_g, n_veiculos_env;
			std::string tipo_estrada, marcas; // e marcas dos veiculos
			ss >> n_feridos_g >> n_veiculos_env >> tipo_estrada;
			vector<std::string> MarcasVeiculos; //tipo de veiculos
				while (ss >> marcas) {
					MarcasVeiculos.push_back(marcas);
				}

			// INEM


			if (n_feridos_g > 0) {

				for (unsigned int j = 0; j < this->postos_socorro.size(); j++) {
					if (this->postos_socorro.at(j)->getTipo() == "Inem") {
						temp_inem.push_back(postos_socorro.at(j));
					}
				}

				//Ordenar em relacao a distancia ao acidente
				this->ordenaVetorPostosSocorro(temp_inem);

				//Correr o vetor de postos
				for (unsigned int k = 0; k < temp_inem.size(); k++) {

					std::string allInfo_Posto = temp_inem.at(k)->getAllInfo();
					std::stringstream ss_disponivel;
					ss_disponivel << allInfo_Posto;

					//eliminar info desnecessária
					u_int n_socorristas_disp, n_veiculos_disp;
					//u_int elim;
					std::string elim_pos, tipo_veiculo;

					ss_disponivel >> n_socorristas_disp >> n_veiculos_disp
							>> elim_pos >> tipo_veiculo;

					if ((n_feridos_g == 1 && tipo_veiculo == "Moto" && n_veiculos_disp > 0) || (n_feridos_g >= 2 && n_feridos_g <= 4 && tipo_veiculo == "Carro" && n_veiculos_disp >= ceil(n_feridos_g / 2)) || (n_feridos_g >= 5 && tipo_veiculo == "Ambulancia" && n_veiculos_disp >= ceil(n_feridos_g / 2))) {
						std::vector<Acidente*> v1 = temp_inem.at(k)->getAcidentesAtribuidos();
						v1.push_back(this->acidentes.at(i));
						temp_inem.at(k)->setAcidentesAtribuidos(v1);
						break;
					}

				}

			}


			// POLICIA

			for(unsigned int j = 0; j < this->postos_socorro.size(); j++){
				if(this->postos_socorro.at(j)->getTipo() == "Policia"){
					temp_policia.push_back(postos_socorro.at(j));
				}
			}

			//Ordenar em relacao a distancia ao acidente
			x_glob = this->acidentes.at(i)->getLocal().first;
			y_glob = this->acidentes.at(i)->getLocal().second;
			this->ordenaVetorPostosSocorro(temp_policia);


			//Correr o vetor de postos
			for(unsigned int k = 0; k < temp_policia.size(); k++){

				std::string allInfo_Posto = temp_policia.at(k)->getAllInfo();
				std::stringstream ss_disponivel;
				ss_disponivel << allInfo_Posto;

				//eliminar info desnecessária
				u_int n_policias_disp, n_veiculos_disp;
				//u_int elim;
				std::string elim_pos, tipo_veiculo;

				ss_disponivel >> n_policias_disp >> n_veiculos_disp >> elim_pos >> tipo_veiculo;


				if((tipo_estrada == "Nacional" && n_policias_disp >= (n_veiculos_env/2) && n_veiculos_disp >= (n_veiculos_env/4) && tipo_veiculo == "Carro") || (tipo_estrada == "Auto-Estrada" && n_policias_disp >= (n_veiculos_env/2) && n_veiculos_disp >= (n_veiculos_env/2) && tipo_veiculo == "Moto")){
					std::vector<Acidente*> v1 = temp_policia.at(k)->getAcidentesAtribuidos();
					v1.push_back(this->acidentes.at(i));
					temp_policia.at(k)->setAcidentesAtribuidos(v1);
					break;
				}

			}

			//depois de atribuir acidentes

			/*

			////Arranjar os carros/////


			Prior_queu temp = oficinas;
			atualizaDisponibilidade(acidentes.at(i)->getData());
			for(unsigned int m = 0; m < MarcasVeiculos.size(); m++){ //para cada marca
				while(!oficinas.empty()){
					for(unsigned int n = 0; n < oficinas.top()->getMarcas().size(); n++){ // para cada marca da oficina
						if(oficinas.top()->getMarcas().at(n) == MarcasVeiculos.at(m)){
							Oficina *oftemp = new Oficina();
							oftemp = oficinas.top();
							oficinas.pop();
							oftemp->setDisponibilidade(oftemp->getDisponibilidade() + 1);
							oftemp->setData(acidentes.at(i)->getData()); //atualiza a utima data
							temp.push(oftemp);//coloca no temporario
							break; //ja encontrou
						}

					}

					oficinas.pop();
				}
			}
			oficinas = temp;
			////acaba

			*/

		}


	}


}


void Menu::adicionaOficina(Oficina *oficina){
	oficinas.push(oficina);
}


void Menu::lerFicheiroOficina() {
	string linha;
	ifstream ficheiro;
	ficheiro.open("src/Oficina.txt");
	while (getline(ficheiro, linha)) {
		stringstream ss(linha);
		Oficina* temp = new Oficina();
		temp->lerInfo(ss);
		this->adicionaOficina(temp);
	}
	ficheiro.close();
}

void Menu::EscreveFicheiroOficina() {
	stringstream ss;
	ofstream ficheiro("src/Oficina.txt",ofstream::out|ofstream::trunc);

	//Escrever no ficheiro
	Prior_queu temp = oficinas;
	while(!temp.empty()){
		ficheiro << temp.top()->getNome() << " ";
		for(unsigned int i = 0; i < temp.top()->getMarcas().size(); i++){
			if(i == (temp.top()->getMarcas().size() - 1)){
				ficheiro << temp.top()->getMarcas().at(i); // se for o ultimo
			}
			else
				ficheiro << temp.top()->getMarcas().at(i) << " ";
		}
	}
	ficheiro.close();

	//Limpar o priority queue
	while(!this->oficinas.empty()){
		this->oficinas.pop();
	}
}


void Menu::criarOficina(){
	cout << "Indique o nome da Oficina: ";
	string nome;
	cin >> nome;
	Oficina *a = new Oficina;
	a->setNome(nome); //atribui um nome
	cout << "Indique as marcas de automóveis que a oficina pode reparar: ";
	int i = 0; // para escolher
	vector<string> marcas;//para guardar as marcas do utilizador
	do{
	cout << endl;
	cout << "+----------------------------------------+" << endl;
	cout << "|   Indique a marca do carro:            |" << endl;
	cout << "|   1 - Audi                             |" << endl;
	cout << "|   2 - BMW                              |" << endl;
	cout << "|   3 - Mercedes                         |" << endl;
	cout << "|   4 - Volkswagen                       |" << endl;
	cout << "|   5 - Ferrari                          |" << endl;
	cout << "|   6 - Porsche                          |" << endl;
	cout << "|   0 - Concluir                         |" << endl;
	cout << "+----------------------------------------+" << endl;
	cin >> i;
	switch(i){
		case(1): {
			marcas.push_back("Audi");
			break;
		}
		case(2):{
			marcas.push_back("BMW");
			break;
		}
		case(3):{
			marcas.push_back("Mercedes");
			break;
		}
		case(4):{
			marcas.push_back("Volkswagen");
			break;
		}
		case(5):{
			marcas.push_back("Ferrari");
			break;
		}
		case(6):{
			marcas.push_back("Porsche");
			break;
		}
	}
	system("cls");
	}
	while(i!=0);
	a->setDisponibilidade(0);
	a->setMarcas(marcas);
}


void Menu::verOficina(){ //para ver a disponibilidade de uma oficina e os carros que repara
	string name;
	cout << "Introduza o nome da Oficina" << endl << endl;
	cin >> name;
	Prior_queu temp = oficinas;
	while(!oficinas.empty()){
		if(oficinas.top()->getNome()==name){
			cout<<"Disponibilidade: "<<oficinas.top()->getDisponibilidade()<<endl;
			cout<<"Marcas que repara: "<<endl;
			for(unsigned int i = 0; i < oficinas.top()->getMarcas().size(); i++){
				cout << oficinas.top()->getMarcas().at(i) << endl;
			}
			break;
		}
		else{
			oficinas.pop();
		}
	}
}


void Menu::verOficinaMarcas(){
	string marca;
	cout << "Introduza a marca do automóvel" << endl << endl;
	cin >> marca;
	bool existe = false;
	Prior_queu temp = oficinas;
	cout<<"Oficinas que reparam: "<<marca<<endl;
	while(!oficinas.empty()){
			for(unsigned int i = 0; i < oficinas.top()->getMarcas().size(); i++){
				if(oficinas.top()->getMarcas().at(i)==marca){
					cout<<oficinas.top()->getNome()<<endl;
					existe = true;
					break;
			}
		}
			oficinas.pop();
	}
	if(!existe){
		cout<<"Nao existem oficinas que reparam: "<<marca<<endl;
	}
}




//unordered_set

void Menu::adiciona_condutor(Condutor c1){
	auto it = this->condutores.find(c1);

	if(it == condutores.end()){
		//não existe ainda ninguém com esse nome
		condutores.insert(c1);
		return;
	}
	else{
		//já existe alguém com esse nome
		if((*it).getData() < c1.getData()){
			condutores.erase(it);
			condutores.insert(c1);
		}
	}

	return;
}





void Menu::remover_condutores_antigos(){

	if(this->condutores.size()==0) throw new Nao_existem_acidentes(); //mudar a excecao, preciso de uma para condutores

	Data d1;
	string anot, mest, diat, horat, minutot;
	u_int ano, mes, dia, hora, minuto;
	cout << "\nAno: ";
	getline(cin,anot);
	eNumero(anot);
	ano = stoi(anot);
	if(ano<=0)throw new Data_Invalida(ano,"ano");

	cout << "\nMes: ";
	getline(cin, mest);
	eNumero(mest);
	mes = stoi(mest);
	if(mes>12 || mes<=0)throw new Data_Invalida(mes,"mês");

	cout << "\nDia: ";
	getline(cin, diat);
	eNumero(diat);
	dia = stoi(diat);
	if(dia>31 || dia<=0)throw new Data_Invalida(dia,"dia");

	cout << "\nHora: ";
	getline(cin, horat);
	eNumero(horat);
	hora = stoi(horat);
	if(hora>23 || hora<=0)throw new Data_Invalida(hora,"hora");

	cout << "\nMinuto: ";
	getline(cin, minutot);
	eNumero(minutot);
	minuto = stoi(minutot);
	if(minuto>=60 || minuto<=0)throw new Data_Invalida(minuto,"minuto");

	d1 = Data(ano, mes, dia, hora, minuto);

	auto it_aux = condutores.begin();

	while(dif_maior_5_anos(((*it_aux).getData()),d1)){
		condutores.erase(it_aux);
		it_aux = condutores.begin();

		if(it_aux == condutores.end()){
			return;
		}
	}

	for(auto it = condutores.begin(); it != condutores.end();){
		it++;
		if(dif_maior_5_anos(((*it).getData()),d1)){
			condutores.erase(it);
			it = it_aux;
		}
		it_aux = it;
	}

}


void Menu::printCondutores() {
	cout << endl;
	unsigned int i = 1;

	if(condutores.size() == 0){
		cout << "Nao existem condutores registados!\n\n";
		return;
	}

	for (auto it = this->condutores.begin(); it != condutores.end(); it++) {

		cout << "=====================" << endl;
		cout << i << "- ";
		cout << "Nome: " << (*it).getName() << " | ";
		cout << "Ultima ocorrencia: " << (*it).getData().getDataFormato();

	}
	cout << "=====================" << endl;
}

void Menu::retirarCondutor(int posicao){
	if(posicao> this->condutores.size())throw new Acidente_Nao_Existente(posicao); //preciso de mais uma exceção
	u_int ondeEstou=0;
	for(auto it=this->condutores.begin();it!=this->condutores.end();it++)
	{
		if(ondeEstou==posicao-1)
		{
			this->condutores.erase(it);
			return;
		}
		ondeEstou++;
	}
	throw new Acidente_Nao_Existente(posicao); //preciso de mais exceções

}


void Menu::removerCondutor(){

	if(this->condutores.size()==0) throw new Nao_existem_acidentes(); //preciso de mais exceções!

	string opcao;

	this->printCondutores();

	cout << "Indique o numero do condutor a remover: ";
	getline(cin, opcao);
	if (opcao == "0") {
		return;
	}
	eNumero(opcao);

	int numero=stoi(opcao);
	if(numero<0) throw new Numero_negativo(numero);
	this->retirarCondutor(numero);



	return;

}



//BST
void Menu::adicionaVeiculo(Veiculo *por)
{
	this->veiculos.insert(*por);
}
void Menu::criarVeiculo()
{
	string marca;
	cout << "Marca do veiculo:";
	getline(cin,marca);

	string anot, mest, diat, horat, minutot;
	u_int ano, mes, dia, hora, minuto;
	cout << "\nAno: ";
	getline(cin,anot);
	eNumero(anot);
	ano = stoi(anot);
	if(ano<=0)throw new Data_Invalida(ano,"ano");

	cout << "\nMes: ";
	getline(cin, mest);
	eNumero(mest);
	mes = stoi(mest);
	if(mes>12 || mes<=0)throw new Data_Invalida(mes,"mês");

	cout << "\nDia: ";
	getline(cin, diat);
	eNumero(diat);
	dia = stoi(diat);
	if(dia>31 || dia<=0)throw new Data_Invalida(dia,"dia");

	cout << "\nHora: ";
	getline(cin, horat);
	eNumero(horat);
	hora = stoi(horat);
	if(hora>23 || hora<=0)throw new Data_Invalida(hora,"hora");

	cout << "\nMinuto: ";
	getline(cin, minutot);
	eNumero(minutot);
	minuto = stoi(minutot);
	if(minuto>=60 || minuto<=0)throw new Data_Invalida(minuto,"minuto");

	for(set<Veiculo>::iterator it=this->veiculos.begin();it!=this->veiculos.end();it++)
	{
		Veiculo temp=(*it);
		if((*it).getMarca()==marca)
		{
			Veiculo testar(marca,temp.getQuantidade()+1,Data(ano, mes, dia, hora, minuto));
			this->veiculos.erase(it);
			this->veiculos.insert(testar);
			return;
		}
	}
	Veiculo testar(marca,1,Data(ano, mes, dia, hora, minuto));
	this->veiculos.insert(testar);
}

void Menu::removerVeiculo()
{
	string testar,marca;
	unsigned int numero;
	cout << "Qual a marca para apagar: ";
	getline(cin,marca);
	cout << "\nQual o ano até que pretende apagar: ";
	getline(cin, testar);
	eNumero (testar);
	numero = stoi(testar);
	for(set<Veiculo>::iterator it=this->veiculos.begin();it!=this->veiculos.end();it++)
	{
		if((*it).getData().getAno()<=numero && (*it).getMarca()==marca)
		{
			this->veiculos.erase(it);
			return;
		}
	}
}

void Menu::printVeiculo()
{
	for(set<Veiculo>::iterator it=this->veiculos.begin();it!=this->veiculos.end();it++)
	{
		cout << "Marca: " << (*it).getMarca() << " | " << "Quantidades de acidentes: " << (*it).getQuantidade() << " | " << "Data: " << (*it).getData().getDataFormato() << endl;
	}
}

void Menu::lerFicheiroVeiculo()
{
	string linha;
	ifstream ficheiro;
	ficheiro.open("src/Veiculo.txt");
	while (getline(ficheiro, linha)) {
		stringstream ss(linha);
		Veiculo* temp = new Veiculo();
		temp->lerInfo(ss);
		this->adicionaVeiculo(temp);
	}
	ficheiro.close();
}

void Menu::EscreveFicheiroVeiculo()
{
	stringstream ss;
	ofstream ficheiro("src/Veiculo.txt", ofstream::out | ofstream::trunc);

	//Escrever no ficheiro
	for(set<Veiculo>::iterator it=this->veiculos.begin();it!=this->veiculos.end();it++) {
		ficheiro << (*it).getMarca() << " " << (*it).getQuantidade() << " " << (*it).getData().getDataString() << endl;
	}
	ficheiro.close();
	this->veiculos.clear();
}
