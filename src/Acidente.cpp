#include "Acidente.h"


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


	//Metodos Get

Data Acidente::getData() const{
	return this->data;
}

std::pair<int,int> Acidente::getLocal() const{
	return this->local;
}

	//Metodos Set

void Acidente::setData(Data d){
	this->data = d;
}
void Acidente::setData(std::string d)
{
	u_int ano,mes,dia,hora,minuto;
	char hifen='-';
	std::stringstream retirar;
	retirar << d;
	retirar >> ano >> hifen >> mes >> hifen >> dia >> hifen >> hora >> hifen >> minuto ;
	this->data=Data(ano,mes,dia,hora,minuto);
}
void Acidente::setLocal(std::pair<int,int> par){
	this->local = par;
}



// Classe Incendios

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



// Classe Florestal

	//Metodos Get

u_int Florestal::getAreaChamas() const{
	return area_Chamas;
}

	//Metodos Set

void Florestal::setAreaChamas(u_int area){
	this->area_Chamas = area;
}

void Florestal::lerInfo(std::stringstream &ss){
	std::string d;
	int x, y;
	u_int n_carros, n_bombeiros, a;

	ss >> d >> x >> y >> n_carros >> n_bombeiros >> a;

	std::pair<int,int> p = std::make_pair(x,y); // construir o par
	this->setData(d);
	this->setLocal(p);
	this->setNumeroCarrosBombeiros(n_carros);
	this->setNumeroBombeiros(n_bombeiros);
	this->setAreaChamas(a);
}


// Classe Domesticos

	//Metodos Get

std::string Domesticos::getTipoCasa() const{
	return this->tipo_casa;
}

	//Metodos Set

void Domesticos::setTipoCasa(std::string s){
	this->tipo_casa = s;
}

void Domesticos::lerInfo(std::stringstream &ss){
	std::string d, s; // data e string "tipo_casa"
	int x, y; // coordenadas
	u_int n_carros, n_bombeiros; // numero de carros e bombeiros

	ss >> d >> x >> y >> n_carros >> n_bombeiros >> s;

	std::pair<int,int> p = std::make_pair(x,y); // construir o par
	this->setData(d);
	this->setLocal(p);
	this->setNumeroCarrosBombeiros(n_carros);
	this->setNumeroBombeiros(n_bombeiros);
	this->setTipoCasa(s);
}


// Classe Assalto

	//Metodos Get

bool Assalto::getExisteFeridos() const{
	return this->existe_Feridos;
}

std::string Assalto::getTipoCasa() const{
	return this->tipo_casa;
}

	//Metodos Set

void Assalto::setExisteFeridos(bool n){
	this->existe_Feridos = n;
}

void Assalto::setTipoCasa(std::string s){
	this->tipo_casa = s;
}

void Assalto::lerInfo(std::stringstream &ss){
	std::string d, s; // data e string "tipo_casa"
	int x, y; // coordenadas
	bool feridos;

	ss >> d >> x >> y >> feridos >> s;

	std::pair<int,int> p = std::make_pair(x,y); // construir o par
	this->setData(d);
	this->setLocal(p);
	this->setExisteFeridos(feridos);
	this->setTipoCasa(s);
}



// Classe Acidente_Viacao

	//Metodos Get

u_int AcidenteViacao::getNumeroFeridosGraves() const{
	return this->numero_FeridosGraves;
}

u_int AcidenteViacao::getNumeroVeiculosEnvolvidos() const{
	return this->numero_VeiculosEnvolvidos;
}

std::string AcidenteViacao::getTipoEstrada() const{
	return this->tipo_Estrada;
}

	//Metodos Set

void AcidenteViacao::setNumeroFeridosGraves(u_int n){
	this->numero_FeridosGraves = n;
}

void AcidenteViacao::setNumeroVeiculosEnvolvidos(u_int n){
	this->numero_VeiculosEnvolvidos = n;
}
void AcidenteViacao::setTipoEstrada(std::string s){
	this->tipo_Estrada = s;
}

void AcidenteViacao::lerInfo(std::stringstream &ss)
{

	std::string d, s; // data e string "tipo_estrada"
	int x, y; // coordenadas
	u_int n_feridos, n_veiculos_env; // numero de feridos graves e veiculos envolvidos

	ss >> d >> x >> y >> n_feridos >> n_veiculos_env >> s;

	std::pair<int,int> p = std::make_pair(x,y); // construir o par
	this->setData(d);
	this->setLocal(p);
	this->setNumeroFeridosGraves(n_feridos);
	this->setNumeroVeiculosEnvolvidos(n_veiculos_env);
	this->setTipoEstrada(s);

}



//////// Parte Fernando


std::string Florestal::getAllInfo() const{
	std::stringstream ss;

	ss << this->numero_CarrosBombeiros << ' ' << this->numero_Bombeiros << ' ' << this->area_Chamas;
	std::string ret;
	ret=ss.str();
	return ret;
}

std::string Domesticos::getAllInfo() const{
	std::stringstream ss;

	ss << this->numero_CarrosBombeiros << ' ' << this->numero_Bombeiros << ' ' << this->tipo_casa;

	std::string ret;
	ss.str(ret);

	return ret;
}

std::string Assalto::getAllInfo() const{
	std::stringstream ss;

	ss << this->existe_Feridos << ' ' << this->tipo_casa;

	std::string ret;
	ss.str(ret);

	return ret;
}

std::string AcidenteViacao::getAllInfo() const{
	std::stringstream ss;

	ss << this->numero_FeridosGraves << ' ' << this->numero_VeiculosEnvolvidos << ' ' << this->tipo_Estrada;

	std::string ret;
	ss.str(ret);

	return ret;
}

// INFO UTILIZADOR

void Florestal::infoUtilizador(){

	//ClearScreen();

	u_int area;

	std::cout << "Área do incêndio: ";
	std::cin >> area;

	//testar se o input é valido!!!

	this->setNumeroCarrosBombeiros(nCarrosBombeirosArea(area));
	this->setNumeroBombeiros(nBombeirosArea(area));
	this->setAreaChamas(area);
}

void Domesticos::infoUtilizador(){

	std::string opcao;
	std::cout << "Lista de opções: ";
	std::cout << "1 - Apartamento\n";
	std::cout << "2 - Moradia\n";

	std::cout << "Indique o tipo de casa: ";
	std::cin >> opcao;

	//testar se o input é valido!!!

	while (!(opcao == "1" || opcao == "2")) {
		std::cout << "\n(!) A opcao fornecida nao e valida (!)\n\n";
		std::cout << "Indique o tipo de casa: ";
		std::cin >> opcao;
	}

	if(opcao == "1"){
		this->setNumeroCarrosBombeiros(numeroCarBombeirosApart());
		this->setNumeroBombeiros(numeroBombeirosApart());
	}

	if(opcao == "2"){
		this->setNumeroCarrosBombeiros(numeroCarBombeirosMoradia());
		this->setNumeroBombeiros(numeroBombeirosMoradia());
	}

}

void Assalto::infoUtilizador(){

	std::string opcao;

	std::cout << "Existem feridos?(S/N) ";
	std::cin >> opcao;

	//testar se o input é valido!!!

	while (!(opcao == "S" || opcao == "N" || opcao == "s" || opcao == "n")) {
		std::cout << "\n(!) A opcao fornecida nao e valida (!)\n\n";
		std::cout << "Existem feridos?(S/N) ";
		std::cin >> opcao;
	}

	bool feridos = false;

	if (opcao == "S" || opcao == "s") {
		feridos = true;
		this->setExisteFeridos(feridos);
	}

	if (opcao == "N" || opcao == "n") {
		feridos = false;
		this->setExisteFeridos(feridos);
	}

	std::cout << "\nLista de opções: ";
	std::cout << "1 - Particular\n";
	std::cout << "2 - Comercial\n";

	std::cout << "Indique o tipo de casa: ";
	std::cin >> opcao;

	//testar se o input é valido!!!

	while (!(opcao == "1" || opcao == "2" || opcao == "0")) {
		std::cout << "\n(!) A opcao fornecida nao e valida (!)\n\n";
		std::cout << "Indique o tipo de casa: ";
		std::cin >> opcao;
	}

	if (opcao == "1") {
		this->setTipoCasa("Particular");
	}

	if (opcao == "2") {
		this->setTipoCasa("Comercial");
	}

}

void AcidenteViacao::infoUtilizador(){

	std::string opcao;

	std::cout << "Numero de feridos graves: ";
	std::cin >> opcao;

	// TESTAR INPUT + EXCECAO

	u_int n = std::stoi(opcao);

	this->setNumeroFeridosGraves(n);

	std::cout << "\nNumero de veiculos envolvidos: ";
	std::cin >> opcao;

	// TESTAR INPUT + EXCECAO

	n = std::stoi(opcao);

	this->setNumeroVeiculosEnvolvidos(n);

	std::cout << "\nLista de opções: ";
	std::cout << "1 - Estrada Nacional\n";
	std::cout << "2 - Auto Estrada\n";

	std::cout << "Indique o tipo de estrada: ";
	std::cin >> opcao;

	//testar se o input é valido!!!

	while (!(opcao == "1" || opcao == "2")) {
		std::cout << "\n(!) A opcao fornecida nao e valida (!)\n\n";
		std::cout << "Indique o tipo de casa: ";
		std::cin >> opcao;
	}

	if (opcao == "1") {
		this->setTipoEstrada("Nacional");
	}

	if (opcao == "2") {
		this->setTipoEstrada("Auto-Estrada");
	}

}


