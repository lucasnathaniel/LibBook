/**
  *@file Lista.h
  *@class Lista 
  *@brief Arquivo com as declaracoes das funcoes da Lista
  */

#ifndef __LISTA_H__
#define __LISTA_H__

#include <iostream>
#include <fstream>
#include "Livro.h"
#include <string>
#include <vector>

using namespace std;

class Lista{
	private:
		int quantity;
		Livro* first;
	public:
		Lista();
    	~Lista();
    	Livro* getFirst();
    	void insertBegin(string titulo, string autor, string editora, string ano);
    	void insertEnd(string titulo, string autor, string editora, string ano);
    	int BuscarLivro(string s);
    	void ListarLivros();
};

Lista *LerLivros();
void separar(string& str, char delim, vector<string>& pedacos);
void InserirLivro();
bool InserirUsuario(string usuario);
bool RealizarEmprestimo(string usuario, Lista* livros);
bool VerificarEmprestimo(string usuario);

#endif