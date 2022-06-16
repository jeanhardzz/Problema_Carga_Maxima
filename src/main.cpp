#include <iostream>
#include <sstream>

#include "headers/maxi_mini_app.h"

/*EXECUÇÃO
* g++ fila_encadeada.cpp tipocelula.cpp cidade.cpp rodovia.cpp grafo_direcionado.cpp maxi_mini_app.cpp main.cpp -o ./tp01
* ./tp01
*/

int main(){    
    
    MaxiMiniApp app;
    app.Leitura();    
    app.Consultas();    
    
    return 0;
}