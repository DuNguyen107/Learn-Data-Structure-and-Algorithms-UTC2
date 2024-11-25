
#include <iostream>
using namespace std;

struct Node
{
    int info;
    Node *pLeft;
    Node *pRight;
};
typedef struct Node* Tree;

Node *getNode(int x);
void insertNode(Tree & T, int x);
void inputTree(Tree &T);
void NLR(Tree T);
bool isSquare (int n);
void SearchStandFor(Node* &p, Node* &q); //Chon node phai nhat tren nhanh con ben trai
void deleteSquareNumbers(Tree &T);

int main()
{
    Tree T = NULL;
    inputTree(T);
    cout<<"\nNLR: "; NLR(T);
    cout<<"\nDelete all square numbers:";
    deleteSquareNumbers(T);
    cout<<"\nNLR: "; NLR(T);

    return 0;
}
Tree getNode(int x){
	Tree T = new Node;
	T->info = x;
	T->pLeft = NULL;
	T->pRight = NULL;
	return T;
}
void insertTree(Tree &T, int x){
	Node* p = getNode(x);
	if(T!=NULL){
		if(x == T->info)
			cout << " ";
		else if(x < T->info) //x them vao nhanh trai
			insertTree(T->pLeft, x);
		else 
			insertTree(T->pRight,x);
	}else{ // cay hien tai o lan de quy do co goc la NULL
		T = getNode(x);
	}	
}
void NLR(Tree T){
	if(!T) return;
	cout << T->info << ' ';
	NLR(T->pLeft); // doc het nhanh trai
	NLR(T->pRight);
}
void inputTree(Tree &T){
	int n; cin >> n;
	int x;
	for(int i=1; i<=n; i++){
		cin >> x;
		insertTree(T,x);
	}
}
bool isSquare (int n){
	for(int i=1; i<=n/2; i++){
		if(i*i == n) return true;
	}
	return false;
}

void SearchStandFor(Node* &p, Node* &q) {
	if (q->pRight != NULL) {
		SearchStandFor(p, q->pRight);
	} else {
		p->info = q->info;
		p = q;
		q = q->pLeft;
	}
}

void deleteSquareNumbers(Tree &T) {
	if (T == NULL) return;
	if(isSquare(T->info) || T->info == 1){
		Node *p = T;
		if(T->pLeft == NULL){ //T hoac la node la hoac co node con ben phai
			T = T->pRight;
		}else if(T->pRight == NULL){
			T = T->pLeft;
		}else{
			SearchStandFor(p, T->pLeft);
		}
		delete p;
		deleteSquareNumbers(T);
	}else{
		deleteSquareNumbers(T->pLeft);
		deleteSquareNumbers(T->pRight);
	}
}

