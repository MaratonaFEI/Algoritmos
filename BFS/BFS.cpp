#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> G; // Lista de Adjacencia
vector<int> d; // Vetor de Distancias
vector<int> cor; // Vetor de Cores
vector<int> p; // Vetor de Pais

queue<int> Q; // Fila de Vertices
int BFS(int i){

    Q.push(i);
    d[i] = 0;
    cor[i] = true;

    while(not Q.empty()){

        int u = Q.front();
        Q.pop();

        for(int i = 0; i < G[u].size(); i++){
            if(not cor[G[u][i]]){

                cor[G[u][i]] = true;
                d[G[u][i]] = d[u] + 1;
                p[G[u][i]] = u;

                Q.push(G[u][i]);
            }
        }
    }
}

int main(){

    int
    N, // Numero de Vertices
    M, // Numero de Arestas
    X, // Vertice X
    Y; // Vertice Y

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

    BFS(0);

    cout << "Distancias: " << endl;
    for(auto &x: d) cout << x << " ";
    cout << endl;

}
