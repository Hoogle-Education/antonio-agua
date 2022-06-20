# Enfileira()

```cpp
// classe base usando duas pilhas
template<typename T>
class Fila {
  private:
    std::stack<T> *pilha1 = new stack<T>();
    std::stack<T> *pilha2 = new stack<T>();
  public:
    void Enfileira(T elemento);
    T Desenfileira();
}

// para enfileirar apenas adiciono na pilha 2
template<typename T>
void Fila::Enfileira(T elemento){
  pilha2->push(elemento); // 1 operação
  // complexidade O(1)
}

// para desenfileirar, preciso retirar todos
// da pilha2, para acessar o elemento mais antigo

template<typename T>
T Fila::Desenfileira(){

  // n operações de passagem
  while(not pilha2->empty()){
    pilha1->push(pilha2->top());
    pilha2->pop();
  }

  // 1 operação de cópia
  T primeiro = pilha1.top();

  // 1 operação de remoção
  pilha1.pop();

  // n-1 passagens de volta para a pilha2
  while(not pilha1->empty()){
    pilha2->push(pilha1->top());
    pilha1->pop();
  }

  // total = n + 1 + 1 + (n-1) = 2n + 1
  // complexidade: O(n)

  return primeiro;
}
```