#ifndef OFICINA_H_
#define OFICINA_H_
#include "Header.h"

class Oficina;
typedef std::priority_queue<Oficina> Prior_queu;

class Oficina{

protected:
	u_int disponibilidade;
	std::vector<std::string> marcas;
public:
	Oficina();
	u_int getDisponibilidade();
	std::vector<std::string> getMarcas();
	void setDisponibilidade(u_int disponibilidade);
	bool operator<(Oficina& of1);
};

Prior_queu oficinas;





#endif /* OFICINA_H_ */
