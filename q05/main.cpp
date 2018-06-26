#include <iostream>

int max_count = 15;
int money = 1000;

int is_ok(int a, int b, int c, int d){
    if(money == 500*a + 100*b + 50*c + 10*d && (a+b+c+d) <= max_count) return true;
    else return false;
}

int main(){
    int answer = 0;
    int count = 0;
    for(int i = money/500; i >= 0; i--){
        if(is_ok(i,0,0,0)){
            count++;
            continue;
        }
        for(int j = money/100; j >= 0; j--){
            if(is_ok(i,j,0,0)) {
                count++;
                continue;
            }
            for(int k = 15; k >= 0; k--){
                if(is_ok(i,j,k,0)){
                    count++;
                    continue;
                }
                for(int l = 15; l >= 0; l--){
                    if(is_ok(i,j,k,l)) count++;
                }
            }
        }
    }
    std::cout << count << '\n';
}
