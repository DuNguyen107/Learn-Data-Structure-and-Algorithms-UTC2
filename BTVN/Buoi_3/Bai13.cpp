/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
[
]
define
include
###End banned keyword*/
#include<iostream>
#include <iomanip>
using namespace std;


struct DONTHUC{
	int somu;
	double heso;
};


struct Node{
	DONTHUC* data;
	Node* next;

};

typedef struct DATHUC{
	Node* head;
	Node* tail;
}List;


//###INSERT CODE HERE -

Node* getNode(DONTHUC x)
{
    Node *p = new Node;
    p->data = new DONTHUC;
    p->data->somu = x.somu;
    p->data->heso = x.heso;
    p->next = NULL;
    return p;
}
void addTail(List &L, DONTHUC x)
{
    Node* p = getNode(x);
    if(L.head == NULL)
        L.head = L.tail = p;
    else
    {
        L.tail->next = p;
        L.tail = p;
    }
}
void Nhap(DATHUC &B){
    B.head = B.tail = NULL;
    DONTHUC p;
    int n; cin >> n;
    double a; int b;
    for (int i = 0; i < n; i++)
    {
		cin >> a >> b;
		p.heso = a;
        p.somu = b;
        addTail(B,p);
    }
}
void Xuat(DATHUC B){
    Node *p = B.head;
    int check = 0;
    while(p!=NULL){
        if(p->data->heso == 0)
            p = p->next;
        else if(p->data->heso > 0){
            check = 1;
            if(p->data->heso == 1){
                if(p->data->somu == 0)
                    cout << p->data->heso;
                else if(p->data->somu == 1)
                    cout << "x";
                else
                    cout << "x^" << p->data->somu;
            }else{
                if(p->data->somu == 0)
                    cout << p->data->heso;
                else if(p->data->somu == 1)
                    cout << p->data->heso << "x";
                else
                    cout << p->data->heso << "x^" << p->data->somu;
            }
            p = p->next;
            break;
        }
        else{
            check = 1;
            if(p->data->heso == -1){
                if(p->data->somu == 0)
                    cout << p->data->heso;
                else if(p->data->somu == 1)
                    cout << "-x";
                else
                    cout << "-x^" << p->data->somu;
            }else{
                if(p->data->somu == 0)
                    cout << p->data->heso;
                else if(p->data->somu == 1)
                    cout << p->data->heso << "x";
                else
                    cout << p->data->heso << "x^" << p->data->somu;
            }
            p = p->next;
            break;
        }   
    }
    
    while(p != NULL){
        if(p->data->heso == 0){
            p = p->next;
            continue;
        }else if(p->data->heso > 0){
            check = 1;
            if(p->data->heso == 1){
                if(p->data->somu == 0)
                    cout << "+" << p->data->heso;
                else if(p->data->somu == 1)
                    cout << "+" << "x";
                else
                    cout << "+x^" << p->data->somu;
            }else{
                if(p->data->somu == 0)
                    cout << "+" << p->data->heso;
                else if(p->data->somu == 1)
                    cout << "+" << p->data->heso << "x";
                else
                    cout << "+" << p->data->heso << "x^" << p->data->somu;
            }
        }
        else{
            check = 1;
            if(p->data->heso == -1){
                if(p->data->somu == 0)
                    cout << p->data->heso;
                else if(p->data->somu == 1)
                    cout << "-x";
                else
                    cout << "-x^" << p->data->somu;
            }else{
                if(p->data->somu == 0)
                    cout << p->data->heso;
                else if(p->data->somu == 1)
                    cout << p->data->heso << "x";
                else
                    cout << p->data->heso << "x^" << p->data->somu;
            }
        }   
        p = p->next;
    }
    if(!check) cout << 0;
}
DATHUC Tong2DaThuc(DATHUC &A, DATHUC &B){
    DATHUC C;
    C.head = C.tail = NULL;
    DONTHUC t;
    Node *p = A.head;
    Node *q = B.head;
    while(p!=NULL && q!=NULL){
        if(p->data->somu == q->data->somu){
            t.heso = p->data->heso + q->data->heso;
            t.somu = p->data->somu;
            addTail(C,t);
            p = p->next;
            q = q->next;
        }else if (p->data->somu > q->data->somu){
            t.heso = p->data->heso;
            t.somu = p->data->somu;
            addTail(C,t);
            p = p->next;
        }else{
            t.heso = q->data->heso;
            t.somu = q->data->somu;
            addTail(C,t);
            q = q->next;
        }
    }
    while(p!=NULL){
        t.heso = p->data->heso;
        t.somu = p->data->somu;
        addTail(C,t);
        p = p->next;
    }
    while(q!=NULL){
        t.heso = q->data->heso;
        t.somu = q->data->somu;
        addTail(C,t);
        q = q->next;
    }
    return C;
}

int main() {
    DATHUC A, B;
    Nhap(A);
    Nhap(B);
    cout << "Da thuc A: "; Xuat(A);
    cout << "\nDa thuc B: "; Xuat(B);
    cout << "\nA+B = "; Xuat(Tong2DaThuc(A, B));
    return 0;
}