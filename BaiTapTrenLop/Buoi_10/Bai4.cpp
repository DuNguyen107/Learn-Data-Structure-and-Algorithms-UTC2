#include<iostream>
#include<map>
using namespace std;

int main(){
	int n; cin >> n;
	map<int,int> mp;
	int x,y;
	for(int i=0; i<n; i++){
		cin >> x;
		mp[x]++;
	}
	for(int i=0; i<=n; i++){
		if(!mp[i]) {
			cout << i;
			break;
		}
	}
}