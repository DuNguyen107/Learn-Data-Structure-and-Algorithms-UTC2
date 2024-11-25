#include<iostream>
using namespace std;

void qs1(int a[], int l, int r){
    int mid = (l+r)/2;
    int i=l, j=r, x = a[mid];
    while(i <= j){
        while(a[i] < x) ++i;
        while(a[j] > x) --j;
        if(i <= j){
            swap(a[i], a[j]);
            ++i; --j;
        }
    }
    if(i < r) qs1(a,i,r);
    if(l < j) qs1(a,l,j);
}
void qs2(int a[], int l, int r){
    int mid = (l+r)/2;
    int i=l, j=r, x = a[mid];
    while(i <= j){
        while(a[i] > x) ++i;
        while(a[j] < x) --j;
        if(i <= j){
            swap(a[i], a[j]);
            ++i; --j;
        }
    }
    if(i < r) qs2(a,i,r);
    if(l < j) qs2(a,l,j);
}
void sort(int a[], int n){
	int *b = new int[n], *c = new int[n];
    int j = 0, k = 0;
    for (int i = 0; i < n; i++) {
        if(a[i] % 2 == 0) {
        	b[j] = a[i];
        	j++;
		}else{
			c[k] = a[i];
			k++;
		}
    }
    qs1(b,0,j-1);
    qs2(c,0,k-1);
    j = 0, k= 0;
    for (int i = 0; i < n; i++) {
        if(a[i] % 2 == 0) {
        	a[i] = b[j];
        	j++;
		}else{
			a[i] = c[k];
			k++;
		}
    }
    delete []b;
    delete []c;
}

int main(){
    int *a, n; cin >> n;
    a = new int [n];



    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }

    sort(a, n);
	cout << "Sorted Array: ";
    for(int i = 0; i < n; i ++){
        cout << a[i] << " ";
    }
}
