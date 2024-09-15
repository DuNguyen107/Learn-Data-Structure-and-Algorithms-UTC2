
/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
string
###End banned keyword*/

#include<iostream>
#include<cstring>
using namespace std;

//###INSERT CODE HERE -

int countWords(char s[]){
    int cnt = 0;
    if(s[0] == ' '){
        cnt--;
    }
    int i=1;
    while(s[i] != '\0'){
        if(isalpha(s[i])){
            if(s[i-1] == ' ' && s[i+1] != ' ')
            cnt++;
        }
        ++i;
    }
    return cnt+1;
}

int main()
{

   char s[256];
   cin.getline(s, 256);

   cout << countWords(s) << endl;
    return 0;
}
