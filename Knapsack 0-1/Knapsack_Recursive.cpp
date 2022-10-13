#include <iostream>
#include <vector>

using namespace std;

int tam;

struct item {
    int valor;
    int peso;
};

vector<item> mochila;

int Knapsack(int tamanho, int i){
  if(tamanho == 0 or i == 0){
      return 0;
  }

  if(mochila[i - 1].peso > tamanho) return Knapsack(tamanho, i - 1);
    
  else {
      int use_item = mochila[i - 1].valor + Knapsack(tamanho - mochila[i - 1].peso, i - 1);
      int no_use_item = Knapsack(tamanho, i - 1);
      return max(use_item, no_use_item);
  }
}

int main(){

  int N, v, w;
  cin >> N;
  
  cin >> tam;
  
  for(int i = 0; i < N; i++){
    cin >> v >> w;
    mochila.push_back({v, w});
  }

  cout << Knapsack(tam, N) << endl;

}
