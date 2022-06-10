#include <stack>
#include <iostream>

using namespace std;

template <typename T>
class Fila
{
private:
  stack<T> *pilha1;
  stack<T> *pilha2;
public:
  Fila();
  ~Fila();
  void enfileira(T elemento);
  void desenfileira();
  T frente();
};

template <typename T>
Fila<T>::Fila()
{
  pilha1 = new stack<T>();
  pilha2 = new stack<T>();
}

template <typename T>
Fila<T>::~Fila()
{
}

template<typename T>
void Fila<T>::enfileira(T elemento) {

  // volta todos os elementos da pilha2 para a pilha 1
  while (not pilha2->empty()) {
    T topo = pilha2->top();
    pilha2->pop();
    pilha1->push(topo);
  }
  
  // empilha o novo elemento
  pilha1->push(elemento);

  // desempilha da pilha1 de volta para a pilha 2
	while (not pilha1->empty()) {
    T topo = pilha1->top();
    pilha1->pop();
    pilha2->push(topo);
  }
}

template<typename T>
void Fila<T>::desenfileira()
{
  // transfiro todos para a pilha1
  //  ficando com a ordem inverttida
  while (not pilha2->empty()) {
    T topo = pilha2->top();
    pilha2->pop();
    pilha1->push(topo);
  }

  // removo o topo da pilha(ultimo da fila)
  pilha1->pop();

  // e trago de volta para a pilha2
  while (not pilha1->empty()) {
    T topo = pilha1->top();
    pilha1->pop();
    pilha2->push(topo);
  }
}

template<typename T>
T Fila<T>::frente()
{
  // o topo da pilha2 será o primeiro da fila
  return pilha2->top();
}


//int main() {
//
//  Fila<char> *fila = new Fila<char>();
//
//  fila->enfileira('a');
//  fila->enfileira('b');
//  fila->desenfileira();
//  cout << fila->frente() << endl;
//
//}