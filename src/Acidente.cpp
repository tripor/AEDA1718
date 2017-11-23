#include "Acidente.h"
#include "erros.h"
#include "Menu.h"
using namespace std;


//////////////////////////////////////
// CLASS ACIDENTE
//////////////////////////////////////


	//Metodos Get

Data Acidente::getData() const{
	return this->data;
}

pair<int,int> Acidente::getLocal() const{
	return this->local;
}

	//Metodos Set

void Acidente::setData(Data d){
	this->data = d;
}
void Acidente::setData(string d)
{
	u_int ano,mes,dia,hora,minuto;
	char hifen;
	stringstream retirar;
	retirar << d;
	retirar >> ano >> hifen >> mes >> hifen >> dia >> hifen >> hora >> hifen >> minuto ;
	Data devolver(ano,mes,dia,hora,minuto);
	this->data=devolver;
}
void Acidente::setLocal(pair<int,int> par){
	this->local = par;
}


// Outros metodos

bool Acidente::acidenteIgual(Acidente* a1) const{
	if(a1->getTipoAcidente() != this->getTipoAcidente()){
			return false;
	}

	if(!(a1->getData() == this->getData()) || a1->getLocal() != this->getLocal()){
		return false;
	}

	if(a1->getAllInfo() != this->getAllInfo()){
		return false;
	}

	return true;

}


void Acidente::infoUtilizadorGeral(){

	string anot, mest, diat, horat, minutot;
	u_int ano, mes, dia, hora, minuto;
	cout << "\nAno: ";
	getline(cin,anot);
	eNumero(anot);
	ano = stoi(anot);

	cout << "\nMes: ";
	getline(cin, mest);
	eNumero(mest);
	mes = stoi(mest);

	cout << "\nDia: ";
	getline(cin, diat);
	eNumero(diat);
	dia = stoi(diat);

	cout << "\nHora: ";
	getline(cin, horat);
	eNumero(horat);
	hora = stoi(horat);

	cout << "\nMinuto: ";
	getline(cin, minutot);
	eNumero(minutot);
	minuto = stoi(minutot);

	this->setData(Data(ano, mes, dia, hora, minuto));

	string  x_coordt, y_coordt;
	int x_coord, y_coord;

	cout << "\nCoordenada X do acidente: ";
	getline(cin, x_coordt);
	eNumero(x_coordt);
	x_coord = stoi(x_coordt);

	cout << "\nCoordenada Y do acidente: ";
	getline(cin, y_coordt);
	eNumero(y_coordt);
	y_coord = stoi(y_coordt);

	pair<int,int> p = make_pair(x_coord,y_coord);

	this->setLocal(p);
}


//////////////////////////////////////
// CLASS INCENDIOS
//////////////////////////////////////

	//Construtores

	//Metodos Get

u_int Incendios::getNumeroCarrosBombeiros() const{
	return this->numero_CarrosBombeiros;
}

u_int Incendios::getNumeroBombeiros() const{
	return this->numero_Bombeiros;
}

	//Metodos Set

void Incendios::setNumeroCarrosBombeiros(u_int n){
	this->numero_CarrosBombeiros = n;
}

void Incendios::setNumeroBombeiros(u_int n){
	this->numero_Bombeiros = n;
}



//////////////////////////////////////
// CLASS FLORESTAL
//////////////////////////////////////

	//Metodos Get

u_int Florestal::getAreaChamas() const{
	return area_Chamas;
}

	//Metodos Set

void Florestal::setAreaChamas(u_int area){
	this->area_Chamas = area;
}

	//Outros metodos


	//Metodos Virtuais

void Florestal::lerInfo(stringstream &ss){
	string d;
	int x, y;
	u_int n_carros, n_bombeiros, a;

	ss >> d >> x >> y >> n_carros >> n_bombeiros >> a;

	pair<int,int> p = make_pair(x,y); // construir o par
	this->setData(d);
	this->setLocal(p);
	this->setNumeroCarrosBombeiros(n_carros);
	this->setNumeroBombeiros(n_bombeiros);
	this->setAreaChamas(a);
}

string Florestal::getAllInfo() const{
	stringstream ss;

	ss << this->numero_CarrosBombeiros << ' ' << this->numero_Bombeiros << ' ' << this->area_Chamas;

	return ss.str();
}

string Florestal::getAllInfoFormatoPrint() const {
	stringstream ss;

	ss << "Numero de Carros Bombeiros: " << this->numero_CarrosBombeiros << " Numeros Bombeiros: " << this->numero_Bombeiros << " Area das chamas: " << this->area_Chamas;

	return ss.str();
}

void Florestal::infoUtilizador(){

	string areat;
	u_int area;

	cout << "Área do incêndio: ";
	getline(cin,areat);
	eNumero(areat);
	area=stoi(areat);

	//testar se o input é valido!!!

	this->setNumeroCarrosBombeiros(nCarrosBombeirosArea(area));
	this->setNumeroBombeiros(nBombeirosArea(area));
	this->setAreaChamas(area);
}


//////////////////////////////////////
// CLASS DOMESTICOS
//////////////////////////////////////

	//Metodos Get

string Domesticos::getTipoCasa() const{
	return this->tipo_casa;
}

	//Metodos Set

void Domesticos::setTipoCasa(string s){
	this->tipo_casa = s;
}

	//Outros metodos


	//Metodos Virtuais

void Domesticos::lerInfo(stringstream &ss){
	string d, s; // data e string "tipo_casa"
	int x, y; // coordenadas
	u_int n_carros, n_bombeiros; // numero de carros e bombeiros

	ss >> d >> x >> y >> n_carros >> n_bombeiros >> s;

	pair<int,int> p = make_pair(x,y); // construir o par
	this->setData(d);
	this->setLocal(p);
	this->setNumeroCarrosBombeiros(n_carros);
	this->setNumeroBombeiros(n_bombeiros);
	this->setTipoCasa(s);
}

string Domesticos::getAllInfo() const{
	stringstream ss;

	ss << this->numero_CarrosBombeiros << ' ' << this->numero_Bombeiros << ' ' << this->tipo_casa;

	return ss.str();
}
string Domesticos::getAllInfoFormatoPrint() const {
	stringstream ss;

	ss << "Numero de Carros de Bombeiros: " << this->numero_CarrosBombeiros << " Numero de Bombeiros: " << this->numero_Bombeiros << " Tipo de Casa: " << this->tipo_casa;

	return ss.str();
}


void Domesticos::infoUtilizador(){

	string opcao;
	cout << "Lista de opções: ";
	cout << "1 - Apartamento\n";
	cout << "2 - Moradia\n";

	cout << "Indique o tipo de casa: ";
	getline(cin,opcao);

	//testar se o input é valido!!!

	if(opcao == "1"){
		this->setNumeroCarrosBombeiros(numeroCarBombeirosApart());
		this->setNumeroBombeiros(numeroBombeirosApart());
	}

	else if(opcao == "2"){
		this->setNumeroCarrosBombeiros(numeroCarBombeirosMoradia());
		this->setNumeroBombeiros(numeroBombeirosMoradia());
	}
	else
	{
		throw new Opcao_Nao_Valida(opcao);
	}

}


//////////////////////////////////////
// CLASS ASSALTO
//////////////////////////////////////

	//Metodos Get

bool Assalto::getExisteFeridos() const{
	return this->existe_Feridos;
}

string Assalto::getTipoCasa() const{
	return this->tipo_casa;
}

	//Metodos Set

void Assalto::setExisteFeridos(bool n){
	this->existe_Feridos = n;
}

void Assalto::setTipoCasa(string s){
	this->tipo_casa = s;
}

	//Outros metodos



	//Metodos Virtuais

void Assalto::lerInfo(stringstream &ss){
	string d, s; // data e string "tipo_casa"
	int x, y; // coordenadas
	bool feridos;

	ss >> d >> x >> y >> feridos >> s;

	pair<int,int> p = make_pair(x,y); // construir o par
	this->setData(d);
	this->setLocal(p);
	this->setExisteFeridos(feridos);
	this->setTipoCasa(s);
}

string Assalto::getAllInfo() const{
	stringstream ss;

	ss << this->existe_Feridos << ' ' << this->tipo_casa;

	return ss.str();
}
string Assalto::getAllInfoFormatoPrint() const {
	stringstream ss;

	ss << "Feridos: " << this->existe_Feridos << " Tipo de Casa: " << this->tipo_casa;

	return ss.str();
}

void Assalto::infoUtilizador(){

	string opcao;

	cout << "Existem feridos?(S/N) ";
	getline(cin,opcao);

	bool feridos = false;

	if (opcao == "S" || opcao == "s") {
		feridos = true;
		this->setExisteFeridos(feridos);
	}

	else if (opcao == "N" || opcao == "n") {
		feridos = false;
		this->setExisteFeridos(feridos);
	}
	else throw new Opcao_Nao_Valida(opcao);

	cout << "\nLista de opções: \n";
	cout << "1 - Particular\n";
	cout << "2 - Comercial\n";

	cout << "Indique o tipo de casa: ";
	getline(cin,opcao);

	if (opcao == "1") {
		this->setTipoCasa("Particular");
	}

	else if (opcao == "2") {
		this->setTipoCasa("Comercial");
	}
	else throw  new Opcao_Nao_Valida(opcao);

}


//////////////////////////////////////
// CLASS ACIDENTEVIACAO
//////////////////////////////////////

	//Metodos Get

u_int AcidenteViacao::getNumeroFeridosGraves() const{
	return this->numero_FeridosGraves;
}

u_int AcidenteViacao::getNumeroVeiculosEnvolvidos() const{
	return this->numero_VeiculosEnvolvidos;
}

string AcidenteViacao::getTipoEstrada() const{
	return this->tipo_Estrada;
}

	//Metodos Set

void AcidenteViacao::setNumeroFeridosGraves(u_int n){
	this->numero_FeridosGraves = n;
}

void AcidenteViacao::setNumeroVeiculosEnvolvidos(u_int n){
	this->numero_VeiculosEnvolvidos = n;
}
void AcidenteViacao::setTipoEstrada(string s){
	this->tipo_Estrada = s;
}

	//Outros metodos



	//Metodos Virtuais

void AcidenteViacao::lerInfo(stringstream &ss)
{

	string d, s; // data e string "tipo_estrada"
	int x, y; // coordenadas
	u_int n_feridos, n_veiculos_env; // numero de feridos graves e veiculos envolvidos

	ss >> d >> x >> y >> n_feridos >> n_veiculos_env >> s;

	pair<int,int> p = make_pair(x,y); // construir o par
	this->setData(d);
	this->setLocal(p);
	this->setNumeroFeridosGraves(n_feridos);
	this->setNumeroVeiculosEnvolvidos(n_veiculos_env);
	this->setTipoEstrada(s);

}


string AcidenteViacao::getAllInfo() const{
	stringstream ss;

	ss << this->numero_FeridosGraves << ' ' << this->numero_VeiculosEnvolvidos << ' ' << this->tipo_Estrada;

	return ss.str();
}
string AcidenteViacao::getAllInfoFormatoPrint() const {
	stringstream ss;

	ss << "Numero de feridos: " << this->numero_FeridosGraves << " Numero de Veiculos involvidos: " << this->numero_VeiculosEnvolvidos << " Tipo de Estrada: " << this->tipo_Estrada;

	return ss.str();
}


void AcidenteViacao::infoUtilizador(){

	string opcao;

	cout << "Numero de feridos graves: ";
	getline(cin,opcao);
	eNumero(opcao);
	u_int n = stoi(opcao);

	this->setNumeroFeridosGraves(n);

	cout << "\nNumero de veiculos envolvidos: ";
	getline(cin,opcao);
	eNumero(opcao);
	n = stoi(opcao);

	this->setNumeroVeiculosEnvolvidos(n);

	cout << "\nLista de opções: \n";
	cout << "1 - Estrada Nacional\n";
	cout << "2 - Auto Estrada\n";

	cout << "Indique o tipo de estrada: ";
	getline(cin,opcao);

	if (opcao == "1") {
		this->setTipoEstrada("Nacional");
	}

	else if (opcao == "2") {
		this->setTipoEstrada("Auto-Estrada");
	}
	else throw new Opcao_Nao_Valida(opcao);

}














