#include<iostream>
#include<vector>
#include<algorithm>
#include<ctime>
#include<queue>
#include<cstdio>
#include<climits>
 
using namespace std;
 
// Estrutura usada para implementar a lista de adjac?ncia
class Vertice{
    public:
        double w; // peso da aresta
        int ind; // identifica??o do vertice destino da aresta
         
        // Construtores
        Vertice(){};
         
        Vertice(int ind, double w){
            this->w = w;
            this->ind = ind;
        }
};
 
 
vector< vector<Vertice> > g; // Lista de Adjac?ncia.
 
 
// Vetores utilizados no algoritmo de Prim
 
//para os 3 vetores a seguir, cada posi??o do vetor representa um vertice do grafo.
vector<int> d; // Vetor que armazena o peso da aresta usada para alcan?ar o v?rtice.
vector<bool> cor; // Define se cada vertice ja foi encontrado ou n?o.
vector<int> p; // Vetor que armazena o pai de cada vertice.
 
 
// Fun??o de compara??o para utilizar a estrutura heap de minimo.
// Pois a biblioteca <algorithm> tem por padr?o a implementa??o do heap de m?ximo.
bool comp(const int A, const int B)
{
    return d[A] > d[B];
}
 
 
// Algoritmo que calcula a arvore espalhada minima de um grafo.
void prim(int s)
{
    vector<int> Q; // Vetor utilizado no heap de minimo bin?rio
     
    // Inicializa??o
    cor.resize(g.size(), false);
    p.resize(g.size(), -1);
    d.resize(g.size(), INT_MAX);
    Q.push_back(s);
    d[s] = 0;
    cor[s] = true;
     
    // Enquanto o heap n?o estiver vazio
    while(!Q.empty()){
    	
        // Procedimento para retirar a raiz da estrutura de heap
        int u = Q[0];
        pop_heap(Q.begin(),Q.end(), comp); Q.pop_back();
         
        // Para todo vertice adjacente ? "u"
        for(int i = 0; i < g[u].size(); i++) {
            // Se o vertice adjacente ? "u" for diferente do vertice pai de "u"
            // E se a aresta para alcan?ar o vertice adjacente for mais leve do que a j? utilizada.
            if(p[u] != g[u][i].ind && g[u][i].w < d[g[u][i].ind]){
                // Processo de relaxamento
                d[g[u][i].ind] = g[u][i].w;
                p[g[u][i].ind] = u;
            }
            // Se o v?rtice adjacente ainda n?o foi encontrada.
            if(cor[g[u][i].ind] == false){
                cor[g[u][i].ind] = true; // Define o vertice adjacente como encontrado
                Q.push_back(g[u][i].ind); // Adiciona o vertice adjacente no heap
            }
        }
 
        make_heap(Q.begin(), Q.end(), comp); // Constroi o heap
    }
}
 
int main(){
    g.resize(3000);
    double seconds;
    time_t start, end;
    time(&start);
	for(int i=0;i<3000;i++){
		for(int j=0;j<3000;j++){
			if(i!=j)
				g[i].push_back(Vertice(j,i+j));
		}
	}
	time(&end);
	seconds = end - start;
	cout<<"tempo para inserir arestas = "<<seconds<<endl;
	time(&start);
	prim(0);
	time(&end);
	seconds = end - start;
	cout<<"tempo para o prim = "<<seconds<<endl;
    return 0;
}
