#include <iostream>

using namespace std;

void windowSliding(string &word){

    string temp;

    for(int i = 1; i <= word.size(); i++){

        for(int j = 0; j < word.size(); j++){

            temp = "";

            for(int k = 0; k < i && i + j <= word.size() && j + k < word.size(); k++){

                cout << word[i + j];

            }

            cout << endl;

        }

    }

}

int main(){
  
  string word = "ABCDEF"
  windowSliding(word);
  /*
  OUTPUT:

  A
  B
  C
  D
  E
  F
  
  AB
  BC
  CD
  DE
  EF
  
  ABC
  BCD
  CDE
  DEF
  
  ABCD
  BCDE
  CDEF
  
  ABCDE
  BCDEF
  ABCDEF
  
  */
  
}
