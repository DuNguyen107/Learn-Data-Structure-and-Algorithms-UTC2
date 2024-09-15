/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
[
###End banned keyword*/

#include <iostream>
using namespace std;


//###INSERT CODE HERE -
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

void addAfter(List &L, int a, int b)
{
    Node *p = getNode(b);
    Node *tmp = L.pHead;

    while (tmp != NULL && tmp->data != a)
    {
        tmp = tmp->next;
    }

    if (tmp == NULL)
    {
        addHead(L, b);
        return;
    }

    p->next = tmp->next;
    tmp->next = p;

    if (tmp == L.pTail)
    {
        L.pTail = p;
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
    while(1){
        int x; cin >> x;
        if(x ==3)
            break;
        else if(x==1)
        {
            int y; cin >> y;
            addTail(L,y);
        }
        else if(x==0)
        {
            int y; cin >> y;
            addHead(L,y);
        }
        else
        {
            int a, b; cin >> a >> b;
            addAfter(L,a,b);
        }
    }
    printList(L);
}
