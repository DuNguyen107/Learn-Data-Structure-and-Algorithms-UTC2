/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
[
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -
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
    p->info = x;
    p->next = NULL;
    return p;
}

void init(List &L)
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
void MySort(List &L){
	node* p = L.pHead;
	node* q;
	int min = 1e9;
    while(p->next != NULL){
        q = p->next;
        while(q != NULL){
            if(q->info < p->info){
                int tmp = q->info;
                q->info = p->info;
                p->info = tmp;
            }
            q = q->next;
        }
        p=p->next;
    }
    
}

int MySearch(List L, int x){
	node* p = L.pHead;
    int cnt = 0;
	while(p != NULL){
		if(p->info == x){
            return cnt;
        }
        cnt++;
		p = p->next;
	}
	return -1;
}
int main()
{
    int n; cin>>n;
    List L;init (L);
    inputList(L,n);
    MySort(L);
    cout<<"Sorted List: ";
    outputList(L);// liet ke cac phan tu cach nhau boi 1 khoang cach

    cout<< "\nFind an element: ";
    int x; cin>>x;
    cout<<x<<endl;
    int result = MySearch(L,x);
    if (result ==-1) cout<<x<<" is not found";
    else cout<<x<<" is found at the position " << result;

	return 0;
}
