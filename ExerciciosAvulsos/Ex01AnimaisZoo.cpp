/*
Crie uma classe Animal para registrar animais de zoológico. É preciso
saber o número da jaula, seu peso e a data que ele foi pesado. Todos
os atributos devem ser privados, e os métodos públicos. Crie o método
construtor com valores padrão para todos os atributos e o método
changeWeight, que recebe o novo peso e a data de hoje, e altera os
atributos do objeto.
*/

#include <iostream>
#include <string>
using namespace std;

class Animal{
    private:
        int jaula;
        float peso;
        string data;
    public:
        Animal(int gJaula = 0, float gPeso = 0, string gData = " ");
        void changeWeight(Animal a);
};

Animal::Animal(int gJaula, float gPeso, string gData){
    jaula = gJaula;
    peso = gPeso;
    data = gData;
}

void Animal::changeWeight(Animal a){
    cout << "Último peso: " << peso << endl;
    cout << "Data da última pesagem: " << data << endl << endl;

    float novoPeso;
    string novaData;

    cout << "Digite o novo peso do animal: ";
    cin >> novoPeso;

    cout << "Digite a data da nova pesagem: ";
    cin >> novaData;

    peso = novoPeso;
    data = novaData;

    cout << "Novo peso: " << peso << endl;
    cout << "Data da nova pesagem: " << data << endl;
}

int main(){
    int gJaula;
    float gPeso, gNovoPeso;
    string gData, gNovaData;

    cout << "\nDigite o número da jaula: ";
    cin >> gJaula;

    cout << "Digite o último peso do animal: ";
    cin >> gPeso;

    cout << "Digite a data da última pesagem: ";
    cin >> gData;

    cout << endl;

    Animal a(gJaula, gPeso, gData);
    a.changeWeight(Animal a);
}