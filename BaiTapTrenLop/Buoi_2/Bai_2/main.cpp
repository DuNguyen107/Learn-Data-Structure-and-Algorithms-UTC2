#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};
struct List
{
    Node *pHead;
    Node *pTail;
};

Node *getNode(int x)
{
    Node* p = new Node;
    p->data = x;
    p->next = NULL;
    return p;
}

void addHead(List &L, int x)
{
    Node *p = getNode(x);
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
    Node *p = getNode(x);
    if(L.pHead == NULL)
        L.pHead = L.pTail = p;
    else
    {
        L.pTail->next = p;
        L.pTail = p;
    }
}

void printList(List L)
{
    Node* p = L.pHead;
    while(p != NULL)
    {
        cout << p->data << ' ';
        p = p->next; // Nháº£y qua Äáº±ng sau
    }
}


int main()
{
    List L;
    L.pHead=L.pTail=NULL; // ds rá»ng
    while(1){
        int x; cin >> x;
        if(x ==3)
            break;
        else if(x==1)
        {
            int y; cin >> y;
            addTail(L,y);
        }
        else
        {
            int y; cin >> y;
            addHead(L,y);

        }
    }
    printList(L);
}
