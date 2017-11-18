#include "Header.h"
#include "PostoSocorro.h"
#include "Acidente.h"
#include "Menu.h"

//////// PARTE A COPIAR







/*

std::string Florestal::WriteAcidente(){
	std::stringstream ss;
	ss << getNumeroCarrosBombeiros();
	ss << " ";
	ss << getNumeroBombeiros();
	ss << " ";
	ss << area_Chamas;
	return ss.str();
}


std::string Domesticos::WriteAcidente(){
		std::stringstream ss;
		ss << getNumeroCarrosBombeiros();
		ss << " ";
		ss << getNumeroBombeiros();
		ss << " ";
		ss << tipo_casa;
		return ss.str();
	}

std::string Assalto::WriteAcidente(){
		std::stringstream ss;
		ss << " ";
		if(existe_Feridos==true)
			ss << "True";
		else
			ss << "False";
		ss << " ";
		ss << tipo_casa;
		return ss.str();
	}


std::string Acidente_Viacao::WriteAcidente(){
		std::stringstream ss;
		ss << numero_FeridosGraves;
		ss << " ";
		ss << numero_VeiculosEnvolvidos;
		ss << " ";
		ss << tipo_Estrada;
		return ss.str();
	}




void EscreveFicheiroAcidente(){
		  std::stringstream ss;
		  std::ofstream ficheiro ("Acidente.txt");
		  while (!ficheiro.eof())
		  {
			  ficheiro << " ";

	for(int i = 0; acidentes.size(); i++){
		´


		  	ficheiro << (acidentes.at(i)->GetTipoAcidente());
		    ficheiro << " ";
			//ficheiro << acidentes.at(i).getData();
		  	//ficheiro << " ";
		    std::pair<int,int> a = acidentes.at(i)->getLocal();
		    ficheiro << a.first;
		    ficheiro << " ";
		    ficheiro << a.second;
		    ficheiro << " ";
			ficheiro << acidentes.at(i)->WriteAcidente();
		  }
	}
		  ficheiro.close();
}

*/
