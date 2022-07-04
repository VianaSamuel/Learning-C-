/*
Para a classe Pessoa, implemente o método ehMaior():booleano. Ele deve
descrever uma operação que verifique se uma pessoa é maior de idade ou não.
Construa a subclasse Aluno como uma especialização da classe Pessoa. Ela deverá
acrescentar o atributo relativo ao número de matrícula do aluno. Deverá também
promover um construtor com três argumentos: o número de matrícula do aluno,
seu nome e sua idade.
*/

#include <iostream>
#include <string>
using namespace std;

class Pessoa{
    // atributos
    protected:
        string nome;
        int idade;

    // métodos
    public:
        // construtor
        Pessoa();

        // setters
        void setNome(string nome);
        void setIdade(int idade);

        // getters
        string getNome();
        int getIdade();

        // funções
        bool ehMaior();
};

Pessoa::Pessoa(){
    this->nome = "";
    this->idade = 0;
}

void Pessoa::setNome(string nome){
    this->nome = nome;
}

void Pessoa::setIdade(int idade){
    this->idade = idade;
}

string Pessoa::getNome(){
    return nome;
}

int Pessoa::getIdade(){
    return idade;
}

bool Pessoa::ehMaior(){
    if (this->idade >= 18) return true;
    return false;
}

class Aluno: public Pessoa{
    private:
        int matricula;
    public:
        Aluno(string nome, int idade, int matricula);
};

Aluno::Aluno(string nome, int idade, int matricula): Pessoa(){
    // atributos da classe-mãe
    this->nome = nome;
    this->idade = idade;

    // atributos da classe-filha
    this->matricula = matricula;
}

int main(){
    Pessoa p;
    string nome;
    int idade;
    
    cout << "Digite sua idade: ";
    cin >> idade;
    p.setIdade(idade);

    bool ehMaior = p.ehMaior();
    if (ehMaior == true) cout << "Maior de idade.";
    else cout << "Menor de idade.";
}