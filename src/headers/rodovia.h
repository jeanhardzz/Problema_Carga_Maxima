#ifndef RODOVIA
#define RODOVIA

#include "cidade.h"

typedef int TipoChave; // TipoChave é um inteiro

class Rodovia{
    private:
        Cidade cidade;
        int capacidade;        
        // outros membros
    public:
        Rodovia();
        Rodovia(Cidade c, int cap);        
        void Imprime();
        TipoChave GetCidade();    
        int GetCapacidade();
};

#endif