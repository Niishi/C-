#include <iostream>
#include <map>

using namespace std;

map<int, int> memo;
int step(int n){
    // if(n == 2) return 1;
    // if(n == 3) return 2;
    if(memo.find(n) != memo.end()) return memo[n];

    int count = 0;
    for(int i = 1; i <= 4; i++){
        if(i >= n) break;
        for(int j = 1; j <= 4; j++){
            if(i + j == n){
                count++;
                break;
            }
            if(i + j < n){
                count += step(n - i - j);
            }
        }
    }
    memo[n] = count;
    return count;
}
int main(){
    cout << step(20);
}
