
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
void NLR(Tree T){
	if(!T) return;
	cout << T->info << ' ';
	NLR(T->left); // doc het nhanh trai
	NLR(T->right);
}
void LRN(Tree T){
	if(!T) return;
	LRN(T->left); // doc het nhanh trai
	LRN(T->right);
	cout << T->info << ' ';
}
void LNR(Tree T){
	if(!T) return;
	LNR(T->left); // doc het nhanh trai
	cout << T->info << ' ';
	LNR(T->right);
}
void inputTree(Tree &T){
	int n; cin >> n;
	int x;
	for(int i=1; i<=n; i++){
		cin >> x;
		insertTree(T,x);
	}
}
int depthOfTree(Tree T){
	if(!T) return -1;
	return max(depthOfTree(T->left), depthOfTree(T->right)) + 1;
}

int isAVL(Tree T){
	if(!T) return 1;
	if(isAVL(T->left)==0) return 0;
	if(isAVL(T->right)==0) return 0;
	if(abs(depthOfTree(T->left) - depthOfTree(T->right)) > 1) return 0;
	return 1;
}
int main()
{
	Tree T = NULL;
	inputTree(T);
    cout<<isAVL(T);
	return 0;
}