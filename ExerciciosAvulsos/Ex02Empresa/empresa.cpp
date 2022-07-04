#include "empresa.h"
#include <iostream>
#include <string>

// construtor
Empresa::Empresa(string nome, string endereco, string cidade, string estado, string cep, string telefone){
    this->nome = nome;
    this->endereco = endereco;
    this->cidade = cidade;
    this->estado = estado;
    this->cep = cep;
    this->telefone = telefone;
}