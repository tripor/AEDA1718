#ifndef MENU_H
#define MENU_H

#include "Header.h"
#include "Oficina.h"
#include "Acidente.h"
#include "PostoSocorro.h"
#include "Condutor.h"
#include "Veiculo.h"
#include "BST.h"

void eNumero(std::string testar);

class Menu{
	Prior_queu oficinas;
	std::vector<Acidente*> acidentes; /**< Vetor de acidentes*/
	std::vector<PostoSocorro*> postos_socorro; /**< Vetor dos postos de socorro*/
	tabHCondutor condutores;
	set<Veiculo> veiculos;
	bool terminar; /**< booleana para parar o ciclo do menu*/
public:
	//Construtores
	/**
	* @brief  Construtor da classe menu
	* @return void
	 */
	Menu();


	//Get methods
	/**
	* @return  Retorna a boleana que permite terminar o programa
	 */
	bool getTerminar() const;

	/**
	* @return  Retorna o vetor de acidentes
	*/
	std::vector<Acidente*> getAcidentes();

	/**
	* @return  Retorna o vetor de postos de socorro
	 */
	std::vector<PostoSocorro*> getPostosSocorro();


	//Operacoes com ficheiros
	//std::ofstream & create_ficheiro_acidente();

	/**
	* @brief  Verifica se existe e e possivel aceder ao ficheiro de acidentes
	* @return true caso exista
	 */
	bool existe_ficheiro_acidentes() const;

	/**
	* @brief  Le o ficheiro de Acidentes e escreve os acidentes no vetor de acidentes
	* @return void
	 */
	void lerFicheiroAcidente();

	 /**
	* @brief  Escreve no ficheiro de acidentes os acidentes presentes no vetor dos mesmos
	* @return void
	 */
	void EscreveFicheiroAcidente();

	/**
	* @brief  Le o ficheiro de postos de socorro e adiciona os postos ao vetor de postos de socorro
	* @return void
	 */
	void lerFicheiroPostoSocorro();

	/**
	* @brief  Escreve no ficheiro de postos de socorro os postos presentes no vetor dos mesmos
	* @return void
	 */
	void escreverFicheiroPostoSocorro();

	/**
	* @brief  Le o ficheiro de condutores e adiciona os postos ao vetor de condutores
	* @return void
	 */
	void lerFicheiroCondutores();

	/**
	* @brief  Escreve no ficheiro de condutores os postos presentes no vetor dos mesmos
	* @return void
	 */
	void escreveFicheiroCondutores();

	//Operacoes com os vetores
	/**
		 * @brief Verifica se existe o presente acidente no vetor de acidentes
		 * @param aci Acidente a verificar
		 * @return true caso exista
	 */
	bool AcidenteExistente(Acidente* aci) const;
	// falta bool PostoSocorroExsitente(PostoSocorro *posto)

	/**
	* @brief Adiciona um acidente ao vetor de acidentes
	* @param acidente Acidente a adicionar
	* @return void
	 */
	void adicionaAcidente(Acidente *acidente);

	/**
	* @brief Adiciona um posto de socorro ao vetor de postos de socorro
	* @param posto Posto de socorro a adicionar
	* @return void
	 */
	void adicionaPostosSocorro(PostoSocorro *posto);

	/**
	* @brief   Remove os acidentes especificados pelo utilizador do vetor de acidentes
	* @param posicao Posicao do acidente a remover
	* @return void
	 */
	void retirarAcidente(u_int posicao);

	/**
	* @brief   Remove os postos especificados pelo utilizador do vetor de postos
	* @param posicao Posicao do posto de socorro a remover
	* @return void
	 */
	void retirarPosto(u_int posicao);

	/**
	* @brief  Limpa os vetores dos postos para evitar repeticoes de cada posto
	* @return void
	 */
	void clearVetoresDosPostos();

	//ATRIBUICAO DE ACIDENTES
	/**
	* @brief Ordena o vetor de acidentes por data
	Verifica que tipo de postos e que o acidente vai necessitar de chamar
	Cria um vetor para cada tipo necessario
	Ordena cada vetor em funcao da distancia ao acidente
	Verifica se, na data do acidente nao existem ja acidentes liberados do vetor (a tratar)
	Verifica cada elemento desse vetor a ver qual e o primeiro que possui os recursos para tratar o acidente
	Adiciona o acidente ao vetor de acidentes por tratar (somando o tempo) e atribuidos
	* @return void
	 */
	void atribuiAcidentes();

	//Ordenar vetores
	/**
	* @brief  Ordena um vetor de acidentes consoante
	* @return void
	 */
	void ordenaVetorAcidentes();

	/**
	* @brief  Ordena um vetor de postos de socorro consoante a sua distancia ao acidente considerado
	* @param v1 vetor com os postos de socorro
	* @return void
	 */
	void ordenaVetorPostosSocorro(std::vector<PostoSocorro*> &v1);

	//Varios menus
	/**
	* @brief  Menu com as opcoes iniciais do programa
	* @return void
	 */
	void menuOpcoesIniciais_0();

	/**
	* @brief  Menu com as opcoes especificas da classe acidente
	* @return void
	 */
	void menuOpcoesAcidente_1();

	/**
	* @brief  Menu com as opcoes especificas da classe de postos de socorro
	* @return void
	 */
	void menuOpcoesPostosSocorro_1();

	/**
	* @brief  Menu com as opcoes especificas da classe Condutor
	* @return void
	 */
	void menuOpcoesCondutores_1();

	/**
	* @brief  Menu com as opcoes especificas da classe Oficina
	* @return void
	 */
	void menuOpcoesOficinas_1();

	/**
	* @brief  Menu com as opcoes especificas da classe Veiculos
	* @return void
	*/
	void menuOpcoesVeiculo_1();

	//Funcoes menu acidente
	/**
	* @brief  Permite ao utilizador criar um acidente
	* @return void
	 */
	void criarAcidente();

	/**
	* @brief   Pergunta ao utilizador o acidente a remover
	* @return void
	 */
	void removerAcidente();

	/**
	* @brief   Pergunta ao utilizador o posto a criar
	* @return void
	 */
	void criarPosto();

	/**
	* @brief   Remove um determinado numero de postos de socorro a especificar pelo utilizador
	* @return void
	 */
	void removerPosto();

	/**
	* @brief   Pergunta ao utilizador o condutor a criar
	* @return void
	 */
	void criarCondutor();

	/**
	* @brief  Imprime os acidentes alocados a um posto
	* @return void
	 */
	void printAcidentesAlocados();

	/**
	* @brief Imprime os postos aos quais foram alocados o acidente
	* @return void
	 */
	void printPostosComAcidenteAlocado();

	//Funcoes print dos vetores
	/**
	* @brief   Funcao para mostrar ao utilizador os acidentes considerados
	* @return void
	 */
	void printAcidentes();

	/**
	* @brief   Funcao para mostrar ao utilizador os postos de socorro considerados
	* @return void
	 */
	void printPostos();

	//Outros

	/**
	 * @brief  Atualiza a disponibilidade da oficina
	 * @param data data do ultimo acdente de viacao
	 * @return void
	 */
	void atualizaDisponibilidade(Data date);

	/**
	 * @brief  "Reinicia" os valores temporarios das oficinas
	 * @return void
	 */
	void inicializaOficinas();

	/**
	 * @brief  Adiciona uma oficina
	 * @param  Oficina a adicionar
	 * @return void
	 */
	void adicionaOficina(Oficina oficina);

	/**
	 * @brief  Ler o ficheiro e atualizar a priority queue
	 * @return void
	 */
	void lerFicheiroOficina();

	/**
	 * @brief  Escreve no ficheiro os valores na priority queue "oficinas"
	 * @return void
	 */
	void EscreveFicheiroOficina();

	/**
	 * @brief  Criar uma oficina, e pergunta ao utilizador os valores
	 * @return void
	 */
	void criarOficina();

	/**
	 * @brief  Lista as oficinas com o nome que pergunta ao utilizador
	 * @return void
	 */
	void verOficina();

	/**
	 * @brief  Lista as oficinas que reparam a marca indicada pelo utilizador
	 * @return void
	 */
	void verOficinaMarcas();

	/**
	 * @brief  Lista todas as oficinas
	 * @return void
	 */
	void printOficinas();

	//unordered set


	/**
	 * @brief  Adiciona um condutor
	 * @param  Condutor a adicionar
	 * @return void
	 */
	void adiciona_condutor(Condutor c1);

	/**
	 * @brief  Retira um condutor
	 * @param  Posicao da lista do condutor a retirar
	 * @return void
	 */
	void retirarCondutor(u_int posicao);

	/**
	 * @brief  Retira todos os condutor cujo ultima ocorrência foi há mais de 5 anos
	 * @return void
	 */
	void remover_condutores_antigos();

	/**
	 * @brief  Imprime todos os condutores
	 * @return void
	 */
	void printCondutores();

	/**
	 * @brief  Remove o condutor indicado pelo utilizador
	 * @return void
	 */
	void removerCondutor();

	//BST

	/**
	 * @brief  Adiciona um veiculo
	 * @param  Veiculo a adicionar
	 * @return void
	 */
	void adicionaVeiculo(Veiculo *por);

	/**
	 * @brief  Cria um veiculo
	 * @return void
	 */
	void criarVeiculo();

	/**
	 * @brief  Remove um veiculo
	 * @return void
	 */
	void removerVeiculo();

	/**
	 * @brief  Lista todos os veiculos
	 * @return void
	 */
	void printVeiculo();

	/**
	 * @brief  Le o ficheiro de veiculos
	 * @return void
	 */
	void lerFicheiroVeiculo();

	/**
	 * @brief  Escreve no ficheiro de veiculos
	 * @return void
	 */
	void EscreveFicheiroVeiculo();

};
/**
 * @brief Ordenar a impressao dos veiculos por tipo
 * @param Acidente 1 a comparar
 * @param Acidente 2 a comparar
 * @return boleano correspondente a comparacao
 */
bool porTipo(Acidente *a1, Acidente *a2);
/**
 * @brief Ordenar a impressao dos veiculos pelo local X
 * @param Acidente 1 a comparar
 * @param Acidente 2 a comparar
 * @return boleano correspondente a comparacao
 */
bool porLocalX(Acidente *a1, Acidente *a2);
/**
 * @brief Ordenar a impressao dos veiculos pelo local Y
 * @param Acidente 1 a comparar
 * @param Acidente 2 a comparar
 * @return boleano correspondente a comparacao
 */
bool porLocalY(Acidente *a1, Acidente *a2);
/**
 * @brief Ordenar a impressao dos veiculos pela data
 * @param Acidente 1 a comparar
 * @param Acidente 2 a comparar
 * @return boleano correspondente a comparacao
 */
bool porData(Acidente *a1, Acidente *a2);
/**
 * @brief Ordenar a impressao dos postos de socorro pelo tipo
 * @param Posto de socorro 1 a comparar
 * @param Posto de socorro 2 a comparar
 * @return boleano correspondente a comparacao
 */
bool porTipoPosto(PostoSocorro *a1, PostoSocorro *a2);
/**
 * @brief Ordenar a impressao dos postos de socorro pelo numero de socorristas
 * @param Posto de socorro 1 a comparar
 * @param Posto de socorro 2 a comparar
 * @return boleano correspondente a comparacao
 */
bool porNumeroSocPosto(PostoSocorro *a1, PostoSocorro *a2);
/**
 * @brief Ordenar a impressao dos postos de socorro pelo numero de veiculos
 * @param Posto de socorro 1 a comparar
 * @param Posto de socorro 2 a comparar
 * @return boleano correspondente a comparacao
 */
bool porNumeroVeiPosto(PostoSocorro *a1, PostoSocorro *a2);
/**
 * @brief Ordenar a impressao dos postos de socorro pelo local X
 * @param Posto de socorro 1 a comparar
 * @param Posto de socorro 2 a comparar
 * @return boleano correspondente a comparacao
 */
bool porLocalXPosto(PostoSocorro *a1, PostoSocorro *a2);
/**
 * @brief Ordenar a impressao dos postos de socorro pelo local Y
 * @param Posto de socorro 1 a comparar
 * @param Posto de socorro 2 a comparar
 * @return boleano correspondente a comparacao
 */
bool porLocalYPosto(PostoSocorro *a1, PostoSocorro *a2);
#endif /* MENU_H_ */
