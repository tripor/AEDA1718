#include "Header.h"
#include "Menu.h"
#include "Acidente.h"
#include "PostoSocorro.h"

#include <algorithm>

//Preciso de globais

int x_glob;
int y_glob;


bool Acidente::operator< (const Acidente & aci) const{
	return (this->getData() < aci.getData());
}

bool menorDistancia(PostoSocorro* a, PostoSocorro* b){

	return (sqrt(pow((a->getPos().first - x_glob),2) + pow((a->getPos().second - y_glob),2)) < sqrt(pow((b->getPos().first - x_glob),2) + pow((b->getPos().second - y_glob),2)));

}


bool CompareAcidentes(Acidente* a1, Acidente* a2){
	return (a1->getData()) < (a2->getData());
}


void Menu::ordenaVetorAcidentes(){
	std::sort(this->acidentes.begin(), acidentes.end(), CompareAcidentes);
}



void Menu::ordenaVetorPostosSocorro(std::vector<PostoSocorro*> &v1){
	//Ordena por distancia a um acidente
	std::sort(v1.begin(), v1.end(), menorDistancia);
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
			std::vector<PostoSocorro*> temp_bombeiros;

			for(unsigned int j = 0; j < this->postos_socorro.size(); j++){
				if(this->postos_socorro.at(j)->getTipo() == "Bombeiros"){
					temp_bombeiros.push_back(postos_socorro.at(j));
				}
			}


			//Ordenar em relacao a distancia ao acidente
			x_glob = this->acidentes.at(i)->getLocal().first;
			y_glob = this->acidentes.at(i)->getLocal().second;
			this->ordenaVetorPostosSocorro(temp_bombeiros);

			//Correr o vetor de postos

			for(unsigned int k = 0; k < temp_bombeiros.size(); k++){
				//Verificar se, na data do acidente não existem já acidentes liberados do vetor "a tratar"

				bool parar = false; // para quando deixa de haver acidentes a tratar com datas de resolucao inferiores

				//ordena o vetor de acidentes a tratar por data de resolucao
				std::sort(temp_bombeiros.at(k)->getAcidentesTratar().begin(), temp_bombeiros.at(k)->getAcidentesTratar().end());

				while(!parar && !(temp_bombeiros.at(k)->getAcidentesTratar().empty())){
					//testa se a data é menor, se sim, vai atualizar os recursos disponiveis, e depois apagar o elemento
						if(temp_bombeiros.at(k)->getAcidentesTratar().at(0)->data < acidentes.at(i)->getData()){
							temp_bombeiros.at(k)->getAllInfo(); //incompleto, falta o set virtual

						}

				}




			}



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










