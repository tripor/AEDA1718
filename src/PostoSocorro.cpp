#include "Menu.h"

using namespace std;
//Class PostoSocorro -----------------------------------------------------------------------------------------
PostoSocorro::PostoSocorro(u_int numero_Socorristas,u_int numero_Veiculos,pair<int,int> local)
{
	this->numero_Socorristas=numero_Socorristas;
	this->numero_Veiculos=numero_Veiculos;
	this->local=local;
	this->acidenteAtribuidos.clear();
	this->acidenteATratar.clear();
}

bool PostoSocorro::operator < (const PostoSocorro & p) const{
	return 1;//sqrt(pow((this->local.first - x_aci),2) + pow((this->local.second - y_aci),2)) < sqrt(pow((p.local.first - x_aci),2) + pow((p.local.second - y_aci),2));
}


void PostoSocorro::setSocorristas(u_int numero_Socorristas)
{
	this->numero_Socorristas=numero_Socorristas;
}
void PostoSocorro::setVeiculos(u_int numero_Veiculos)
{
	this->numero_Veiculos=numero_Veiculos;
}
void PostoSocorro::setPosicao(pair<int,int> local)
{
	this->local=local;
}
void PostoSocorro::setAcidentesTratar(std::vector<Acidente*> v1){
	this->acidenteATratar = v1;
}
void PostoSocorro::setAcidentesAtribuidos(std::vector<Acidente*> v1){
	this->acidenteAtribuidos = v1;
}


u_int PostoSocorro::getSocorristas()
{
	return this->numero_Socorristas;
}
u_int PostoSocorro::getVeiculos()
{
	return this->numero_Veiculos;
}
pair<int,int> PostoSocorro::getPos()
{
	return this->local;
}
void PostoSocorro::infoUtilizadorGeral()
{
	string socorristast,veiculost;
	u_int socorristas,veiculos;
	cout << endl << "Número de Socorristas: ";
	getline(cin,socorristast);
	eNumero(socorristast);
	socorristas=stoi(socorristast);
	this->setSocorristas(socorristas);

	cout << endl << "Número de Veiculos: ";
	getline(cin, veiculost);
	eNumero(veiculost);
	veiculos = stoi(veiculost);
	this->setVeiculos(veiculos);

	string x_coordt, y_coordt;
	int x_coord, y_coord;

	cout << "\nCoordenada X do posto: ";
	getline(cin, x_coordt);
	eNumero(x_coordt);
	x_coord = stoi(x_coordt);

	cout << "\nCoordenada Y do posto: ";
	getline(cin, y_coordt);
	eNumero(y_coordt);
	y_coord = stoi(y_coordt);

	pair<int, int> p = make_pair(x_coord, y_coord);

	this->setPosicao(p);
}
//Class Bombeiros ----------------------------------------------------------------------------------------------
Bombeiros::Bombeiros(u_int numero_Socorristas,pair<int,int> local,u_int numero_Ambulancias,u_int numero_Autotanques):PostoSocorro(numero_Socorristas,numero_Ambulancias+numero_Autotanques,local)
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
string Bombeiros::getAllInfo() {
	stringstream devolver;
	devolver << this->getSocorristas() << ' ' << this->getVeiculos() << ' '
			<< this->getPos().first << '-' << this->getPos().second << ' '
			<< this->getAmbulancias() << ' ' << this->getAutotanques();
	return devolver.str();
}
string Bombeiros::getAllInfoFormatoPrint()
{
	stringstream devolver;
	devolver << "Número de socorristas: " << this->getSocorristas() << " Número de veiculos: " << this->getVeiculos() << " Posição: X="
			<< this->getPos().first << " Y=" << this->getPos().second << " Número de ambulancias: "
			<< this->getAmbulancias() << " Número de AutoTanques: " << this->getAutotanques();
	return devolver.str();
}
void Bombeiros::guardarInformacao(stringstream &receber)
{
	char hifen='-';
	u_int numero_Socorristas,numero_Veiculos,numero_Ambulancias,numero_Autotanques;
	int x,y;
	pair<int,int> temp;
	receber >> numero_Socorristas >> numero_Veiculos >> x >> hifen >> y >> numero_Ambulancias >> numero_Autotanques;
	temp=make_pair(x,y);
	this->setSocorristas(numero_Socorristas);
	this->setVeiculos(numero_Veiculos);
	this->setPosicao(temp);
	this->numero_Ambulancias=numero_Ambulancias;
	this->numero_Autotanques=numero_Autotanques;
}
void Bombeiros::infoUtilizador()
{
	string ambulanciast,autotanquest;
	u_int ambulancias,autotanques;
	cout << endl << "Numero de Ambulancias: ";
	getline(cin, ambulanciast);
	eNumero (ambulanciast);
	ambulancias = stoi(ambulanciast);


	cout << endl << "Numero de Autotanques: ";
	getline(cin, autotanquest);
	eNumero(autotanquest);
	autotanques = stoi(autotanquest);

	if(ambulancias + autotanques != this->getVeiculos()){
		//throw new Opcao_Nao_Valida(opcao);
	}
	else{
		this->numero_Ambulancias=ambulancias;
		this->numero_Autotanques=autotanques;
	}

}
//Class Policia --------------------------------------------------------------------------------------------------
Policia::Policia(u_int numero_Socorristas,u_int numero_Veiculos,pair<int,int> local,string veiculo):PostoSocorro(numero_Socorristas,numero_Veiculos,local)
{
	this->veiculo=veiculo;
}
string Policia::getVeiculo()
{
	return this->veiculo;
}
string Policia::getAllInfo() {
	stringstream devolver;
	devolver << this->getSocorristas() << ' ' << this->getVeiculos() << ' '
			<< this->getPos().first << '-' << this->getPos().second << ' '
			<< this->getVeiculo();
	string res;
	res = devolver.str();
	return res;
}
string Policia::getAllInfoFormatoPrint()
{
	stringstream devolver;
	devolver << "Número de socorristas: " << this->getSocorristas() << " Número de veiculos: " << this->getVeiculos() << " Posição: X="
			<< this->getPos().first << " Y=" << this->getPos().second << " Tipo de veiculo:  "
			<< this->getVeiculo();
	return devolver.str();
}
void Policia::guardarInformacao(stringstream &receber)
{
	char hifen='-';
	u_int numero_Socorristas,numero_Veiculos;
	string tipo;
	int x,y;
	pair<int,int> temp;
	receber >> numero_Socorristas >> numero_Veiculos >> x >> hifen >> y >> tipo;
	temp=make_pair(x,y);
	this->setSocorristas(numero_Socorristas);
	this->setVeiculos(numero_Veiculos);
	this->setPosicao(temp);
	this->veiculo=tipo;
}
void Policia::infoUtilizador()
{
	string tipo;

	cout << "\nLista de opções: \n";
	cout << "1 - Moto\n";
	cout << "2 - Carro\n";

	cout << "Indique o tipo de veiculo: ";
	getline(cin,tipo);

	if (tipo == "1") {
		this->veiculo = "Moto";
	}

	else if (tipo == "2") {
		this->veiculo = "Carro";
	}
	//else throw new Opcao_Nao_Valida(opcao);


}
//Class Inem -----------------------------------------------------------------------------------------------------
Inem::Inem(u_int numero_Socorristas,u_int numero_Veiculos,pair<int,int> local,string veiculo):PostoSocorro(numero_Socorristas,numero_Veiculos,local)
{
	this->veiculo=veiculo;
}
string Inem::getVeiculo()
{
	return this->veiculo;
}
string Inem::getAllInfo()
{
	stringstream devolver;
		devolver << this->getSocorristas() << ' ' << this->getVeiculos() << ' '
				<< this->getPos().first << '-' << this->getPos().second << ' '
				<< this->getVeiculo();
		string res;
		res = devolver.str();
		return res;
}
string Inem::getAllInfoFormatoPrint()
{
	stringstream devolver;
	devolver << "Número de socorristas: " << this->getSocorristas() << " Número de veiculos: " << this->getVeiculos() << " Posição: X="
			<< this->getPos().first << " Y=" << this->getPos().second << " Tipo de veiculo:  "
			<< this->getVeiculo();
	return devolver.str();
}
void Inem::guardarInformacao(stringstream &receber)
{
	char hifen='-';
	u_int numero_Socorristas,numero_Veiculos;
	string tipo;
	int x,y;
	pair<int,int> temp;
	receber >> numero_Socorristas >> numero_Veiculos >> x >> hifen >> y >> tipo;
	temp=make_pair(x,y);
	this->setSocorristas(numero_Socorristas);
	this->setVeiculos(numero_Veiculos);
	this->setPosicao(temp);
	this->veiculo=tipo;
}
void Inem::infoUtilizador()
{
	string tipo;

	cout << "\nLista de opções: \n";
	cout << "1 - Ambulancia\n";
	cout << "2 - Carro\n";
	cout << "3 - Moto\n";

	cout << "Indique o tipo de veiculo: ";
	getline(cin,tipo);

	if (tipo == "1") {
		this->veiculo = "Ambulancia";
	}

	else if (tipo == "2") {
		this->veiculo = "Carro";
	}
	else if (tipo == "3") {
		this->veiculo = "Moto";
	}

	//else throw new Opcao_Nao_Valida(opcao);


}

void PostoSocorro::printAcidentesAtribuidos(){

	for (unsigned int i = 0; i < this->acidenteAtribuidos.size(); i++) {

		cout << endl << string('=',20);
		cout << i+1 << "- ";
		cout << "Tipo: " << acidenteAtribuidos.at(i)->getTipoAcidente() << "| ";
		cout << "Local: x=" << acidenteAtribuidos.at(i)->getLocal().first << "| ";
		cout << " y= " << acidenteAtribuidos.at(i)->getLocal().second << "| ";
		cout << " Data: " << acidenteAtribuidos.at(i)->getData().getDataFormato() << " | ";

		cout << this->acidenteAtribuidos.at(i)->getAllInfoFormatoPrint() << endl;

	}

}

