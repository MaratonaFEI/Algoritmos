#include <iostream>
#include <vector>

using namespace std;

class FenwickTree {

    public:

        int getSum(vector<int> BITree, int index);
        void updateBIT(vector<int> &BITree, int index, int val);
        int sum(int x, vector<int> BITree1, vector<int> BITree2);
        void updateRange(vector<int> &BITree1, vector<int> &BITree2, int val, int l, int r);
        int rangeSum(int l, int r, vector<int> BITree1, vector<int> BITree2);
        vector<int> constructBITree(int n);
        void print(vector<int> BITree);

};

int FenwickTree::getSum(vector<int> BITree, int index){

    int sum = 0;
 
    index = index + 1;
 
    while (index > 0) {
       
        sum += BITree[index];
 
        index -= index & (-index);
    }
    return sum;
};

void FenwickTree::updateBIT(vector<int> &BITree, int index, int val){

    index = index + 1;
 
    while (index <= BITree.size() - 1) {
     
        BITree[index] += val;
 
        index += index & (-index);
    }

};

int FenwickTree::sum(int x, vector<int> BITree1, vector<int> BITree2){

    return (getSum(BITree1, x) * x) - getSum(BITree2, x);

}

void FenwickTree::updateRange(vector<int> &BITree1, vector<int> &BITree2, int val, int l, int r){

    updateBIT(BITree1, l, val);
    updateBIT(BITree1, r + 1, -val);
 
    updateBIT(BITree2, l, val * (l - 1));
    updateBIT(BITree2, r + 1, -val * r);

}

int FenwickTree::rangeSum(int l, int r, vector<int> BITree1, vector<int> BITree2){

    return sum(r, BITree1, BITree2) - sum(l - 1, BITree1, BITree2);

}

vector<int> FenwickTree::constructBITree(int n){

    vector<int> BITree(n+1);

    for(int i = 1; i <= n; i++) BITree[i] = 0;

    return BITree;
}

void FenwickTree::print(vector<int> BITree){

    for(int x : BITree) cout << x << " ";
    cout << '\n';
}

int main(){

    int n = 5;

    FenwickTree ft;

    vector<int> BITree1, BITree2;

    BITree1 = ft.constructBITree(n);
    BITree2 = ft.constructBITree(n);

    int l = 0, r = 4, val = 5;
    ft.updateRange(BITree1, BITree2, val, l, r);
 
    ft.print(BITree1);
    ft.print(BITree2);

    l = 2, r = 4, val = 10;
    ft.updateRange(BITree1, BITree2, val, l, r);

    ft.print(BITree1);
    ft.print(BITree2);

    l = 1, r = 4;

    cout << "Sum of elements from [" << l << "," << r
         << "] is ";
    cout << ft.rangeSum(l, r, BITree1, BITree2) << "\n";

}
