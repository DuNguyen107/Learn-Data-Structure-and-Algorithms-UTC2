/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include  <iostream>
using namespace std;

struct DNode
{
	int info;
	DNode *pNext, *pPrev;
};

struct DList
{
	DNode *pHead, *pTail;
};

//###INSERT CODE HERE -
void init(DList &L){
	L.pHead = L.pTail = NULL;
}

DNode* getNode(int x){
	DNode* p = new DNode;
	p->info = x;
	p->pNext = p->pPrev = NULL;
	return p; 
}
void addHead(DList &L, int x){
	DNode* p = getNode(x);
	if(L.pHead == NULL){
		L.pHead = L.pTail = p;
	}else{
		p->pNext = L.pHead;
		L.pHead->pPrev = p;
		L.pHead = p;
	}
}
void addTail(DList &L, int x){
	DNode* p = getNode(x);
	if(L.pHead == NULL){
		L.pHead = L.pTail = p;
	}else{
		p->pPrev = L.pTail;
		L.pTail->pNext = p;
		L.pTail = p;
	}
}
void createList(DList &L){
	int x;
	while(1){
		cin >> x;
		if(x == -1) break;
		addTail(L,x);
	}
}
void printList(DList L){
	DNode* p = L.pHead;
	if(L.pHead == NULL){
		cout << "List is empty";
		return;
	}
	while(p != NULL){
		cout << p->info << " ";
		p = p->pNext;
	}
}
DNode* SearchValue(DList L, int x){
	DNode* p = L.pHead;
	while(p != NULL){
		if(p->info == x) return p;
		p = p->pNext;
	}
	return NULL;
}
void addAfter(DList &L, int x, int y){
	DNode* p = getNode(y);
	DNode* q = SearchValue(L,x);
	if(q == NULL){
		cout << "\nCan't find the value "<<x;
		return;
	}
	p->pPrev = q;
	p->pNext = q->pNext;
	if(q->pNext != NULL)
		q->pNext->pPrev = p;
	q->pNext = p;
	if(q == L.pTail)
		L.pTail = p;
}
void addBefore(DList &L, int x, int y){
	DNode* p = getNode(y);
	DNode* q = SearchValue(L,x);
	if(q == NULL){
		cout << "\nCan't find the value "<<x;
		return;
	}
	p->pPrev = q->pPrev;
	p->pNext = q;
	if(q->pPrev != NULL)
		q->pPrev->pNext = p;
	q->pPrev = p;
	if(q == L.pHead)
		L.pHead = p;
}
void addAfterMulti(DList &L, int x, int y){
	int check = 0;
	DNode* k = L.pHead;
	while(k != NULL){
		if(k->info == x){
			check = 1;
			DNode* p = getNode(y);
            p->pNext = k->pNext; 
            p->pPrev = k;        
            if(k->pNext != NULL) 
                k->pNext->pPrev = p;
            else
                L.pTail = p;     
            k->pNext = p;       
		}
		k = k->pNext;
	}
	if(!check)
		cout << "\nCan't find the value "<<x;
}
void addBeforeMulti(DList &L, int x, int y){
	int check = 0;
	DNode* k = L.pHead;
	while(k != NULL){
		if(k->info == x){
			check = 1;
			DNode* p = getNode(y);
            p->pNext = k; 
            p->pPrev = k->pPrev;        
            if(k->pPrev != NULL) 
                k->pPrev->pNext = p;
            else
                L.pHead = p;     
            k->pPrev = p;    
		}
		k = k->pNext;
	}
	if(!check)
		cout << "\nCan't find the value "<<x;
}
void removeHead(DList &L){
	if(L.pHead == NULL){
		cout<<"\nList is empty. Can't delete";
		return;
	}
	DNode *p = L.pHead;
	char c;
	cout<<"\nDo you want to delete the first element?(y/n): ";  cin >> c;
	if(c == 'n' || c == 'N')
		return;
	if(L.pHead == L.pTail){
		cout<<"\nThe list becomes empty";
		L.pHead = L.pTail = NULL;
	}	
	else{
		L.pHead = L.pHead->pNext;
		L.pHead->pPrev = NULL; 
	}
	p->pNext = NULL;
	delete p;
}
void removeTail(DList &L){
	if(L.pHead == NULL){
		cout<<"\nList is empty. Can't delete";
		return;
	}
	DNode *p = L.pTail;
	char c;
	cout<<"\nDo you want to delete the last element?(y/n): ";  cin >> c;
	if(c == 'n' || c == 'N')
		return;
	if(L.pHead == L.pTail){
		cout<<"\nThe list becomes empty";
		L.pHead = L.pTail = NULL;
	}
	else{
		L.pTail = L.pTail->pPrev;
		L.pTail->pNext = NULL; 
	}
	p->pPrev = NULL;
	delete p;	
}
void removeNode(DList &L, int x){
	if (L.pHead==NULL){cout<<"\nList is empty. Can't delete";return;}
	DNode* k = SearchValue(L,x);
	if(k == NULL){
		cout << "\nCan't find the value "<<x;
		return;
	}
	cout<<"\nDo you want to delete "<<x<<" ?(y/n): ";
	char c; cin >> c;
	if(c == 'y' || c == 'Y'){
		if(L.pHead == L.pTail && L.pHead == k){
			delete k;
	        L.pHead = L.pTail = NULL; 
	    }
		else if(L.pHead == k){
			L.pHead = L.pHead->pNext;
			if(L.pHead != NULL)
				L.pHead->pPrev = NULL;
		}else{
			if(k == L.pTail){
				L.pTail = L.pTail->pPrev;
				L.pTail->pNext = NULL;
			}
			else{
				k->pPrev->pNext = k->pNext;
				k->pNext->pPrev = k->pPrev;
			} 
		}
		if(L.pHead == NULL){
			cout<<"\nThe list becomes empty";
			L.pTail = L.pHead = NULL;
			return;
		}else{
			delete k;
		}
	}else
		return;
}
void removeMultiNodeS(DList &L, int x){
	DNode* p = SearchValue(L,x);
	if(p == NULL){
		cout << "\nCan't find the value "<< x;
		return;
	}
	cout<<"\nDo you want to delete "<<x<<"s ?(y/n): ";
	char c; cin >> c;
	if(c == 'y' || c == 'Y'){
	//	DNode* p = L.pHead;
		while(p != NULL){
			if(p->info == x){
				DNode* k = p;
				p = p->pNext;
				if(L.pHead == L.pTail && k->info == x){
					delete k;
	//		        L.pHead = L.pTail = NULL; 
			        cout<<"\nThe list becomes empty"; 
					L.pTail = L.pHead = NULL;
					return;
			    }
				else if(k == L.pHead){
					L.pHead = L.pHead->pNext;
					if(L.pHead != NULL)
						L.pHead->pPrev = NULL;
				}
				else{
					if(k == L.pTail){
						L.pTail = L.pTail->pPrev;
						L.pTail->pNext = NULL;
					}
					else{
					    k->pPrev->pNext = k->pNext;
					    k->pNext->pPrev = k->pPrev;
					}
				}
				if(L.pHead == NULL){
					cout<<"\nThe list becomes empty"; 
					L.pTail = L.pHead = NULL;
					return;
				}
				else delete k;
			}else
				p=p->pNext;	
		}
	}else
		return;
}
void removeAfter(DList &L, int x){
	DNode* k = SearchValue(L,x);
	if(k == NULL){
		cout << "\nCan't find the value "<<x;
		return;
	}
	if(k == L.pTail){
		cout<<endl<<x<<" is the last element. Can't delete the element after it";
		return;
	}
	cout<<"\nDo you want to delete the element after "<<x<<" ?(y/n): ";
	char c; cin >> c;
	if(c == 'y' || c == 'Y'){
		DNode* p = k->pNext;
		if(p->pNext == NULL){
			p->pPrev->pNext = p->pNext;
			L.pTail = p->pPrev;
		}
		else{
			p->pPrev->pNext = p->pNext;
			p->pNext->pPrev = p->pPrev;
		}
		delete p;
	}
}

void removeBefore(DList &L, int x){
	DNode* k = SearchValue(L,x);
	if(k == NULL){
		cout << "\nCan't find the value "<<x;
		return;
	}
	if(k == L.pHead){
		cout<<endl<<x<<" is the first element. Can't delete the element before it";
		return;
	}
	cout<<"\nDo you want to delete the element before "<<x<<" ?(y/n): ";
	char c; cin >> c;
	if(c == 'y' || c == 'Y'){
		DNode* p = k->pPrev;
		if(p->pPrev == NULL){
			p->pNext->pPrev = p->pPrev;
			L.pHead = p->pNext;
		}
		else{
			p->pNext->pPrev = p->pPrev;
			p->pPrev->pNext = p->pNext;
		}
		delete p;
	}
}

void removeMultiAfters(DList &L, int x){
	DNode* k = SearchValue(L,x);
	if(k == NULL){
		cout << "\nCan't find the value "<< x;
		return;
	}
	if(L.pHead == L.pTail && L.pTail == k){
		cout<<"\nList has only one "<<x<<" and "<<x<<" is the last element. Can't delete the element after it";
		return;
	}
	int check = 0;
	if(L.pTail == k){
		DNode* p = k->pPrev;
		while(p != NULL){
			if(p->info == x){
				check = 1;
				break;
			}
			p = p->pPrev;		
		}
		if(!check){
			cout<<"\nList has only one "<<x<<" and "<<x<<" is the last element. Can't delete the element after it";
			return;
		}
	}
	cout<<"\nDo you want to delete all elements after "<<x<<" ?(y/n): "; 
	char c; cin >> c;
	if(c == 'y' || c == 'Y'){
		while(k != NULL){
			if(k->info == x){
				DNode* p = k->pNext;				
				if(p != NULL){
					if(p == L.pTail){
						L.pTail = k;
						k->pNext = NULL;
					}
					else{
						p->pPrev->pNext = p->pNext;
						p->pNext->pPrev = p->pPrev;
					}
					delete p;
				}
			}
			k = k->pNext;
		}
	}
}
void removeMultiBefores(DList &L, int x){
	DNode* k = SearchValue(L,x);
	if(k == NULL){
		cout << "\nCan't find the value "<< x;
		return;
	}
	if(L.pHead == L.pTail && L.pHead == k){
		cout<<"\nList has only one "<<x<<" and "<<x<<" is the first element. Can't delete the element before it";
		return;
	}
	int check = 0;
	if(L.pHead == k){
		DNode* p = k->pNext;
		while(p != NULL){
			if(p->info == x){
				check = 1;
				break;
			}
			p = p->pNext;		
		}
		if(!check){
			cout<<"\nList has only one "<<x<<" and "<<x<<" is the first element. Can't delete the element before it";
			return;
		}
	}
	cout<<"\nDo you want to delete all elements before "<<x<<" ?(y/n): "; 
	char c; cin >> c;
	if(c == 'y' || c == 'Y'){
		while(k != NULL){
			if(k->info == x){
				DNode* p = k->pPrev;				
				if(p != NULL) {
					if(p == L.pHead){
						L.pHead = k;
						k->pPrev = NULL;
					}
					else{
						p->pNext->pPrev = p->pPrev;
						p->pPrev->pNext = p->pNext;
					}
					delete p;
				}
			}
			k = k->pNext;
		}
	}
}

void removeAll(DList &L){
	cout<<"\nDo you want to delete all elements?(y/n): ";
	char c; cin >> c;
	if(c == 'y' || c == 'Y'){
		while(L.pHead != NULL){
			L.pHead = L.pHead->pNext;
		}
		L.pTail = NULL;
		cout<<"\nThe list becomes empty";
	}
}
int main()
{
	DList L;
	init(L);
	int x,y,choice; char c;

	cout<<"MENU:";
    cout<<"\n1. Create a DList";
    cout<<"\n2. Print the DList";
    cout<<"\n3. Insert a value at the front";
    cout<<"\n4. Insert a value at the end";
    cout<<"\n5. Insert a value after a given value (only for the first value found)";
    cout<<"\n6. Insert a value before a given value (only for the first value found)";
    cout<<"\n7. Insert a value after a given value (for all the same values)";
    cout<<"\n8. Insert a value before a given value (for all the same values)";
    cout<<"\n9. Delete the first element";
    cout<<"\n10. Delete the last element";
    cout<<"\n11. Delete the first element containing a specific value";
    cout<<"\n12. Delete all elements storing a particular value";
    cout<<"\n13. Delete the element after a specific value (only for the first one found)";
    cout<<"\n14. Delete the element before a specific value (only for the first one found)";
    cout<<"\n15. Delete all elements after a specific value";
    cout<<"\n16. Delete all elements before a specific value";
    cout<<"\n17. Delete all elements";
    cout<<"\n20. Exit"<<endl;


	while(true)
    {
        cout<<"\n\t\tPLEASE SELECT YOUR CHOICE: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"\nEnter your positive integers until you enter -1 to finish: ";
            createList(L);
            break;
        case 2:
            cout<<"\nYour current DList: ";
            printList(L);
            break;
        case 3:
            cout<<"\nEnter a number: ";
            cin>>x;
            addHead(L,x);
            break;
        case 4:
            cout<<"\nEnter a number: ";
            cin>>x;
            addTail(L,x);
            break;
        case 5:
            cout<<"\nEnter two numbers: ";
            cin>>x>>y;
            addAfter(L,x,y);
            break;
        case 6:
            cout<<"\nEnter two numbers: ";
            cin>>x>>y;
            addBefore(L,x,y);
            break;
        case 7:
            cout<<"\nEnter two numbers: ";
            cin>>x>>y;
            addAfterMulti(L,x,y);
            break;
        case 8:
            cout<<"\nEnter two numbers: ";
            cin>>x>>y;
            addBeforeMulti(L,x,y);
            break;
        case 9:
            removeHead(L);
            break;
        case 10:
            removeTail(L);
            break;
        case 11:
            if (L.pHead==NULL){cout<<"\nList is empty. Can't delete";break;}
            cout<<"\nEnter a number: ";
            cin>>x;
            removeNode(L,x);
            break;
        case 12:
            if (L.pHead==NULL){cout<<"\nList is empty. Can't delete";break;}
            cout<<"\nEnter a number: ";
            cin>>x;
            removeMultiNodeS(L,x);
            break;
        case 13:
            if (L.pHead==NULL){cout<<"\nList is empty. Can't delete";break;}
            cout<<"\nEnter a number: ";
            cin>>x;
            removeAfter(L,x);
            break;
        case 14:
            if (L.pHead==NULL){cout<<"\nList is empty. Can't delete";break;}
            cout<<"\nEnter a number: ";
            cin>>x;
            removeBefore(L,x);
            break;
        case 15:
            if (L.pHead==NULL){cout<<"\nList is empty. Can't delete";break;}
            cout<<"\nEnter a number: ";
            cin>>x;
            removeMultiAfters(L,x);
            break;
        case 16:
            if (L.pHead==NULL){cout<<"\nList is empty. Can't delete";break;}
            cout<<"\nEnter a number: ";
            cin>>x;
            removeMultiBefores(L,x);
            break;
        case 17:
            if (L.pHead==NULL){cout<<"\nList is empty. Can't delete";break;}
			removeAll(L);
            break;
        case 20:
            cout<<"\nGOOD BYE";
            return 0;

        }
    }

	return 0;
}
