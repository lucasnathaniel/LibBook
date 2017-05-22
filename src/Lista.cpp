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
/**
  *@brief Busca livro na lista
  */
int Lista::BuscarLivro(string s){
    Livro* percorre = first->getNext();
    for(int i = 1; i < this->quantity && percorre != NULL; i++){
        if(percorre->getTitulo() == s){
            cout << "O livro: \033[38;5;50m" << s << "\033[0m foi achado!" << endl;
            cout << "\033[38;5;66m Título: \033[38;5;94m" << percorre->getTitulo() << endl;
			cout << "\033[38;5;66m Autor: \033[38;5;94m" << percorre->getAutor() << endl;
			cout << "\033[38;5;66m Editora: \033[38;5;94m" << percorre->getEditora() << endl;
			cout << "\033[38;5;66m Ano: \033[38;5;94m" << percorre->getAno() << endl;
            return 1;
        }
        percorre = percorre->getNext();
    }
    return 0;
}
/**
  *@brief Lista os livros que estão na Lista
  */
void Lista::ListarLivros(){
    Livro* percorre = first->getNext();
    cout << "\033[96m";
    for(int i = 1; i < this->quantity && percorre != NULL; i++){
        cout << percorre->getTitulo() << endl;
        percorre = percorre->getNext();
    }
    cout << "\033[0m";
}
/**
  *@brief Lê livros em arquivo e retorna como lista de livros
  */
Lista *LerLivros(){
	Lista *livros = new Lista();
	ifstream livraria("../src/Livros/livros.txt");
	
	if(!livraria){
		cout << "Arquivo não foi aberto" << endl;
	}
	string linha;
	vector<string> v;
	int cont = 0;
	if(livraria.is_open()){
		while(getline(livraria, linha)){
			separar(linha, ' ', v);
			livros->insertEnd(v[0+cont*4], v[1+cont*4], v[2+cont*4], v[3+cont*4]);
			cont+=1;
		}
		livraria.close();
	}
	return livros;
}
/**
  *@brief Separador de string em substrings
  */
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
/**
  *@brief Insere livro no banco de dandos
  */
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
	inserir << ano << endl;
	inserir.close();
}
/**
  *@brief Cria um usuario na pasta /src/Usuarios
  */
bool InserirUsuario(string usuario){

  string endereco = "../src/Usuarios/" + usuario + ".txt";
  ifstream user(endereco);

  if(user.is_open()){
    user.close();
    return false;
  }else{
    string sistema = "touch " + endereco;
    const char * sistema_char = sistema.c_str();
    system(sistema_char);
    user.close();
    return true;
  }
}
/**
  *@brief adiciona livros no banco de dados dos usuarios
  */
bool RealizarEmprestimo(string usuario, Lista* livros){
  string endereco = "../src/Usuarios/" + usuario + ".txt";
  ifstream user(endereco);
  char sim = '1';
  time_t now = time(0);
  tm *ltm = localtime(&now);

  if(user.is_open()){
    string livro;
    while(sim == '1'){
      cout << "Escolha o livro para cadastrar" << endl;
      cin >> livro;
      if(livros->BuscarLivro(livro) == 1){
        
        ofstream inserir(endereco, std::ios::app);
		int dia = ltm->tm_mday;
		int mes = ltm->tm_mon+2; // ajustar o mes
		if(ltm->tm_mon == 1 && ltm->tm_mday > 28){ // se for janeiro dia 29, 30, 31
			switch(ltm->tm_mday){
				case 29:
					dia = 1;
					mes++;
					break;
				case 30:
					dia = 2;
					mes++;
					break;
				case 31:
					dia = 3;
					mes++;
					break;
			}
		}
		if(dia==31 && ltm->tm_mday != 7 && ltm->tm_mday != 1){ // se for 31 e não for julho ou janeiro
			dia = 1;
			mes++;
		}
		if(ltm->tm_mon +1 == 12){ //se for dezembro
        	inserir << livro << ' ' << dia << ' ' << 0 << ' ' << 1901 + ltm->tm_year << endl;
        }else{
        	inserir << livro << ' ' << dia << ' ' <<  mes << ' ' << 1900 + ltm->tm_year << endl;
        }
        return true;
      }else{
        cout << "Livro NÃO encontrado!" << endl;
        cout << "Deseja buscar novamente?" << endl;
        cout << "(1)Sim    (2)Não" << endl;
        cin >> sim;
        if(sim == '1'){
          continue;
        }else{
          return false;
        }
      }
    }
  }else{
    cout << "Usuario não encontrado!" << endl;
    return false;
  }
  return false;
}
/**
  *@brief Verifica se o Emprestimo foi realizado
  */
bool VerificarEmprestimo(string usuario){
	
	string endereco = "../src/Usuarios/" + usuario + ".txt";
	ifstream user(endereco);
	
	if(user.is_open()){
		time_t now = time(0);
		tm *ltm = localtime(&now);
		int cont = 0, dia, mes, ano;
		string linha, livro;
		vector<string> v;
		while(getline(user, linha)){
			separar(linha, ' ', v);
			livro = v[0+cont*4];
			dia = stoi(v[1+cont*4]);
			mes = stoi(v[2+cont*4]);
			ano = stoi(v[3+cont*4]);
			cont+=1;
			if(ltm->tm_year + 1900 > ano){
				cout << "O livro \033[96m" << livro << "\033[0m está atrasado, o prazo de devolução dele era: " << dia << '/' << mes << '/' << ano << endl;
				continue;
			}if(ltm->tm_year + 1900 == ano){
				if(ltm->tm_mon + 1> mes){
					cout << "O livro \033[96m" << livro << "\033[0m está atrasado, o prazo de devolução dele era: " << dia << '/' << mes << '/' << ano << endl;
					continue;
				}
				if(ltm->tm_mon +1 == mes){
					if(ltm->tm_mday > dia){
						cout << "O livro \033[96m" << livro << "\033[0m está atrasado, o prazo de devolução dele era: " << dia << '/' << mes << '/' << ano << endl;
						continue;
					}
				}
			}
			cout << "O livro \033[96m" << livro << "\033[0m não está atrasado" << endl;
			}
		user.close();

	}else{
		cout << "Usuario não encontrado!" << endl;
		user.close();
		return false;
	}
	return false;
}