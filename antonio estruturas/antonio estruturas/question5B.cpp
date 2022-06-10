#include <iostream>
#include <queue>
#include <stack>

using std::queue;
using std::stack;
using std::cout;
using std::endl;

template<typename T>
void inverte(queue<T>* fila) {

  queue<T> *fila1 = new queue<T>();
  queue<T> *fila2 = new queue<T>();


  // jogo todos os elementos pra fila1
  while (not fila->empty()) {
    fila1->push(fila->front());
    fila->pop();
  }

  int localFrente = 1;
  
  while (not fila1->empty() or not fila2->empty()) {

    // vou oscilar os elementos entre as filas
    // de transicao
    // se uma das filas tiver apenas um 
    // elemento, este elemento deve ir para
    // fila original
    
    if (localFrente == 1) { // da primeira p/ segunda
      if (fila1->size() == 1) {
        localFrente = 2;
        fila->push(fila1->front());
      }
      else fila2->push(fila1->front());

      fila1->pop();
    } 
    else { // da segunda p/ primeira
      if (fila2->size() == 1) {
        localFrente = 1;
        fila->push(fila2->front());
      } 
      else fila1->push(fila2->front());
    
      fila2->pop();
    }

  }

}

//int main(void) {
//
//  queue<char> *fila = new queue<char>();
//
//  fila->push('a');
//  fila->push('b');
//  fila->push('c');
//
//  inverte(fila);
//
//  while (not fila->empty()) {
//    cout << fila->front() << endl;
//    fila->pop();
//  }
//
//  return 0;
//}