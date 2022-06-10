
#include <iostream>
#include "Arvore.h";

using std::cout;
using std::endl;

int main(void) {
	
	Arvore* arvore = new Arvore();

	arvore->adiciona(3);
	arvore->adiciona(2);
	arvore->adiciona(5);
	//arvore->adiciona(4);
	//arvore->adiciona(1);
	//arvore->adiciona(7);

	arvore->apresenta_emOrdem();

	return 0;
}
