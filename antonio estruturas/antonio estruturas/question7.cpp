// -----------------------------------------

#include <iostream>
#include <string>
#include <stack>
#include <queue>

using std::cout;
using std::endl;
using std::queue;
using std::stack;
using std::string;

// -----------------------------------------
// O(L + S) no qual L é o numero de letras e 
// S é o numero de Simbolos pois apenas armazenamos
// de forma organizada e apresentamos os simbolos
// na ordem correta

string saida_polonesa(const char *expressao)
{

  // operacoes saem ao contrario do original
  stack<char> *operadores = new stack<char>();

  // letras saem na ordem que entraram
  queue<char> *letras = new queue<char>();

  // saida come�a vazia
  string saida = "";

  int i = 0;

  // enquanto nao for o fim da expressao
  while (expressao[i] != '\0')
  {

    // se for um caracter alfabetico
    if (isalpha(expressao[i]))
      letras->push(expressao[i]); // acrescentado as letras

    // se diferente de um paranteses
    else if (expressao[i] != '(' && expressao[i] != ')')
      operadores->push(expressao[i]); // acrescentado aos operadores

    // toda vez que fecho um parenteses
    // devo liberar as letras e operacoes acumuladas ate entao
    if (expressao[i] == ')')
    {
      while (!letras->empty())
      {
        saida += letras->front();
        letras->pop();
      } // libero as letras e coloca na saida

      while (!operadores->empty())
      {
        saida += operadores->top();
        operadores->pop();
      } // libero os operadores e coloco na saida
    }

    // proximo caracter
    i++;
  }

  return saida;
}

// int main(void) {
//
//   cout << saida_polonesa("((A+B)*(C-(F/D)))") << endl;
//
//   return 0;
// }