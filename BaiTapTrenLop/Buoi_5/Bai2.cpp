/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -
struct Node{
	int info;
	Node *left, *right;
};
//struct Tree{
//	node* root;
//};
typedef Node* Tree;
Tree getNode(int x){
	Tree T = new Node;
	T->info = x;
	T->left = NULL;
	T->right = NULL;
	return T;
}
void insertTree(Tree &T, int x){
	Node* p = getNode(x);
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
Node* Search(Tree T, int x){
	if(T->info == x) return T;
	if(x > T->info)
		return Search(T->right,x);
	else if(x < T->info)
		return Search(T->left,x);
	return NULL;
}
int minValue(Tree T){
	if(T->left == NULL) return T->info;
	return minValue(T->left);		
}
int maxValue(Tree T){
	if(T->right == NULL) return T->info;
	return maxValue(T->right);			
}
int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"LNR: "; LNR(T); cout<<endl;


    int x; cout<<"\nEnter the element you want to find: ";cin>>x;
    Node *p=Search(T,x);
    if (p) cout<< "Found";
    else cout<<"Not found";
    cout<<"\nMinimum value in BTS is "<<minValue(T);
    cout<<"\nMinimax value in BTS is "<<maxValue(T);


	return 0;
}