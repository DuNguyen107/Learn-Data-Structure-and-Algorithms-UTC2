#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int flag = 0;
    for(int i=1; i<n; i++){
        flag = 0;
        for(int j=0; j<n-i; j++){ 
            if (a[j] > a[j+1]){
                swap(a[j], a[j+1]);
                for(int k=0; k<n; k++) cout << a[k] << ' ';
                cout << endl;
                flag = 1;
            }
        }
        if(!flag) break;
    }
}
