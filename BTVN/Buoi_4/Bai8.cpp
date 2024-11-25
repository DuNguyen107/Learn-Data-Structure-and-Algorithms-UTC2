
#include <iostream>
using namespace std;

struct Node
{
    int info;
    Node *pLeft;
    Node *pRight;
};
typedef struct Node* Tree;
Node *getNode(int x);
void insertNode(Tree & T, int x);
void inputTree(Tree &T);
void NLR(Tree T);
int nodesWithLevel(Tree T, int k, int c);

int main()
{
    Tree T = NULL;
    inputTree(T);
    cout<<"\nNLR: "; NLR(T);
    int k; cout<<"\nEnter k: "; cin >>k;
    cout<<nodesWithLevel(T,k,0); 

    return 0;
}
Node* getNode(int x) {
    Node* p = new Node;
    p->info = x;
    p->pLeft = p->pRight = NULL;
    return p;
}

void insertTree(Tree &T, int x) {
    if (T == NULL) {
        T = getNode(x);
    } else {
        if (x < T->info)
            insertTree(T->pLeft, x);
        else if (x > T->info)
            insertTree(T->pRight, x);
    }
}
void NLR(Tree T){
	if(!T) return;
	cout << T->info << ' ';
	NLR(T->pLeft); // doc het nhanh trai
	NLR(T->pRight);
}
void inputTree(Tree &T) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        insertTree(T, x);
    }
}

int n = 0;
int nodesWithLevel(Tree T, int k, int level) {
    if(T == NULL) return 0;
    int dem = 0;
    if(n==0){
        cout << "\nList of nodes with level " << k << " (R->L): ";
        n = 1;
    }
    if(level == k){
        cout << T->info << " ";
        dem = 1;
    }else {
        dem += nodesWithLevel(T->pRight, k, level + 1);
        dem += nodesWithLevel(T->pLeft, k, level + 1);
    }
    if(n==1 && level == 0){
        cout << "\nNumber of nodes with level " << k << ": ";
        n = 0;
    }
    return dem;
}