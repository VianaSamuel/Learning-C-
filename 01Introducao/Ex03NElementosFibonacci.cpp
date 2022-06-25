/*
Faça um programa que imprima os L primeiros elementos da série de Fibonacci.
Por exemplo, se o usuário digitou o número 40, deverão ser apresentados os
40 números da sequência na tela.
*/

#include <iostream>
using namespace std;

int main() {
  int qntd;
  int n1 = 0, n2 = 1, n3 = 1;
  
  cout << "\nDigite a quantidade de números desejada: ";
  cin >> qntd;
  cout << endl << endl;

  cout << "Sequência:\n";
  for (int i = 0; i < qntd; i++){
    cout << n3 << endl;
    n3 = n1 + n2;
    n1 = n2;
    n2 = n3;
  }
}