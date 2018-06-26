#include <vector>
#include <string>
#include <sstream>
using namespace std;
vector<string> split(const string &str, char sep){
    vector<string> v;
    stringstream ss(str);
    string buffer;
    while(getline(ss, buffer, sep)){
        v.push_back(buffer);
    }
    return v;
}
