#include <iostream>

int main(){
    bool b[100];
    for(int i = 0; i < 100; i++){
        b[i] = false;
    }
    for(int i = 2; i <= 100; i++){
        for(int j = i-1; j <= 100; j += i){
            b[j] = !b[j];
        }
    }
    for(int i = 0; i < 100; i++){
        if(!b[i]) std::cout << i+1 << '\n';
    }
}
