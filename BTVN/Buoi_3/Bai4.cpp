#include<string>
#include <iostream>
using namespace std;

struct province{
    int id, pop;
    double area;
    string name;
};
struct node
{
    province info;
    node* next;
};

struct List
{
    node* pHead;
    node* pTail;
};

node* getNode(province x)
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

void addHead(List &L, province x)
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

void addTail(List &L, province x)
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
// void eraseEle(List &L, string n){
// 	if(L.pHead == NULL) return;
// 	if(L.pHead->info.name == n){
// 		eraseHead(L);
// 		return;
// 	}	
//     if(L.pTail->info.name == n){
// 		eraseTail(L);
// 		return;
// 	}	
// 	node* p = L.pHead;
// 	node* q = NULL;
//     while(p != NULL){
//         if(p->info.name == n){
//             q->next = p->next;
// 	        delete p;
// 			return;
// 		}
//         q = p;
//         p = p->next;
//     }
// }
void inputList(List &L, int n)
{
    province x;
    for(int i=1; i<=n; i++){
        cin >> x.id; cin.ignore();
        getline(cin, x.name); 
        cin >> x.pop; cin >> x.area;
        addTail(L,x);
    }
}

void outputList(List L)
{
    cout << "ID\t|Province\t|Population\t|Area\n";
    if(L.pHead == NULL){
        cout << "List is empty";
        return;
    }
    node *p = L.pHead;
    while(p != NULL){
        cout << p->info.id << "\t" << p->info.name << "\t" << p->info.pop << "\t" << p->info.area << endl;
        p = p->next;
    }
}
void eraseEle(List &L, string n, int &check){
	if(L.pHead == NULL) return;
	if(L.pHead->info.name == n){
		eraseHead(L);
        check = 1;
		return;
	}	
	node* p = L.pHead;
	node* q = NULL;
    while(p != NULL){
        if(p->info.name == n){
            check = 1;
			break;
		}
		q = p;
        p = p->next;
    }
    if(p == NULL) return;
	if (p == L.pTail) {
        check = 1;
        q->next = NULL; 
        L.pTail = q;    
        delete p;       
        return;
    }
	q->next = p->next;
	delete p;
    
}
int main(){
    List L; Init(L);
    int n; cin >> n;
    inputList(L,n); cin.ignore();
    string s; getline(cin, s);
    cout << "List of provinces:\n";
    outputList(L);
    if(L.pHead == NULL)
        return 0;
    cout << "Enter the name of the province you want to delete:\n";
    int check = 0;
    eraseEle(L,s,check);
    if(check){
        cout << "Updated List:\n";
        outputList(L);
    }
    else {
        // cout << "ID\t|Province\t|Population\t|Area\n";
        cout << "Not found";
    }  
}

