#include <iostream>
using namespace std;

struct node
{
    int info;
    node* next;
};

struct List
{
    node* pHead;
    node* pTail;
};

node* getNode(int x)
{
    node*p = new node;
    p->info = x;
    p->next = NULL;
    return p;
}

void Init(List &L)
{
    L.pHead = NULL;
    L.pTail = NULL;
}

void addHead(List &L, int x)
{
    node* p = getNode(x);
    if(L.pHead == NULL)
        L.pHead = L.pTail = p;
    else
    {
        p->next = L.pHead;
        L.pHead = p;
    }
}

void addTail(List &L, int x)
{
    node* p = getNode(x);
    if(L.pHead == NULL)
        L.pHead = L.pTail = p;
    else
    {
        L.pTail->next = p;
        L.pTail = p;
    }
}
void moveHead(List &L){
    node* p = L.pHead;
    node* q = NULL;
    while(p->next != NULL){
        q = p;
        p = p->next;
    }  
    q->next = p->next;
    L.pTail = q;
    p->next = L.pHead->next;
    L.pHead = p;
}
void inputList(List &L, int m)
{
    int x;
    for(int i=1; i<=m; i++){
        cin >> x;
        if(x != L.pTail->info){
            addHead(L,x);
            cout << L.pTail->info << ' ';
        }else{
            moveHead(L);
            cout << L.pTail->info << ' ';
        }
    }
}
// void outputList(List L)
// {
//     node *p = L.pHead;
//     while(p != NULL){
//         if(a[p->info] > 1){
//             cout << p->info << ' ';
//             a[p->info] = -1;
//         }
//         else if(a[p->info] == 1){
//             cout << p->info << ' ';
//         }
//         p=p->next;
//     }
// }
int main(){
	int n,m; cin >> n >> m;
    List L; Init(L);
    for(int i=1; i<=n; i++){
    	addTail(L,i);
	}
    inputList(L,m);
    // outputList(L);
    // for(int i=1; i<=n; i++){
    //     if(a[i] == 0){
    //         cout << i << ' ';
    //         a[i] = 1;
    //     }
    // }
    
}