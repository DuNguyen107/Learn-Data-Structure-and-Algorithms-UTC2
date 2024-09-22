#include <iostream>
using namespace std;

struct node {
    int info;
    node* next;
};

struct List {
    node* pHead;
    node* pTail;
};

node* getNode(int x) {
    node* p = new node;
    p->info = x;
    p->next = NULL;
    return p;
}

void Init(List &L) {
    L.pHead = NULL;
    L.pTail = NULL;
}

void addHead(List &L, int x) {
    node* p = getNode(x);
    if (L.pHead == NULL)
        L.pHead = L.pTail = p;
    else {
        p->next = L.pHead;
        L.pHead = p;
    }
}

void addTail(List &L, int x) {
    node* p = getNode(x);
    if (L.pHead == NULL)
        L.pHead = L.pTail = p;
    else {
        L.pTail->next = p;
        L.pTail = p;
    }
}

void moveHead(List &L, node* p, node* q) {
    if (p == L.pHead) return; 
    if (p == L.pTail){
        L.pTail = q;
        L.pTail->next = NULL;
    }else
		q->next = p->next; 
    p->next = L.pHead; 
    L.pHead = p;
}

void inputList(List &L, int n, int m) {
    for (int i = 1; i <= m; i++) {
        int x; cin >> x;
        node* p = L.pHead;
        node* q = NULL;
        while (p != NULL && p->info != x){
            q = p;
            p = p->next;
        }
        if (p == NULL)  addHead(L, x);
        else moveHead(L, p, q);
    }
}

void outputList(List L, int n) {
    node* p = L.pHead;
    while (p != NULL) {
        cout << p->info << ' ';
        p = p->next;
    }
    for (int i = 1; i <= n; i++) {
        bool found = false;
        p = L.pHead;
        while (p != NULL) {
            if (p->info == i) {
                found = true;
                break;
            }
            p = p->next;
        }
        if (!found) cout << i << " ";
    }
    cout << endl;
}

int main() {
    int n, m;
    cin >> n >> m;
    List L; Init(L);
    inputList(L, n, m);
    outputList(L, n);
    return 0;
}
