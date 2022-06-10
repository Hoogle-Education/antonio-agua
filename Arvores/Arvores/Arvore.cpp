
// ----------------------------------------------

#include "Arvore.h"

// ----------------------------------------------

void Arvore::adiciona(int valor) {
	
	cout << "raiz: " << raiz << " || valor: " << valor << endl;

	if (raiz != NULL) {

		// No temporario para percorrer a árvore
		No* atual = raiz;

		// explorando o local vazio correto na árvore
		while (true) {

			if ( atual->valor < valor ) {
				if (atual->dir == NULL) atual->dir = new No(valor);
				else atual = atual->dir;
			}
			else {
				atual = atual->esq;
				cout << "esquerda" << endl;
			}

			cout << (atual != NULL) ? (atual->valor) : 0;
		}

		// No que percorreu e encontrou
		atual = new No(valor);

	}	else raiz = new No(valor); 
	// a arvore acabou de começar

}

// ----------------------------------------------

// ERD
// RED
//

void Arvore::apresenta_emOrdem() {

	if (raiz == NULL) return;
	else apresenta_emOrdem(raiz);

}

void Arvore::apresenta_emOrdem(No* no) {

	if (no == NULL) return;

	apresenta_emOrdem(no->esq);

	cout << no->valor << " ";

	apresenta_emOrdem(no->dir);

}

// ----------------------------------------------