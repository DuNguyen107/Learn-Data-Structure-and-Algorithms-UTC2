
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
int max(int a, int b){
    if(a>b) return a;
    else if (a<b)return b;
}

void print_longest_increasing_sub_list(List L){
    Node *p =L.head->next;
    Node *q =L.head;
    int max_val = 0, dem = 1;
    while(p != NULL){
        if(p->val >= q->val){
            ++dem;
        }else{
            max_val = max(max_val, dem);
            dem = 1;
        }
        q = p;
        p = p->next;
    }
    cout << max_val;
}
int main()
{
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    List l;

    list_initializing(l);
    int x;
    do{
        cin >> x;
        if (x != -1) add_tail(l, x);
        else break;
    } while(true);

    print_longest_increasing_sub_list(l);


    return 0;
}