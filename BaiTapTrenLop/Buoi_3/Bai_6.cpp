
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

struct Node{
    int val;
    Node* next;
};

struct List{
    Node *head, *tail;
    int x;
};

void list_initializing(List &l){
    l.head = l.tail = NULL;
}
void add_tail(List &l, int x){
    Node*p = new Node;
    p->val = x;
    p->next = NULL;

    if (l.head == NULL){
        l.head = l.tail = p;
    } else {
        l.tail->next = p;   
        l.tail = p;
    }
}

void xuat(List &l){
    for(Node *p = l.head; p != NULL; p = p->next){
        cout << p->val << " ";
    }
    cout << endl;
}


int duyet(List L){
    if(L.head == NULL)
        return 0;
    Node* p = L.head;
    int cnt = 0;
    while(p != NULL){
        ++cnt;
        p = p->next;
    }
    return cnt;
}
int is_subsequence(List L1, List L2){
    int lenL1 = duyet(L1), lenL2 = duyet(L2);
    // if (lenL1 > lenL2) return 0;

    char c[lenL1 + 5], d[lenL1 + 5];
    Node* p = L1.head;
    int i = 0;
    while(p != NULL){
        c[i] = p->val + '0';
        // cout << c[i] << " ";
        p = p->next;
        ++i;
    }
    // cout << endl;
    Node* a = L1.head;
    Node* b = L2.head;
    int j = 0;
    while(a != NULL && b != NULL){
        if(a->val == b->val){
            d[j] = b->val + '0';
            // cout << d[j] << " ";
            ++j;
            a = a->next;
        }
        b = b->next;
    }
    // cout << endl;
    // if(a != NULL || b != NULL) return 0;
    for(int k=0; k<lenL1; k++){
        if(c[k] != d[k]) 
            return 0;
    }
    return 1;
}



int main()
{
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    List lists[2];

    for(int i = 0; i < 2; i++){
        list_initializing(lists[i]);
        int x;
        do{
            cin >> x;
            if (x != -1) add_tail(lists[i], x);
            else break;
        } while(true);
    }

    if ( is_subsequence(lists[0], lists[1])) cout << "TRUE";
    else cout << "FALSE";


    return 0;
}
