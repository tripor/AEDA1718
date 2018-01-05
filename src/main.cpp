#include "Header.h"
#include "Acidente.h"
#include "PostoSocorro.h"
#include "Menu.h"
#include "erros.h"

using namespace std;

int main()
{
	cout << "Bem vindo ao gestor de recursos da Protecao Civil!" << endl;
	Menu e1;
	e1.lerFicheiroAcidente();
	e1.lerFicheiroPostoSocorro();
	e1.lerFicheiroCondutores();
	e1.lerFicheiroOficina();
	e1.ordenaVetorAcidentes();
	e1.lerFicheiroVeiculo();

	while (!e1.getTerminar())
	{
		try{
			e1.menuOpcoesIniciais_0();
		}
		catch(Erro *e)
		{
			cout << e->getInfoErro() << endl;
		}
	}

	e1.ordenaVetorAcidentes();
	e1.EscreveFicheiroAcidente();
	e1.escreverFicheiroPostoSocorro();
	e1.escreveFicheiroCondutores();
	e1.EscreveFicheiroOficina();
	e1.EscreveFicheiroVeiculo();

	return 0;
}




