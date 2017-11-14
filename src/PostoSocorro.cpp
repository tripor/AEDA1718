#include "Menu.h"

//Class PostoSocorro -----------------------------------------------------------------------------------------
PostoSocorro::PostoSocorro(u_int numero_Socorristas,u_int numero_Veiculos,std::pair<int,int> local)
{
	this->numero_Socorristas=numero_Socorristas;
	this->numero_Veiculos=numero_Veiculos;
	this->local=local;
}

bool PostoSocorro::operator< (const PostoSocorro & p) const{
	//return sqrt(pow((this->local.first - x_aci),2) + pow((this->local.second - y_aci),2)) < sqrt(pow((p.local.first - x_aci),2) + pow((p.local.second - y_aci),2));
}


void PostoSocorro::setSocorristas(u_int numero_Socorristas)
{
	this->numero_Socorristas=numero_Socorristas;
}
void PostoSocorro::setVeiculos(u_int numero_Veiculos)
{
	this->numero_Veiculos=numero_Veiculos;
}
u_int PostoSocorro::getSocorristas()
{
	return this->numero_Socorristas;
}
u_int PostoSocorro::getVeiculos()
{
	return this->numero_Veiculos;
}
std::pair<int,int> PostoSocorro::getPos()
{
	return this->local;
}
//Class Bombeiros ----------------------------------------------------------------------------------------------
Bombeiros::Bombeiros(u_int numero_Socorristas,std::pair<int,int> local,u_int numero_Ambulancias,u_int numero_Autotanques):PostoSocorro(numero_Socorristas,numero_Ambulancias+numero_Autotanques,local)
{
	this->numero_Ambulancias=numero_Ambulancias;
	this->numero_Autotanques=numero_Autotanques;
}
u_int Bombeiros::getAmbulancias()
{
	return this->numero_Ambulancias;
}
u_int Bombeiros::getAutotanques()
{
	return this->numero_Autotanques;
}
//Class Policia --------------------------------------------------------------------------------------------------
Policia::Policia(u_int numero_Socorristas,u_int numero_Veiculos,std::pair<int,int> local,std::string veiculo):PostoSocorro(numero_Socorristas,numero_Veiculos,local)
{
	this->veiculo=veiculo;
}
std::string Policia::getVeiculo()
{
	return this->veiculo;
}
//Class Inem -----------------------------------------------------------------------------------------------------
Inem::Inem(u_int numero_Socorristas,u_int numero_Veiculos,std::pair<int,int> local,std::string veiculo):PostoSocorro(numero_Socorristas,numero_Veiculos,local)
{
	this->veiculo=veiculo;
}
std::string Inem::getVeiculo()
{
	return this->veiculo;
}
