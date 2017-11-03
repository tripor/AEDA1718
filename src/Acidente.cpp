#include "Acidente.h"

// Classe Acidente

	//Construtores

Acidente::Acidente(std::string d, std::pair<int,int> local){
	this->data = d;
	this->local = local;
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

Incendios::Incendios(u_int n_carros, u_int n_bombeiros, std::string d, std::pair<int,int> local): Acidente(d, local){
	this->numero_CarrosBombeiros = n_carros;
	this->numero_Bombeiros = n_bombeiros;
}

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


// Classe Domesticos

	//Metodos Get

std::string Domesticos::getTipoCasa() const{
	return this->tipo_casa;
}

	//Metodos Set

void Domesticos::setTipoCasa(std::string s){
	this->tipo_casa = s;
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



// Classe Acidente_Viacao

	//Metodos Get

u_int Acidente_Viacao::getNumeroFeridosGraves() const{
	return this->numero_FeridosGraves;
}

u_int Acidente_Viacao::getNumeroVeiculosEnvolvidos() const{
	return this->numero_VeiculosEnvolvidos;
}

std::string Acidente_Viacao::getTipoEstrada() const{
	return this->tipo_Estrada;
}

	//Metodos Set

void Acidente_Viacao::setNumeroFeridosGraves(u_int n){
	this->numero_FeridosGraves = n;
}

void Acidente_Viacao::setNumeroVeiculosEnvolvidos(u_int n){
	this->numero_VeiculosEnvolvidos = n;
}
void Acidente_Viacao::setTipoEstrada(std::string s){
	this->tipo_Estrada = s;
}
