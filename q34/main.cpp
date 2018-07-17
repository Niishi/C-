#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<bool> > Board;

int set(Board board, int x1, int y1, int x2, int y2){
    int answer = 0;
    //飛車のきき
    for(int i = 0; i < 9; i++){
        if(y1 == y2 && x1 < x2){
            if(i == x2) break;
        }
        if(y1 == y2 && x1 > x2){
            if(i <= x2) continue;
        }
        board[y1][i] = true;
    }
    for(int i = 0; i < 9; i++){
        if(x1 == x2 && y1 < y2){
            if(i == y2) break;
        }
        if(x1 == x2 && y1 > y2){
            if(i <= y2) continue;
        }
        board[i][x1] = true;
    }

    //角のきき
    
}

int main(){
    Board board;
    for(int i = 0; i < 9; i++){
        vector<bool> v;
        for(int j = 0; j < 9; j++){
            v.push_back(false);
        }
        board.push_back(v);
    }

}
