#include <iostream>
#include "headers/maxi_mini_app.h"

/*Inicializacao
*/
MaxiMiniApp::MaxiMiniApp(){
    this->n=0;
    this->m=0;
    this->q=0;
}

/*Leitura
*/
void MaxiMiniApp::Leitura(){
    std::string linha;
    std::stringstream s;

    getline(std::cin, linha); 
    s << linha;
    s>>n;
    s>>m;
    s>>q;

    grafo.SetN(n) ;

    for(int i=1;i<=m;i++){
        std::stringstream ss;        
        TipoChave cidade1, cidade2;
        int capacidade;

        getline(std::cin, linha);
        ss << linha;
        ss >> cidade1;
        ss >> cidade2;
        ss >> capacidade;

        Rodovia rodovia(cidade2,capacidade);

        grafo.AdicionaAresta(cidade1,rodovia);
    }

    for(int i=1;i<=q;i++){
        std::stringstream sss;        
        TipoChave cidade1, cidade2;        

        getline(std::cin, linha);
        sss << linha;
        sss >> cidade1;
        sss >> cidade2;
        

        consultas[cidade1] = cidade2;        
    }
}

/*Visualização
*/
void MaxiMiniApp::ImprimeGrafo(){
    std::cout<<"n = "<<n<<" / m= "<<m<<" / q = "<<q<<std::endl;
    grafo.Imprime();
}

/*Calcula a maior carga entre duas cidades
*Encontra um caminho usando BFS
*encontra a aresta de menor capacidade nesse caminho
*salva como possivel carga maxima
*deleta essa aresta de menor capacidade
*repita ate nao existir mais caminhos
*/
int MaxiMiniApp::CargaMaxima(TipoChave s, TipoChave t){
    int carga_maxima = -1;
    GrafoDirecionado grafo_aux;
    grafo_aux = grafo;
    while(grafo_aux.Bfs(s,t)){
        if(grafo_aux.GetGargalo() >  carga_maxima){
                carga_maxima = grafo_aux.GetGargalo();
        }
        //std::cout<<std::endl;
        //grafo_aux.ImprimePredecessores(s,t);
        //std::cout<<"Gargalo = "<< grafo_aux.GetGargalo();        
        //std::cout<<" entre "<<grafo_aux.GetArestaGargalo().first<<" e "<<grafo_aux.GetArestaGargalo().second<<std::endl;        
        grafo_aux.ApagaAresta(grafo_aux.GetArestaGargalo().first,grafo_aux.GetArestaGargalo().second);
        //std::cout<<"\n";
        //grafo_aux.Imprime();
    }
    /*
    */
    return carga_maxima;
}

/*Efetua todas as consultas sobre a carga maxima
*/
void MaxiMiniApp::Consultas(){
    for (auto item : consultas){
        //std::cout<<"\n";
        //std::cout<<"Consulta ("<<item.first<<","<<item.second<<") = ";
        std::cout<<CargaMaxima(item.first,item.second)<<std::endl;        
        //grafo.Imprime();                 
    }
}
