
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


// funcao auxiliar recursiva para apresentar chamando por no
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

// funcao auxiliar recursiva para apresentar chamando por no
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

// funcao auxiliar recursiva para apresentar chamando por no
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

// funcao auxiliar recursiva calcular a soma
// e acrescentar o valor com a soma das subarvores
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

// funcao auxiliar para encontrar
// o no que guarda o valor passado
No* Arvore::busca(int valor) {

	if (raiz == NULL) return NULL;

	No* no = NULL;
	No* atual = raiz;

	// faço uma pesquisa binária na árvore
	// tentando encontrar este valor
	while (no == NULL && atual != NULL) {
		if (valor > atual->valor) 
			atual = atual->dir;
		else if (valor < atual->valor) 
			atual = atual->esq;
		else 
			no = atual;
	}

	// retorno o valor encontrado
	return no;
}

// ----------------------------------------------

int Arvore::altura(int valor) {

	// chamo a função altura para no deste valor
	return altura( busca(valor) );

}

// funcao auxiliar recursiva para calcular a altura
// a partir dos nos da subarvore
int Arvore::altura(No* no) {

	if (no == NULL) return 0;

	// a altura é 1 do atual
	// somado com a maior subarvore possivel entre os filhos
	return 1 + max(altura(no->esq), altura(no->dir));

}

// ----------------------------------------------


int Arvore::fator_balanceamento(int valor) {

	// encontro o no correspondente ao valor que sera buscado
	No* no = busca(valor);


	// o fator de balanceamento é a diferença entre as alturas 
	// da esquerda e da direita
	return altura(no->esq) - altura(no->dir);

}

// ----------------------------------------------

// Algoritmo de BFS	
void Arvore::apresentaNiveis() {

	// filas de dados a serem processados
	queue<No*> *principal = new queue<No*>();
	queue<No*> *espera = new queue<No*>();

	// incluo o raiz na fila principal
	principal->push(raiz);

	// pego a altura total da arvore
	int altura_arvore = altura(raiz);

	while (not principal->empty()) {

		// apresento a altura de cima pra baixo
		cout << "Altura #" << altura_arvore << " : ";

		while (not principal->empty()) { // enquanto a principal tiver no
			No* frente = principal->front(); // pego a frente da fila principal
			cout << frente->valor << " "; // apresento seu valor

			// vejo se tem filhos para colocar em espera
			// se tiver eu coloco na fila de espera
			if (frente->esq != NULL) espera->push(frente->esq); 
			if (frente->dir != NULL) espera->push(frente->dir);

			// elimino o no ja apresentado
			principal->pop();
		}

		cout << endl;

		// enquanto a fila de espera estiver cheia
		// e a principal vazia
		// eh hora de atualizar a fila principal
		while (not espera->empty()) {
			principal->push(espera->front()); // adiciono na principal
			espera->pop(); // tiro da fila de espera
		}

	}

}

// ----------------------------------------------

int Arvore::produtoNos() {

	if (raiz == NULL) return -1; // arvore vazia
	else return produtoNos(raiz);

}

// funcao auxiliar recursiva para calcular o produto
// a partir dos subprodutos das subarvores
int Arvore::produtoNos(No* no) {

	// elemento neutro
	if (no == NULL) return 1;

	// retorno o valor multiplicado pelo produto das subarvores
	return no->valor * produtoNos(no->esq) * produtoNos(no->dir);

}

// ----------------------------------------------