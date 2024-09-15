#include<bits/stdc++.h>
using namespace std;

int DemChuCaiThuong(string s){
    stringstream ss(s);
    string word;
    int cnt = 0;
    while(ss >> word){
        int check = 0;
        for(int i=0; i<word.size(); i++)
            if(isupper(word[i]) || isdigit(word[i]) || !isalpha(word[i]))
            {
                check = 1;
                break;
            }
        if(check == 0)
            ++cnt;
    }
    return cnt;
}
int main(){
    string s;
    getline(cin, s);
    cout << DemChuCaiThuong(s);
}
