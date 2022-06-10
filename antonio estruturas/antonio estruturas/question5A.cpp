#include <iostream>
#include <queue>
#include <stack>

using std::queue;
using std::stack;
using std::cout;
using std::endl;

void inverte(queue<char> *f) {

  // para inverter
  // jogo todos na pilha e tiro
  // saem invertidos

  stack<char> *p = new stack<char>();

  // coloco na pilha
  while (not f->empty()) {
    p->push(f->front());
    f->pop();
  }

  // retorno para fila
  while (not p->empty()) {
    f->push(p->top());
    p->pop();
  }

}

//int main(void) {
//
//  queue<char>* fila = new queue<char>();
//
//  fila->push('a');
//  fila->push('b');
//  fila->push('c');
//  fila->push('d');
//  fila->push('e');
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