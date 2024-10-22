#include<iostream>
using namespace std;

void merge(int *a, int na, int *b, int nb){
    int i=0, j=0;
    int *c = new int[na+nb];
    int res = 0;
    while(i < na && j < nb){
        if(a[i] < b[j]){
            c[res] = a[i];
            i++;
        }else{
            c[res] = b[j];
            j++;
        }
        res++;
    }
    while (i < na){
        c[res++] = a[i++];
    }
    while (j < nb) {
        c[res++] = b[j++];
    }
    for (int k = 0; k < na + nb; k++)
    {
        a[k] = c[k];
    }
}
int main() {
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        int *a = new int[n + 100]; 
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int *b = new int[m]; 
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }
        merge(a,n,b,m);
        for(int i=0; i<n+m; i++){
            cout << a[i] << ' ';
        }
        cout << endl;
    }
}
