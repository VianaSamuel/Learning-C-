/*
Dados os seguintes campos de uma classe Pessoa: nome, dia de aniversário e mês de
aniversário, desenvolver um programa que preencha um cadastro de 10 pessoas e grave
em um arquivo (nome fornecido pelo usuário) cada um dos meses do ano e quem são as
pessoas que fazem aniversário naquele mês, exibir também o dia. Na classe Pessoa, crie
os métodos para manipular os atributos (construtores, assessores, métodos gerais).
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

typedef struct cadastro_{

} cadastro;

class Pessoa{
    // atributos
    public:
        string nome;
        int mes;
        int dia;

    // construtor
    Pessoa(string gNome = " ", int gMes = 0, int gDia = 0){
        nome = gNome;
        mes = gMes;
        dia = gDia;
    }

    // registrador
    void registra(Pessoa *pp, string arquivo){
        fstream file;
        file.open(arquivo.c_str(), ios::app);

        bool tem[12];
        for (int i = 1; i <= 12; i++){
            tem[i] = false;
            file << "Mês " << i << ":";
            for (int j = 0; j < 10; j++){
                if (pp[j].mes == i){
                    tem[i] = true;
                    file << "\nAniversariante: " << pp[j].nome << ", dia " << pp[j].dia << ".";
                }
            }
            if (tem[i] == false){
                file << "\nNenhum aniversariante nesse mês.";
            }
            file << "\n\n";
        }

        file.close();
    }

};

int main(){
    string gArquivo;
    cout << "\nDigite o nome do arquivo (com '.txt'): ";
    cin >> gArquivo;
    cout << endl;

    Pessoa p[10];
    for (int i = 0; i < 10; i++){
        cout << "Nome: ";
        cin.ignore();
        getline(cin, p[i].nome);

        cout << "Mês do aniversário: ";
        cin >> p[i].mes;

        cout << "Dia do aniversário: ";
        cin >> p[i].dia;

        cout << endl;
    }

    p->registra(p, gArquivo);

    cout << "Arquivo gerado com sucesso.";
}