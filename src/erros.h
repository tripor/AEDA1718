#ifndef SRC_ERROS_H_
#define SRC_ERROS_H_

#include "Header.h"

class Erro {
public:
	Erro(){}
	virtual ~Erro() {}
	virtual std::string getInfoErro() const = 0;
};

class Tamanho_Input_Invalido : public Erro{
	std::stringstream info;
public:
	Tamanho_Input_Invalido(int tamanho){
		info <<"(!) Quantidade invalida de caracteres inseridos (" << tamanho << ") (!)";
	}
	std::string getInfoErro() const{
		return info.str();
	}
};

class Opcao_Nao_Valida: public Erro {
	std::stringstream info;
public:
	Opcao_Nao_Valida(std::string escrito) {
		info << "(!) O input \""<< escrito << "\" não é uma opção valida (!)";
	}
	std::string getInfoErro() const {
		return info.str();
	}
};

class Nao_existem_acidentes: public Erro {
	std::stringstream info;
public:
	Nao_existem_acidentes() {
		info << "(!) Não existem acidentes para serem removidos (!)";
	}
	std::string getInfoErro() const {
		return info.str();
	}
};
class Nao_existem_postos: public Erro {
	std::stringstream info;
public:
	Nao_existem_postos() {
		info << "(!) Não existem postos de socorro para serem removidos (!)";
	}
	std::string getInfoErro() const {
		return info.str();
	}
};

class Acidente_Nao_Existente: public Erro {
	std::stringstream info;
public:
	Acidente_Nao_Existente(u_int posicao) {
		info << "(!) Não existe nenhum acidente na posição " << posicao
				<< " do vetor (!)";
	}
	std::string getInfoErro() const {
		return info.str();
	}
};
class Posto_Nao_Existente: public Erro {
	std::stringstream info;
public:
	Posto_Nao_Existente(u_int posicao) {
		info << "(!) Não existe nenhum posto na posição " << posicao
				<< " do vetor (!)";
	}
	std::string getInfoErro() const {
		return info.str();
	}
};

class Nao_e_numero: public Erro {
	std::stringstream info;
public:
	Nao_e_numero(std::string numero) {
		info << "(!) Não foi inserido um número \"" << numero <<"\" (!)";
	}
	std::string getInfoErro() const {
		return info.str();
	}
};

class Numero_negativo: public Erro {
	std::stringstream info;
public:
	Numero_negativo(int numero) {
		info << "(!) Foi inserido o número negativo \"" << numero << "\" (!)";
	}
	std::string getInfoErro() const {
		return info.str();
	}
};


#endif /* SRC_ERROS_H_ */
