#include "Acidente.h"

// Classe Acidente

	//Construtores

Acidente::Acidente(std::string d, std::pair<int,int> local){
	this->data = d;
	this->local = local;
}

	//Operadores

bool Acidente::operator== (const Acidente* & a) const{
	if(this->getTipoAcidente() != a->getTipoAcidente()){
		return false;
	}
	if(this->getTipoAcidente() == "Florestal"){



	}

	return true;
}

	//Metodos Get

std::string Acidente::getData() const{
	return this->data;
}

std::pair<int,int> Acidente::getLocal() const{
	return this->local;
}

	//Metodos Set

void Acidente::setData(std::string d){
	this->data = d;
}

void Acidente::setLocal(std::pair<int,int> par){
	this->local = par;
}



// Classe Incendios

	//Construtores

/*
	Incendios::Incendios(u_int n_carros, u_int n_bombeiros, std::string d, std::pair<int,int> local): Acidente(d, local){
	this->numero_CarrosBombeiros = n_carros;
	this->numero_Bombeiros = n_bombeiros;
}*/

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
