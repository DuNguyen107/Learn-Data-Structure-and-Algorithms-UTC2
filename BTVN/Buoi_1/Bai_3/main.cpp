//Kiểm tra mảng toàn số giai thừa
#include <iostream>

using namespace std;

void inputArray(int a[], int &n){
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
}

void outputArray(int a[], int n){
	for(int i=0; i<n; i++){
		cout << a[i] << " ";
	}
}

long long Factorial (int n){
	long long giaithua = 1;
	for(int i=2; i<=n; i++){
		giaithua *= i;
	}
	return giaithua;
}


int isFactorial(int n){
	for(int i=0; ; i++){
		long long f = Factorial(i);
        if(f == n)
            return 1;
        if(f > n)
            return 0;
	}
}

int isTotalFactorial(int a[], int n){
	for(int i=0; i<n; i++){
		if(!isFactorial(a[i]))
			return 0;
	}
	return 1;
}

long long maxFactorial (int a[], int n){
	long long max_cur = 0;
	for(int i=0; i<n; i++){
		if(isFactorial(a[i]) && a[i] > max_cur)
			max_cur = a[i];
	}
	return max_cur;
}

int main()
{
    int n, a[100];
    inputArray(a,n);
    cout<<"Array:"<<endl;
    outputArray(a,n);
    cout<<endl;

    if (isTotalFactorial (a,n)==1)
    {
        cout <<"Mang toan so giai thua"<<endl;
        cout << "So giai thua lon nhat: "<<maxFactorial (a,n);
    }
    else cout<<"Mang khong phai chua toan cac so giai thua";

    return 0;
}
