#ifndef SRC_CONDUTOR_H_
#define SRC_CONDUTOR_H_

#include "Header.h"


class Condutor{
protected:
	std::string nome;
	Data d_acidente;
public:
	Condutor(){}
	Condutor(std::string n, Data d){nome = n; d_acidente = d;}
	std::string getName() const;
	Data getData() const;
	void setName(std::string s);
	void setData(Data d);
	void setData(std::string s);


};





#endif /* SRC_CONDUTOR_H_ */
