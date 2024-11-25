#include<iostream>
using namespace std;

void qs(int a[], int l, int r){
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
    if(i < r) qs(a,i,r);
    if(l < j) qs(a,l,j);
}
void sort(int a[], int n){
	int *b = new int[n];
    int j = 0;
    for (int i = 0; i < n; i++) {
        if(a[i] % 2 == 0) {
        	b[j] = a[i];
        	j++;
		}
    }
    qs(b,0,j-1);
    j = 0;
    for (int i = 0; i < n; i++) {
        if(a[i] % 2 == 0) {
        	a[i] = b[j];
        	j++;
		}
    }
    delete []b;
}
/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -

int main(){
    int *a, n; cin >> n;
    a = new int [n];



    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }

    sort(a, n);

    for(int i = 0; i < n; i ++){
        cout << a[i] << " ";
    }
}
