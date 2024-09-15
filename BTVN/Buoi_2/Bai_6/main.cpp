
#include <iostream>
#include <cstring>
#include <string>
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

void eraseTail(List &L){
    if(L.pHead == NULL) // ko co phan tu
        return;
    if(L.pHead == L.pTail){ // co 1 phan tu
        delete L.pHead;
        L.pHead = L.pTail = NULL;
    }
    else{
        node* p = L.pHead;
        while(p != NULL){
            if(p->next == L.pTail){
                delete L.pTail;
                p->next = NULL;
                L.pTail = p;
            }
            p = p->next;
        }
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

void moveLastToFront(List &L){
    if(L.pHead == NULL || L.pHead == L.pTail)
        return;
    node* p = L.pHead;
    while(p->next != NULL){
        p = p->next;
    }
    addHead(L,stoi(p->info));
    eraseTail(L);
}

int main()
{
    List L;
    L.pHead=L.pTail=NULL;
    int n; cin>>n;
    inputList(L,n);
    cout<<"Created List: "<<endl;
    outputList(L);
    cout<<endl;

    moveLastToFront(L); //di chuyen node cuoi ve dau danh sach
    cout<<"Updated List after moving the last element to front of L: "<<endl;
    outputList(L);
    return 0;
}
