

#include<vector>
#include<iostream>
using namespace std;

int main()
{
	int n; cin >> n;
	vector<int> a(n+1,0);
	int x;
	for(int i=0; i<n; i++){
		cin >> x;
		a.push_back(x);
	}
	for(int i=0; i<n; i++){
		cout << a[i] << ' ';
	}
//	int mex = a[0];
//	for(int i=0; i<a.size(); i++){
//		if(mex > a[i] && a[a[i]] == 0){
//			mex = a[i];
//			break;
//		}
//	}
//	cout << mex;
    return 0;
}




