#ifndef ACIDENTE_H_
#define ACIDENTE_H_

#include "Header.h"

// Classe Acidente e suas derivadas

class Acidente{
	std::string data; // Formato YYYY-MM-DD
	std::pair<int,int> local; // Sistema de coordenadas (x,y)
public:
	//Methods
	//...

};

class Incendios : public Acidente{
	u_int numero_CarrosBombeiros;
	u_int numero_Bombeiros;
public:
	//Methods
	//...

};

class Florestal : public Incendios{
	u_int area_Chamas;
public:
	//Methods
	//...

};

class Domesticos : public Incendios{
	std::string tipo_casa; // "Apartamento" ou "Moradia"
public:
	//Methods
	//...

};


class Assalto : public Acidente{
	bool existe_Feridos;
	std::string tipo_casa; // "Particular" ou "Comercial"
public:
	//Methods
	//...

};

class Acidente_Viacao : public Acidente{
	u_int numero_FeridosGraves;
	u_int numero_VeiculosEnvolvidos;
	std::string tipo_Estrada; // "Nacional" ou "Auto-Estrada"
public:
	//Methods
	//...

};





#endif /* ACIDENTE_H_ */
