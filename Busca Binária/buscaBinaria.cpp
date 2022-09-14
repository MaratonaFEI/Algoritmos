#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int buscaBinaria(vector<int> arr, int elemento){
        int i = 0;
        int f = arr.size() - 1;
        while(i <= f){
            int pivo = (i+f)/2;
            if(elemento > arr[pivo]) i = pivo + 1;
            else if(elemento < arr[pivo]) f = pivo - 1;
            else return pivo;
        }
        return -1;
    }


int main(){
    vector <int> arr {1,4,6,3,5,9,10}; 

    sort(arr.begin(),arr.end()); 
    
    cout << buscaBinaria(arr, 10) << endl;
    cout << buscaBinaria(arr, 1) << endl;
    
}
