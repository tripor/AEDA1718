#ifndef SRC_VEICULO_H_
#define SRC_VEICULO_H_

#include "Header.h"

class Veiculo{
private:
	std::string marca;
	int quantidade;
	Data data;
public:
	Veiculo(){}
	Veiculo(std::string marca,int quantidade,Data data){
		this->marca=marca;
		this->quantidade=quantidade;
		this->data=data;
	}
	std::string getMarca() const;
	int getQuantidade() const;
	Data getData() const;
	void incQuant();
	bool operator <(const Veiculo & a) const;
	bool operator ==(const Veiculo & a);
	void operator =(const Veiculo & a);
	void lerInfo(std::stringstream &ss);
};

#endif /* SRC_VEICULO_H_ */
