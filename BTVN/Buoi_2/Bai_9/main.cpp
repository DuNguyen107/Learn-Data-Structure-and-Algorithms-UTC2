
#include <iostream>
#include <cstring>
#include <string>
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
    if(p == NULL)
        exit(1);
    p->info = x;
    p->next = NULL;
    return p;
}

void Init(List &L)
{
    L.pHead = NULL;
    L.pTail = NULL;
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


void inputList(List &L, int n)
{
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        node* p = getNode(x);
        if (L.pHead == NULL) {
            L.pHead = L.pTail = p;
        } else {
            L.pTail->next = p;
            L.pTail = p;
        }
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

void concate(List &L1, List &L2){
    if (L2.pHead == NULL)  
        return;
    if (L1.pHead == NULL) {
        L1 = L2;
        return;
    } else {
        node* temp = L1.pHead;
        while(temp->next != NULL)
        	temp = temp->next;
        temp->next = L2.pHead;
    }     
}


int main()
{
    List L1, L2;
    Init(L1);Init(L2);

    int n; cin>>n;
    inputList(L1,n);
    cout<<"Created 1st List: "<<endl;
    outputList(L1);
    cout<<endl;

    cin>>n;
    inputList(L2,n);
    cout<<"Created 2nd List: "<<endl;
    outputList(L2);
    cout<<endl;

    concate(L1,L2); // Noi L2 vao L1
    cout<<"Updated L1: "<<endl;
    outputList(L1);

    return 0;
}
