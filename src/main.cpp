#include "Header.h"
#include "Acidente.h"
#include "PostoSocorro.h"
#include "Menu.h"

using namespace std;

int main()
{
	cout << "Bem vindo ao gestor de recursos da Protecao Civil!" << endl;
	Menu e1;
	e1.lerFicheiroAcidente();
	e1.lerFicheiroPostoSocorro();

	while (!e1.getTerminar())
	{
		e1.menuOpcoesIniciais_0();
	}
	return 0;
}




