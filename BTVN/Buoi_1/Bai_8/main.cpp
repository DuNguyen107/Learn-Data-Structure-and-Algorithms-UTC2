#include <iostream>

using namespace std;

void inputArray(int a[][100], int n, int m){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> a[i][j];
        }
    }
}

void outputArray(int a[][100], int n, int m){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}

void horizontal_invert(int a[][100], int n, int m){
    for(int i=0; i<n/2; i++){
        for(int j=0; j<m; j++){
            int swapArray = a[i][j];
            a[i][j] = a[n-i-1][j];
            a[n-i-1][j] = swapArray;
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;


    int a[100][100];

    inputArray(a, n, m);

    horizontal_invert(a, n, m);

    outputArray(a, n, m);

    return 0;
}
