#include <string>
#include <iostream>
using namespace std;
int main(){
    string str;
    str = "this is a string";
    str[2] = 'a';
    str[3] = 't';
    if(str.length() >= 5){
        cout << str << '\n';
    }
    if(str.find("is") != string::npos){
        cout << str.find("is") << '\n';
    }
}
