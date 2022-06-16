#ifndef CIDADE
#define CIDADE

typedef int TipoChave; // TipoChave é um inteiro

class Cidade{
    private:
        TipoChave chave;
        // outros membros
    public:
        Cidade();
        Cidade(TipoChave c);
        void SetChave(TipoChave c);
        TipoChave GetChave();
        void Imprime();    
};

#endif