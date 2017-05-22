/**
  *@file Livro.h
  *@class Livro
  *@brief Arquivo com as declaracoes das funcoes da classe Livro
  */

#ifndef __LIVRO_H__
#define __LIVRO_H__

using namespace std;
#include <iostream>
#include <string>


class Livro{
	private:
		string m_titulo, m_autor, m_editora;
		string m_ano;
		Livro* next;

	public:
		Livro();
		Livro(string titulo, string autor, string editora, string ano);
		~Livro();
		string getTitulo();
		void setTitulo(string titulo);
		string getAutor();
		void setAutor(string autor);
		string getEditora();
		void setEditora(string editora);
		string getAno();
		void setAno(string ano);
		Livro* getNext();
		void setNext(Livro* book);

};
void Interface();

#endif