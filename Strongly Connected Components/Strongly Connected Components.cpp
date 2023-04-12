#include <bits/stdc++.h>

using namespace std;

#define BRANCO 0
#define CINZA 1
#define PRETO 2

struct vertex {
    int id;
    int time_s = 0;
    int time_f = 0;
};

vector<int> cor;
unordered_map<int, vertex> tempo;
int t = 0;

bool comp(vertex a, vertex b){
    return a.time_f > b.time_f;
}

void DFS(vector<vector<int>> &Graph, int u){

    cout << "(" << char(u + 'a') << " ";

    tempo[u].time_s = ++t;

    for(auto &i : Graph[u]){
        if(cor[i] == BRANCO){
            cor[i] = CINZA;
            DFS(Graph, i);
        }
    }

    tempo[u].time_f = ++t;
    cout << " " << char(u + 'a') << ")";
    cor[u] = PRETO;

}

void DFSt(vector<vector<int>> &Graph, int u){

    cout << char(u + 'a') << " ";

    tempo[u].time_s = ++t;

    for(auto &i : Graph[u]){
        if(cor[i] == BRANCO){
            cor[i] = CINZA;
            DFSt(Graph, i);
        }
    }

    tempo[u].time_f = ++t;
    cor[u] = PRETO;

}



int main() {

    int V, A, K;
    char X, Y;

    cin >> V >> A >> K;

    vector<vector<int>> Graph(V);
    vector<vector<int>> Graph_transpose(V);

    for(int i = 0; i < A; i++) {

        cin >> X >> Y;

        Graph[X - 'a'].push_back(Y - 'a');
        Graph_transpose[Y - 'a'].push_back(X - 'a');

    }

    cor.resize(V, BRANCO);

    cout << "Lista de Adjacencia:" << endl;
    for(int i = 0; i < Graph.size(); i++){
        cout << char('a' + i) << ": ";
        for(int j = 0; j < Graph[i].size(); j++){

            cout << char('a' + Graph[i][j]) << " ";

        }

        cout << endl;

    }

    cout << "Parenteses:" << endl;

    cor[K] = PRETO;
    DFS(Graph, K);

    for(int i = 0; i < V; i++){

        if(cor[i] == BRANCO){
            cor[i] = PRETO;
            DFS(Graph, i);
        }

    }

    cout << endl;
    vector<vertex> sorted_time;

    for(auto &i : tempo){
        sorted_time.push_back({i.first, i.second.time_s, i.second.time_f});
    }

    sort(sorted_time.begin(), sorted_time.end(), comp);

    cor.clear();
    cor.resize(V, BRANCO);

    int c = 0;

    for(int i = 0; i < V; i++){

        if(cor[sorted_time[i].id] == BRANCO) {
            cor[sorted_time[i].id] = PRETO;
            cout << "Ciclo " << ++c << ": ";
            DFSt(Graph_transpose, sorted_time[i].id);
            cout << endl;
        }

    }

    return 0;
}
