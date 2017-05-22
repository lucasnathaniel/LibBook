/**
  *@title LibBook
  *@file main.cpp
  *@version 1.7
  *@date 11/05/2017
  *@author Lucas Nathaniel
  *@brief principal funcao do programa
  *@section LICENSE
  *
  * This program is free software; you can redistribute it and/or
  * modify it under the terms of the GNU General Public License as
  * published by the Free Software Foundation; either version 2 of
  * the License, or (at your option) any later version.
  * 
  * This program is distributed in the hope that it will be useful, but
  * WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
  * General Public License for more details at
  * http://www.gnu.org/copyleft/gpl.html
  *
  */

#include "main.h"

using namespace std;
int main(){

	char entrada;
	char entrada_c;
	string livro, usuario;
	while(1){
		system("clear");
		Interface();
   		time_t now = time(0);
   		tm *ltm = localtime(&now);
   		cout << "Hoje é: " << ltm->tm_mday << '/' << 1 + ltm->tm_mon << '/' << 1900 + ltm->tm_year<<endl;
   		cout << endl;

   		cout << "\033[91mObs: Os espaços entre palavras devem ser '_'!\033[0m\n" << endl;

		Lista *livros = LerLivros();
		cout << "(0) Listar Livros" << endl;
		cout << "(1) Buscar livro" << endl;
		cout << "(2) Realizar emprestimo" << endl;
		cout << "(3) Visualizar emprestimos atrasados" << endl;
		cout << "(4) Inserir usuario" << endl;
		cout << "(5) Inserir Livro" << endl;
		cout << "(6) Sair" << endl;
		cin >> entrada;
		switch(entrada){
			case '1':
				cout << "Digite o nome do livro para buscar" << endl;
				cin >> livro;
				if(!livros->BuscarLivro(livro)){
					cout << "O livro " << livro << " não foi achado!" << endl;
				}
				cout << "\033[0mPressiona uma tecla para prosseguir" << endl;
				cin >> entrada_c;
				break;
			case '2':
				cout << "Digite seu nome" << endl;
				cin >> usuario;
				if(RealizarEmprestimo(usuario, livros)){
					cout << "Emprestimo realizado com sucesso!" << endl;
				}else{
					cout << "Falha em realizar emprestimo!" << endl;
				}

				cout << "Pressiona uma tecla para prosseguir" << endl;
				cin >> entrada_c;
				break;
			case '3':
				cout << "Digite seu nome" << endl;
				cin >> usuario;
				if(VerificarEmprestimo(usuario)){
					cout << "Nenhum emprestimo atrasado" << endl;
				}
				cout << "Pressiona uma tecla para prosseguir" << endl;
				cin >> entrada_c;
				break;
			case '4':
				cout << "Digite seu nome" << endl;
				cin >> usuario;
				if(InserirUsuario(usuario)){
					cout << "Usuario inserido com sucesso!" << endl;
				}else{
					cout << "Usuario ja existe!" << endl;
				}

				cout << "Pressiona uma tecla para prosseguir" << endl;
				cin >> entrada_c;
				break;
			case '5':
				InserirLivro();
				cout << "Pressiona uma tecla para prosseguir" << endl;
				cin >> entrada_c;
				break;
			case '0':
				livros->ListarLivros();
				cout << "\nPressiona uma tecla para prosseguir" << endl;
				cin >> entrada_c;				
				break;
			case '6':
				

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