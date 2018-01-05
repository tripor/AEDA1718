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
	string nome1;
	vector<string> marcas1;
	ss >> nome1;
	this->setNome(nome1);
	while (ss >> nome1){
		marcas1.push_back(nome1);
	}
	this->setMarcas(marcas1);
}

