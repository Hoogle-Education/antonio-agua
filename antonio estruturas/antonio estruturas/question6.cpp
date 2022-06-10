#include <iostream>
#include <stack>

using namespace std;

class PilhaMin {
private:
	stack<int>* pilha;
	int menorElemento;
public:
	PilhaMin();
	~PilhaMin();
	void empilha(int elemento);
	void desempilha();
	int topo();
	int obterMinimo() { return menorElemento; }
};

PilhaMin::PilhaMin() {
	pilha = new stack<int>();
}

PilhaMin::~PilhaMin() {
}

void PilhaMin::empilha(int elemento) {

	// se a pilha estiver vazia
	if (pilha->empty()) menorElemento = elemento;

	// operador ternário
	pilha->push((elemento < menorElemento) ?
					2 * elemento - menorElemento : elemento);
	// decido se inserir um valor atualizado para 
	// o menor elemento

	menorElemento = (elemento < menorElemento) ? 
		elemento : menorElemento;
	// atualizo o valor de menor elemento se inseri diferente

}

int PilhaMin::topo() {

	int topo = pilha->top();

	if (topo <= menorElemento) {
		int menorAnterior = 2 * menorElemento - topo;
		// descubro o menor elemento anterior
		// pois o elemento original é dependente do 
		// menor elemento anterior

		// calculo o menor elemento anterior
		return (topo + menorAnterior) / 2;
	}
	else {

		// caso não seja um elemento modificado
		// apenas retorno o proprio topo
		return pilha->top();
	}

}

void PilhaMin::desempilha() {

	int topo = pilha->top();

	// se o topo foi um menor elemento modificado
	// preciso atualizar o valor do menor elemento
	// para o menor elemento anterior
	if ( topo <= menorElemento ) 
		menorElemento = 2 * menorElemento - topo;
	
	pilha->pop();

}


//int main(void) {
//
//	PilhaMin* pilha = new PilhaMin();
//
//	pilha->empilha(5); // 2 5
//	pilha->empilha(3); // 1 3 
//	pilha->empilha(8); // 8
//	pilha->empilha(4); // 8
//	pilha->empilha(6); // 8
//	pilha->empilha(2); // 8
//	pilha->empilha(3); // 8
//	pilha->empilha(10); // 8
//	pilha->empilha(1); // 8
//	pilha->empilha(2); // 8
//
//	cout << pilha->topo() << endl;
//	cout << pilha->obterMinimo() << endl;
//	pilha->desempilha();
//	pilha->desempilha();
//	cout << pilha->topo() << endl;
//	cout << pilha->obterMinimo() << endl;
//
//	return 0;
//}