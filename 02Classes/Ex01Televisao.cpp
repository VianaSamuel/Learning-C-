/*
Implemente uma televisão. A televisão tem um controle de volume do som e um controle de seleção de canal.

    - O controle de volume permite aumentar ou diminuir o volume de som em uma unidade de cada vez,
      ou colocar a TV no mudo.
    - O controle de canal também permite aumentar e diminuir o número do canal em uma unidade,
      porém, também possibilita trocar para um canal indicado (entre 0 e 99).
    - Também devem existir métodos para consultar o valor do volume de som e o canal selecionado.

No programa principal, crie uma televisão inicializada no canal 10 e volume 0, e um laço infinito com um
menu com as opções de (1) alterar volume, (2) alterar canal ou (3) imprimir informações.
A opção volume pede um dado adicional (+, - ou M para mudo) referente à ação desejada. Já a opção canal pode
receber + ou - referente a mudanças de uma unidade, ou um valor numérico referente ao canal desejado.
*/

#include <iostream>
using namespace std;

class Televisao{
    // atributos
    private:
        int vol;
        int can;
    // construtor, setters e métodos
    public:
        Televisao(int vol, int can);
        void setVol(int vol);
        void setCan(int can);
        void alteraVol(char alt);
        void alteraCan(char alt, int alt_num);
        void consulta();
};

// construtor PADRÃO
Televisao::Televisao(int vol, int can){
    this->vol = 0;
    this->can = 10;
}

// setter VOLUME
void Televisao::setVol(int vol){
    this->vol = vol;
}

// setter CANAL
void Televisao::setCan(int can){
    this->can = can;
}

// método VOLUME
void Televisao::alteraVol(char alt){
    if (alt == '+')
        vol++;
    else if (alt == '-')
        vol--;
    else if (alt == 'm' || alt == 'M')
        vol = 0;
}

// método CANAL
void Televisao::alteraCan(char alt, int alt_num){
    if (alt == '+')
        can++;
    else if (alt == '-')
        can--;
    else {
        can = alt_num;
    }
}

// método CONSULTA
void Televisao::consulta(){
    cout << endl;
    cout << "Volume atual: " << vol << endl;
    cout << "Canal atual: " << can << endl;
}

void linha(){
    cout << "----------------------------------" << endl;
}

int main(){
    int vol, can;
    Televisao t(vol, can);

    while(1){
        char alt;
        int opc, alt_num;

        cout << endl;
        linha();
        cout << "Escolha uma opção:" << endl;
        linha();
        cout << "(1) Alterar volume" << endl;
        cout << "(2) Alterar canal" << endl;
        cout << "(3) Status atual" << endl;
        linha();
        cin >> opc;

        if (opc == 1){
            cout << endl << "Opções para alterar volume:" << endl;
            cout << "(+) => Aumentar em 1" << endl;
            cout << "(-) => Diminuir em 1" << endl;
            cout << "(M) => Mutar" << endl << endl;
            cout << "Escolha sua opção: ";
            cin >> alt;
            t.alteraVol(alt);
        }

        else if (opc == 2){
            cout << endl << "Opções para alterar canal:" << endl;
            cout << "(+) => Aumentar em 1" << endl;
            cout << "(-) => Diminuir em 1" << endl;
            cout << "(N) => Mudar para o número desejado" << endl << endl;
            cout << "Escolha sua opção: ";
            cin >> alt;
            if (alt == '+' || alt == '-'){
                t.alteraCan(alt, alt_num);
            }
            else if (alt == 'n' || alt == 'N'){
                cout << endl;
                cout << "Digite o número do canal (0 a 99): ";
                cin >> alt_num;
                if (alt_num < 0 || alt_num > 99)
                    cout << endl << "Input inválido!" << endl;
                else
                    t.alteraCan(alt, alt_num);
            }
        }

        else if (opc == 3){
            t.consulta();
        }
    }
}