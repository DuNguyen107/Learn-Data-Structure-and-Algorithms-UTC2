
#include<iostream>
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
		if(x == T->info){
			cout<<"Bi trung gia tri, ket thuc qua trinh tao cay"<<endl;
			return;
		}
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
	int x, a[100] = {0};
	for(int i=1; i<=n; i++){
		cin >> x;
		insertTree(T,x);
		if(a[x] == 1) return;
		a[x] = 1;
	}
	
}

int main()
{
	Tree T = NULL;
	inputTree(T); //Khi bi trung gia tri thi ket thuc qua trinh tao cay, khong nhap tiep nua
	cout<<"NLR: "; NLR(T);
	return 0;
}



