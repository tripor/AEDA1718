#include "Header.h"
#include "PostoSocorro.h"
#include "Acidente.h"
#include "Menu.h"

//////// PARTE A COPIAR
/*


void Menu::printAcidentes(){

		std::stringstream ss;
	for(unsigned int i = 0; i<acidentes.size(); i++){

		std::cout << "<" << acidentes.at(i)->getTipoAcidente()<< std::endl;
		std::cout << "<" << "[" << acidentes.at(i)->getLocal().first<<",";
		std::cout <<acidentes.at(i)->getLocal().second <<"]"<<std::endl;
		(acidentes.at(i)->getData()).printDate();
		std::cout << std::endl;
		std::string a = acidentes.at(i)->getTipoAcidente();//para as condições

		ss << acidentes.at(i)->getAllInfo();

		if(a=="Incendio_Florestal"){

			std::string n_carros;
			ss >> n_carros;
			std::cout<<"Numero de carros de bombeiros: "<<n_carros<<std::endl;

			std::string n_bombeiros;
			ss >> n_bombeiros;
			std::cout<<"Numero de bombeiros: "<<n_bombeiros<<std::endl;

			std::string area_chamas;
			ss >> area_chamas;
			std::cout<<"area em chamas: "<<area_chamas<<std::endl;
		}

		else if (a=="Incendio_Domestico"){
			std::string n_carros;
			ss >> n_carros;
			std::cout<<"Numero de carros de bombeiros: "<<n_carros<<std::endl;

			std::string n_bombeiros;
			ss >> n_bombeiros;
			std::cout<<"Numero de bombeiros: "<<n_bombeiros<<std::endl;

			std::string tipo_casa;
			ss>>tipo_casa;
			std::cout<<"Tipo de casa: "<<tipo_casa<<std::endl;

		}

		else if(a=="Assalto"){
			std::string feridos;
			ss>>feridos;
			if(feridos=="0")
				std::cout<<"Nao existem feridos: "<<std::endl;
			else
				std::cout<<"Existem feridos: "<<std::endl;

			std::string tipo_casa;
			ss>>tipo_casa;
			std::cout<<"Tipo de casa: " << tipo_casa << std::endl;


		}


		else if(a=="AcidenteViacao"){

			std::string n_feridosGraves;
			ss>>n_feridosGraves;
			std::cout<<"Numero de feridos graves: " << n_feridosGraves << std::endl;

			std::string n_veiculos;
			ss>>n_veiculos;
			std::cout<<"Numero de veiculos envolvidos: " << n_veiculos << std::endl;

			std::string tipo_estrada;
			ss>>tipo_estrada;
			std::cout<<"Tipo de estrada: " << tipo_estrada << std::endl;


		}
	}
}

void Menu::printPostos(){

		std::stringstream ss;
	for(unsigned int i = 0; i<postos_socorro.size(); i++){
		ss << postos_socorro.at(i)->getAllInfo();
		std::string n_socorristas;
		ss >> n_socorristas;
		std::cout << "< Numero de socorristas: " << n_socorristas<< std::endl;

		std::string n_veiculos;
		ss >> n_veiculos;
		std::cout << "< Numero de veiculos: " << n_veiculos<< std::endl;

		std::string corX;
		std::string corY;
		ss >> corX;
		ss >> corY;
		std::cout << "<" << "[" << corX<<",";
		std::cout << corY <<"]"<<std::endl;

		std::string TipoPosto;
		TipoPosto = postos_socorro.at(i)->getTipo();

		if(TipoPosto=="Bombeiros"){
			std::string n_ambulancia;
			ss >> n_ambulancia;
			std::cout << "Numero de ambulancias: " << n_ambulancia << std::endl;
			std::string n_autotanques;
			ss >> n_autotanques;
			std::cout << "Numero de autotanques: " << n_autotanques << std::endl;
		}
		else if(TipoPosto=="Policia"){
			std::string veiculo;
			std::cout << "Veiculo: " << veiculo << std::endl;
		}

		else if(TipoPosto=="Inem"){
			std::string Veiculo;
			std::cout << "Veiculo: " << Veiculo << std::endl;
		}

	}
}


void PostoSocorro::printAcidentesAtribuidos(){

		std::stringstream ss;
		for(unsigned int i = 0; i<acidenteAtribuidos.size(); i++){

			std::cout << "<" << acidenteAtribuidos.at(i)->getTipoAcidente()<< std::endl;
			std::cout << "<" << "[" << acidenteAtribuidos.at(i)->getLocal().first<<",";
			std::cout <<acidenteAtribuidos.at(i)->getLocal().second <<"]"<<std::endl;
			(acidenteAtribuidos.at(i)->getData()).printDate();
			std::cout << std::endl;
			std::string a = acidenteAtribuidos.at(i)->getTipoAcidente();

			ss << acidenteAtribuidos.at(i)->getAllInfo();

			if(a=="Incendio_Florestal"){

				std::string n_carros;
				ss >> n_carros;
				std::cout<<"Numero de carros de bombeiros: "<<n_carros<<std::endl;

				std::string n_bombeiros;
				ss >> n_bombeiros;
				std::cout<<"Numero de bombeiros: "<<n_bombeiros<<std::endl;

				std::string area_chamas;
				ss >> area_chamas;
				std::cout<<"area em chamas: "<<area_chamas<<std::endl;
			}

			else if (a=="Incendio_Domestico"){
				std::string n_carros;
				ss >> n_carros;
				std::cout<<"Numero de carros de bombeiros: "<<n_carros<<std::endl;

				std::string n_bombeiros;
				ss >> n_bombeiros;
				std::cout<<"Numero de bombeiros: "<<n_bombeiros<<std::endl;

				std::string tipo_casa;
				ss>>tipo_casa;
				std::cout<<"Tipo de casa: "<<tipo_casa<<std::endl;

			}

			else if(a=="Assalto"){
				std::string feridos;
				ss>>feridos;
				if(feridos=="0")
					std::cout<<"Nao existem feridos: "<<std::endl;
				else
					std::cout<<"Existem feridos: "<<std::endl;

				std::string tipo_casa;
				ss>>tipo_casa;
				std::cout<<"Tipo de casa: " << tipo_casa << std::endl;


			}


			else if(a=="AcidenteViacao"){

				std::string n_feridosGraves;
				ss>>n_feridosGraves;
				std::cout<<"Numero de feridos graves: " << n_feridosGraves << std::endl;

				std::string n_veiculos;
				ss>>n_veiculos;
				std::cout<<"Numero de veiculos envolvidos: " << n_veiculos << std::endl;

				std::string tipo_estrada;
				ss>>tipo_estrada;
				std::cout<<"Tipo de estrada: " << tipo_estrada << std::endl;

			}
		}


}



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
