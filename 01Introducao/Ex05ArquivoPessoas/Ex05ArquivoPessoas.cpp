/*
Elaborar uma classe Pessoa (código, nome, idade, endereço, número, complemento) e,
após cadastrar os dados de várias pessoas em um vetor de objetos desta classe, gravar o
conteúdo do vetor no arquivo cujo nome deve ser fornecido pelo usuário. Na classe
Pessoa, crie os métodos para manipular os atributos (construtores, assessores, métodos
gerais).
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Pessoa{
    // atributos
    public:
        string arquivo;
        int codigo;
        string nome;
        int idade;
        string endereco;
        int numero;
        string complemento;

    // construtor
    Pessoa(string gArquivo, int gCodigo, string gNome, int gIdade, string gEndereco, int gNumero, string gComplemento){
        arquivo = gArquivo;
        codigo = gCodigo;
        nome = gNome;
        idade = gIdade;
        endereco = gEndereco;
        numero = gNumero;
        complemento = gComplemento;
    }

    // registrador
    void registra_pessoa(Pessoa p_){
        fstream file;
        file.open(arquivo.c_str(), ios::app);

        file << "Código: " << codigo;
        file << "\n";
        file << "Nome: " << nome;
        file << "\n";
        file << "Idade: " << idade;
        file << "\n";
        file << "Endereço: " << endereco;
        file << "\n";
        file << "Número: " << numero;
        file << "\n";
        file << "Complemento: " << complemento;
        file << "\n\n";

        file.close();
    }

};

int main(){
    string gArquivo;
    cout << "\nDigite o nome do arquivo (com '.txt'): ";
    cin >> gArquivo;

    int num;
    cout << "Digite o número de pessoas a serem cadastradas: ";
    cin >> num;
    cout << endl;

    int gCodigo, gIdade, gNumero;
    string gNome, gEndereco, gComplemento;
    Pessoa *p = new Pessoa(gArquivo, gCodigo, gNome, gIdade, gEndereco, gNumero, gComplemento);

    for (int i = 0; i < num; i++){
        cout << "Digite o código: ";
        cin >> gCodigo;

        cout << "Digite o nome: ";
        cin.ignore();
        getline(cin, gNome);

        cout << "Digite a idade: ";
        cin >> gIdade;

        cout << "Digite o endereço: ";
        cin.ignore();
        getline(cin, gEndereco);

        cout << "Digite o número da residência: ";
        cin >> gNumero;

        cout << "Digite o complemento: ";
        cin.ignore();
        getline(cin, gComplemento);

        cout << endl;

        Pessoa p = Pessoa(gArquivo, gCodigo, gNome, gIdade, gEndereco, gNumero, gComplemento);
        p.registra_pessoa(p);
    }
}