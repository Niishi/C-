#include <utility>
#include <vector>
#include <iostream>
using namespace std;
int main(){
    std::vector<pair<int, int>> vc;
    int n;
    cin >> n;
    while(n--){
        int x, y;
        cin >> x >> y;
        vc.push_back(pair<int, int>(x,y));
    }
    pair<int, int> p = vc.front();
    cout << p.first << p.second << '\n';
}
