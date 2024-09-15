/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
string
###End banned keyword*/
#include <iostream>
#include<cstring>
using namespace std;

//###INSERT CODE HERE -

void transformString(char s1[], char *s2) {
    int i = 0;
    while (s1[i] != '\0') {  // Dùng '\0' để kiểm tra ký tự kết thúc
        if (islower(s1[i])) {
            s2[i] = s1[i] - 32;  // Chuyển từ ký tự thường sang ký tự hoa
        } else if (isupper(s1[i])) {
            s2[i] = s1[i] + 32;  // Chuyển từ ký tự hoa sang ký tự thường
        } else if (!isalpha(s1[i]) && !isdigit(s1[i])) {
            if (s1[i] != '*' && s1[i] != ' ') {
                s2[i] = '*';  // Thay thế các ký tự đặc biệt bằng '*'
            } else {
                s2[i] = s1[i];  // Giữ nguyên ký tự '*'
            }
        } else if (isdigit(s1[i])) {
            s2[i] = s1[i];  // Giữ nguyên các ký tự số
        }
        i++;
    }
    s2[i] = '\0';  // kết thúc bằng '\0'
}


int main()
{
    char s1[200], s2[200];
    cout<<"Nhap chuoi = ";
    cin.getline(s1, 199);
    transformString(s1, s2); //khong dung duoc ham toupper, tolower
    cout<<"\ns1="<<s1<<endl;
    cout<<"s2="<<s2;

    return 0;
}
