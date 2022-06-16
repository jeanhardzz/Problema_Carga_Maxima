#include <iostream>
#include "headers/grafo_direcionado.h"


GrafoDirecionado::GrafoDirecionado(){
    this->n = 0;
    this->m = 0;
}

int GrafoDirecionado::GetN(){
    return this->n;
}
void GrafoDirecionado::SetN(int n){
    this->n=n;
}

int GrafoDirecionado::GetM(){
    return this->m;
}
void GrafoDirecionado::SetM(int m){
    this->m=m;
}

/*Adiciona Aresta no grafo
*/
void GrafoDirecionado::AdicionaAresta(TipoChave cidade, Rodovia rodovia){
    Rodovia rod(cidade,0); //rodovia pra ele mesmo
    auto aux = g.find(cidade);
    if(aux == g.end()){ //Se o no nao existe no grafo        
        //this->g[cidade].push_back(rod);
        //this->n++;
    }

    this->m++;
    this->g[cidade].push_back(rodovia); 
}

/*Remove aresta do grafo
*/
void GrafoDirecionado::ApagaAresta(TipoChave v1, TipoChave v2){
    int i=0;
    for (auto item : g[v1]) {
        if(item.GetCidade() == v2){            
            g[v1].erase(g[v1].begin()+i);
        }
        i++;
    }
}

/*Visualiza o grafo
*/
void GrafoDirecionado::Imprime(){
    for(auto &item : g){
        std::cout << item.first << " - " ;
        for (std::vector<Rodovia>::iterator itv = item.second.begin() ; itv != item.second.end(); ++itv){
            itv->Imprime();
        }
        std::cout<<std::endl;                     
    }    
}

/*Algoritmo de busca em largura para encontrar um caminho em s e t
*Modificado para ir guardando as capacidades limitantes
*/
bool GrafoDirecionado::Bfs(TipoChave s, TipoChave t){
    std::map<TipoChave,bool> visitados;
    gargalo =  INT32_MAX;

    for(int i=1;i<=n;i++){
        visitados[i] = false;        
    }

    FilaEncadeada fila;
    fila.Enfileira(s);
    visitados[s] = true;
    std::map<TipoChave,TipoChave> predecessores_aux;
    predecessores_aux[s] = -1;

    while(!fila.Vazia()){
        TipoChave u = fila.Desenfileira();
        //std::cout<<"\nOlhando vizinhos de "<<u<<std::endl;
        for(int v=1;v<=n;v++){
            if(visitados[v] ==  false && Existe(u,v)){
                //std::cout<<"Existe aresta entre "<<u<<" e "<<v<<std::endl;

                if(v == t){                    
                    predecessores_aux[v] = u;
                    predecessores = predecessores_aux;                    
                    return true;
                }

                fila.Enfileira(v);
                predecessores_aux[v] = u;
                visitados[v] = true;

            }
        }
    }
    return false;
}

/*Verifica se existe uma aresta e armazena a aresta de capacidade limitante
*/
bool GrafoDirecionado::Existe(TipoChave v1, TipoChave v2){    
    for (auto item : g[v1]) {
        if(item.GetCidade() == v2){            
            if(item.GetCapacidade()<gargalo){
                gargalo = item.GetCapacidade();
                aresta_gargalo.first = v1;
                aresta_gargalo.second = v2;
            }              
            return true;
        }
    }
    return false;
}

/*Dado duas cidades, mostra um caminho entre elas usando bfs
*/
void GrafoDirecionado::ImprimeCaminho(TipoChave s, TipoChave t){
    bool caminho = Bfs(s,t);
    std::vector<TipoChave> path;
    if(caminho){
        TipoChave p = t;
        path.push_back(p);

        while(predecessores[p] != -1){
            p = predecessores[p];
            path.push_back(p);
        }

        std::cout<<"Caminho entre "<<s<<" e "<<t<<" : ";
        for (int i= path.size()-1; i>=0; i--) {
            std::cout<<path[i]<<" - ";
        }
        std::cout<<std::endl;
    }

}

/*Apos rodar o bfs e gerar um caminho = predecessores
*essa função apenas imprime esse caminho salvo na ultima busca bfs feita
*/
void GrafoDirecionado::ImprimePredecessores(TipoChave s,TipoChave t){    
    std::vector<TipoChave> path;
    
        TipoChave p = t;
        path.push_back(p);

        while(predecessores[p] != -1){
            p = predecessores[p];
            path.push_back(p);
        }

        std::cout<<"Caminho entre "<<s<<" e "<<t<<" : ";
        for (int i= path.size()-1; i>=0; i--) {
            std::cout<<path[i]<<" - ";
        }
        std::cout<<std::endl;

}

std::map<TipoChave,TipoChave> GrafoDirecionado::GetPredecessores(){
    return predecessores;
}

int GrafoDirecionado::GetGargalo(){
    return gargalo;
}

std::pair<TipoChave,TipoChave> GrafoDirecionado::GetArestaGargalo(){
    return aresta_gargalo;
}

