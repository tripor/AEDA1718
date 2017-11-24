#ifndef POSTOSOCORRO_H_
#define POSTOSOCORRO_H_

#include "Header.h"
#include "Acidente.h"

// Classe PostoSocorro e suas derivadas

/**
	 * @class PostoSocorro
	 * @brief Classe base dos diferentes tipos de Postos de socorro
	*/
class PostoSocorro {
	u_int numero_Socorristas; /**< Numero de socorristas no posto*/
	u_int numero_Veiculos; /**< Numero de veiculos no posto*/
	std::pair<int, int> local; /**< Par com dois inteiros com as coordenadas x,y num referencial de duas dimensoes*/
	std::vector<Acidente*> acidenteAtribuidos; /**< Vector com acidentes atribuidos ao posto*/
	std::vector<Acidente*> acidenteATratar; /**< Acidentes que estão a ser tratados*/
public:
	//construtores
	/**
	 * @brief Construtor da classe PostoSocorro
	 */
	PostoSocorro() {
		this->numero_Socorristas = 0;
		this->numero_Veiculos = 0;
		this->acidenteATratar.clear();
		this->acidenteAtribuidos.clear();
		std::pair<int, int> temp;
		temp = std::make_pair(0, 0);
		this->local = temp;
	}
	/**
	 * @brief Construtor da classe PostoSocorro
	 */
	PostoSocorro(u_int numero_Socorristas, u_int numero_Veiculos,
			std::pair<int, int> local);
	/**
	 * @brief Destrutor da classe PostoSocorro
	 */
	virtual ~PostoSocorro() {
	}

	//set
	/**
	  * @brief atribui um numero de socorristas ao posto
	  * @param numero_Socorristas Numero de socorristas
	  * @return void
	*/
	void setSocorristas(u_int numero_Socorristas);
	/**
	  * @brief atribui um numero de veículos ao posto
	  * @param numero_Veiculos Numero de veiculos
	  * @return void
	*/
	void setVeiculos(u_int numero_Veiculos);
	/**
	  * @brief atribui uma posição no referêncial a este posto
	  * @param local local do acidente representado por um par de inteiros([x,y])
	  * @return void
	*/
	void setPosicao(std::pair<int, int> local);
	/**
	* @brief atribui um novo vetor de acidentes a tratar
	* @param novo vetor de acidentes
	*/
	void setAcidentesTratar(std::vector<Acidente*> v1);
	/**
	* @brief atribui um novo vetor de acidentes atribuidos
	* @param novo vetor de acidentes
	*/
	void setAcidentesAtribuidos(std::vector<Acidente*> v1);
	/**
	* @brief limpa o vetor de acidentes atribuidos ao posto
	*/
	void clearAcidentesAtribuidos(){this->acidenteAtribuidos.clear();}
	/**
	* @brief limpa o vetor de acidentes a tratar do posto
	*/
	void clearAcidentesATratar(){this->acidenteATratar.clear();}

	//get

	/**
	* @return retorna o numero de socorristas do posto
	*/
	u_int getSocorristas();
	/**
	* @return retorna o numero de veículos presentes no posto
	*/
	u_int getVeiculos();
	/**
	* @return retorna um par de inteiros com as coordenadas x,y do posto no referencial
	*/
	std::pair<int, int> getPos();
	/**
	 * @brief Mostra os acidentes atribuidos a um determinado posto
	* @return void
	*/
	void printAcidentesAtribuidos();
	/**
	* @return retorna o vetor de acidentes a tratar do posto
	*/
	std::vector<Acidente*> getAcidentesTratar(){return this->acidenteATratar;}
	/**
	* @return retorna o vetor de acidentes atribuidos ao posto
	*/
	std::vector<Acidente*> getAcidentesAtribuidos(){return this->acidenteAtribuidos;}


	//outros metodos
	/**
	  * @brief Compara dois postos de socorro
	  * @param p Objeto da classe posto de socorro
	  * @return retorna true se o primeiro posto estiver mais próximo do local do acidente que o segundo, caso contrário retorna false.
	*/
	bool operator<(const PostoSocorro & p) const;
	virtual std::string getTipo()=0;
	virtual std::string getAllInfo()=0;
	virtual std::string getAllInfoFormatoPrint()  = 0;
	virtual void guardarInformacao(std::stringstream &receber)=0;
	virtual void infoUtilizador() = 0;
	virtual void setAllInfo(std::string s) = 0;
	/**
	* @brief pergunta ao utilizador os parâmetros gerais de um posto
	*/
	void infoUtilizadorGeral();
};

/**
* @class Bombeiros
* @brief Classe Derivada da classe PostosSocorro
*/
class Bombeiros: public PostoSocorro {
	u_int numero_Ambulancias;/**< Numero de ambulâncias no posto de bombeiros*/
	u_int numero_Autotanques;/**< Numero de autotanques no posto de bombeiros*/
public:
	//construtor
	/**
	 * @brief Construtor da classe PostoSocorro
	 */
	Bombeiros() :
			PostoSocorro() {
		this->numero_Ambulancias = 0;
		this->numero_Autotanques = 0;
	}
	/**
		 * @brief Contrutor da classe Posto de Bombeiros com parametros especificos
		 * @param numero_Socorristas Numero de socorristas
		 * @param local Coordenadas do posto
		 * @param numero_Ambulancias Numero de ambulancias
		 * @param numero_Autotanques Numero de autotanques
		 */
	Bombeiros(u_int numero_Socorristas, std::pair<int, int> local,
			u_int numero_Ambulancias, u_int numero_Autotanques);
	/**
	* @brief Destrutor da classe PostoSocorro
	*/
	~Bombeiros() {
	}
	;
	//get
	/**
	* @return retorna o numero de ambulâncias no posto de bombeiros
	*/
	u_int getAmbulancias();
	/**
	* @return retorna o numero de autotanques no posto de bombeiros
	*/
	u_int getAutotanques();
	/**
	* @return retorna o tipo do posto
	*/
	std::string getTipo() {
		return "Bombeiros";
	}
	/**
	* @return retorna uma string com a informacao de um posto de Bombeiros
	*/
	std::string getAllInfo();
	/**
	* @return retorna uma string com a informacao de um posto de Bombeiros pronta para ser mostrada em consola
	*/
	std::string getAllInfoFormatoPrint() ;

	void setAllInfo(std::string s){}
	//set
	/**
	 * @param string com a informacao
	 * @brief Guarda num objeto informação de um posto de bombeiros que recebe através de uma stringstream
	 * @return Void
	 */
	void guardarInformacao(std::stringstream &receber);
	/**
	* @brief pergunta ao utilizador os parâmetros especificos de um posto
	*/
	void infoUtilizador();


};

/**
* @class Policia
* @brief Classe Derivada da classe PostosSocorro
*/
class Policia: public PostoSocorro {
	std::string veiculo; /**< String com o tipo de veiculo no posto (do tipo “Moto” ou “Carro”)*/
public:
	//construtor
	/**
	 * @brief Construtor da classe Policia
	 */
	Policia() :
			PostoSocorro() {
		this->veiculo.clear();
	}
	/**
		 * @brief Contrutor da classe Posto de Bombeiros com parametros especificos
		 * @param numero_Socorristas Numero de socorristas
		 * @param numero_Veiculos Numero de veiculos
		 * @param local Coordenadas do posto
		 * @param veiculo string com o tipo de veiculo do posto (“Moto” ou “Carro”)
		 * @return void
		 */
	Policia(u_int numero_Socorristas, u_int numero_Veiculos,
			std::pair<int, int> local, std::string veiculo);
	/**
	* @brief Destrutor da classe Policia
	*/
	~Policia() {
	}
	//get
	/**
	* @return retorna uma string com o tipo de veículo de um determinado posto de polícia(“Moto”, Carro”)
	*/
	std::string getVeiculo();
	/**
	* @return  Retorna uma string com o tipo de Posto - Policia ("Policia")
	*/
	std::string getTipo() {
		return "Policia";
	}
	/**
	* @return retorna uma string com a informação de um posto de Policia
	*/
	std::string getAllInfo();
	/**
	* @return retorna uma string com a informação de um posto de Policia pronta para ser mostrada em consola
	*/
	std::string getAllInfoFormatoPrint() ;
	void setAllInfo(std::string s){}
	//set
	/**
	 * @brief Guarda num objeto informação de um posto de policia que recebe através de uma stringstream
	 * @return Void
	 */
	void guardarInformacao(std::stringstream &receber);
	/**
	* @brief pergunta ao utilizador os parâmetros especificos de um posto
	*/
	void infoUtilizador();

};

/**
* @class Inem
* @brief Classe Derivada da classe PostosSocorro
*/
class Inem: public PostoSocorro {
	std::string veiculo; /**<string com o tipo de veiculo no posto (“Moto”, Carro” ou “Ambulancia”)*/
public:
	//contrutor
	/**
	 * @brief Construtor da classe Inem
	 */
	Inem() :
			PostoSocorro() {
		this->veiculo.clear();
	}
	/**
		 * @brief Construtor da classe Inem com parametros especificos
		 * @param numero_Socorristas Numero de socorristas
		 * @param numero_Veiculos Numero de veiculos
		 * @param local Coordenadas do posto
		 * @param veiculo string com o tipo de veiculo do posto (“Moto”, Carro” ou “Ambulancia”)
		 * @return void
		 */
	Inem(u_int numero_Socorristas, u_int numero_Veiculos,
			std::pair<int, int> local, std::string veiculo);
	/**
	* @brief Destrutor da classe Inem
	*/
	~Inem() {
	}
	//get
	/**
	 * @return retorna uma string com o tipo de veiculo do posto de INEM (“Moto”, Carro” ou “Ambulancia”)
	 */
	std::string getVeiculo();
	/**
	* @return  Retorna uma string com o tipo de Posto - Inem ("Inem")
	*/
	std::string getTipo() {
		return "Inem";
	}
	/**
	* @return retorna uma string com a informação de um posto de Inem
	*/
	std::string getAllInfo();
	/**
	* @return retorna uma string com a informação de um posto de inem pronta para ser mostrada em consola
	*/
	std::string getAllInfoFormatoPrint() ;
	void setAllInfo(std::string s){}
	//set
	/**
	 * @brief Guarda num objeto informação de um posto de Inem que recebe através de uma stringstream
	 * @return Void
	 */
	void guardarInformacao(std::stringstream &receber);
	/**
	* @brief pergunta ao utilizador os parâmetros especificos de um posto
	*/
	void infoUtilizador();

};



#endif /* POSTOSOCORRO_H_ */
