#include <vector>
#include <iostream>
using namespace std;
int main(){
    std::vector<int> vc;
    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        vc.push_back(x);
    }
    n = vc.size() /2;
    if(vc[n] == vc.at(n)){
        cout << n << '\n';
    }
}
