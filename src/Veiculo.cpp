#include "Veiculo.h"
#include "erros.h"
#include "Menu.h"
using namespace std;

string Veiculo::getMarca() const
{
	return this->marca;
}

int Veiculo::getQuantidade() const
{
	return this->quantidade;
}

Data Veiculo::getData() const
{
	return this->data;
}
void Veiculo::incQuant()
{
	this->quantidade++;
}
bool Veiculo::operator <(const Veiculo & a) const
{
	if(this->quantidade==a.quantidade)
	{
		return !(this->data<a.data);
	}
	else
	{
		return this->quantidade>a.quantidade;
	}
}
bool Veiculo::operator ==(const Veiculo & a)
{
	return this->marca==a.marca;
}
void Veiculo::operator =(const Veiculo & a)
{
	this->data=a.data;
	this->marca=a.marca;
	this->quantidade=a.quantidade;
}
void Veiculo::lerInfo(std::stringstream &ss)
{
	string marca;
	char hifen='-';
	int quantidade;
	int ano,mes,dia,hora,minuto;
	ss >> marca >> quantidade >> ano >> hifen >> mes >> hifen >> dia >> hifen >> hora >> hifen >> minuto;
	Data nova_data(ano,mes,dia,hora,minuto);
	this->data=nova_data;
	this->marca=marca;
	this->quantidade=quantidade;
}
