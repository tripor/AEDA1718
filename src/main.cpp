/*
 * main.cpp
 *
 *  Created on: 31/10/2017
 *      Author: tripor
 */
#include "Header.h"
#include "Menu.h"
#include <iostream>

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






}


