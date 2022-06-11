
// ----------------------------------------------

#include "Arvore.h"

// ----------------------------------------------

void Arvore::adiciona(int valor) {

	if (raiz == NULL) {
		raiz = new No(valor);
		return;
	}

	// No temporario para percorrer a árvore
	No* atual = raiz;

	// explorando o local vazio correto na árvore
	while (true) {

		if (valor > atual->valor and atual->dir == NULL) {
			atual->dir = new No(valor);
			break;
		}

		if (valor < atual->valor and atual->esq == NULL) {
			atual->esq = new No(valor);
			break;
		}

		if (valor > atual->valor) 
			atual = atual->dir;
		else 
			atual = atual->esq;
		
	}

	// a arvore acabou de começar

}

// ----------------------------------------------

void Arvore::apresenta_emOrdem() {

	if (raiz == NULL) return;
	else apresenta_emOrdem(raiz);

}

void Arvore::apresenta_emOrdem(No* no) {
	// ESQUERDA - RAIZ - DIREITA

	if (no == NULL) return;

	apresenta_emOrdem(no->esq);

	cout << no->valor << " ";

	apresenta_emOrdem(no->dir);

}

// ----------------------------------------------

void Arvore::apresenta_preOrdem() {

	if (raiz == NULL) return;
	else apresenta_preOrdem(raiz);

}

void Arvore::apresenta_preOrdem(No* no) {
	// RAIZ - ESQUERDA - DIREITA

	if (no == NULL) return;

	cout << no->valor << " ";

	apresenta_preOrdem(no->esq);

	apresenta_preOrdem(no->dir);

}

// ----------------------------------------------

void Arvore::apresenta_posOrdem() {
	if (raiz == NULL) return;
	else apresenta_posOrdem(raiz);

}

void Arvore::apresenta_posOrdem(No* no) {
	// ESQUERDA - DIREITA - RAIZ

	if (no == NULL) return;

	apresenta_posOrdem(no->esq);

	apresenta_posOrdem(no->dir);

	cout << no->valor << " ";

}

// ----------------------------------------------

int Arvore::somaFolha() {
	if (raiz == NULL) return 0;
	else return somaFolha(raiz);
}

int Arvore::somaFolha(No* no) {

	// os filhos das folhas
	// devem ser nulos e retornar zero pra soma
	if (no == NULL) return 0;

	// a soma eh o valor atual
	// coma soma das subArvores desse no atual
	// (recursivo)
	return no->valor 
				 + somaFolha(no->esq) 
				 + somaFolha(no->dir);

}

// ----------------------------------------------

int Arvore::altura(int valor) {

	if (raiz == NULL) return 0;

	No* praCalcular = NULL;
	No* atual = raiz;

	while (praCalcular == NULL) {
		if (valor > atual->valor) atual = atual->dir;
		else if (valor < atual->valor) atual = atual->esq;
		else praCalcular = atual;
	}

	return altura(praCalcular);

}

int Arvore::altura(No* no) {

	if (no == NULL) return 0;

	return 1 + max(altura(no->esq), altura(no->dir));

}

// ----------------------------------------------