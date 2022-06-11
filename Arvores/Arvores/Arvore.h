
// ----------------------------------------------
#pragma once

#include <iostream>
#include <algorithm>
#include <string>
#include <stack>

// ----------------------------------------------

using std::stack;
using std::string;
using std::cout;
using std::endl;
using std::max;

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
	int somaFolha(No* no);
	void apresenta_emOrdem(No* no);
	void apresenta_preOrdem(No* no);
	void apresenta_posOrdem(No* no);
	int altura(No* no);
public:
	Arvore() { raiz = NULL; }
	void adiciona(int valor);
	void apresenta_emOrdem();
	void apresenta_preOrdem();
	void apresenta_posOrdem();
	int somaFolha();
	int altura(int valor);
};