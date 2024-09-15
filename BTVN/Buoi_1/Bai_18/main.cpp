#include <bits/stdc++.h>
using namespace std;

struct chuyenbay {
    string machuyenbay, ngay, diadiem;
    double giobay;
}; typedef struct chuyenbay CB;

void nhapChuyenBay(CB &a){
    getline(cin, a.machuyenbay);
    getline(cin, a.ngay);
    cin >> a.giobay; cin.ignore();
    getline(cin, a.diadiem);
}

void nhapDSChuyenBay(CB a[], int &n){
    cin >> n;
    cin.ignore();
    for(int i=0; i<n; i++){
        nhapChuyenBay(a[i]);
    }
}
int main()
{
    CB a[100];
    int n;

    nhapDSChuyenBay(a,n); // Nhap danh sach cac chuyen bay
    string s; cin >> s;
    int max_cb = 0;
    double max_val = 0;
    for(int i=0; i<n; i++){
        if(a[i].giobay > max_val){
            max_val = a[i].giobay;
            max_cb = i;
        }
    }
    string x = a[max_cb].diadiem, t;
    // cout << x;
    stringstream ss(x);
    while(ss >> x){
        t = x;
    }
    if(t == s )
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
