/**
  *@title LibBook
  *@file main.cpp
  *@version 1.0
  *@date 11/05/2017
  *@author Lucas Nathaniel
  *@brief principal funcao do programa
  *
  */

#include "main.h"

using namespace std;

int main(){

	int entrada;
	char entrada_c;
	while(1){
		system("clear");
		Interface();
		cout << "(1) Buscar livro" << endl;
		cout << "(2) Realizar emprestimo" << endl;
		cout << "(3) Visualizar emprestimos atrasados" << endl;
		cout << "(4) Inserir usuario" << endl;
		cout << "(5) Inserir Livro" << endl;
		cout << "(6) Sair" << endl;
		cin >> entrada;
		Lista *livros = LerLivros();
		switch(entrada){
			case 1:
				

				cout << "Pressiona uma tecla para prosseguir" << endl;
				cin >> entrada_c;
				break;
			case 2:
				

				cout << "Pressiona uma tecla para prosseguir" << endl;
				cin >> entrada_c;
				break;
			case 3:
				

				cout << "Pressiona uma tecla para prosseguir" << endl;
				cin >> entrada_c;
				break;
			case 4:
				

				cout << "Pressiona uma tecla para prosseguir" << endl;
				cin >> entrada_c;
				break;
			case 5:
				InserirLivro();

				cout << "Pressiona uma tecla para prosseguir" << endl;
				cin >> entrada_c;
				break;
			case 6:
				

				cout << "Volte sempre!" << endl;
				return 0;
			default:
				cout << "Dígito incorreto" << endl;
				cout << "Pressiona uma tecla para prosseguir" << endl;
				cin >> entrada_c;
				break;
		}
	}

	return 0;
}