#include <iostream>

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

void addHead(List L, int x)
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

void printList(List L)
{
    Node* p = L.pHead;
    while(p != NULL)
    {
        cout << p->data << ' ';
        p = p->next; // Nhảy qua đằng sau
    }
}


int main()
{
    List L;
    L.pHead=L.pTail=NULL; // ds rỗng
}