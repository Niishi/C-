#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <stack>
#include <cctype>
#include <algorithm>
using namespace std;

template < typename T > std::string to_string( const T& n )
{
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
}

bool check_int(std::string str)
{
    if (all_of(str.cbegin(), str.cend(), isdigit))
    {
        return true;
    }
    return false;
}

vector<string> split(const string &str, char sep){
    vector<string> v;
    stringstream ss(str);
    string buffer;
    while(getline(ss, buffer, sep)){
        v.push_back(buffer);
    }
    return v;
}

int main(){
    for(int i = 1000; i < 10000; i++){
        // string a = ;
        cout << to_string(i) << "\n";
    }
}

int calc(const string &a){
    vector<string> v = split(a, ' ');
    stack<string> st;
    // for(string word : v){
    //
    // }
}
