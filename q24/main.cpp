#include <iostream>

using namespace std;

int answer = 0;

bool check_over(int a[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(a[i][j] != 0) return false;
        }
    }
    return true;
}

bool check_shoot_migi(int a[3][3], int i, int j){
    return (i != 1 && j < 2 && a[i][j+1] > 0);
}

bool check_shoot_sita(int a[3][3], int i, int j){
    return (j != 1 && i < 2 && a[i+1][j] > 0);
}

void tansaku(int a[3][3]){
    if(check_over(a)){
        answer++;
        return;
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(a[i][j] != 0){
                a[i][j] = 0;
                tansaku(a);
                if(check_shoot_migi(a, i, j)){
                    a[i][j+1] = 0;
                    tansaku(a);
                    a[i][j+1] = 1;
                }
                if(check_shoot_sita(a, i, j)){
                    a[i+1][j] = 0;
                    tansaku(a);
                    a[i+1][j] = 1;
                }
                a[i][j]=1;
            }
        }
    }
}

int main(){
    int a[][3] ={{1,2,3},
                 {4,5,6},
                 {7,8,9}};
    tansaku(a);
    cout << answer << endl;
}
