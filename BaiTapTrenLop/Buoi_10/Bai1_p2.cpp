
#include <iostream>
#include <cstring>
#include <string>
#define MAX 1000
using namespace std;

struct node{
	int info;
	node* next;	
};

node* getNode(int x)
{
    node*p = new node;
    p->info = x;
    p->next = NULL;
    return p;
}
struct Hash{
	int m;
	node **b; // con trỏ quản lý mảng chứa các con trỏ đầu(head)
	int n;
};
void initHash(Hash &H){
	H.n = 0;
	H.b = new node* [H.m];
	for(int i=0; i<H.m; i++){
		H.b[i] = NULL;
	}
}
int hashfunc(int x, Hash &H){
	return x % H.m;
}
void addList(node* &head, int x){// thêm phần tử vào danh sách liên kết
	node *new_ele = getNode(x);
	
	//tìm vị trí phù hợp trong ds để thêm
	//lần lượt xét qua từng node, nếu x > giá trị của node thì đi tiếp
	if(head == NULL) {
		head = new_ele; 
		return;
	}
	node*p = head, *q = NULL;
	while(p != NULL && x > p->info){
		q = p;
		p = p->next;
	}
	/*Khi while dừng lại thì có những trường hợp:
	1. ds rỗng
	2. x < giá trị của node -> thêm x vào sau node trước
	3. hết ds -> thêm vào cuối
	4. thêm vào đầu
	*/
	if(q == NULL){
		new_ele->next = head;
		head = new_ele;
	}
	else{
		new_ele->next = q->next;
		q->next = new_ele;
	}
}
void insertHash(Hash H,int x){
	int idx = hashfunc(x,H);
	addList(H.b[idx],x);
}
void printList(node* head){
	node* p =head;
	while(p != NULL){
		cout << p->info << " ";
		p = p->next;
	}
}
void traverseAllHash(Hash H){
	for(int i=0; i<H.m; i++){
		cout << "Bucket " << i << ": ";
		printList(H.b[i]);
		cout << endl;
	}
}
int main()
{
    Hash H;
    cin>>H.m; // m la so dia chi co trong bang bam
    initHash(H); //khoi tao cac bucket

    int n,x;cin>>n; // n la so luong gia tri can phai luu tru
    for (int i = 1; i<=n;i++)
    {
        cin>>x;
        insertHash(H,x); // them 1 gia tri du lieu vao bang bam
    }
    cout<<"Created Hash:"<<endl;
    traverseAllHash(H); // Xuat toan bo cac bucket cua Bang bam

    return 0;
}

