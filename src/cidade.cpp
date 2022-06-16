#include <iostream>
#include "headers/cidade.h"

Cidade::Cidade(){
    chave = -1; // indica um item vazio
}

Cidade::Cidade(TipoChave c){
    chave = c;
}

void Cidade::SetChave(TipoChave c){
    chave = c;
}

TipoChave Cidade::GetChave(){
    return chave;
}

void Cidade::Imprime(){
    std::cout << chave << " ";
}