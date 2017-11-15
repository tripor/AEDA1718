#ifndef HEADER_H_
#define HEADER_H_

#include <string>
#include <vector>
#include <utility>
#include <iostream>
#include <fstream>
#include <sstream>
#include "math.h"
#include <stdlib.h>

typedef unsigned int u_int;

#ifdef _WIN32
#include <windows.h>
#define Chars() SetConsoleCP(1252); SetConsoleOutputCP(1252);
#else
#define Chars() void;
#endif

#ifdef _WIN32
#define ClearScreen() system("CLS");
#else
#define ClearScreen() system("Clear");
#endif

extern int x_aci;
extern int y_aci;

class Data{
private:
	u_int ano;
	u_int mes;
	u_int dia;
	u_int hora;
	u_int minuto;
public:
	Data() {
		this->ano = 0;
		this->mes = 0;
		this->dia = 0;
		this->hora = 0;
		this->minuto = 0;
	}
	Data(u_int ano, u_int mes, u_int dia, u_int hora, u_int minuto) {
		if (minuto >= 60) {
			this->hora = minuto / 60;
			this->minuto = minuto % 60;
		}
		if (hora >= 24) {
			this->dia = hora / 24;
			this->hora = hora % 24;
		}
		if (dia >= 32) {
			this->mes = dia / 31;
			this->dia = dia % 31;
		}
		if (mes >= 13) {
			this->ano = mes / 13;
			this->mes = mes % 13;
		}
	}

	u_int getAno() {
		return ano;
	}
	u_int getMes() {
		return mes;
	}
	u_int getDia() {
		return dia;
	}
	u_int getHora() {
		return hora;
	}
	u_int getMinuto() {
		return minuto;
	}

	Data operator +(const Data & a) {
		return Data(this->ano + a.ano, this->mes + a.mes, this->dia + a.dia,
				this->hora + a.hora, this->minuto + a.minuto);
	}
	bool operator ==(const Data & a) {
		return (this->ano == a.ano && this->mes == a.mes && this->dia == a.dia
				&& this->hora == a.hora && this->minuto == a.minuto);
	}
	friend std::ostream & operator<<(std::ostream & o, const Data & data) {
		o << data.ano << "-" << data.mes << "-" << data.dia << "-" << data.hora
				<< "-" << data.minuto;
		return o;
	}

};

u_int nCarrosBombeirosArea(u_int a);

u_int nBombeirosArea(u_int a);

#endif /* HEADER_H_ */
