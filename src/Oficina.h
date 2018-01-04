#ifndef OFICINA_H_
#define OFICINA_H_
#include "Header.h"

class Oficina;
typedef std::priority_queue<Oficina*> Prior_queu;

/**
 * @class Oficina)
*/
class Oficina{

protected:
	std::string nome; /**< Nome que identifica a oficina*/
	u_int disponibilidade; /**< Numero de dias ate que a oficina esteja livre*/
	std::vector<std::string> marcas; /**< Vetor com as marcas de automoveis que a oficina repara*/
	Data utimaData; /**< Data do ultimo acidente de viacao*/
public:
	/**
	 * @brief Construtor da classe Oficina
	 */
	Oficina(){
		this->disponibilidade = 0;
	};

	/**
	 * @return Retorna uma string com o nome da Oficina
	 */
	std::string getNome();

	/**
	 * @return Retorna a disponibilidade da oficina
	 */
	u_int getDisponibilidade() const;

	/**
	 * @return Retorna um vetor com as marcas que automoveis que a oficina repara
	 */
	std::vector<std::string> getMarcas() const;

	/**
	 * @return Retorna a data do ultimo acidente de viacao
	 */
	Data getUltimaData() const;

	/**
	 * @brief  Atribui uma data a oficina
	 * @param data Data do ultimo acidente de viacao
	 * @return void
	 */
	void setData(Data data);

	/**
	 * @brief  Atribui uma nome a oficina
	 * @param nome Nome da Oficina
	 * @return void
	 */
	void setNome(std::string nome);

	/**
	 * @brief  Atribui um valor de disponibilidade a oficina
	 * @param disponibilidade disponibilidade da oficina
	 * @return void
	 */
	void setDisponibilidade(u_int disponibilidade);

	/**
	 * @brief  Atribui um marcas de automoveis a oficina (que podem ser reparados nesta)
	 * @param marcas vetor com as marcas de automoveis
	 * @return void
	 */
	void setMarcas(std::vector<std::string> marcas);

	/**
	 * @brief  Operador menor
	 * @param of1 objeto da classe oficina
	 * @return true caso a disponibilidade da primeira oficina seja menor que a da segunda
	 */
	bool operator<(Oficina& of1);

	/**
	 * @brief  Cria um objeto da classe oficina atraves das informacoes que receb
	 * @param ss stringstream com as informacoes da oficina
	 * @return void
	 */
	void lerInfo(std::stringstream &ss);
};






#endif /* OFICINA_H_ */
