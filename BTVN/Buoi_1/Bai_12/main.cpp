/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
string
###End banned keyword*/

#include <iostream>
#include<cstring>

using namespace std;

//###INSERT CODE HERE -

void ThayTheKyTuChuCai(char *s, char x){
    char s2[256];
    int i=0;
    while(s[i] != '\0'){
        if(isalpha(s[i]))
            s[i] = x;
        ++i;
    }
}

int main()
{
    char s[256];
    cin.getline(s,256);
    char x;
    cin>>x;
    ThayTheKyTuChuCai(s,x); // Ham thay the cac ky tu chu cai co trong chuoi s thanh ky tu x
    cout<<s;
    return 0;
}