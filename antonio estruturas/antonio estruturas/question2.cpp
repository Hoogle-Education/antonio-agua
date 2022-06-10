#include <queue>
#include <iostream>

using namespace std;

template <typename T>
class Pilha
{
private:
  queue <T>* fila1;
  queue <T>* fila2;
public:
  Pilha();
  ~Pilha();
  void empilha(T elemento);
  void desempilha();
  T topo();
};

template <typename T>
Pilha<T>::Pilha()
{
  fila1 = new queue<T>();
  fila2 = new queue<T>();
}

template <typename T>
Pilha<T>::~Pilha()
{
}

template<typename T>
void Pilha<T>::empilha(T elemento) {
  fila1->push(elemento);
}

template<typename T>
void Pilha<T>::desempilha()
{

  int cont = 1, max = fila1->size();

  // passo todos exceto o ultimo par a fila 2
  while (not fila1->empty()) {
    
    // se ainda nao contei o maximo passo pra 2
    if(cont++ != max) fila2->push(fila1->front());

    // sempre tiro todos
    fila1->pop();
  }

  // trago todos de volta para a fila 1
  while (not fila2->empty()) {
    fila1->push(fila2->front());
    fila2->pop();
  }

}

template<typename T>
T Pilha<T>::topo()
{
  int cont = 1, max = fila1->size(),
      topo = fila1->front();

  while (not fila1->empty()) {

    // se contei ate o ultimo, o ultimo eh
    // o topo
    if (cont++ == max) topo = fila1->front();
      
    // passo todos
    fila2->push(fila1->front());
    fila1->pop();
  }

  // volto com todos
  while (not fila2->empty()) {
    fila1->push(fila2->front());
    fila2->pop();
  }

  return topo;
}

//int main(void) {
//
//  Pilha<char>* pilha = new Pilha<char>();
//
//  pilha->empilha('a');
//  pilha->empilha('b');
//  pilha->empilha('c');
//
//  cout << pilha->topo() << endl;
//
//  pilha->desempilha();
//
//  cout << pilha->topo() << endl;
//
//  return 0;
//}