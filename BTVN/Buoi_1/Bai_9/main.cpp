#include <iostream>

using namespace std;

void inputMatrix(int a[][100], int &n){
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> a[i][j];
        }
    }
}

void outputMatrix(int a[][100], int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}

void maxElementOfEachRow(int a[][100], int n){
    for(int i=0; i<n; i++){
        int max_val = -1;
        int vt1=0,vt2=0;
        for(int j=0; j<n; j++){
            if(a[i][j] > max_val){
                max_val = a[i][j];
                vt1 = i;
                vt2 = j;
            }
        }
        cout << "a[" << vt1 << "][" << vt2 << "]=" << max_val << endl;
    }
}

int main()
{
    int a[100][100];
    int n;
    inputMatrix(a,n);
    cout<<"Matrix: "<<endl;
    outputMatrix(a,n);

    cout<<"Maximum element of each row in the matrix: "<<endl;
    maxElementOfEachRow(a,n); // Tim phan tu lon nhat cua moi dong, xuat vi tri cua phan tu do va gia tri lon nhat.VD: a[0][1]=12

    return 0;
}
