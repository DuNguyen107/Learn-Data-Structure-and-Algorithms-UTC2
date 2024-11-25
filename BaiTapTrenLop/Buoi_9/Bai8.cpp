#include<iostream>
using namespace std;

struct toaDo{
    double x,y,z;
};
void binarySearch(toaDo a[], int n, double xa, double ya, double za){
    int l = 0, r = n-1;
    int mid, dem = 0, check = 0;
	while(l <= r){
        dem++;
		mid = (l+r) / 2;
		if(a[mid].x == xa){
			if(a[mid].y == ya){
                if(a[mid].z == za){
                    cout << dem << endl;
                    check = 1;
                    break;
                }
                else if(a[mid].z < za) l = mid + 1;
                else r = mid - 1;
            }
            else if(a[mid].y < ya) l = mid + 1;
            else r = mid - 1;
		}
		else if(a[mid].x < xa) l = mid + 1;
		else r = mid - 1;
	}
    if(!check) cout << "KHONG\n";
}
int main(){
    int n; cin >> n;
    toaDo *a = new toaDo[n];
    for(int i=0; i<n; i++){
    	cin >> a[i].x >> a[i].y >> a[i].z;
	}
    int m; cin >> m;
    double x,y,z;
    while(m--){
        cin >> x >> y >> z;
        binarySearch(a,n,x,y,z);
    }
}