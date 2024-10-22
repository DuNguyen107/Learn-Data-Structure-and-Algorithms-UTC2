#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i=1; i<n; i++){
        int x = a[i];
        int j, flag = 0;
        for(j=i-1; j>=0 && a[j] > x; j--){
            a[j+1] = a[j];
            flag = 1;
            for(int k=0; k<n; k++){
                cout << a[k] << ' ';
            }
            cout << endl;
        }
        a[j+1] = x;
        for(int k=0; k<n; k++){
            cout << a[k] << ' ';
        }
        cout << endl;
    }
}
