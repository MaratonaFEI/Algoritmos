#include <bits/stdc++.h>

struct vertice {

    int d;
    int p;
    std::vector<int> E;

};

void init(std::vector<vertice> &G, int s){

    for(vertice &u : G){
        u.d = INT_MAX;
        u.p = -1;
    }

    G[s].d = 0;

}

void relax(std::vector<vertice> &G, std::vector<std::vector<int>> &w, int u, int v){

    if(G[u].d != INT_MAX && G[v].d > G[u].d + w[u][v]){
        G[v].d = G[u].d + w[u][v];
        G[v].p = u;
    }

}

bool bellman_ford(std::vector<vertice> &G, std::vector<std::vector<int>> &w, int s){

    init(G, s);

    for(int i = 1; i < G.size(); i++){
        for (int u = 0; u < G.size(); u++) {
            for (int &v: G[u].E) {
              
                relax(G, w, u, v);

            }
        }
    }

    for(int i = 0; i < G.size(); i++){

        for(int v : G[i].E){

            if(G[i].d != INT_MAX && G[v].d > G[i].d + w[i][v]) return false;

        }

    }

    return true;


}

int main() {

    int V, E, Z;
    char X, Y;

    std::cin >> V >> E;

    std::vector<vertice> G(V);
    std::vector<std::vector<int>> w(V);

    for(int i = 0; i < V; i++) w[i].resize(V, 0);

    for(int i = 0; i < E; i++){

        std::cin >> X >> Y >> Z;

        X -= 'a';
        Y -= 'a';

        G[X].E.push_back(Y);
        G[Y].E.push_back(X);
        w[X][Y] = Z;
        w[Y][X] = Z;

    }

    for (int i = 0; i < V; i++) {
        std::cout << "=- " << i << " -=" << std::endl;
        bellman_ford(G, w, i);

        char it = 'a';

        for(vertice &u : G){
            std::cout << it++ << ": " << u.d << std::endl;
        }
    }

    return 0;
}
