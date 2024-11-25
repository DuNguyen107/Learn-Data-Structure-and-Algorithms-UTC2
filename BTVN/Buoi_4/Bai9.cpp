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
vector<int> v;
int Search(Tree T, int x) {
    if (T == NULL) {
        return 0;
    }
	v.push_back(T->info);
    if (T->info == x) {
        return 1;
    }
	if(Search(T->left, x) || Search(T->right, x)) return 1;
	v.pop_back();
	return 0;
}
int main()
{
	Tree T = NULL;
	inputTree(T);
	int x; cin >> x;
	if(Search(T,x)){
		cout << "Found. Path: ";
		for(auto i : v){
			cout << i << " ";
		}
	}else{
		cout << "Not found";
	}
	
}
