/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
new
string
###End banned keyword*/

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

//###INSERT CODE HERE -
void MaHoaMatThu(char *s){
    if(islower(s[0])){
        int x = (int)s[0] - 97;
        cout << x;
    }
    else if(isupper(s[0])){
        int x = (int)s[0] - 65;
        cout << x;
    }else if(s[0] == ' ')
        cout << "-";
    else
        cout << s[0];
    int i=1;
    while(s[i] != '\0'){
        if(islower(s[i])){
            int x = (int)s[i] - 97;
            if(s[i-1] != ' ')
                cout << "." << x;
            else
                cout << x;
        }
        else if(isupper(s[i])){
            int x = (int)s[i] - 65;
            if(s[i-1] != ' ')
                cout << "." << x;
            else
                cout << x;
        }else if(s[i] == ' ')
            cout << "-";
        else
            cout << s[i];
        ++i;
    }
}

int main()
{
    char s[100];
    cin.getline(s,99);
    cout<<"Chuoi vua nhap: "<<s;
    cout<<"\nChuoi sau khi duoc ma hoa: ";
    MaHoaMatThu(s);

    return 0;
}
