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
	string livro, usuario;
	while(1){
		system("clear");
		Interface();
   		time_t now = time(0);
   		tm *ltm = localtime(&now);
   		cout << "Hoje é: " << ltm->tm_mday << '/' << 1 + ltm->tm_mon << '/' << 1900 + ltm->tm_year<<endl;
   		cout << endl;

		Lista *livros = LerLivros();
		cout << "(1) Buscar livro" << endl;
		cout << "(2) Realizar emprestimo" << endl;
		cout << "(3) Visualizar emprestimos atrasados" << endl;
		cout << "(4) Inserir usuario" << endl;
		cout << "(5) Inserir Livro" << endl;
		cout << "(6) Sair" << endl;
		cin >> entrada;
		switch(entrada){
			case 1:
				cout << "Digite o nome do livro para buscar" << endl;
				cin >> livro;
				if(livros->BuscarLivro(livro)){
					cout << "O livro " << livro << " foi achado!" << endl;
				}else{
					cout << "O livro " << livro << " não foi achado!" << endl;
				}
				cout << "Pressiona uma tecla para prosseguir" << endl;
				cin >> entrada_c;
				break;
			case 2:
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
			case 3:
				cout << "Digite seu nome" << endl;
				cin >> usuario;

				cout << "Pressiona uma tecla para prosseguir" << endl;
				cin >> entrada_c;
				break;
			case 4:
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