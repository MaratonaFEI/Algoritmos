#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<vector<int>> G; // Lista de Adjacencia
vector<int> d; // Vetor de Distancias
vector<bool> cor; // Vetor de Cores
vector<int> p; // Vetor de Pais

stack<int> S; // Stack de Vertices
void DFS(int i){

    S.push(i);
    d[i] = 0;
    cor[i] = true;

    while(not S.empty()){

        int u = S.top();
        S.pop();

        for(int i = 0; i < G[u].size(); i++){
            if(not cor[G[u][i]]){

                cor[G[u][i]] = true;
                d[G[u][i]] = d[u] + 1;
                p[G[u][i]] = u;

                S.push(G[u][i]);
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

    DFS(0);

    cout << "Distancias: " << endl;
    for(auto &x: d) cout << x << " ";
    cout << endl;

}
