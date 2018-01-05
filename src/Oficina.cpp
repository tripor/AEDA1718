#include "Oficina.h"
#include "erros.h"
#include "Menu.h"
using namespace std;


u_int Oficina::getDisponibilidade() const{
	return disponibilidade;
}

Data Oficina::getUltimaData() const{
	return utimaData;
}

void Oficina::setData(Data date){
	this->utimaData = date;
}

string Oficina::getNome() const{
	return nome;
}

void Oficina::setNome(string nome){
	this->nome = nome;
}

vector<string> Oficina::getMarcas() const{
	return marcas;
}

void Oficina::setDisponibilidade(u_int disponibilidade){
	this->disponibilidade = disponibilidade;
}

void Oficina::setMarcas(vector<string> marcas){
	this->marcas = marcas;
}

bool Oficina::operator<(const Oficina &of1) const{
	return (this->disponibilidade < of1.getDisponibilidade());
}

void Oficina::lerInfo(stringstream &ss){
	string nome;
	vector<string> marcas;
	ss >> nome;
	while (ss >> nome){
		marcas.push_back(nome);
	}
	this->setNome(nome);
	this->setMarcas(marcas);
}

