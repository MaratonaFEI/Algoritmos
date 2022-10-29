#include <iostream>

using namespace std;

class No {
    public:
        No(int valor){
            this->valor = valor;
            this->esq = NULL;
            this->dir = NULL;
        }

        int valor;
        No *esq;
        No *dir;
};

class AB {

    public:

        No *raiz;

        bool insere(int valor){
            No *novo = new No(valor);
            if(raiz == NULL){
                raiz = novo;
                return true;
            }

            No *anterior = NULL;
            No *atual = raiz;

            while(atual != NULL){
                anterior = atual;
                if(valor < atual->valor) atual = anterior->esq;
                else if(valor > atual->valor) atual = anterior->dir;
            }

            if(valor < anterior->valor) atual->esq = novo;
            else if(valor > anterior->valor) atual->dir = novo;

            return true;

        }

        void imprime(No *pai){
            if(pai == NULL){
                cout << "PAI NULL" << endl;   
                return;
            }
            cout << pai->valor << endl;
            imprime(pai->esq);
            imprime(pai->dir);
        
        }

};

int main(){

    int T, tam, n;

    cin >> T;

    while(T--){
        AB *arv = new AB();
        cin >> tam;
        for(int i = 0; i < tam; i++){
            cin >> n;
            arv->insere(n);
        }

        arv->imprime(arv->raiz);

    }

}
