
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
node* swapData(List &L, int x, int y){
    // if(L.pHead == NULL) return NULL;
    // if(x == y) return NULL; // x=y thi khong can hoan vi
    node* truocX = nullptr, *hientaiX = L.pHead; // tim 1 node o truoc x va node x
    while (hientaiX && hientaiX->info != to_string(x)) {
        truocX = hientaiX;
        hientaiX = hientaiX->next;
    }
    node* truocY = nullptr, *hientaiY = L.pHead; //// tim 1 node o truoc y va node y
    while (hientaiY && hientaiY->info != to_string(y)) {
        truocY = hientaiY;
        hientaiY = hientaiY->next;
    }
    if (!hientaiX || !hientaiY) return NULL; // duyet toi phan tu cuoi cung ko co x y 
    
    if (truocX != nullptr) // next cua node trc x luu dia chi cua y
        truocX->next = hientaiY;
    else  // neu x o node dau tien 
        L.pHead = hientaiY;
    if (truocY != nullptr) // next cua node trc y luu dia chi cua y
        truocY->next = hientaiX;
    else  // neu y o node dau tien 
        L.pHead = hientaiX;
    node* temp = hientaiX->next;
    hientaiX->next = hientaiY->next;
    hientaiY->next = temp;
    return hientaiY;
}

int main()
{
    List L;
    L.pHead=L.pTail=NULL;
    int n; cin>>n;
    inputList(L,n);
    cout<<"Created List: "<<endl;
    outputList(L); // Neu ds rong thi xuat "List is empty"
    cout<<endl;

    int x, y; cin>>x>>y;
    node *p = swapData(L,x,y);
    /* Tim 2 node chua x va y,
    Hoan vi gia tri cua 2 node do,
    nghia la: Lien ket giua cac node khong thay doi, node ban dau chua x se doi lai la chua y
    Ham return node chua x ban dau, luc chua hoan vi*/

    cout<<"Updated List after swapping "<<x<<" and "<<y<<": "<<endl;
    outputList(L);
    cout<<endl;

    /* Kiem tra xem co that su hoan vi info cua 2 node khong
    Neu hoan vi info thi node chua x ban dau se doi lai chua y*/

    if(p) // co hoan vi
    {
        cout<<"At the address of "<<x<< ": ";
        cout<<p->info;
    }
    else cout<<"Can not swap";
    return 0;
}
