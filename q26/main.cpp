#include <iostream>

using namespace std;

void tansaku(){

}
int main(){
    int n = 3;
    int m = 2;
    int parking[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            parking[i][j] = 1;
        }
    }
    parking[0][0] = 2;
    parking[n-1][m-1] = 0;
}
