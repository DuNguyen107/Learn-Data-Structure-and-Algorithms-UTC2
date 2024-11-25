#include<iostream>
using namespace std;

void Merge(int *a, int left, int mid, int right) {
    int n1 = mid - left + 1;  // Số phần tử mảng trái
    int n2 = right - mid;     // Số phần tử mảng phải
    
    // Tạo mảng tạm để lưu 2 nửa
    int *L = new int[n1];
    int *R = new int[n2];
    
    // Copy dữ liệu vào mảng tạm
    for(int i = 0; i < n1; i++)
        L[i] = a[left + i];
    for(int i = 0; i < n2; i++)
        R[i] = a[mid + 1 + i];
        
    // Merge 2 mảng tạm vào mảng a
    int i = 0, j = 0;  // index của 2 mảng tạm
    int k = left;      // index của mảng gốc a
    
    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    
    // Copy phần tử còn lại của mảng L nếu có
    while(i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }
    
    // Copy phần tử còn lại của mảng R nếu có
    while(j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }
    
    // Giải phóng bộ nhớ
    delete[] L;
    delete[] R;
}

void MergeSort(int a[], int l, int r) {
    if(l < r) {
        int m = l + (r - l)/2;  // Tương đương (l+r)/2 nhưng tránh tràn số
        
        MergeSort(a, l, m);     // Sắp xếp nửa đầu
        MergeSort(a, m+1, r);   // Sắp xếp nửa sau
        
        Merge(a, l, m, r);      // Merge hai nửa đã sắp xếp
    }
}
int binarySearch(int a[],int n,int l,int r,int k){
	int pos = -1;
	while(l <= r){
		int mid = (l+r) / 2;
		if(a[mid] == k){
			pos = mid;
			break;
		}
		else if(a[mid] < k) l = mid + 1;
		else r = mid - 1;
	}
	return pos;
}
void inputArray(int a[], int &n){
	for(int i=0; i<n; i++)
		cin >> a[i];
}
void outputArray(int a[],int n){
	for(int i=0; i<n; i++){
		cout << a[i] << ' ';
	}
}

int main()
{
    int n; cin>>n;
    int *a = new int[n];
    inputArray(a,n);
    MergeSort(a,0,n-1);
    cout<<"Sorted Array: ";
    outputArray(a,n);// liet ke cac phan tu cach nhau boi 1 khoang cach

    cout<< "\nFind an element: ";
    int x; cin>>x;
    cout<<x<<endl;
    int result = binarySearch(a,n,0,n-1,x);
    if (result ==-1) cout<<x<<" is not found";
    else cout<<x<<" is found at the position " << result;

	return 0;
}

