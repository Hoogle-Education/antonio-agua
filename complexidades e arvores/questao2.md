# Questao 2

## letra A

```cpp
int produtoFolhas(No *no) {
    if (no == NULL) { 
        return 1;
    } else if ((no->esq == NULL) && (no->dir == NULL)) {
        return no->valor;
    } else {
        return produtoFolhas(no->esq) * produtoFolhas(no->dir);
    }
}
```

Se o `no` valer nulo retorno 1, elemento neutro da multiplicação. (caso base)

Se o `no` for uma folha, ele tem ambos filhos nulos, e por isso retorna seu valor. (caso base)

Se não é folha e não é nulo, preciso dividir em subproblemas para cada subárvore deste `no`, então chamo a `produtoFolhas` recursivamente.

## letra B

```cpp
void imprimeOrdem(No *argNo) {
    if (argNo != NULL) {
        imprimeOrdem(argNo->esq);
        printf("%d ", argNo->valor);
        imprimeOrdem(argNo->dir);
    }
}
```

```
6 4 7 1 5 8 9
```

O percurso em-ordem consiste em acessar o `no` mais a esquerda e fazer o percurso Esquerda-Raiz-Direita, entre as subárvores.

```
1 4 5 6 7 8 9
```



