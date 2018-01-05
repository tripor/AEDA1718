#ifndef SRC_CONDUTOR_H_
#define SRC_CONDUTOR_H_

#include "Header.h"

/**
 * @class Acidente
 * @brief Classe base dos tipos de acidente que o programa consegue gerir
 */
class Condutor{
protected:
	std::string nome; /**<Nome do condutor*/
	Data d_acidente; /**<Data do ultimo acidente do condutor*/
public:
	/**
	 * @brief Construtor da classe Condutor.
	 */
	Condutor(){}

	/**
	 * @brief Construtor com parametros da classe Condutor.
	 */
	Condutor(std::string n, Data d){nome = n; d_acidente = d;}

	/**
	 * @return O valor do nome do condutor
	 */
	std::string getName() const;

	/**
	 * @return O valor do parametro data do condutor
	 */
	Data getData() const;

	/**
	 * @brief  Atribui um nome ao condutor (atraves de uma string)
	 * @param s String com o nome
	 * @return void
	 */
	void setName(std::string s);

	/**
	 * @brief  Atribui uma data ao condutor (atraves de uma data)
	 * @param d Data
	 * @return void
	 */
	void setData(Data d);

	/**
	 * @brief  Atribui uma data ao condutor (atraves de uma string)
	 * @param s Data
	 * @return void
	 */
	void setData(std::string s);


};

typedef std::unordered_set<Condutor> tabH;


struct condutor_Hash
{
	int operator() (const Condutor & cond) const
	{
		return 0;
	}

	bool operator() (const Condutor & c1, const Condutor & c2) const
	{
		return (c1.getName() == c2.getName());
	}
};

typedef std::unordered_set<Condutor, condutor_Hash, condutor_Hash> tabHCondutor;



#endif /* SRC_CONDUTOR_H_ */
