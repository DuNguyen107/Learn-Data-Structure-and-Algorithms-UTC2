#include<iostream>
using namespace std;

int dem = 0;
void qs(int a[], int l, int r){
    int mid = (l+r)/2;
    int i=l, j=r, x = a[mid];
    while(i <= j){
        while(a[i] > x) ++i;
        while(a[j] < x) --j;
        if(i <= j){
            swap(a[i], a[j]);
            dem++;
            ++i; --j;
        }
    }
    if(i < r) qs(a,i,r);
    if(l < j) qs(a,l,j);
}
int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    qs(a,0,n-1);
    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    cout << endl << "Number of times to swap 2 numbers: " << dem;
}
