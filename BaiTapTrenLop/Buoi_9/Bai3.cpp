
#include <iostream>
using namespace std;

int main()
{
	int n; cin >> n;
	int a[n];
	for(int i=0; i<n; i++) cin >> a[i];
	int m; cin >> m;
	while(m--){
		int k, pos = -1, l=0, r = n-1;
		cin >> k;
		while(l <= r){
			int mid = (l+r) / 2;
			if(a[mid] == k){
				pos = mid;
				break;
			}
			else if(a[mid] < k) l = mid + 1;
			else r = mid - 1;
		}
		cout << pos << endl;
	}
    return 0;
}
