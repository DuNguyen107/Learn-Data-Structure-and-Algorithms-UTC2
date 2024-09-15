/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
string
###End banned keyword*/

#include <iostream>
#include<cstring>

using namespace std;

//###INSERT CODE HERE -

int size_char(char s[])
{
    int s_size = 0;
    int i=0;
    while(s[i] != '\0'){
        s_size++;
        ++i;
    }
    return s_size;
}

bool SoSanhBangNhauTheoSo(char s[], char t[]){
    if(size_char(s) != size_char(t))
        return false;
    int i=0;
    while(s[i] != '\0')
    {
        if(isalpha(s[i]) && !isalpha(t[i]))
            return 0;
        else if(!isalpha(s[i]) && isalpha(t[i]))
            return 0;
        else if(isdigit(s[i]) && !isdigit(t[i]))
            return 0;
        else if(!isdigit(s[i]) && isdigit(t[i]))
            return 0;
        else if(isdigit(s[i]) && isdigit(t[i]))
        {
            if(s[i] != t[i])
                return 0;
        }
        ++i;
    }
    return 1;
}

int main()
{
    char s[256], t[256];
    cin.getline(s,256);
    cin.getline(t,256);
    cout<<SoSanhBangNhauTheoSo(s,t);//so giong nhau, cung la chu cai

    return 0;
}
