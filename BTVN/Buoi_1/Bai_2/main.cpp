//Đếm số lượng số chính phương ở vị trí lẻ

#include<bits/stdc++.h>
using namespace std;

bool scp(int n){
	if(n==0 || n==1)
		return 1;
	int can = sqrt(n) ;
	if(can*can == n)
		return 1;
	else
		return 0;
}


int main()
{
    int n; cin >> n;
    int a[n];
    if(n<1){
    	cout << "Mang rong.";
    	return 0;
	}
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	for(int i=0; i<n; i++){
		cout << a[i] << " ";
	}
	cout << endl;
	int cnt = 0;
	for(int i=0; i<n; i++){
		if(i%2 != 0 && scp(a[i])){
			cnt++;
			cout << a[i] << " ";
		}
	}
	cout << endl;
	if(!cnt)
		cout << "Mang khong chua so chinh phuong.";
	else
		cout << cnt;
}
