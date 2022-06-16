#ifndef MAX_MINI_APP
#define MAX_MINI_APP

#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include "grafo_direcionado.h"
#include "rodovia.h"

class MaxiMiniApp{
      private:
        GrafoDirecionado grafo; 
        int n; //cidade
        int m; //rodovias
        int q; //consultas        
        std::map<TipoChave,TipoChave> consultas;              
      public:
        MaxiMiniApp();
        void Leitura(); //Leitura dos dados via linha de comando
        void ImprimeGrafo(); //Visualiza o grafo        
        int CargaMaxima(TipoChave s, TipoChave t); //Calcula a maior carga entre duas cidades
        void Consultas(); //Efetua todas as consultas de carga maxima solicitadas
};

#endif