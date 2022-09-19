#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> G; // Lista de Adjacencia
vector<int> d; // Vetor de Distancias
vector<bool> cor; // Vetor de Cores
vector<int> p; // Vetor de Pais

queue<int> Q; // Fila de Vertices
void BFS(int i){

    Q.push(i); // primeiro vertice a ser verificado
    d[i] = 0; // dist do primeiro vertice = 0
    cor[i] = true; // setar cor do primeiro vertice como true

    while(not Q.empty()){ // enquanto a lista nao estiver vazia, rodar o BFS

        int u = Q.front(); // vertice [u]
        Q.pop();

        for(int i = 0; i < G[u].size(); i++){ // "for" para pegar todos os vertices ligados com [u]
            if(not cor[G[u][i]]){ // se ele ja foi verificado, nao verificar novamente

                cor[G[u][i]] = true; // setar a cor do vertice ligado com [u] como true
                d[G[u][i]] = d[u] + 1; // dist do vertice ligado com [u] como a distancia dele + 1
                p[G[u][i]] = u; // designar o pai do vertice ligado com o [u] como o [u] 

                Q.push(G[u][i]); // push no vertice para verificar suas ligacoes
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

    G.resize(N); // alocar o tamanho do grafo

    for(int i = 0; i < M; i++){
        cin >> X >> Y;
        G[X].push_back(Y); // vertice x liga com o vertice y
        G[Y].push_back(X); // vertice y liga com o vertice x
    }

    d.resize(N, -1);
    cor.resize(N, false); // preenchimento dos vetores
    p.resize(N, -1);

    BFS(0); // comecar a vertificacao com o vertice 0

    cout << "Distancias: " << endl;
    for(auto &x: d) cout << x << " ";
    cout << endl;

}
