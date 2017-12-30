#ifndef OFICINA_H_
#define OFICINA_H_
#include "Header.h"

class Oficina;
typedef std::priority_queue<Oficina*> Prior_queu;

class Oficina{

protected:
	std::string nome;
	u_int disponibilidade;
	std::vector<std::string> marcas;
	Data utimaData;
public:
	Oficina(){
		this->disponibilidade = 0;
	};
	std::string getNome();
	u_int getDisponibilidade() const;
	std::vector<std::string> getMarcas() const;
	Data getUltimaData() const;
	void setData(Data data);
	void setNome(std::string nome);
	void setDisponibilidade(u_int disponibilidade);
	void setMarcas(std::vector<std::string> marcas);
	bool operator<(Oficina& of1);
	void lerInfo(std::stringstream &ss);
};






#endif /* OFICINA_H_ */
