#include <iostream>

using namespace std;

int main(){
    int n = 16;
    int pair[n / 2 + 1];
    pair[0] = 1;

    for(int i = 1; i <= n/2; i++){
        pair[i] = 0;
        for(int j = 0; j < i; j++){
            pair[i] += pair[j] * pair[i-j-1];
        }
    }

    std::cout << pair[n/2] << '\n';
}
