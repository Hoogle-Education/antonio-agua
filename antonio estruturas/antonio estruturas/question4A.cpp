#include <iostream>
#include <stack>
#include <queue>

using namespace std;

template<typename T>
void inverte(stack<T>* pilha) {

	// apenas tirando os elementos da pilha
	// eles ja irão sair invertidos
	
	queue<T> fila;

	// passo os elementos para a fila
	while (not pilha->empty()) {
		fila.push(pilha->top());
		pilha->pop();
	}

	// retorno eles invertidos para a pilha
	while (not fila.empty()) {
		pilha->push(fila.front());
		fila.pop();
	}

}

//int main() {
//
//	stack<char> pilha;
//
//	pilha.push('a');
//	pilha.push('b');
//	pilha.push('c');
//	pilha.push('d');
//
//	inverte(&pilha);
//
//	cout << pilha.top() << endl;
//
//	return 0;
//}