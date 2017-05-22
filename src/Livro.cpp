/**
  *@file Livro.cpp
  *@brief funcao com a implementacao dos nós da lista
  */
#include "Livro.h"
/**
  *@brief Destrutor
  */
Livro::~Livro(){

}
/**
  *@brief Construtor com parâmetros
  */
Livro::Livro(string titulo, string autor, string editora, string ano){
	this->setTitulo(titulo);
	this->setAutor(autor);
	this->setEditora(editora);
	this->setAno(ano);
	this->setNext(NULL);
}
/**
  *@brief Construtor sem parâmetros
  */
Livro::Livro(){
	this->setNext(NULL);
}
/**
  *@brief Getter Título
  */
string Livro::getTitulo(){
	return m_titulo;
}
/**
  *@brief Setter Título
  */
void Livro::setTitulo(string titulo){
	this->m_titulo = titulo;
}
/**
  *@brief Getter Autor
  */
string Livro::getAutor(){
	return m_autor;
}
/**
  *@brief Setter Título
  */
void Livro::setAutor(string autor){
	this->m_autor = autor;
}
/**
  *@brief Getter Editora
  */
string Livro::getEditora(){
	return m_editora;
}
/**
  *@brief Setter Editora
  */
void Livro::setEditora(string editora){
	this->m_editora = editora;
}
/**
  *@brief Getter Ano
  */
string Livro::getAno(){
	return m_ano;
}
/**
  *@brief Setter Ano
  */
void Livro::setAno(string ano){
	this->m_ano = ano;
}
/**
  *@brief Getter Next
  */
Livro* Livro::getNext(){
    return this->next;
}
/**
  *@brief Setter Next
  */
void Livro::setNext(Livro* book){
    this->next = book;
}
/**
  *@brief Interface Gráfica
  */
void Interface(){
	cout << "\033[38;5;66m _     _ _    \033[38;5;94m______             _           " << endl;
	cout << "\033[38;5;66m| |   (_) |   \033[38;5;94m| ___ \\   \033[32mLucas \033[38;5;94m  | |         " << endl;
	cout << "\033[38;5;66m| |    _| |__ \033[38;5;94m| |_/ / \033[32mNathaniel\033[38;5;94m | | __       " << endl;
	cout << "\033[38;5;66m| |   | | '_ \\\033[38;5;94m| ___ \\/ _ \\ / _ \\| |/ /   " << endl;
	cout << "\033[38;5;66m| |___| | |_) \033[38;5;94m| |_/ / (_) | (_) |   <        " << endl;
	cout << "\033[38;5;66m\\_____/_|_.__/\033[38;5;94m\\____/ \\___/ \\___/|_|\\_\\ " << endl;
	cout <<"\n\033[96mBem-vindo à LibBook, o que você gostaria de fazer?\033[0m" << endl;
}