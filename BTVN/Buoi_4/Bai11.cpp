#include <iostream>
using namespace std;

struct node{
	int info;
	node *left, *right;
};
typedef node* Tree;
Tree getNode(int x){
	Tree T = new node;
	T->info = x;
	T->left = NULL;
	T->right = NULL;
	return T;
}

void insertTree(Tree &T, int x){
	node*p = getNode(x);
	if(T!=NULL){
		if(x == T->info)
			cout << " ";
		else if(x < T->info) //x them vao nhanh trai
			insertTree(T->left, x);
		else 
			insertTree(T->right,x);
	}else{ // cay hien tai o lan de quy do co goc la NULL
		T = getNode(x);
	}	
}
void inputTree(Tree &T){
	int n; cin >> n;
	int x;
	for(int i=1; i<=n; i++){
		cin >> x;
		insertTree(T,x);
	}
}

int SearchFloor(Tree T, int x) {
    if (T == NULL) {
        return 0;
    }
	int res = 201;
	while(T!=NULL){
		if (T->info == x) {
            res = T->info;
            break;
        } 
        else if (T->info < x) {
            res = T->info;
            T = T->right; 
        } 
        else {
            T = T->left; 
        }
	}
	return res;
}

int main()
{
	Tree T = NULL;
	inputTree(T);
	int x; cin >> x;
    cout << SearchFloor(T,x);
	return 0;
}
