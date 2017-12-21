#include "Oficina.h"
#include "erros.h"
#include "Menu.h"
using namespace std;


u_int Oficina::getDisponibilidade(){
	return disponibilidade;
}

std::vector<std::string> Oficina::getMarcas() const{
	return marcas;
}

void Oficina::setDisponibilidade(u_int disponibilidade){
	this->disponibilidade = disponibilidade;
}

bool Oficina::operator<(Oficina &of1){
	return (disponibilidade < of1.getDisponibilidade());
}

