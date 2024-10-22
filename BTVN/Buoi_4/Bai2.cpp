
#include <iostream>
#include <string>
using namespace std;


typedef struct Product{
	int id;
	string name;
	string type;
	int year;
	int warranty;
} PRO;
struct node{
	PRO info;
	node *left, *right;
};
typedef node* Tree;
Tree getNode(PRO x){
	Tree T = new node;
	T->info = x;
	T->left = NULL;
	T->right = NULL;
	return T;
}
void insertTree(Tree &T, PRO x){
	node* p = getNode(x);
	if(T!=NULL){
		if(x.id == T->info.id){
			cout << "";
		}
		else if(x.id < T->info.id) //x them vao nhanh trai
			insertTree(T->left, x);
		else 
			insertTree(T->right,x);
	}else{ // cay hien tai o lan de quy do co goc la NULL
		T = getNode(x);
	}	
}
// void NLR(Tree T){
// 	if(!T) return;
// 	cout << T->info << ' ';
// 	NLR(T->left); // doc het nhanh trai
// 	NLR(T->right);
// }
void inputTree(Tree &T){
	int n; cin >> n;
	PRO x;
	for(int i=1; i<=n; i++){
		cin >> x.id; cin.ignore();
		getline(cin, x.name);
		getline(cin, x.type);
		cin >> x.year;
		cin >> x.warranty;
		insertTree(T,x);
	}
	
}
void listProduct(Tree T,string t){
	if(!T) return;
	if(T->info.type == t){
		cout << T->info.id << "\t" << T->info.name << "\t"  << T->info.type << "\t";
		cout << T->info.year << "\t" << T->info.warranty << endl;
	}
	listProduct(T->left,t); // doc het nhanh trai
	listProduct(T->right,t);
}
int countProduct(Tree T,int y){
	if(!T) return 0;
	int dem = 0;
	if(T->info.warranty > y){
		dem++;
	}
	return dem + countProduct(T->left,y) + countProduct(T->right,y);
}


int main()
{
    Tree T = NULL;
    inputTree(T);

    string type;  cin.ignore(); getline(cin,type);
    cout<<"List of products whose type is  "<<type<<": ";
    cout<<"\nID\tName\tType\tYear\tWarranty\n";
    listProduct(T,type);

    int year;cin>>year;
    cout<<"Number of products with more than "<<year<<" years of warranty: "<<countProduct(T,year)<<endl;


	return 0;
}




