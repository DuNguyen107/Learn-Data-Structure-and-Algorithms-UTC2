/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/


#include <iostream>
using namespace std;



//###INSERT CODE HERE

void inputArray(int a[], int &numbers){
    while(true){
        int n; cin >> n;
        if(n == -1)
            break;
        if(n >= 0){
            a[numbers] = n;
            numbers++;
        }
    }
}

void outputArray(int a[], int n){
    if(n == 0){
        cout << "Empty";
        return;
    }
    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

int chan(int n){
    if(n%2 == 0) return 1;
    else return 0;
}

void erase_val(int a[], int &n, int l){
    for(int i=l; i<n; i++){
        a[i] = a[i+1];
    }
    --n;
}
void eraseArray(int a[], int &n, int m){
    int cnt = 0;
    for(int i=0; i<n; i++){
        if(chan(a[i])){
           ++cnt;
            erase_val(a,n,i);
            i=-1;
            if(cnt == m)
                break;
        }
    }
    if(m==0)
    {
        cout << "No deletion required";
        return;
    }
    if(cnt == 0)
        cout << "There are no even numbers in the array\n";
    else if(cnt < m){
        cout << "Not enough " << m <<" even numbers but still delete\n";
        cout << "After:";
        outputArray(a, n);
    }
    else{
        cout << "After:";
        outputArray(a, n);
    }
}
int main()
{
    int a[1000];
    int numbers = 0;
    inputArray(a, numbers);
    int m; cin >> m;
    cout << "Before:";
    outputArray(a, numbers);
    eraseArray(a,numbers,m);
}

