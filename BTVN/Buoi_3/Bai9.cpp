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
int a[100005] = {0};
void inputList(List &L, int x)
{
    a[x]++;
    addHead(L,x);
}
void outputList(List L)
{
    node *p = L.pHead;
    while(p != NULL){
        if(a[p->info] > 1){
            cout << p->info << ' ';
            a[p->info] = -1;
        }
        else if(a[p->info] == 1){
            cout << p->info << ' ';
        }
        p=p->next;
    }
}
int main(){
	int n,m; cin >> n >> m;
    List L; Init(L);
    int x;
    for(int i=1; i<=m; i++){
        cin >> x;
        inputList(L,x);
    }
    outputList(L);
    for(int i=1; i<=n; i++){
        if(a[i] == 0){
            cout << i << ' ';
            a[i] = 1;
        }
    }
}