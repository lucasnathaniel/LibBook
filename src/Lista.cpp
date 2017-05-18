/**
  *@file Lista.cpp
  *@brief Arquivo com a implementação da lista
  *
  */

#include "Lista.h"
#include "Livro.h"
/**
  *@brief Construtor
  */
Lista::Lista(){
    first = NULL;
    this->quantity = 0;
}
/**
  *@brief Destrutor
  */
Lista::~Lista(){

}
/**
  *@brief retorna o primeiro elemento
  */
Livro* Lista::getFirst(){
	return first;
}
/**
  *@brief insere um elemento no comeco da lista
  */
void Lista::insertBegin(string titulo, string autor, string editora, string ano){
    Livro* novo = new Livro(titulo, autor, editora, ano);
    novo->setNext(first);
    first = novo;
    this->quantity++;
}
/**
  *@brief insere um elemento no final da lista
  */
void Lista::insertEnd(string titulo, string autor, string editora, string ano){
    
    if(first == NULL){
		insertBegin(titulo, autor, editora, ano);
		return;
	}
    
    Livro* novo = new Livro(titulo, autor, editora, ano);
    Livro* percorre = first;
    
    while(percorre->getNext() != NULL){
    	percorre = percorre->getNext();
    }
    percorre->setNext(novo);
    this->quantity++;
}

Lista *LerLivros(){
	Lista *livros = new Lista();
	ifstream livraria("../src/Livros/livros.txt");
	
	if(!livraria){
		cout << "Arquivo não foi aberto" << endl;
	}
	string linha;
	vector<string> v;
	
	if(livraria.is_open()){
		while(getline(livraria, linha)){
			separar(linha, ' ', v);
			livros->insertEnd(v[0], v[1], v[2], v[3]);
		}
		livraria.close();
	}
	return livros;
}

void separar(string& str, char delim, vector<string>& pedacos) {
    string::size_type i = 0;
    string::size_type j = str.find(delim);

    while (j != string::npos) {
        pedacos.push_back(str.substr(i, j - i));
        i = ++j;
        j = str.find(delim, j);

        if (j == string::npos)
            pedacos.push_back(str.substr(i, str.length()));
    }
}

void InserirLivro(){

	ofstream inserir("../src/Livros/livros.txt", std::ios::app);
	string linha, titulo, autor, editora, ano;

	cout << "Digite o titulo do livro" << endl;
	cin >> titulo;
	inserir << titulo << ' ';
	cout << "Digite o autor do livro" << endl;
	cin >> autor;
	inserir << autor << ' ';
	cout << "Digite a editora do livro" << endl;
	cin >> editora;
	inserir << editora << ' ';
	cout << "Digite o ano do livro" << endl;
	cin >> ano;
	inserir << titulo << endl;
	inserir.close();
}