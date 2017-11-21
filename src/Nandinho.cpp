#include "Header.h"
#include "Menu.h"
#include "Acidente.h"
#include "PostoSocorro.h"

template <class Comparable>
void insertionSort(std::vector<Comparable> &v)
{
	for (unsigned int p = 1; p < v.size(); p++)
	{
		Comparable tmp = v[p];
		int j;
		for (j = p; j > 0 && (*tmp) < (*v[j-1]); j--)
			v[j] = v[j-1];
		v[j] = tmp;
	}
}

bool Acidente::operator< (const Acidente & aci) const{
	return (this->getData() < aci.getData());
}

bool PostoSocorro::menorDistancia(PostoSocorro & a, PostoSocorro & b, std::pair<int, int> p){
	int x = p.first;
	int y = p.second;

	return (sqrt(pow((a.local.first - x),2) + pow((a.local.second - y),2)) < sqrt(pow((b.local.first - x),2) + pow((b.local.second - y),2)));

}



void Menu::ordenaVetorAcidentes(){
	// Ordena os acidentes por data
	insertionSort(this->acidentes);
}


void Menu::ordenaVetorPostosSocorro(){
	//Ordena por distancia a um acidente

}


void Menu::atribuiAcidentes(){
	//Ordenar o vetor de acidentes por data

	//////FOR//////

	//Verificar que tipo de postos é que o acidente vai necessitar de chamar

	//Criar um vetor para cada tipo necessário

	//Ordenar cada vetor em funcao da distancia ao acidente

	//Verificar se, na data do acidente não existem já acidentes liberados do vetor "a tratar"

	//Verificar cada elemento desse vetor a ver qual é o primeiro que possui os recursos para tratar o acidente

	//Adicionar o acidente (objeto ou pointer?) ao vetor de acidentes por tratar (somando o tempo) e atribuidos

	for(unsigned int i = 0; i < this->acidentes.size(); i++){

		std::string tipo = this->acidentes.at(i)->getTipoAcidente();

		if(tipo == "Florestal"){
			//Precisa de posto de bombeiros
			std::vector<Acidente*> temp_bombeiros;

			for(unsigned int j = 0; j < this->postos_socorro.size(); j++){
				if(this->postos_socorro.at(j)->getTipo() == "Bombeiros"){
					//Acidente* temp = this->postos_socorro.at(j);
					//temp_bombeiros.push_back(temp);
				}
			}


			//Ordenar em relacao a distancia ao acidente




		}
		if(tipo == "Domestico"){
			//Precisa de posto de bombeiros

		}
		if(tipo == "Assalto"){
			//Precisa de policia (qualquer tipo) e se houver feridos, um veiculo INEM qualquer

		}
		if(tipo == "AcidenteViacao"){
			//Se só houver 1 ferido grave, mota INEM
			//Se houver 2 a 4, 1 a 2 carros INEM
			//Se houver 5 ou mais, (NºFeridos graves/2) = NºAmbulancias
			//Policia, Carro se for estrada nacional, (nºveiculos envolvidos/2)
			//Policia, Mota se for auto estrada, (nºveiculos envolvidos/2)


		}


	}



}










