
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

int duyet(List L){
    node* p = L.pHead;
    int cnt = 0;
    while(p != NULL){
        cnt++;
        p = p->next;
    }
    return cnt;
}

node* findMiddle(List L){
    if(L.pHead == NULL)
        return NULL;
    //code tự làm

    // int cnt = 1; 
    // if(duyet(L) % 2 == 0){
    //     node* p = L.pHead;
    //     while(1){
    //         if(cnt == duyet(L) / 2 + 1)
    //             return p;
    //         ++cnt;
    //         p = p->next;
    //     }
    // }else{
    //     node* p = L.pHead;
    //     while(1){
    //         if(cnt == duyet(L) / 2 + 1)
    //             return p;
    //         ++cnt;
    //         p = p->next;
    //     }
    // }

    // tham khảo chatgpt vì code trên chạy quá thời gian

    node* duyet = L.pHead;
    node* mid = L.pHead;
    while(duyet != NULL && duyet->next != NULL){
        duyet = duyet->next->next;
        mid = mid->next;
    }
    return mid;

}

node* findElementFromEnd(List L, int x){
    if(L.pHead == NULL){
        node* p = new node;
        p->info = "List is empty";
        return p;
    }
    if(x > duyet(L)){
        node* p = new node;
        p->info = "The index is invalid";
        return p;
    }
    node* p = L.pHead;
    int cnt = duyet(L);
    while(1){
        if(cnt==x){
            return p;
        }
        cnt--;
        p = p->next;
        if(p == NULL){
            node* tmp = new node;
            tmp->info = "The index is invalid";
            tmp->next = NULL;
            return tmp;
        }
    }
}


int main()
{
    List L;
    Init(L);
    int n; cout<<"Enter a number: "; cin>>n;
    cout<<"\nEnter a sequence of "<<n<<" numbers: ";
    inputList(L,n);
    cout<<"\nThe created Linked List: ";
    outputList(L);

    int i; cout<<"\nEnter a number: "; cin>>i;
    cout<<"\nThe element at index "<<i<<" (from the end of L): ";
    node *p = findElementFromEnd(L,i);
    if(p) cout<<p->info;


    return 0;
}
