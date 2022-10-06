#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstdio>
#include <cmath>
#include<climits>
 
using namespace std;
 
int N;
 
int main(){
 
  while(scanf("%d", &N)){
    if(!N) return 0;
    long int dist[N][N];
    fill(dist[0], dist[0] + (N) * (N), INT_MAX);
    long int X,Y;
    double w;
    int T;
    for(int i = 0; i < N-1; i++){
      dist[i][i] = 0;
      scanf("%ld %lf", &Y, &w);
      dist[i+1][Y] = w;
      dist[Y][i+1] = w;
    }
 
    for (int k = 0; k < N; k++) {
        
        for (int i = 0; i < N; i++) {
            
            for (int j = 0; j < N; j++) {
              
                if (dist[i][j] > (dist[i][k] + dist[k][j]) && (dist[k][j] != INT_MAX
                        && dist[i][k] != INT_MAX))
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    cin >> T;
    for(int i = 0; i < T; i++){
      scanf("%ld %ld", &X, &Y);
      printf("%ld ", dist[X][Y]);
    }
    printf("\n");
  }
 
}
