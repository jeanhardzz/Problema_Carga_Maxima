#ifndef TIPOCELULA
#define TIPOCELULA

#include "cidade.h"
class TipoCelula{
    public:
        TipoCelula();
    private:
        TipoChave item;
        TipoCelula *prox;
    
    friend class FilaEncadeada;
};

#endif