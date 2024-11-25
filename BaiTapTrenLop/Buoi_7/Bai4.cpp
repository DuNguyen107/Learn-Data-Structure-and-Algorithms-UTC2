#include <iostream>
using namespace std;

struct Node {
    int info;
    Node *left, *right;
};

typedef Node* Tree;

Node* getNode(int x) {
    Node* p = new Node;
    p->info = x;
    p->left = p->right = NULL;
    return p;
}

void insertTree(Tree &T, int x) {
    if (T == NULL) {
        T = getNode(x);
    } else {
        if (x < T->info)
            insertTree(T->left, x);
        else if (x > T->info)
            insertTree(T->right, x);
    }
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
void nodesWithLevel(Tree T, int k, int level = 0) 
{
    if (!T) return;
    if (level == k)
	{	
        cout << T->info << " ";
    } 
	else 
	{
        nodesWithLevel(T->right, k, level + 1);
        nodesWithLevel(T->left, k, level + 1);
    }
}

int main()
{
	Tree T = NULL;
	inputTree(T);
    int k; cout<<"Enter k: "; cin >>k;
    cout<<"\nList of nodes with level "<<k<<" (R->L) : ";
    nodesWithLevel(T, k);

	return 0;
}