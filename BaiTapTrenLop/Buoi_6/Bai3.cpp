
#include <iostream>
using namespace std;

//###INSERT CODE HERE -
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
void inputTree(Tree &T){
	int n; cin >> n;
	int x;
	for(int i=1; i<=n; i++){
		cin >> x;
		insertTree(T,x);
	}
}
void rotateLeft(Tree &T){
	if(!T){
		cout<< "\nKhong the xoay vi cay rong";
		return;
	}
	if(!T->right){
		cout<< "\nKhong the xoay trai vi khong co nut con ben phai";
		return;
	}	
	node* p = T->right;
	T->right = p->left;
	p->left = T;
	T= p;
}

int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"\nNLR: "; NLR(T);
	rotateLeft(T);
	cout<<"\nNLR: "; NLR(T);
	return 0;
}
