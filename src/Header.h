#ifndef HEADER_H_
#define HEADER_H_

#include <string>
#include <vector>
#include <utility>
#include <iostream>
#include <fstream>
#include <sstream>
#include "math.h"
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <unordered_set>
#include <set>
#include <time.h>

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
		this->ano=ano;
		this->mes=mes;
		this->dia=dia;
		this->hora=hora;
		this->minuto=minuto;
		if (minuto >= 60) {
			this->hora += minuto / 60;
			this->minuto = minuto % 60;
		}
		if (hora >= 24) {
			this->dia += hora / 24;
			this->hora = hora % 24;
		}
		if (dia >= 32) {
			this->mes += dia / 31;
			this->dia = dia % 30;
		}
		if (mes >= 13) {
			this->ano += mes / 13;
			this->mes = mes % 12;
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

	void setDia(u_int dia){
		this->dia = dia;
	}

	std::string getDataString(){
		std::stringstream devolver;
		devolver << ano << "-" << mes << "-" << dia << "-" << hora << "-" << minuto;
		return devolver.str();
	}

	Data operator +(const Data & a) {
		return Data(this->ano + a.ano, this->mes + a.mes, this->dia + a.dia,
				this->hora + a.hora, this->minuto + a.minuto);
	}

	int operator -(const Data & a){
		Data temp (this->ano, this->mes, this->dia, this->hora, this->minuto);
		Data temp1 = a;

		struct tm data1, data2;

		data1.tm_year = temp.ano;
		data1.tm_mon = temp.mes;
		data1.tm_mday = temp.dia;
		data1.tm_hour = temp.hora;
		data1.tm_min = temp.minuto;
		data1.tm_sec = 0;

		data2.tm_year = temp1.ano;
		data2.tm_mon = temp1.mes;
		data2.tm_mday = temp1.dia;
		data2.tm_hour = temp1.hora;
		data2.tm_min = temp1.minuto;
		data2.tm_sec = 0;

		double seconds = difftime(mktime(&data2),mktime(&data1));

		int dias = (seconds/86400);

		return dias;
	}


	bool operator ==(const Data & a) {
		return (this->ano == a.ano && this->mes == a.mes && this->dia == a.dia
				&& this->hora == a.hora && this->minuto == a.minuto);
	}
	bool operator <(const Data & a) const {
		if(this->ano < a.ano){
			return true;
		}
		else if (this->ano == a.ano && this->mes < a.mes){
			return true;
		}
		else if (this->ano == a.ano && this->mes == a.mes && this->dia < a.dia){
			return true;
		}
		else if (this->ano == a.ano && this->mes == a.mes && this->dia == a.dia && this->hora < a.hora){
			return true;
		}
		else if (this->ano == a.ano && this->mes == a.mes && this->dia == a.dia && this->hora == a.hora && this->minuto < a.minuto){
			return true;
		}
		return false;
	}

	friend std::ostream & operator<<(std::ostream & o, const Data & data) {
		o << data.ano << "-" << data.mes << "-" << data.dia << "-" << data.hora
				<< "-" << data.minuto;
		return o;
	}
	std::string getDataFormato(){
		std::stringstream ss;
		ss << ano << "-" << mes << "-" << dia << " " << hora << ":" << minuto;
		return ss.str();
	}

};



u_int nCarrosBombeirosArea(u_int a);

u_int nBombeirosArea(u_int a);

u_int numeroCarBombeirosApart();

u_int numeroBombeirosApart();

u_int numeroCarBombeirosMoradia();

u_int numeroBombeirosMoradia();

#endif /* HEADER_H_ */
