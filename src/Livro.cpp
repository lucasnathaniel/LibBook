/**
  *@file Livro.cpp
  *@brief funcao com a implementacao dos nós, 
  */
#include "Livro.h"

Livro::~Livro(){

}

Livro::Livro(string titulo, string autor, string editora, string ano){
	this->setTitulo(titulo);
	this->setAutor(autor);
	this->setEditora(editora);
	this->setAno(ano);
	this->setNext(NULL);
}
Livro::Livro(){
	this->setNext(NULL);
}

string Livro::getTitulo(){
	return m_titulo;
}
void Livro::setTitulo(string titulo){
	this->m_titulo = titulo;
}

string Livro::getAutor(){
	return m_autor;
}
void Livro::setAutor(string autor){
	this->m_autor = autor;
}

string Livro::getEditora(){
	return m_editora;
}
void Livro::setEditora(string editora){
	this->m_editora = editora;
}

string Livro::getAno(){
	return m_ano;
}
void Livro::setAno(string ano){
	this->m_ano = ano;
}

Livro* Livro::getNext(){
    return this->next;
}

void Livro::setNext(Livro* book){
    this->next = book;
}

void Interface(){
	cout << " _     _ _    ______             _           " << endl;
	cout << "| |   (_) |   | ___ \\           | |         " << endl;
	cout << "| |    _| |__ | |_/ / ___   ___ | | __       " << endl;
	cout << "| |   | | '_ \\| ___ \\/ _ \\ / _ \\| |/ /   " << endl;
	cout << "| |___| | |_) | |_/ / (_) | (_) |   <        " << endl;
	cout << "\\_____/_|_.__/\\____/ \\___/ \\___/|_|\\_\\ " << endl;
	cout <<"\nBem-vindo à LibBook, o que você gostaria de fazer?" << endl;
}