#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<vector<int>> G; // Lista de Adjacencia
vector<int> d; // Vetor de Distancias
vector<bool> cor; // Vetor de Cores
vector<int> p; // Vetor de Pais

void DFS(int k){

    for(int i = 0; i < G[k].size(); i++){
      if(not cor[G[k][i]]){

        cor[G[k][i]] = true;
        d[G[k][i]] = d[k] + 1;
        p[G[k][i]] = k;

        DFS(G[k][i]);
      }
    }
}

int main(){

    int
    N, // Numero de Vertices
    M, // Numero de Arestas
    X, // Vertice X
    Y, // Vertice Y
    k = 0; // Primeiro Vertice a ser verificado

    cin >> N >> M;

    G.resize(N);

    for(int i = 0; i < M; i++){
        cin >> X >> Y;
        G[X].push_back(Y);
        G[Y].push_back(X);
    }

    d.resize(N, -1);
    cor.resize(N, false);
    p.resize(N, -1);

    d[k] = 0;
    cor[k] = true;
    DFS(k);

    cout << "Distancias: " << endl;
    for(auto &x: d) cout << x << " ";
    cout << endl;

}
