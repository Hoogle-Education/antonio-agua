#include <iostream>
#include <stack>
#include <queue>

using namespace std;

template<typename T>
void inverte(stack<T>* p) {

  // uso o problema 3 aqui
  stack<T> *p1 = new stack<T>();
  stack<T> *p2 = new stack<T>();

  // faço duas pilhas terem o
  // comportamento de uma fila
  while (not p->empty()) {
    p1->push(p->top());
    p->pop();
  }

  while (not p1->empty()) {
    p2->push(p1->top());
    p1->pop();
  }

  // e agora faço como se fosse a letra a
  // invertende uma pilha com uma "fila"
  while (not p2->empty()) {
    p->push(p2->top());
      p2->pop();
  }
}

//int main() {
//
//  stack<char>* p = new stack<char>();
//
//  p->push('a');
//  p->push('d');
//
//  inverte(p);
//
//  cout << p->top() << endl;
//
//  return 0;
//}