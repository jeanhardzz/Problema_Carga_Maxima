#include <iostream>
#include "headers/rodovia.h"        

Rodovia::Rodovia(){

}

Rodovia::Rodovia(Cidade c, int cap){
    cidade = c;
    capacidade = cap;
}

void Rodovia::Imprime(){
    std::cout<<cidade.GetChave()<<" : "<<capacidade<<" ";
}

TipoChave Rodovia::GetCidade(){
    return cidade.GetChave();
}

int Rodovia::GetCapacidade(){
    return capacidade;
}