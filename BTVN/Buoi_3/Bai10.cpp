#include <iostream>
using namespace std;

struct node
{
    int info;
    node* next;
};

node* getNode(int x)
{
    node*p = new node;
    p->info = x;
    p->next = NULL;
    return p;
}

int main(){
	int n,m; cin >> n >> m;
    node* head = getNode(1);
    node* tail = head;
    for(int i=2; i<=n; i++){
    	tail->next = getNode(i);
    	tail = tail->next;
	}
    int x;
    for(int i=1; i<=m; i++){
    	cin >> x;
    	if(head->info == x){
    		cout << tail->info << ' ';
    		continue;
		}
		node* cur = head;
		node* pre = NULL;
		while(cur->next && cur->next->info != x){
			cur = cur->next;
		}
		if(cur->next){
			node* p = cur->next;
			cur->next = p->next;
			if(p==tail){
				tail = cur;
			}
			p->next = head;
			head = p;
		}
		cout << tail->info << ' ';
	}
}
