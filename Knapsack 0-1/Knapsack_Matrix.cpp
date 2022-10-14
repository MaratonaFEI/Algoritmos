#include <iostream>
#include <vector>

using namespace std;

struct conteudo {

  int valor;
  int peso;
};

int N, v, w, tam;
vector<conteudo> mochila; // Mochila com pesos e valores

int Knapsack(int v_size, int tamanho){

  vector<vector<int>> cashe(v_size + 1, vector<int>(tamanho + 1)); // Matriz de possibilidades da Mochila

  for(int i = 0; i <= N; i++){

    for(int w = 0; w <= tamanho; w++){

      if(i == 0 or w == 0) cashe[i][w] = 0;
        
      else if(mochila[i - 1].peso <= w)
        cashe[i][w] = max(mochila[i - 1].valor +
        cashe[i - 1][w - mochila[i - 1].peso],
        cashe[i - 1][w]);
        
      else cashe[i][w] = cash[i - 1][w];
    }
  }
  return cashe[v_size][tamanho];
}


int main(){

  cin >> N; // Quantidade de Itens
  cin >> tam; // Limite da Mochila
  
  for(int i = 0; i < N; i++){
      cin >> v >> w;
      mochila.push_back({v, w});
  }

  cout << Knapsack(N, tam) << endl;

}
