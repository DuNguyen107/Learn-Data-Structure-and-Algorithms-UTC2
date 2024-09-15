/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
[
###End banned keyword*/

#include <iostream>
using namespace std;


//###INSERT CODE HERE -

struct khach{
    int stt;
    string monan;
};

struct Node
{
    khach data;
    Node* next;
};
struct List
{
    Node *pHead;
    Node *pTail;
};

Node *getNode(khach x)
{
    Node* p = new Node;
    p->data = x;
    p->next = NULL;
    return p;
}

void addTail(List &L, khach x)
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
        cout << p->data.stt << ' ' << p->data.monan << endl;
        p = p->next; // Nhảy qua đằng sau
    }
}


void eraseHead(List &L){
    if(L.pHead == NULL)
        return;
    if(L.pHead == L.pTail)
    {
        delete L.pHead;
        L.pHead=L.pTail=NULL;
    }
    else{
        Node *p = L.pHead;
        L.pHead = L.pHead->next;
        delete p;
    }

}
int main()
{
    List L;
    L.pHead=L.pTail=NULL; // ds rỗng
    int cnt = 0;
    khach k;
    while(1){
        int x; cin >> x;
        if(x == 0)
        {
            ++cnt;
            string s; cin >> s;
            k.monan = s;
            k.stt = cnt;
            addTail(L,k);
        }
        else if(x==1){
            eraseHead(L);
        }
        else
            break;
    }
    if(L.pHead != NULL) printList(L);
    else cout << "Tiem qua e, khong co khach nao";
}
