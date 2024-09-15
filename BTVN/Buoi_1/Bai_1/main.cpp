//Tạo mảng các số nguyên từ mảng cho trước
#include <iostream>
using namespace std;

bool snt(int n){
	for(int i=2; i*i<=n; i++){
		if(n%i == 0)
			return false;
	}
	return n>=2;
}

void inputArray(int a[], int n){
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
}

void outputArray(int a[], int n){
	for(int i=0; i<n; i++){
		cout << a[i] << " ";
	}
}

void filterPrimes(int a[], int n, int b[], int &nb, int m){
	nb = 0;
	int countPrime = 0;
	for(int i=0; i<n; i++){
		if(snt(a[i])){
			countPrime++;
			b[nb] = a[i];
			++nb;
		}
		if(countPrime == m) break;
	}
	if(nb == 0)
		cout << "Mang a khong chua so nguyen to\n";
	else if(nb < m)
		cout << "Mang a khong co du " << m << " so nguyen to\n";
}

int main()
{
    int na, a[100],nb, b[100];
    cin>>na;
    inputArray(a,na);
    cout<<"Mang a:"<<endl;
    outputArray(a,na);
    cout<<endl;
    int m;cin>>m;
    filterPrimes(a,na,b,nb,m); //tao ra mang b bang cach tach m so nguyen to tu a
    cout<<"Mang b:"<<endl;
    outputArray(b,nb);

    return 0;
}
