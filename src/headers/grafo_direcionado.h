#ifndef GRAFO
#define GRAFO

#include "cidade.h"
#include "rodovia.h"
#include "fila_encadeada.h"
#include <map>
#include <vector>

class GrafoDirecionado{
    private:
        std::map<TipoChave,std::vector<Rodovia>> g; //cidade e lista de rodovias ligadas a essa cidade
        int n; // numero de vertices/cidade
        int m; // numero de arestas/rodovias
        std::map<TipoChave,TipoChave> predecessores;//usado pra recuperar o caminho depois do bfs
        int gargalo; //rodovia de menor capacidade em um caminho
        std::pair<TipoChave,TipoChave> aresta_gargalo; //aresta de menor capacidade em um caminho
    public:
        GrafoDirecionado();   
        int GetN();
        void SetN(int n);
        int GetM();
        void SetM(int m);     
        void AdicionaAresta(TipoChave cidade, Rodovia rodovia);//Adiciona a conexao de no1 para no2
        void ApagaAresta(TipoChave v1, TipoChave v2);
        void Imprime();
        bool Bfs(TipoChave s, TipoChave t); 
        bool Existe(TipoChave v1, TipoChave v2);
        void ImprimeCaminho(TipoChave s, TipoChave t);
        std::map<TipoChave,TipoChave> GetPredecessores();
        int Gargalo(TipoChave s, TipoChave t);
        int GetGargalo();
        std::pair<TipoChave,TipoChave> GetArestaGargalo();
        void ImprimePredecessores(TipoChave s,TipoChave t);    
        
};

#endif