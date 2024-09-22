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
void eraseEle(List &L, int n){
	if(L.pHead == NULL) return;
	if(L.pHead->info == to_string(n)){
		eraseHead(L);
		return;
	}	
	node* p = L.pHead;
	node* q = NULL;
    while(p != NULL){
        if(p->info == to_string(n)){
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
// void eraseEle(List &L, int n){
// 	if(L.pHead == NULL) return;
// 	if(L.pHead->info == n){
// 		eraseHead(L);
// 		return;
// 	}	
//     if(L.pTail->info == n){
// 		eraseTail(L);
// 		return;
// 	}	
// 	node* p = L.pHead;
// 	node* q = NULL;
//     while(p != NULL){
//         if(p->info == n){
//             q->next = p->next;
// 	        delete p;
// 			return;
// 		}
//         q = p;
//         p = p->next;
//     }
// }
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
			q->next = p->next;
			p->next = NULL;
			delete p;
			p = q->next;
			if(p == NULL)
                L.pTail = q;
		}else{
			q = p;
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