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

  vector<vector<int>> cash(v_size + 1, vector<int>(tamanho + 1)); // Matriz de possibilidades da Mochila

  for(int i = 0; i <= N; i++){

    for(int w = 0; w <= tamanho; w++){

      if(i == 0 or w == 0) cash[i][w] = 0;
        
      else if(mochila[i - 1].peso <= w)
        cash[i][w] = max(mochila[i - 1].valor +
        cash[i - 1][w - mochila[i - 1].peso],
        cash[i - 1][w]);
        
      else cash[i][w] = cash[i - 1][w];
    }
  }
  return cash[v_size][tamanho];
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
