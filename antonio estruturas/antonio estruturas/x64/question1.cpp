#include <iostream>

using std::cout;
using std::endl;

template <class T>
class Node {
public:
  T elemento;
  Node<T>* proximo;

  // gerador de novos nos
  Node(T elemento) {
    this->elemento = elemento;
    this->proximo = NULL;
  }

};


template <class T>
class Deque {
private:
  // anoto as pontas da lista
  Node<T>* posicaoInicio;
  Node<T>* posicaoFim;
public:

  Deque() {
  }

  void insereInicio(T elemento) {

    // crio o no a ser inserido
    Node<T>* no = new Node<T>(elemento);

    // se nao ha ninguem na lista
    if (posicaoInicio == NULL)
      posicaoFim = no; // o ultimo tambem vale no
    else // senao
      no->proximo = posicaoInicio; 
    // o proximo do novo primeiro eh o antigo primeiro

    // sempre atualizo o primeiro
    posicaoInicio = no;
  }

  
  void insereFim(T elemento) {

    // crio um no com o elemento a ser inserido
    auto no = new Node<T>(elemento);

    // se nao ha fim
    if (posicaoFim == NULL)
      posicaoInicio = no; // o comeco tambem vale no
    else // senao
      posicaoFim->proximo = no;
    // o proximo do fim sera o novo no

    // atualizo a posicao do fim para o no
    posicaoFim = no;

  }

  void removeinicio() {

    // se a posicao do inicio esta vazia
    // nao ha nada parar remover
    if (posicaoInicio == NULL) return;
     
    // referencia ao no a ser removido
    Node<T> *no = posicaoInicio;

    // se a lista so tem um elemento
    if (posicaoInicio == posicaoFim) {
      posicaoInicio = NULL; // anula os
      posicaoFim = NULL;    // elementos
    }
    else // senao
      posicaoInicio = posicaoInicio->proximo; 
    // atualiza o valor que olhamos como inicio
        
    // deletamos o incio atraves de uma referencia ate ele
    delete no;
  }

  void removeFim() {

    Node<T>* no = posicaoFim;
    
    // se a posicao do fim esta vazia
    // nao ha nada parar remover
    if (posicaoFim == NULL) return;

    // se a lista so tem um elemento
    if (posicaoInicio == posicaoFim) {
      posicaoInicio = NULL;
      posicaoFim = NULL;
    }
    else {
      // variavel para andar ate o final
      Node<T>* novoFim = posicaoInicio;

      // ando ate antes do antigo final
      while (novoFim->proximo != posicaoFim) {
        novoFim = novoFim->proximo;
      }

      // atualizo o final para antes do final
      posicaoFim = novoFim;
      posicaoFim->proximo = NULL;
    }

    // deleto o antigo final por referencia
    delete posicaoFim;
  }

  T bucaInicio() {
    return posicaoInicio->elemento;
  }

  T buscaFim() {
    return posicaoFim->elemento;
  }

  void apresenta() {

    // no para percorrer a lista
    Node<T>* atual = posicaoInicio;

    while (atual != NULL) {

      // caminho pela lista apagando os elementos
      cout << atual->elemento << endl;
      atual = atual->proximo;
    }

  }

};


int main(int argc, char* argv[]) {

  Deque<int>* meuDeque = new Deque<int>();

  meuDeque->insereInicio(9);
  meuDeque->insereInicio(3);
  meuDeque->insereInicio(4);
  meuDeque->insereInicio(7);

  meuDeque->removeFim();
  meuDeque->removeinicio();
  
  meuDeque->apresenta();

  return 0;

}