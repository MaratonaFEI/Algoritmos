#include <iostream>

using namespace std;

int hanoi(int n, int total){
  if(n != 0){
    total = total*2;
    return hanoi(n-1, total);
  }
  return total;
}

int main(){
  int t = 1;
  int n;
  cin >> n; // número de discos
  int m;// número de movimentos com n discos
  m = hanoi(n,t) - 1;
  cout << m << endl;
} 
