#include "headers/fila_encadeada.h"

FilaEncadeada::FilaEncadeada() : Fila()
{
    frente = new TipoCelula; // Célula cabeça;
    tras = frente;
}

FilaEncadeada::~FilaEncadeada(){
    Limpa();
    delete frente;
}

void FilaEncadeada::Enfileira(TipoChave item) {
    TipoCelula *nova;
    nova = new TipoCelula();
    nova->item = item;
    tras->prox = nova;
    tras = nova;
    tamanho++;
}

TipoChave FilaEncadeada::Desenfileira() {
    TipoCelula *p;
    TipoChave aux;
    if (tamanho == 0)
        throw "Fila está vazia!";
    aux = frente->prox->item;
    p = frente;
    frente = frente->prox;
    delete p;
    tamanho--;
    return aux;
}

void FilaEncadeada::Limpa(){
    TipoCelula *p;
    p = frente->prox;
    while(p!=0){
        frente->prox = p->prox;
        delete p;
        p = frente->prox;
    }
    tamanho = 0;
    tras = frente;
}

bool FilaEncadeada::Vazia(){
    if(tamanho==0){
        return true;
    }else{
        return false;
    }
}