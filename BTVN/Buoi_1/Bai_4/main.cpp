#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    char s[n];
    set<char> se;
    for(int i=0; i<n; i++){
        cin >> s[i];
        if(islower(s[i]))
            s[i] -= 32;
        if(isalpha(s[i]))
            se.insert(s[i]);
    }
    cout << 26 - se.size();
}
