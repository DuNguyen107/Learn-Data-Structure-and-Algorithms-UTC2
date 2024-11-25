

#include <iostream>
using namespace std;

void inputMatrix(int a[][50],int &n, int &m){
	cin >> n; cin >> m;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> a[i][j];
		}
	}
}
void outputMatrix(int a[][50], int n, int m){
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}


void uniqueElements(int a[][50],int n,int m){
	int max = 0, check = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(a[i][j] > max) max = a[i][j];
		}
	}
	int *b = new int[max+1]{0};
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(b[a[i][j]] == 0) {
				b[a[i][j]] = 1;
			}else{
				b[a[i][j]]++;
			}
		}
	}
	for(int i=0; i<=max; i++){
		if(b[i] == 1){
			check = 1;
			break;
		}
	}
	if(check){
		cout<<"Unique elements in the matrix:\n";
		for(int i=0; i<=max; i++){
			if(b[i] == 1)
				cout << i << " ";
		}
	}else{
		cout << "No unique element in the matrix";
	}
	delete[] b;
}

int main()
{
    int m,n,a[50][50];
    inputMatrix(a,n,m);
    cout<<"Matrix:\n";
    outputMatrix(a,n,m);
    uniqueElements(a,n,m);
    return 0;
}



