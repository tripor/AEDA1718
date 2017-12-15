#ifndef OFICINA_H_
#define OFICINA_H_
#include "Header.h"

class Oficina{

protected:
	u_int disponibilidade;
	std::vector<std::string> veiculos;
public:
	Oficina();
	u_int getDisponibilidade();
	std::vector<std::string> getVeiculos();
	void setDisponibilidade(u_int disponibilidade);
	bool operator<(Oficina& of1)const;
};

typedef std::priority_queue<Oficina> oficinas;


#endif /* OFICINA_H_ */
