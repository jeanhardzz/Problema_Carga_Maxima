#include "fila.h"
#include "tipocelula.h"

class FilaEncadeada : public Fila{
    public:
        FilaEncadeada();
        virtual ~FilaEncadeada();
        void Enfileira(TipoChave item);
        TipoChave Desenfileira();
        void Limpa();
        bool Vazia();
    private:
        TipoCelula* frente;
        TipoCelula* tras;
};