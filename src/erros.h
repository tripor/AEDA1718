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
		info << "(!) O input \""<< escrito << "\" n�o � uma op��o valida (!)";
	}
	std::string getInfoErro() const {
		return info.str();
	}
};

class Nao_existem_acidentes: public Erro {
	std::stringstream info;
public:
	Nao_existem_acidentes() {
		info << "(!) N�o existem acidentes para serem removidos (!)";
	}
	std::string getInfoErro() const {
		return info.str();
	}
};
class Nao_existem_postos: public Erro {
	std::stringstream info;
public:
	Nao_existem_postos() {
		info << "(!) N�o existem postos de socorro para serem removidos (!)";
	}
	std::string getInfoErro() const {
		return info.str();
	}
};

class Nao_existem_acidentes_listar: public Erro {
	std::stringstream info;
public:
	Nao_existem_acidentes_listar() {
		info << "(!) N�o existem acidentes para serem listados (!)";
	}
	std::string getInfoErro() const {
		return info.str();
	}
};
class Nao_existem_postos_listar: public Erro {
	std::stringstream info;
public:
	Nao_existem_postos_listar() {
		info << "(!) N�o existem postos de socorro para serem listados (!)";
	}
	std::string getInfoErro() const {
		return info.str();
	}
};

class Nao_existem_condutores_listar: public Erro {
	std::stringstream info;
public:
	Nao_existem_condutores_listar() {
		info << "(!) N�o existem condutores para serem listados (!)";
	}
	std::string getInfoErro() const {
		return info.str();
	}
};
class Nao_existem_oficinas_listar: public Erro {
	std::stringstream info;
public:
	Nao_existem_oficinas_listar() {
		info << "(!) N�o existem oficinas para serem listadas (!)";
	}
	std::string getInfoErro() const {
		return info.str();
	}
};


class Acidente_Nao_Existente: public Erro {
	std::stringstream info;
public:
	Acidente_Nao_Existente(u_int posicao) {
		info << "(!) N�o existe nenhum acidente na posi��o " << posicao
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
		info << "(!) N�o existe nenhum posto na posi��o " << posicao
				<< " do vetor (!)";
	}
	std::string getInfoErro() const {
		return info.str();
	}
};

class Condutor_Nao_Existente: public Erro {
	std::stringstream info;
public:
	Condutor_Nao_Existente(u_int posicao) {
		info << "(!) N�o existe nenhum Condutor na posi��o " << posicao
				<< " da lista mostrada (!)";
	}
	std::string getInfoErro() const {
		return info.str();
	}
};

class Nao_e_numero: public Erro {
	std::stringstream info;
public:
	Nao_e_numero(std::string numero) {
		info << "(!) N�o foi inserido um n�mero \"" << numero <<"\" (!)";
	}
	std::string getInfoErro() const {
		return info.str();
	}
};

class Numero_negativo: public Erro {
	std::stringstream info;
public:
	Numero_negativo(int numero) {
		info << "(!) Foi inserido um n�mero negativo \"" << numero << "\" (!)";
	}
	std::string getInfoErro() const {
		return info.str();
	}
};

class Numero_Demasiado_Grande: public Erro {
	std::stringstream info;
public:
	Numero_Demasiado_Grande(std::string numero) {
		info << "(!) Foi inserido o n�mero demasiado grande \"" << numero << "\" (!)";
	}
	std::string getInfoErro() const {
		return info.str();
	}
};

class Numero_De_Veiculos: public Erro {
	std::stringstream info;
public:
	Numero_De_Veiculos() {
		info << "(!) O n�mero inserido de veiculos de cada tipo n�o coincide com o n�mero total de veiculos (!)";
	}
	std::string getInfoErro() const {
		return info.str();
	}
};
class Data_Invalida: public Erro {
	std::stringstream info;
public:
	Data_Invalida(int numero,std::string tipo) {
		info << "(!) O/A " << tipo << " inserido n�o � valido \"" << numero << "\" (!)";
	}
	std::string getInfoErro() const {
		return info.str();
	}
};


#endif /* SRC_ERROS_H_ */
