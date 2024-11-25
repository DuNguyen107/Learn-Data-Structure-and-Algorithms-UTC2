
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
node* Search(Tree T, int x) {
    if (T == NULL) {
        return NULL;
    }
    if (T->info == x) {
        return T;
    }
    
    node* leftResult = Search(T->left, x);
    if (leftResult != NULL) return leftResult;
    
    return Search(T->right, x);
}

void SetLeft(node* T, int c) {
    if (T == NULL) {
        return;
    }
    if (T->left == NULL) {
        T->left = getNode(c);
    } 
}

void SetRight(node* T, int c) {
    if (T == NULL) {
        return;
    }
    if (T->right == NULL) {
        T->right = getNode(c);
    } 
}

void DeleteLeft(node* T){
    if(T==NULL){
        cout<<"Node khong ton tai\n";
        return;
    }
    if (T->left == NULL) {
         cout << "Khong co node ben trai\n";
    } else {
        if(T->left->left == NULL && T->left->right == NULL){
            delete T->left;
            T->left = NULL;
        }
        else
            cout << "Khong la node la nen khong xoa duoc\n";
    }
}
void DeleteRight(node *T){
    if(T==NULL){
        cout<<"Node khong ton tai\n";
        return;
    }
    if (T->right == NULL) {
         cout << "Khong co node ben phai\n";
    } else {
        if(T->right->left == NULL && T->right->right == NULL){
            delete T->right;
            T->right = NULL;
        }
        else
            cout << "Khong la node la nen khong xoa duoc\n";
            
    }
}
int main()
{
	Tree T = NULL;
	int x,b,c; char a;
	cin>>x;	T=getNode(x); // tao nut goc
	while(true)
    {
        cin>>a; // Ky tu cho biet chen vao trai hay phai
        if(a!='L'&& a!='R') break;
        cin>>b>>c;
        if(a=='L') SetLeft(Search(T,b),c);
        else if (a=='R') SetRight(Search(T,b),c);

    }
	cout<<"LNR: "; LNR(T);
	cout<<"\nDelete some nodes:\n";
	string s;
	while(true)
    {
        cin>>s; // Chuoi cho biet xoa ben trai hay ben phai
        if(s!="DL"&& s!="DR") break;
        cin>>b;
        if(s=="DL") DeleteLeft(Search(T,b));
        else if(s=="DR") DeleteRight(Search(T,b));

    }
    cout<<"\nLNR: "; LNR(T);

	return 0;
}
