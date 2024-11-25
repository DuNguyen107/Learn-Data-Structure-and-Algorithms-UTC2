
#include <iostream>
using namespace std;
int main()
{
	int n; cin >> n;
	int a[n];
	for(int i=0; i<n; i++) cin >> a[i];
	int m; cin >> m;
	int k, pos;
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
    return 0;
}
