
#include <iostream>
using namespace std;
struct node
{
    string info;
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
    p->info = to_string(x);
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

node* SearchValue(List L, int a){
    node* p = L.pHead;
    while(p != NULL){
        if(p->info == to_string(a))
            return p;
        p = p->next;
    }
    return NULL;
}
void addAfter(List &L, int a, int b){
    node* k = SearchValue(L,a);
    if(k == NULL){
        addHead(L,b);
        return;
    }
    node* p = getNode(b);
    p->next = k->next;
    k->next = p;

    if(k == L.pTail)
        L.pTail = p;
}

void eraseHead(List &L){
    if(L.pHead == NULL) // ko co phan tu
        return;
    if(L.pHead == L.pTail){ // co 1 phan tu
        delete L.pHead;
        L.pHead = L.pTail = NULL;
    }
    else{
        node *p = L.pHead;
        L.pHead = L.pHead->next;
        delete p;
    }
}
void inputList(List &L, int n)
{
    for(int i=1; i<=n; i++){
        int x; cin >> x;
        addTail(L,x);
    }
}

void outputList(List L)
{
    if(L.pHead == NULL){
        cout << "List is empty";
        return;
    }
    node *p = L.pHead;
    while(p != NULL){
        cout << p->info << ' ';
        p = p->next;
    }
}

int main()
{
    List L;
    Init(L);
    while(1){
        int x; cin >> x;
        if(x == 0){
            int n; cin >> n;
            addHead(L,n);
        }else if(x == 1){
            int n; cin >> n;
            addTail(L,n);
        }else if(x == 2){
            int a, b; cin >> a >> b;
            addAfter(L, a, b);
        }else if(x == 5){
            eraseHead(L);
        }else
            break;
    }
    if(L.pHead == NULL)
        cout << "blank";
    else
        outputList(L);
    return 0;
}
