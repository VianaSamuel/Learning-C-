/*
Faça um algoritmo que leia o ano de nascimento de uma pessoa e calcule sua idade,
considerando o ano atual. Para verificar se já fez aniversário no ano atual, pergunte se
a pessoa já fez aniversário, sendo que ela pode entrar com a informação "S" ou "N".
Verifique também se a pessoa já tem idade para conseguir a Carteira de Habilitação
(18 anos ou mais) e imprima a mensagem referente a esta checagem. Imprima a idade
da pessoa.
*/

#include <iostream>
using namespace std;

class Processa{
  // atributos
  public:
    int nasc;
    int atual;
    char niver;

  // construtor
  Processa(int nasc, int atual, char niver){
    this->nasc = nasc;
    this->atual = atual;
    this->niver = niver;
  }

  // retorna idade
  int retornaIdade(void){
    int idade;
    if (this->niver == 's' || this->niver == 'S')
      idade = this->atual - this->nasc;
    else
      idade = (this->atual - this->nasc) - 1;
    return idade;
  }

  // verifica CNH
  bool verificaCNH(void){
    bool pode;
    if (this->retornaIdade() >= 18) pode = true;
    else pode = false;
    return pode;
  }
};

int main(){
  int nasc, atual;
  char niver;

  cout << endl;
  cout << "Digite seu ano de nascimento: ";
  cin >> nasc;

  cout << "Digite o ano atual: ";
  cin >> atual;

  cout << "Você já fez aniversário nesse ano? ( S / N ): ";
  cin >> niver;

  cout << endl;

  Processa *x = new Processa(nasc, atual, niver);

  int anos = x->retornaIdade();
  cout << "Você tem " << anos << " anos." << endl;

  bool cnh = x->verificaCNH();
  if (cnh == true) cout << "Você pode tirar a Carteira Nacional de Habilitação.";
  else cout << "Você não pode tirar a Carteira Nacional de Habilitação.";
}
