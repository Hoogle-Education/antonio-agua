# Questão 1

## letra A

```cpp
for(int i = N; i > N/2; i++){
  if(B[20] > 3)
    printf("%d", B[i]);
}
```

### 1. melhor caso

Teremos o `B[20] <= 3`, deste modo não executaríamos a operação dentro do `if`, apenas iriamos checar, fazendo aproximadamente (N/2) operações.

### 2. pior caso

Quando o `B[20] > 3`, pois teremos duas operações para uma das (N/2) interações. Deste modo, N operações, aproximadamente.

### 3. Complexidade

Tanto o pior caso quando o melhor caso descrevem um modelo linear de complexidade, O(N).

## letra B

```cpp
int k = N; // 1

for(int i=0; i<5; i++) // 5 interações
  k = k * N; // 1 operação

for(int i=0; i<k; ++i) // N^6 interações
  if(B[i] > 0) { // 1 operação
    for(int x=1; x<100; x++) // 99 interações
      printf("%d", B[i % N]); // 2 operações
  } else {
    for(int x=1; x<100; x++) // 499 interações
      printf("%d", -B[i % N]) // 3 operações
  }
```

### 1. melhor caso

O melhor caso seria todos os valores de B serem maiores que zero, pois assim sempre realizaríamos um número menor de operações no último `for`.

### 2. pior caso

Todos os valores de B serem negativos, pois desta forma, fazemos muito mais operações para um mesmo caso.

### 3. Complexidade

Como N é infinitamente grande, as constantes produzidas no último loop não fazem diferença, deste modo a complexidade final é O(N^6).

## letra C

```cpp
int i = 1;

while(i < N) {

  i = i * 3; 

  // N = 1 => 0 op
  // N = 2 => 1 op
  // N = 3 => 1 op 
  // N = 4 => 2 op
  // N = 5 => 2 op
  // ...
  // N = 9 => 2 op 
  // N = 10 => 3 op
  // ...
  // N => floor(log_3(N)) + 1 operações

  if(B[6] < 300){
    for(int j=1; j < N/2; j++){ // N/2 interações
      int k = j+1; // 1 operação
      // opera enquanto for crescente 
      // e a lista B não tiver acabado
      while((k < N) && (B[k] > B[j])){ 
        printf("%d", B[k]); // 1 operação
        k++; // 1 operação
      }
    }
  }

}
```

### 1. Melhor caso

O melhor caso seria o valor de `B[6] >= 300`, desta forma faríamos apenas aproximadamente `log_3(N) + 1` operações.

### 2. Pior caso

O pior caso seria o valor de `B[6] < 300` e para complementar, a sequência ser perfeitamente crescente, pois desta forma o `while((k < N) && (B[k] > B[j]))` sempre teria suas condições satisfeitas até o fim da lista, para cada j indo até a metade lista.

Supondo j par, sem perda de generalidade.

Contando operações internas:

```cpp
// j = 1 => N-1 op
// j = 2 => N-2 op
// j = 3 => N-3 op
// ...
// j = N/2 => N - N/2 operações
```

total de operações neste loop: Soma da P.A com primero elemento `N - N/2`, último elemento: `N-1` e razão 1.

resposta: `(1/2) * (N/2) * ((3N-2)/2)`

resultado assintótico local: `O(N^2)`

### 3. Complexidade

Neste caso a complexidadade irá variar para cada um dos casos

|Melhor caso|Pior caso|
|:-:|:-:|
|O melhor caso irá realizar apenas `log_3(N) + 1` operações, resultando em O(log(N))**|O pior caso, irá rodar a *assintótica local* `log(N)` vezes, complexidade final: O(N^2 * log(N))|

(**) = a base 3 some, pois durante a mudança de base para a base 2 do log, o log_2(3) se torna uma constante, e constantes serão ignoradas na notação assintótica.
