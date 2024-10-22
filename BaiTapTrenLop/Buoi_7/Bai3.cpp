
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
        cout << "Node khong ton tai\n"; // node cha không tồn tại
        return;
    }
    if (T->left == NULL) {
        T->left = getNode(c);
    } else {
        cout << "Da co node con ben trai\n"; // Báo lỗi nếu đã có con trái
    }
}

void SetRight(node* T, int c) {
    if (T == NULL) {
        cout << "Node khong ton tai\n"; // node cha không tồn tại
        return;
    }
    if (T->right == NULL) {
        T->right = getNode(c);
    } else {
        cout << "Da co node con ben phai\n"; // Báo lỗi nếu đã có con phải
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
        if(a!='L'&& a!='R') break; // Neu khong phai L hoac R thi ket thuc viec tao cay
        cin>>b>>c;
        if(a=='L') SetLeft(Search(T,b),c); // chen c vao ben trai b
        else if (a=='R') SetRight(Search(T,b),c); // chen c vao ben phai b
    }
	cout<<"\nLNR: "; LNR(T); cout<<endl;

	return 0;
}



