#include <iostream>
int main(){
    int count = 0;
    for(int i = 1; i <= 10000; i++){
        int n = 0;
        if(i % 2 == 0) n = i * 3 +1;
        else n = i;
        while(true){
            if(n % 2 == 0) n /= 2;
            else n = n * 3 + 1;

            if(n == 1) break;
            if(n == i){
                count++;
                break;
            }
        }
    }
    std::cout << count << '\n';
}
