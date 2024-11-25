
#include <iostream>
#include <cstring>
#include <string>
#define M 10		// M là số nút có trên bảng băm, đủ để chứa các nút nhập vào bảng băm
#define NULLKEY -1
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
	int *hashtable; // con trỏ quản lý mảng chứa các con trỏ đầu(head)
	int n;
};
void initHash(Hash &H){
	H.n = 0;
	H.hashtable = new int[M] {NULLKEY};
}
int hashfunc(int x){
	return x % M;
}
bool isFull(Hash &H) {
    return H.n == M;
}
void insertHash(Hash H,int x){
	if(isFull(H)){
		cout << "\nBang bam bi day, khong them duoc";
		return;
	}
	int index = hashfunc(x);
	while(H.hashtable[index] != NULLKEY){
		// băm lại theo phương pháp dò tuyến tính
		index++;
		if(index == M) index= 0;
	}
	H.hashtable[index] = x;
	H.n++;
}
void traverseAllHash(Hash H){
	for(int i=0; i<M; i++){
		cout << "Insert " << i << ": " << H.hashtable[i] << endl;
	}
}
int main()
{
    Hash H;
    initHash(H);

    int n,x;cin>>n; // n la so luong gia tri can phai luu tru
    for (int i = 1; i<=n;i++)
    {
        cin>>x;
        cout<<"\nInsert "<<x;
        insertHash(H,x); // them 1 gia tri du lieu vao bang bam
    }
    cout<<"\nCreated Hash:"<<endl;
    traverseAllHash(H);

    return 0;
}

