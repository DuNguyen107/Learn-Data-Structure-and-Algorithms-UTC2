
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
//void NLR(Tree T){
//	if(!T) return;
//	cout << T->info << ' ';
//	NLR(T->left); // doc het nhanh trai
//	NLR(T->right);
//}
//void LRN(Tree T){
//	if(!T) return;
//	LRN(T->left); // doc het nhanh trai
//	LRN(T->right);
//	cout << T->info << ' ';
//}
//int dem = 0;
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
int countNodes(Tree T){
	if(!T) return 0;
	return countNodes(T->left) + countNodes(T->right) + 1;
}

int depthOfTree(Tree T){
	if(!T) return -1;
	return max(depthOfTree(T->left), depthOfTree(T->right)) + 1;
}
void countEven(Tree T, int &count_even){
	if(!T) return ;
	if(T->info % 2 == 0){
		count_even++;
	}
	countEven(T->left, count_even);
	countEven(T->right, count_even);
}
void countOdd(Tree T, int &count_odd){
	if(!T) return ;
	if(T->info % 2 != 0){
		count_odd++;
	}
	countOdd(T->left, count_odd);
	countOdd(T->right, count_odd);
}
int countPositive(Tree T){
	if(!T) return 0;
	int dem = 0;
	if(T->info > 0) dem++;
	return dem+countPositive(T->left)+countPositive(T->right);
}
int countNegative(Tree T){
	if(!T) return 0;
	int dem = 0;
	if(T->info < 0) dem++;
	return dem+countNegative(T->left)+countNegative(T->right);
}
int prime(int n){
	if(n<2) return 0;
	for(int i=2; i<=n/2; i++){
		if(n%i == 0)
			return 0;
	}
	return 1;
}
int countPrime(Tree T){
	if(!T) return 0;
	int dem = 0;
	if(prime(T->info)) dem++;
	return dem + countPrime(T->left) + countPrime(T->right);
}
void listPrime(Tree T){
	if(!T) return;
	if(prime(T->info))
		cout << T->info << ' ';
	listPrime(T->left); // doc het nhanh trai
	listPrime(T->right);
}
int main()
{
	Tree T = NULL;
	inputTree(T);
    cout<<"LNR: "; LNR(T); cout<<endl;

	cout<<"Number of nodes: " << countNodes(T)<<endl;
    cout<<"Depth of Tree: "<<depthOfTree(T)<<endl;

    int count_even = 0, count_odd =0;
    countEven(T, count_even);countOdd(T, count_odd);
    cout<<"Number of even nodes: "<<count_even<<endl;
    cout<<"Number of odd nodes: "<<count_odd<<endl;

    cout<<"Number of positive nodes: "<<countPositive(T)<<endl;
    cout<<"Number of negative nodes: "<<countNegative(T)<<endl;

    cout<<"Number of prime nodes: "<<countPrime(T)<<endl;
    cout<<"Prime numbers: "; listPrime(T);



	return 0;
}
