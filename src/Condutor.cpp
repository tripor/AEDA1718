#include "Condutor.h"
#include "erros.h"
#include "Menu.h"
using namespace std;

string Condutor::getName() const{
	return nome;
}

Data Condutor::getData() const{
	return d_acidente;
}

void Condutor::setName(std::string s){
	this->nome = s;
}

void Condutor::setData(Data d){
	this->d_acidente=d;
}

void Condutor::setData(std::string s){
	u_int ano,mes,dia,hora,minuto;
	char hifen;
	stringstream retirar;
	retirar << s;
	retirar >> ano >> hifen >> mes >> hifen >> dia >> hifen >> hora >> hifen >> minuto ;
	Data devolver(ano,mes,dia,hora,minuto);
	this->d_acidente=devolver;
}


