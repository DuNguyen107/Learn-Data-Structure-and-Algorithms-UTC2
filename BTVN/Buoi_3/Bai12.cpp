/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
[
]
define
include
###End banned keyword*/
#include<iostream>
#include<cmath>
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
void Nhap(DATHUC &B, double a, int b){
    DONTHUC p;
    p.heso = a;
    p.somu = b;
    addTail(B,p);
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
double TinhDaThuc(DATHUC B, double x){
    Node* p = B.head;
    double sum = 0;
    while(p != NULL){
        sum+= p->data->heso * pow(x,p->data->somu);
        p = p->next;
    }
    return sum;
}

int main() {
    DATHUC B;
    B.head=B.tail=NULL;
    int n; cin >> n;
    double heso; int somu;
    for (int i = 0; i < n; i++)
    {
		cin >> heso >> somu;
		Nhap(B,heso,somu);
    }
    cout << "Da thuc vua nhap la: "; Xuat(B);
    double x; cin >> x;
    cout << "\nVoi x=" << x << ", gia tri da thuc la: "
         << setprecision(2) << fixed << TinhDaThuc(B, x);
    return 0;
}