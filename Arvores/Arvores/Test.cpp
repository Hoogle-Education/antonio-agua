#include <iostream>
#include "Arvore.h";

using std::cout;
using std::endl;

int main(void) {

	Arvore* arvore = new Arvore();

	arvore->adiciona(3);
	arvore->adiciona(2);
	arvore->adiciona(5);
	arvore->adiciona(4);
	arvore->adiciona(1);
	arvore->adiciona(7);

	arvore->apresenta_emOrdem();
	cout << endl;
	arvore->apresenta_posOrdem();
	cout << endl;
	arvore->apresenta_preOrdem();
	cout << endl;

	cout << "Soma: " << arvore->somaFolha() << endl;

	int valor = 3;
	cout << "Altura(" << valor << ") = " 
			 << arvore->altura(valor) << endl;

	cout << "Fator de Balanceamento(" << valor << ") = "
		<< arvore->fator_balanceamento(valor) << endl;

	arvore->apresentaNiveis();

	cout << "Produto dos nos = " << arvore->produtoNos() << endl;

	return 0;
}