
#include <iostream>
#include <cstring>
#include <string>
using namespace std;


struct Province{
	int id,pop;
	string name;
	double area;
};typedef struct Province pro;

struct node{
	pro info;
	node* next;
};

struct List{
	node* pHead;
	node* pTail;
};

void Init(List &L){
	L.pHead = L.pTail = NULL;
}
node* getNode(pro x){
	node* p = new node;
	p->info = x;
	p->next = NULL;
	return p;
}
void addTail(List &L, pro x)
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
void inputProvinces(pro &x){
	cin >> x.id; cin.ignore();
	getline(cin, x.name);
	cin >> x.pop >> x.area; 
}

void outputProvince(pro x){
	cout << x.id <<"\t"<<x.name<<"\t"<<x.pop<<"\t"<<x.area << endl;
}
 
void inputListProvinces(List &L){
	pro x;
	int n; cin >> n;
	for(int i=1; i<=n; i++){
		inputProvinces(x);
		addTail(L,x);
	}
}
void outputListProvinces(List &L){
	node* p = L.pHead;
	pro x;
	while(p!=NULL){
		x = p->info;
		outputProvince(x);
		p = p->next;
	}
}
void outputProvincesMore1MillionPop(List L){
	node* p = L.pHead;
	pro x;
	if(p == NULL)
		return;
	while(p != NULL){
		if(p->info.pop > 1000){
			x = p->info;
			outputProvince(x);
		}
		p = p->next;	
	}
}

node *findProMaxArea(List L){
	double max = -1;
	node* p =L.pHead;
	node* temp;
	if(p == NULL) return NULL;
	while(p != NULL){
		if(p->info.area > max){
			max = p->info.area;
			temp = p;
		}
		p = p->next;
	}
	return temp;
}



int main()
{
    List L;
    Init(L);
    inputListProvinces(L);
    cout<<"List of provinces:"<<endl;
    cout<<"ID\t|Province\t|Population\t|Area"<<endl;
    outputListProvinces(L);

    cout<<"Provinces with a population of more than 1 million:"<<endl;
    outputProvincesMore1MillionPop(L);

    cout<<"The largest province:"<<endl;
    node *p = findProMaxArea(L);
    if(p) outputProvince(p->info);

    return 0;
}



