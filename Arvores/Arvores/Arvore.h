
// ----------------------------------------------
#pragma once

#include <iostream>
#include <string>
#include <stack>

// ----------------------------------------------

using std::stack;
using std::string;
using std::cout;
using std::endl;

// ----------------------------------------------

class No {
public:
	int valor;
	No* esq;
	No* dir;

	No(int valor) {
		this->valor = valor;
		dir = NULL;
		esq = NULL;
	}
};

// ----------------------------------------------

class Arvore {
private:
	No* raiz;
	void apresenta_emOrdem(No* no);
public:
	Arvore() { raiz = NULL; }
	void adiciona(int valor);
	void apresenta_emOrdem();
};