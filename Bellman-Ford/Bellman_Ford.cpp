#include <bits/stdc++.h>

struct vertice {

    int d;
    int p;
    std::vector<int> E;

};

void init(std::vector<vertice> &G, int s){

    for(vertice u : G){
        u.d = INT_MAX;
        u.p = -1;
    }

    G[s].d = 0;

}

void relax(std::vector<vertice> &G, std::vector<std::vector<int>> &w, int u, int v){

    if(G[v].d > G[u].d + w[u][v]){
        G[v].d = G[u].d + w[u][v];
        G[v].p = u;
    }

}

bool bellman_ford(std::vector<vertice> &G, std::vector<std::vector<int>> &w, int s){

    init(G, s);
    std::cout << "init complete" << std::endl;
    for(int i = 1; i < G.size(); i++){

        for(int v : G[i].E){

            relax(G, w, i, v);

        }

    }
    std::cout << "w set complete" << std::endl;
    for(int i = 0; i < G.size(); i++){

        for(int v : G[i].E){

           if(G[v].d > G[i].d + w[i][v]) return false;

        }

    }
    std::cout << "cyclic complete" << std::endl;

    return true;

}

int main() {

    int V, E, Z;
    char X, Y;

    std::cin >> V >> E;

    std::vector<vertice> G(V);
    std::vector<std::vector<int>> w(V, std::vector(V, 0));

    for(int i = 0; i < E; i++){

        std::cin >> X >> Y >> Z;

        X -= 'a';
        Y -= 'a';

        //std::cout<< int(X) << " " << int(Y) << " " << Z << std::endl;


        G[X].E.push_back(Y);
        G[Y].E.push_back(X);
        w[X][Y] = Z;
        w[Y][X] = Z;

        //std::cout << i << std::endl;

    }

    std::cout << "input complete" << std::endl;

    bellman_ford(G, w, 0);

    char it = 'a';

    for(vertice u : G){
        std::cout << it++ << ": " << u.d << std::endl;
    }

    return 0;
}
