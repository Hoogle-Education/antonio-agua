#include <stack>
#include <iostream>

using namespace std;

template <typename T>
class Fila
{
private:
  stack<T> pilha1*;
  stack<T> pilha2*;
public:
  Fila();
  ~Fila();
  void enfileira(T elemento);
  void desenfileira(T elemento);
};

Fila::Fila()
{
  pilha1 = new stack<T>();
  pilha2 = new stack<T>();
}

Fila::~Fila()
{
}

template<typename T>
void Fila::enfileira(T elemento){
  while(not pilha2.empty()){
    T topo = pilha2.top();
    pilha2.pop();
    pilha1.push(topo);
  }
}

int main(){

}

## 