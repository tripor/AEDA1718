#ifndef SRC_VEICULO_H_
#define SRC_VEICULO_H_

#include "Header.h"

/**
 * @class Acidente
 * @brief Classe base dos tipos de acidente que o programa consegue gerir
 */
class Veiculo{
private:
	std::string marca; /**<Marca do condutor*/
	int quantidade; /**<Quantidade de ocorrência do condutor*/
	Data data; /**<Data da última ocorrência do condutor*/
public:

	/**
	 * @brief Construtor da classe Condutor.
	 */
	Veiculo(){}

	/**
	 * @brief Construtor com parametros da classe Condutor.
	 */
	Veiculo(std::string marca,int quantidade,Data data){
		this->marca=marca;
		this->quantidade=quantidade;
		this->data=data;
	}

	/**
	 * @return Parametro "marca" do veiculo
	 */
	std::string getMarca() const;

	/**
	 * @return Parametro "quantidade" do veiculo
	 */
	int getQuantidade() const;

	/**
	 * @return Parametro "data" do veiculo
	 */
	Data getData() const;

	/**
	 * @brief Incrementa a quantidade por 1
	 */
	void incQuant();

	/**
	 * @brief Operador < para a classe Veiculo
	 */
	bool operator <(const Veiculo & a) const;

	/**
	 * @brief Operador == para a classe Veiculo
	 */
	bool operator ==(const Veiculo & a);

	/**
	 * @brief Operador = para a classe Veiculo
	 */
	void operator =(const Veiculo & a);

	/**
	 * @brief le a info na stringstream e guarda
	 */
	void lerInfo(std::stringstream &ss);
};

#endif /* SRC_VEICULO_H_ */
