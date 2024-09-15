/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<cstdio>

using namespace std;

//###INSERT CODE HERE -

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

void dinhdang(string &s){
    s[2] = '/';
    s[5] = '/';
    string x;
    if(s[3] == '0'){
        for(int i=0; i<10; i++){
            if(i != 3)
                x += s[i];
        }
    }
    s = x;
}
void xuatChuyenBayToiTinh(CB a[], int n, string s){
    for(int i=0; i<n; i++){
        if(a[i].diadiem == s){
            dinhdang(a[i].ngay);
            cout << a[i].machuyenbay << "\t" << a[i].ngay << "\t";
            cout << a[i].giobay << "\t" << a[i].diadiem << endl;
        }
    }
}

int main()
{
    CB a[100];
    int n;

    nhapDSChuyenBay(a,n); // Nhap danh sach cac chuyen bay


    cout<<"Machuyen\t|Ngaybay\t|Giobay\t|Noiden\n";
    xuatChuyenBayToiTinh(a,n,"Ha Noi");

    return 0;
}
