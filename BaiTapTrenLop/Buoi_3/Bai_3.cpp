
#include <iostream>
using namespace std;


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
        if(p->info == a)
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
        p->next = NULL;
        delete p;
    }
}
void eraseEle(List &L, int n){
	if(L.pHead == NULL) return;
	if(L.pHead->info == n){
		eraseHead(L);
		return;
	}	
	node* p = L.pHead;
	node* q = NULL;
    while(p != NULL){
        if(p->info == n){
			break;
		}
		q = p;
        p = p->next;
    }
    if(p == NULL) return;
	if (p == L.pTail) {
        q->next = NULL; 
        L.pTail = q;    
        delete p;       
        return;
    }
	q->next = p->next;
	delete p;
}

void eraseListEle(List &L, int n){
	node* p = L.pHead;
	node* q = NULL;
	while(p != NULL && p->info == n){
		L.pHead = p->next;
		delete p;
		p = L.pHead;
	}
	if(L.pHead == NULL) return;
    while(p != NULL){
        if(p->info == n){
//			if(p->next){
			q->next = p->next;
			p->next = NULL;
			delete p;
			p = q->next;
//			}else{
//		        q->next = NULL; 
//		        L.pTail = q;    
//		        delete p;   
//			}
			if(p == NULL)
                L.pTail = q;
		}else{
			q = p;
        	p = p->next;
		}
		
    }
}

void outputList(List L)
{
    if(L.pHead == NULL){
        cout << "blank";
        return;
    }
    node *p = L.pHead;
    while(p != NULL){
        cout << p->info << ' ';
        p = p->next;
    }
}

int main()
{
    List L;
    Init(L);
    while(1){
        int x; cin >> x;
        if(x == 0){
            int n; cin >> n;
            addHead(L,n);
        }else if(x == 1){
            int n; cin >> n;
            addTail(L,n);
        }else if(x == 2){
            int a, b; cin >> a >> b;
            addAfter(L, a, b);
        }else if(x == 3){
        	int n; cin >> n;
        	eraseEle(L,n);
		}else if(x==4){
			int n; cin >> n;
			eraseListEle(L,n);
		}else if(x == 5){
            eraseHead(L);
        }else
            break;
    }
    if(L.pHead == NULL)
        cout << "blank";
    else
        outputList(L);
    return 0;
}