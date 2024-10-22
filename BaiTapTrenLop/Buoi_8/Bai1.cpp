#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int min, flag;
    for (int i = 0; i < n - 1; i++) {
        min = i; flag = 0;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min]) {
                min = j;
                flag = 1; 
            }
        }
        swap(a[i], a[min]);
        if (flag) {
            for (int k = 0; k < n; k++) {
                cout << a[k] << ' ';
            }
            cout << endl;
        }
    }
}
