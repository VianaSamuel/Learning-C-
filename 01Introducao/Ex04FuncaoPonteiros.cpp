/*
Faça um programa que leia dois valores inteiros e chame uma função que
receba estes 2 valores por referência (ponteiros) e coloque o maior valor
na primeira variável e o menor valor na segunda variável. Escreva o conteúdo
das 2 variáveis na tela no programa principal.
*/

#include <iostream>
using namespace std;

typedef struct variaveis_{
  int v1;
  int v2;
} variaveis;

variaveis alocaValores(int *p1, int *p2, variaveis var){
  if (*p1 > *p2){
    var.v1 = *p1;
    var.v2 = *p2;
  } else if (*p1 < *p2){
    var.v1 = *p2;
    var.v2 = *p1;
  }
  return var;
}

int main() {
  int val1, val2;
  
  cout << "\nDigite o valor 1: ";
  cin >> val1;

  cout << "Digite o valor 2: ";
  cin >> val2;
  cout << endl;

  int *ptr1, *ptr2;
  ptr1 = &val1;
  ptr2 = &val2;

  variaveis v;
  variaveis r = alocaValores(ptr1, ptr2, v);

  cout << "Primeira variável: " << r.v1 << endl;
  cout << "Segunda variável: " << r.v2;
}