#ifndef ACIDENTE_H_
#define ACIDENTE_H_

#include "Header.h"

// Classe Acidente e suas derivadas

/**
 * @class Acidente
 * @brief Classe base dos tipos de acidente que o programa consegue gerir
 */
class Acidente{
protected:
	Data data; /**<Objeto da classe data com a data do acidente*/ // Formato YYYY-MM-DD-HH-MM
	std::pair<int,int> local; /**<coordenadas do local do acidente([x,y])*/ // Sistema de coordenadas (x,y)
public:
	//Construtores e destrutor
	/**
	 * @brief Construtor da classe Acidente.
	 */
	Acidente(){this->data = Data();this->local=std::make_pair(0,0);}

	/**
	 * @brief Constroi um acidente com parametros especificos
	 * @param d Data
	 * @param local Local
	 */
	Acidente(Data d, std::pair<int,int> local){this->data=d;this->local=local;}

	/**
	 * @brief Destrutor da classe Acidente.
	 */
	virtual ~Acidente(){};


	//Metodos Get

	/**
	 * @return  Retorna a data do acidente (objeto da classe data)
	 */
	Data getData() const;


	/**
	 * @return Devolve o local de um acidente (par de inteiros (x,y))
	 */
	std::pair<int,int> getLocal() const;

	//Metodos Set
	/**
	 * @brief Atribui um data ao acidente
	 * @param d Data
	 * @return void
	 */
	void setData(Data d);

	/**
	 * @brief  Atribui uma data ao acidente (atraves de uma string)
	 * @param d String com a data
	 * @return void
	 */
	void setData(std::string d);

	/**
	 * @brief Atribui um local ao acidente (atraves de um par de inteiros)
	 * @param par Par de inteiros com o local do acidente
	 * @return void
	 */
	void setLocal(std::pair<int,int> par);

	//Metodos Virtuais
	virtual void lerInfo(std::stringstream &ss) = 0;
	virtual std::string getTipoAcidente() const = 0;
	virtual std::string getAllInfo() const = 0;
	virtual std::string getAllInfoFormatoPrint() const = 0;

	/**
	 * @brief  Pede ao utilizador os valores dos parametros gerais de cada acidente
	 * @return void
	 */
	virtual void infoUtilizador() = 0;

	//Outros
	/**
	 * @brief Compara dois acidentes
	 * @param a1 Apontador para um acidente
	 * @return True se o acidente que recebe como parametro for igual ao acidente.
	 */
	bool acidenteIgual(Acidente* a1) const;
	//bool operator== (const Acidente & a) const;

	/**
	 * @brief  Operador menor- Ordena os acidentes por dada
	 * @return True se o acidente que recebe como parametro possui data mais recente
	 */
	bool operator< (const Acidente & aci) const;

	/**
	 * @brief  Pergunta ao utilizador os parametros gerais de um acidente
	 * @return void
	 */
	void infoUtilizadorGeral();

};


/**
 * @class Incendios
 * @brief Classe derivada da classe acidente (Incendios)
*/
class Incendios : public virtual Acidente{
protected:
	u_int numero_CarrosBombeiros; /**<numero de carros de bombeiros envolvidos no incendio*/
	u_int numero_Bombeiros; /**< numero de bombeiros envolvidos no incendio*/
public:

	//Construtores e destrutor
	/**
	 * @brief Construtor da classe Incendios
	 */
	Incendios():Acidente(){this->numero_Bombeiros=0;this->numero_CarrosBombeiros=0;};

	/**
	 * @brief Construtor com parametro a especificar: numero de carros, numero de bombeiros, data e local
	 * @param n_carros numero de carros
	 * @param n_bombeiros numero de bombeiros
	 * @param local par de inteiros com a localizacao do incendio
	 * @param d Obejto da classe Data com a data do incendio
	*/
	Incendios(u_int n_carros, u_int n_bombeiros, Data d, std::pair<int,int> local): Acidente(d, local){
		this->numero_CarrosBombeiros = n_carros;
		this->numero_Bombeiros = n_bombeiros;
	}
	/**
	 * @brief Destrutor da classe Incendios
	 */
	~Incendios(){};
	//Metodos Get
	/**
	* @return retorna o numero de carros de bombeiros envolvidos no incendio
	*/
	u_int getNumeroCarrosBombeiros() const;


	/**
	* @return retorna o numero de bombeiros envolvidos no incendio
	*/
	u_int getNumeroBombeiros() const;
	//Metodos Set

	/**
	    * @brief atribui um numero de carros de bombeiros ao incendio.
	    * @param n numero de carros de bombeiros
	    * @return void
		*/
	void setNumeroCarrosBombeiros(u_int n);

	/**
	    * @brief atribui um numero de bombeiros ao incendio
	    * @param n numero de bombeiros
	    * @return void
		*/
	void setNumeroBombeiros(u_int n);
	//Outros Metodos*/


	void lerInfo(std::stringstream ss);
	std::string getTipoAcidente() const{return  " ";}
	std::string getAllInfo() const{return " ";}
	std::string getAllInfoFormatoPrint() const{return " ";}
	void infoUtilizador(){};

};

/**
	 * @class Florestal
	 * @brief Classe derivada da classe acidente (Incendios)
	*/
class Florestal : public Incendios{
	u_int area_Chamas; /**<parâmetro com a area do incendio*/
public:

	//Construtores e destrutor
	/**
	 * @brief Construtor da classe Florestal
	 */
	Florestal():Incendios(){this->area_Chamas=0;}

	/**
	 * @brief Destrutor da classe Florestal
	 */
	~Florestal(){};
	//Metodos Get

	/**
	* @return retorna a area do incendio
	*/
	u_int getAreaChamas() const;
	//Metodos Set

	/**
	    * @brief atribui uma área para as chamas do incendio florestal
	    * @param area area das chamas
	    * @return void
		*/
	void setAreaChamas(u_int area);
	//Outros Metodos

	/**
	    * @brief recebe uma stringstream por referência e cria um objeto da classe respectiva (Florestal) com os parametros da stringstream que foi lida do ficheiro de acidentes.
	    * @param ss stringstream com a informacao do incendio florestal obtida do ficheiro
	    * @return void
		*/
	void lerInfo(std::stringstream &ss);

	/**
	 * @return  retorna um string que caracteriza o respetivo acidente(Florestal)
	*/
	std::string getTipoAcidente() const {return "Florestal";}

	/**
	 * @return  retorna uma string com a informacao do incendio florestal
	*/
	std::string getAllInfo() const;

	/**
	 * @return  retorna uma string com a informacao do incendio florestal para ser mostrada na consola
	*/
	std::string getAllInfoFormatoPrint() const;

	/**
	 * @return  Pergunta ao utilizador os parametros especificos de um acidente
	*/
	void infoUtilizador();


};

/**
	 * @class Domesticos
	 * @brief Classe derivada da classe acidente (Incendios)
	*/
class Domesticos : public Incendios{
	std::string tipo_casa; /**< parametro com o tipo de casa (Apartamento ou moradia)*/
public:
	//Construtores e destrutor
	/**
	 * @brief Construtor da classe Domesticos
	 */
	Domesticos():Incendios(){this->tipo_casa=" ";}

	/**
	 * @brief Destrutor da classe Domesticos
	 */
	~Domesticos(){};
	//Metodos Get

	/**
	* @return retorna o tipo de casa onde ocorreu o incendio (Apartamento ou Moradia)
	*/
	std::string getTipoCasa() const;
	//Metodos Set

	/**
	  * @brief atribui um tipo de casa onde ocorreu o acidente
	  * @param s com o tipo de casa (Apartamento ou Moradia)
	  * @return void
	*/
	void setTipoCasa(std::string s);
	//Outros Metodos

	/**
	    * @brief recebe uma stringstream por referência e cria um objeto da classe respectiva (Incendio Domestico) com os parametros da stringstream que foi lida do ficheiro de acidentes.
	    * @param ss stringstream com a informacao do incendio domestico obtida do ficheiro
	    * @return void
		*/
	void lerInfo(std::stringstream &ss);

	/**
	 * @return  retorna um string que caracteriza o respetivo acidente(Domestico)
	*/
	std::string getTipoAcidente() const{return "Domestico";}

	/**
	 * @return  retorna uma string com a informacao do incendio domestico
	*/
	std::string getAllInfo() const;

	/**
	 * @return  retorna uma string com a informacao do incendio domestico pronta a imprimir
	*/
	std::string getAllInfoFormatoPrint() const;

	/**
	 * @return  questiona ao utilizador dos valores especificos o acidente
	*/
	void infoUtilizador();

};

/**
 * @class Assaltos
 * @brief Classe derivada da classe acidente (Assaltos)
*/
class Assalto : public Acidente{
	bool existe_Feridos; /**< True caso existam e false caso nao existam feridos no assalto*/
	std::string tipo_casa; /**< String com o tipo de casa onde ocorreu o assalto (particular ou comercial)*/
public:
	//Construtores e destrutor
	/**
	 * @brief Construtor da classe Assalto
	 */
	Assalto():Acidente(){this->existe_Feridos=false;this->tipo_casa=" ";}

	/**
	 * @brief Destrutor da classe Assalto
	 */
	virtual ~Assalto(){}

	//Metodos Get

	/**
    * @brief Verifica se existem ou nao feridos no acidente
    * @return retorna o valor da booleana existe_Feridos
	*/
	bool getExisteFeridos() const;

	/**
    * @return Retorna a string tipo_casa  (particular ou comercial)
	*/
	std::string getTipoCasa() const;

	//Metodos Set
	/**
    * @brief modifica a booleana existe_feridos (true caso existam feridos)
    * @param n variavel booleana
    * @return void
	*/
	void setExisteFeridos(bool n);

	/**
    * @brief atribui um tipo_casa ao assalto
    * @param s string com o tipo de casa
    * @return void
	*/
	void setTipoCasa(std::string s);

	//Outros Metodos

	/**
    * @brief recebe uma stringstream por referencia e cria um objeto da classe respectiva (Assalto) com os parametros da stringstream que foi lida do ficheiro de acidentes.
    * @param ss stringstream com a informacao do assalto
    * @return void
	*/
	void lerInfo(std::stringstream &ss);

	/**
    * @return retorna uma string que caracteriza um assalto (Assalto)
	*/
	std::string getTipoAcidente() const{return "Assalto";}

	/**
    * @return retorna uma string com a informacao do assalto
	*/
	std::string getAllInfo() const;

	/**
    * @return retorna uma string com a informacao do assalto pronta para ser impressa em ecra
	*/
	std::string getAllInfoFormatoPrint() const;

	/**
    * @brief Questiona o utilizador acerca dos valores dos parametros do assalto
    * @return void
	*/
	void infoUtilizador();

};


/**
 * @class AcidenteViacao
 * @brief Classe derivada da classe acidente (AcidenteViacao)
*/
class AcidenteViacao : public Acidente{
	u_int numero_FeridosGraves; /**< Numero de feridos graves no acidente*/
	std::vector<std::string> veiculosEnvolvidos; /**< Tipo de veiculos envolvidos*/
	u_int numero_VeiculosEnvolvidos; /**< Numero de veiculos envolvidos no acidente*/
	std::string tipo_Estrada; /**< String com o tipo de estrada do acidente de viação (Nacional ou Auto-Estrada)*/ // "Nacional" ou "Auto-Estrada"
public:
	//Construtores e destrutor

	/**
	 * @brief Construtor da classe AcidenteViacao
	 */
	AcidenteViacao():Acidente(){this->numero_FeridosGraves=0;this->numero_VeiculosEnvolvidos=0;this->tipo_Estrada=" ";}

	/**
	 * @brief Destrutor da classe AcidenteViacao
	 */
	virtual ~AcidenteViacao(){}
	//Metodos Get

	/**
	 * @return Retorna o numero de feridos graves
	 */
	u_int getNumeroFeridosGraves() const;

	/**
	 * @return Retorna o numero de feridos envolvidos
	 */
	u_int getNumeroVeiculosEnvolvidos() const;


	std::vector<std::string> getVeiculosEnvolvidos();

	/**
	 * @return Retorna uma string com o tipo de estrada do acidente de viacao(nacional ou autoestrata)
	 */
	std::string getTipoEstrada() const;

	//Metodos Set

	/**
	 * @brief  Atribui um valor de feridos graves
	 * @param n Numero de feridos graves
	 * @return void
	 */
	void setNumeroFeridosGraves(u_int n);

	void setVeiculosEnvolvidos(std::vector<std::string> veiculosEnvolvidos);

	/**
	 * @brief  Atribui um numero de veiculos envolvidos
	 * @param n Numero de veiculos envolvidos
	 * @return void
	 */
	void setNumeroVeiculosEnvolvidos(u_int n);

	/**
	 * @brief  Atribui um tipo de estrada ao um acidente
	 * @param s string com o tipo de estrada
	 * @return void
	 */
	void setTipoEstrada(std::string s);

	/**
	 * @brief  ecebe uma stringstream por referência e cria um objeto da classe respectiva (AcidenteViacao) com os parametros da stringstream que foi lida do ficheiro de acidentes.
	 * @param ss stringstream com a informação de um acidente de viacao
	 * @return void
	 */
	void lerInfo(std::stringstream &ss);

	/**
	* @brief retorna uma string que caracteriza um acidente de viacao (AcidenteViacao)
    * @return void
	*/
	std::string getTipoAcidente() const{return "AcidenteViacao";}

	/**
    * @return retorna uma string com a informacao completa do acidente de viacao
	*/
	std::string getAllInfo() const;


	/**
    * @return retorna uma string com a informação completa do acidente de viacao pronta para imprimir na consola
	*/;
	std::string getAllInfoFormatoPrint() const;

	/**
    * @brief Questiona o utilizador acerca dos valores dos parametros do acidente de viacao
    * @return void
	*/
	void infoUtilizador();

};


#endif /* ACIDENTE_H_ */
