

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

void inputTree(Tree &T){
	int n; cin >> n;
	int x;
	for(int i=1; i<=n; i++){
		cin >> x;
		insertTree(T,x);
	}
}
void replace(node* &p, node* &r){
    if(r->left != NULL) replace(p,r->left);
    else{
        p->info = r->info;
		p = r;
		r = r->right;
    }
}
void deleteRoot(Tree &T, int m){
    for(int i=1; i<=m; i++){
		if(T == NULL) return;
		node*p = T;
		if(T->left == NULL) {
			T = T->right; 
		}
		else if(T->right == NULL) {
			T = T->left;
		}else
			replace(p,T->right);
		delete p;
	}
}

void deleteNode(Tree &T, int x){
	if(T == NULL) return;
	if(x < T->info){
		deleteNode(T->left,x);
	}else if(x > T->info){
		deleteNode(T->right,x);
	}else{
		node *p = T;
		if(T->left == NULL){ //T hoac la node la hoac co node con ben phai
			T = T->right;
		}else if(T->right == NULL){
			T = T->left;
		}else{
			replace(p,T->right);
		}
		delete p;
	}
}

int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"NLR: "; NLR(T);
    int x; cout<<"\nEnter the element you want to delete: ";cin>>x;
    deleteNode(T,x);
    cout<<"\nNLR: "; NLR(T);

	return 0;
}

