
#include <iostream>
using namespace std;

void inputArray(int *&a, int &n){
	cin >> n;
	a = new int[n+1];
	for(int i=0; i<=n; i++)
		cin >> a[i];
}

void findElements(int *&a, int n, int m){
	m = a[n];
	int k,pos;
	while(m--){
		pos = -1;
		cin >> k;
		for(int i=0; i<n; i++){
			if(a[i] == k) {
				pos = i;
				break;
			}
		}
		cout << pos << endl;
	}
	delete []a;
	a = NULL;
}
int main()
{
    int n,m;
    int *a=NULL;
    inputArray(a,n);
    findElements(a,n,m);

    return 0;
}
