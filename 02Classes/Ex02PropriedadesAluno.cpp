/*
a) Para a classe Pessoa, implemente o método ehMaior():booleano. Ele deve
descrever uma operação que verifique se uma pessoa é maior de idade ou não.

b) Construa a subclasse Aluno como uma especialização da classe Pessoa. Ela deverá acrescentar
o atributo relativo ao número de matrícula do aluno. Deverá também promover um construtor com
três argumentos: o número de matrícula do aluno, seu nome e sua idade.

c) Implemente o método maisVelho(Pessoa): Pessoa na classe Pessoa. Ele deve calcular e retornar
a instância de Pessoa relativa à pessoa mais velha, a corrente ou aquela recebida por parâmetro.

d) Teste as suas classes instanciando dois alunos, pedindo suas idades ao usuário e imprimindo se
ambos são ou não maior de idade, além de qual dos dois é o mais velho.
*/

#include <iostream>
#include <string>
using namespace std;

// classe MÃE
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
        Pessoa maisVelho(Pessoa p);
};

// construtor PADRÃO MÃE
Pessoa::Pessoa(){
    this->nome = "";
    this->idade = 0;
}

// INÍCIO métodos MÃE
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
Pessoa Pessoa::maisVelho(Pessoa p){
    return p;
}
// FIM métodos MÃE

// classe FILHA
class Aluno: public Pessoa{
    // atributos
    private:
        int matricula;

    // métodos
    public:
        //construtor
        Aluno();

        // setter
        void setMatricula(int matricula);

        // getter
        int getMatricula();
};

// construtor PADRÃO FILHA
Aluno::Aluno(): Pessoa(){
    this->nome = "";
    this->idade = 0;
    this->matricula = 0;
}

// INÍCIO métodos FILHA
void Aluno::setMatricula(int matricula){
    this->matricula = matricula;
}
int Aluno::getMatricula(){
    return this->matricula;
}
// FIM métodos FILHA

int main(){
    Aluno a[2];
    Pessoa velho;

    string nome;
    int idade, matricula;
    int maior = 0;

    int i;

    for (i = 0; i < 2; i++){
        cout << endl << "Digite seu nome: ";
        cin >> nome;
        a[i].setNome(nome);

        cout << "Digite sua idade: ";
        cin >> idade;
        a[i].setIdade(idade);

        cout << "Digite sua matrícula: ";
        cin >> matricula;
        a[i].setMatricula(matricula);

        if (idade >= maior){
            maior = idade;
            velho = a[i].maisVelho(a[i]);
        }
    }

    cout << endl;

    for (i = 0; i < 2; i++){
        cout << "---------------------------" << endl;
        cout << "Aluno " << i+1 << ":" << endl;
        cout << "---------------------------" << endl;
        cout << "Matrícula: " << a[i].getMatricula() << endl;
        bool ehMaior = a[i].ehMaior();
        if (ehMaior == true) cout << "O aluno é maior de idade." << endl << endl;
        else cout << "O aluno é menor de idade." << endl << endl;
    }

    cout << "---------------------------" << endl;
    cout << "Aluno mais velho: " << velho.getNome() << endl;
    cout << "---------------------------" << endl << endl;
}