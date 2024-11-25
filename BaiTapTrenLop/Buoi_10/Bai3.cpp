
#include <iostream>
#include <math.h>

using namespace std;

void inputArray(char a[],int &n){
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
}
void printArray(char a[], int n){
	for(int i=0; i<n; i++){
		cout << a[i] << ' ';
	}
	cout << endl;
}


void removeDups(char a[], int n){
	int *b = new int[256]{0};
	int dem = 0;
	for(int i=0; i<n; i++){
		if(isalpha(a[i])){
			a[i] = tolower(a[i]);
			if(b[a[i]] == 0) {
				b[a[i]] = 1;
				dem++;
			}
		}
	}
	cout << 26-dem;
	delete[] b;
}
int main()
{
    char a[100];int n;
    inputArray(a,n);
    removeDups(a, n);

    return 0;
}
