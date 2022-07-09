/*
    a) Para a classe Pessoa, implemente o método ehMaior():booleano. Ele deve
descrever uma operação que verifique se uma pessoa é maior de idade ou não.
    b) Construa a subclasse Aluno como uma especialização da classe Pessoa. Ela deverá
acrescentar o atributo relativo ao número de matrícula do aluno. Deverá também
promover um construtor com três argumentos: o número de matrícula do aluno,
seu nome e sua idade.
    c) Implemente o método maisVelho(Pessoa): Pessoa na classe Pessoa. Ele deve calcular e retornar a instância de Pessoa relativa à pessoa mais velha, a corrente ou aquela recebida por parâmetro.
    d) Teste as suas classes instanciando dois alunos, pedindo suas idades ao usuário e imprimindo se ambos são ou não maior de idade, além de qual dos dois é o mais velho.
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
        void setMatricula(int matricula);
        int getMatricula();
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
    Aluno a("", 0, 0);
    string nome;
    int idade, matricula;

    cout << endl << "Digite seu nome: ";
    cin >> nome;
    p.setNome(nome);

    cout << "Digite sua idade: ";
    cin >> idade;
    p.setIdade(idade);

    cout << "Digite sua matrícula: ";
    cin >> matricula;
    a.setMatricula(matricula);

    bool ehMaior = p.ehMaior();
    if (ehMaior == true) cout << "Maior de idade.";
    else cout << "Menor de idade.";
}