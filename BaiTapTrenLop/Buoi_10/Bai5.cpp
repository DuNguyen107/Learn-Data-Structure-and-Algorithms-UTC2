#include<iostream>
#include<set>
using namespace std;

int main(){
	set<int> se;
	
	int n; cin >> n;
	int x,max = 0;
	for(int i=0; i<n; i++){
		cin >> x;
		b.insert(x);
//		if(x > max) max = x;
	}
	for(int i=0; i<=n; i++){
		if(b.find(i) == b.end()){
			cout << i;
			break;
		}
	}
}