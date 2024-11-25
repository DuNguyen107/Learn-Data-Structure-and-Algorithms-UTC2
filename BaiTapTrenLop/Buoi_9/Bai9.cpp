#include<iostream>
#include<cmath>
using namespace std;

struct Ca{
    string loai, mau;
    double can, dai, tuoi;

    double getTb() const{
        return (dai+can)/2.0;
    }
};
void qs(Ca a[], int l, int r){
    int mid = (l+r)/2;
    int i=l, j=r;
	Ca x = a[mid];
    while(i <= j){
        while(a[i].getTb() < x.getTb()) ++i;
        while(a[j].getTb() > x.getTb()) --j;
        if(i <= j){
            swap(a[i], a[j]);
            ++i; --j;
        }
    }
    if(i < r) qs(a,i,r);
    if(l < j) qs(a,l,j);
}
int main(){
    int n; cin >> n;
    Ca *a = new Ca[n];
    for(int i=0; i<n; i++){
    	cin >> a[i].loai >> a[i].can >> a[i].mau >> a[i].dai >> a[i].tuoi;
	}
    qs(a,0,n-1);
    int k; cin >> k; 
    cout << a[k].loai << " " << a[k].can << " " << a[k].mau << " " << a[k].dai << " " << a[k].tuoi << endl;
    double m; cin >> m;
    double min = abs(m - a[0].getTb());
    int pos = 0;
    for(int i=0; i<n; i++){
        double res = abs(m-a[i].getTb());
        if(res < min){
            min = res;
            pos = i;
        }
    }
    cout << a[pos].loai << " " << a[pos].can << " " << a[pos].mau << " " << a[pos].dai << " " << a[pos].tuoi << endl;
}