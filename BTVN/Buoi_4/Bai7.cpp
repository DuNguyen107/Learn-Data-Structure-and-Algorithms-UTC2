
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
void LNR(Tree T){
	if(!T) return;
	LNR(T->left); // doc het nhanh trai
	cout << T->info << ' ';
	LNR(T->right);
}
void insertTree(Tree &T, int x){
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
int depthOfTree(Tree T){
	if(!T) return 0;
	return max(depthOfTree(T->left), depthOfTree(T->right)) + 1;
}
bool isFullBinaryTree (Tree T){
	if(T == NULL) return true;
	if(T->left == NULL && T->right == NULL) return true;
	if (T->left != NULL && T->right != NULL) {
        return isFullBinaryTree(T->left) && isFullBinaryTree(T->right);
    }
	return false;
}
bool nodesWithLevel(Tree T, int k, int level) {
    if (!T) return true; 
    if (T->left == NULL && T->right == NULL) {
        return level == k; 
    }
    return nodesWithLevel(T->left, k, level + 1) && nodesWithLevel(T->right, k, level + 1);
}
int isCompleteBinaryTree (Tree T){
	if(T == NULL) return 1;
	int k = depthOfTree(T);
	if(isFullBinaryTree(T) && nodesWithLevel(T,k-1,0)){
		return 1;
	}
	return 0;
}

int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"LNR: "; LNR(T);
	int i=isCompleteBinaryTree (T);
	if(i==0) cout<<"\nThe tree is not a Complete Binary Tree";
    else cout<<"\nThe tree is a Complete Binary Tree";
	return 0;
}


