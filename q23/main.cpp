#include <iostream>
#include <vector>

using namespace std;

int answer = 0;

void tansaku(int n, int count){
    if(n == 0){
        if(count > 0) answer++;
        return;
    }
    tansaku(n-1, count+1);  //勝った場合
    if(count > 1)   tansaku(n-1, count-1);  //負けた場合
}

int main(){
    tansaku(24, 10);

    std::cout << answer << '\n';
}
