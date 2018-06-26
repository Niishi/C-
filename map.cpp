#include <map>
#include <iostream>
using namespace std;

int main(){
    map<char, int> mp;
    mp['a'] = 1;
    mp['b'] = 2;
    mp.insert(map<char, int>::value_type('c', 3)); // 長い
	if(mp.find('c') != mp.end())
		cout << mp['c'] << '\n';
}
