#include <iostream>
#include <stack>
#include <queue>

using namespace std;

template<typename T>
void inverte(stack<T>* p) {


   stack <char> *p1 = new stack<T>();

  // cont sera o contador de quando é o momento
  // do auxiliar entrar na pilha original
  for (int cont = p->size() - 1; cont >= 0; cont--) {
    
    // auxiliar guarda o termo que ficará em 
    // espera enquanto o resto transita
    char aux;

    // enquanto a pilha não
    // estiver vazia
    while (not p->empty()) {
      char topo = p->top();
      p->pop();

      if (p->empty()) aux = topo;
      else p1->push(topo);
    }
    // o auxiliar será sempre o ultimo elemento da pilha


    // contador da posicao do auxiliar
    int pos = 0;

    // passo todos os elementos até chegar no
    // valor correto da posicao do auxiliar
    while (!p1->empty() || aux != NULL) {
      // faço enquanto tiver conteudo na pilha 1
      // faço enquanto o auxiliar ainda guardar alguma coisa
      // ou -> usado pois a pilha pode nao ter acabado quando
      // colocamos o auxiliar

      // se a posicao for o contador
      if (pos == cont) {
        p->push(aux); // coloco o auxilinar na sua posicao
        aux = NULL; // esvazio o auxiliar
      }
      else {
        p->push(p1->top()); // coloco o topo da pilha1
        p1->pop(); // limpo
      }

      pos++; // por fim caminho com a posicao do elemento atual
    }

  }


}

//int main(void) {
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
//	return 0;
//}