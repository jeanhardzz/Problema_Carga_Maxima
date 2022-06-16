#ifndef FILA
#define FILA

#include "cidade.h"

class Fila
{
    public:
        Fila() {tamanho = 0;};
        int GetTamanho() {return tamanho;};
        bool Vazia() {return tamanho == 0;};
        virtual void Enfileira(TipoChave item) = 0;
        virtual TipoChave Desenfileira() = 0;
        virtual void Limpa() = 0;
    protected:
        int tamanho;
};

#endif