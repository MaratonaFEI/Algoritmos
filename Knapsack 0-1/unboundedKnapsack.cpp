#include<iostream>
#include <vector>

using namespace std;

struct item {
    int valor, peso;
};

int unboundedKnapsack(int tam, vector<item> &mochila){
	
    vector<int> dp(tam+1, 0);

    int n = mochila.size();

	for(int i = 0; i <= tam; i++){

	    for(int j = 0; j < n; j++){

		    if(mochila[j].peso <= i){

			    dp[i] = max(dp[i], dp[i-mochila[j].peso] + mochila[j].valor);

            }
        }   
    }

	return dp[tam];
}

int main(){

    int N, tam, w, v, h = 0;

    while(cin >> N >> tam && N+tam){
	
        vector<item> mochila;

        for(int i = 0; i < N; i++){
            
            cin >> w >> v;

            mochila.push_back({v, w});

        }
        
	    cout << unboundedKnapsack(tam, mochila) << endl;
    
    }
	return 0;
}
