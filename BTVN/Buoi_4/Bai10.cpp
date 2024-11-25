#include <iostream>
#include<vector>
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
void LNR(Tree T){
	if(!T) return;
	LNR(T->left); // doc het nhanh trai
	cout << T->info << ' ';
	LNR(T->right);
}
void insertTree(Tree &T, int x){
	node* p = getNode(x);
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

void secondLargest(Tree T) {
    if (T == NULL || (T->left == NULL && T->right == NULL)) {
        return;
    }
	Tree p;
	while(T->right != NULL){
		p = T;
		T = T->right;
	}
	if (T->left != NULL) {
        T = T->left;
        while (T->right != NULL) {
            T = T->right;
        }
        cout << "2nd largest value is " << T->info << endl;
    }else{
		cout << "2nd largest value is " << p->info << endl;
	}
}

int main()
{
	Tree T = NULL;
	inputTree(T);
    secondLargest(T);
	return 0;
}
