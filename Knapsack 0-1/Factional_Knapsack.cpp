#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct conteudo {

  int valor;
  int peso;
};

bool comp(conteudo a, conteudo b) { 
    double A = (double) a.valor / (double) a.peso;
    double B = (double) b.valor / (double) b.peso;
    return A > B;
}

int N, w, v, tam;

double Knapsack_Frac(int N, int tamanho, vector<conteudo> &mochila){
 
    double result = 0.0;
 
    for (int i = 0; i < N; i++) {
        if (mochila[i].peso <= tamanho) {
            tamanho -= mochila[i].peso;
            result += mochila[i].valor;
        }
 
        else {
            result += mochila[i].valor * ((double)tamanho / (double)mochila[i].peso);
            break;
        }
    }
 
    return result;
}


int main(){
    int T;
    cin >> T;
    while(T--){
        vector<conteudo> mochila;
        cin >> N >> tam;
  
        for(int i = 0; i < N; i++){
            cin >> v >> w;
            mochila.push_back({v, w});
        }

        sort(mochila.begin(), mochila.end(), comp);

        double resp = Knapsack_Frac(N, tam, mochila);

        printf("%.2lf\n", resp);
        mochila.clear();
    }

}
