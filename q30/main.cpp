#include <iostream>
#include <map>

using namespace std;

const int N = 20;
map<int, int> memo;

int set_tap(int remain){
    if(memo[remain] != 0) return memo[remain];

    int count = 0;
    for(int i = 1; i <= remain / 2; i++){
        if(remain - i == i) count += set_tap(i) * (set_tap(i) + 1) / 2;
        else count += set_tap(remain - i) * set_tap(i);
    }
    for(int i = 1; i <= remain / 3; i++){
        for(int j = i; j <= (remain - i) / 2; j++){
            if((remain - (i+j) == i) && (i==j))
                count += set_tap(i) * (set_tap(i) + 1) * (set_tap(i) + 2) / 6;
            else if(remain - (i + j) == i)
                count += set_tap(i) * (set_tap(i) + 1) * set_tap(j) / 2;
            else if(i == j)
                count += set_tap(remain - (i + j)) * set_tap(i) * (set_tap(i) + 1) / 2;
            else if(remain - (i + j) == j)
                count += set_tap(j) * (set_tap(j) + 1) * set_tap(i) / 2;
            else
                count += set_tap(remain - (i + j)) * set_tap(j) * set_tap(i);
        }
    }
    memo[remain] = count;
    return count;
}
int main(){
    memo[1] =  1;
    cout << set_tap(N) << endl;
}
