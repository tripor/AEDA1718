#include "Header.h"
#include "Acidente.h"
#include "PostoSocorro.h"
#include "Menu.h"

using namespace std;

int main()
{
	cout << endl << "Bem vindo ao gestor de recursos da Protecao Civil!" << endl;

	// Funcao que abrem os ficheiros de Acidentes e Postos de Socorro

	Menu e1;

	cout << endl << "Prima 'Enter' para seguir para o menu inicial... " << endl;
	cin.get();
	cin.get();

	while (true)
	{
		e1.menuOpcoesIniciais();
	}

	return 0;
}


