/*
Fazer um programa leia uma sequência de valores inteiros fornecida pelo usuário
em uma linha de entrada e conte o número de valores positivos, negativos e zeros.
*/

#include <iostream>
using namespace std;

int main() {
  int num;
  int pos = 0, neg = 0, zero = 0;
  
  cout << "\nDigite uma sequência de valores, separando por enter.\nDigite -999 para obter os resultados." << endl << endl;
  while (1){
    cin >> num;
    if (num == -999){
      break;
    } else {
      if (num == 0)
        zero++;
      else if (num > 0)
        pos++;
      else if (num < 0)
        neg++;
    }
  }

  cout << endl;
  cout << "Quantidade de valores positivos: " << pos << endl;
  cout << "Quantidade de valores negativos: " << neg << endl;
  cout << "Quantidade de zeros: " << zero << endl;
}