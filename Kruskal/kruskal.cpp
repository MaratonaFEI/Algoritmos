#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Aresta{
public:
    int v1;
    int v2;
    int w;

    Aresta(int v1, int v2, int w){
        this->v1 = v1;
        this->v2 = v2;
        this->w = w;
    }
};

vector< Aresta > A;
vector<int> conj;

bool comp(Aresta a, Aresta b){
    return a.w < b.w;
}

int find(int k){
    if(conj[k]== -1)
        return k;
    return find(conj[k]);
}
int soma = 0;

void kruskal(int m){
    conj.resize(m, -1);
    int conta = 0;
    soma = 0;

    for (int i = 0; i <A.size() ; ++i) {
        int v_1 = find(A[i].v1);
        int v_2 = find(A[i].v2);

        if(v_1 != v_2){
            soma += A[i].w;
            conj[v_1] = v_2;
            conta++;
        }
        if(conta == m-1)
            return;
    }
}

int main() {
    int m, n, x, y , z;

    while(cin >> m >> n ){
        if(m==0 && n==0)
            break;
        A.clear();
        conj.clear();
        for (int i = 0; i <n ; ++i) {
            cin >> x >> y >> z;
            A.push_back(Aresta(x,y,z));
        }

        sort(A.begin(), A.end(), comp);

        kruskal(m);

        cout << soma << endl;
    }

    return 0;
}
