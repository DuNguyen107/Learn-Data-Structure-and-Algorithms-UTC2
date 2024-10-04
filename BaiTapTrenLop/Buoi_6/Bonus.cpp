
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
void inputTree(Tree &T){
	int n; cin >> n;
	int x;
	for(int i=1; i<=n; i++){
		cin >> x;
		insertTree(T,x);
	}
}
int countNodes(Tree T){
	if(!T) return 0;
	return countNodes(T->left) + countNodes(T->right) + 1;
}
int countLeafs(Tree T){
	if(!T) return 0;
    int dem = 0;
	if(T->left == NULL && T->right == NULL){
		dem++;
	}
	return dem + countLeafs(T->left)+countLeafs(T->right);
}
int n = 0;
int countInternalNodes(Tree T){
	if(!T) return 0;
	int dem = 0;
	if((T->left != NULL || T->right != NULL) && n)
		dem++;
	n = 1;
	return dem + countInternalNodes(T->left)+countInternalNodes(T->right);	
}
int countOneChild(Tree T){
	if(!T) return 0;
	int dem = 0;
	if((T->left == NULL && T->right != NULL) || (T->left != NULL && T->right == NULL)){
		dem++;
	}
	return dem+countOneChild(T->left)+countOneChild(T->right);
}
int countTwoChildren(Tree T){
	if(!T) return 0;
	int dem = 0;
	if(T->left != NULL && T->right != NULL){
		dem++;
	}
	return dem + countTwoChildren(T->left)+countTwoChildren(T->right);
}
int countLess(Tree T,int x){
	if(!T) return 0;
	int dem = 0;
	if(T->info < x){
		dem++;
	}
	return dem + countLess(T->left,x)+countLess(T->right,x);
}
int countBetweenValues(Tree T,int x, int y){
	if(!T) return 0;
	int dem = 0;
	if(T->info > x && T->info < y){
		dem++;
	}
	return dem + countBetweenValues(T->left,x,y)+countBetweenValues(T->right,x,y);
}
// void LNR(Tree T){
// 	if(!T) return;
// 	LNR(T->left); 
// 	cout << T->info << ' ';
// 	LNR(T->right);
// }
// int isCompleteBinaryTree (Tree T){
// 	if(!T) return 0;
// 	if(!T->left || !T->right){
// 		return 0;
// 	}
	
// }
// int main()
// {
// 	Tree T = NULL;
// 	inputTree(T);
// 	cout<<"LNR: "; LNR(T);
// 	int i=isCompleteBinaryTree (T);
// 	if(i==0) cout<<"\nThe tree is not a Complete Binary Tree";
//     else cout<<"\nThe tree is a Complete Binary Tree";
// 	return 0;
// }



