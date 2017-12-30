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
