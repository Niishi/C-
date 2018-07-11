#include <iostream>
#include <vector>
#include "Point.h"
using namespace std;

const int N = 6;

const int USED = 1;
const int UN_USED = 0;
const int NONE = -1;

const int YOKO = 2;
const int SHITA = 3;



int answer = 0;

Point points[7][7];
Point getPoint(int r, int c){
    return points[r][c];
}


Point::Point(int rr, int cc) : r(rr), c(cc){
    if(this->c != N) edge_migi = UN_USED;
    else edge_migi = NONE;
    if(this->r != N) edge_shita = UN_USED;
    else edge_shita = NONE;
    if(this->r != 0) edge_ue = UN_USED;
    else edge_ue = NONE;
    if(this->c != 0) edge_hidari = UN_USED;
    else edge_hidari = NONE;
};

void Point::set_road(int dir, bool unset){
    switch (dir) {
        case YOKO:
            if(!unset)edge_hidari = USED;
            else edge_hidari = UN_USED;
            break;
        case SHITA:
            if(!unset) edge_ue = USED;
            else edge_ue = UN_USED;
            break;
    }
}


void Point::move(bool is_return_path){

    if(!is_return_path && this->r == N && this->c == N){
        is_return_path = true;
        this->move(is_return_path);
    }
    if(is_return_path && this->r == 0 && this->c == 0){
        answer++;
        return;
    }
    if(!is_return_path){
        if(edge_migi == UN_USED){
            edge_migi = USED;
            Point next = getPoint(r,c+1);
            next.set_road(YOKO, false);
            next.move(is_return_path);
            next.set_road(YOKO, true);
            edge_migi = UN_USED;
        }
        if(edge_shita == UN_USED){
            edge_shita = USED;
            Point next = getPoint(r + 1, c);
            next.set_road(SHITA, false);
            next.move(is_return_path);
            next.set_road(SHITA, true);
            edge_shita = UN_USED;
        }
    }else{
        if(edge_hidari == UN_USED){
            edge_hidari = USED;
            getPoint(r, c - 1).move(is_return_path);
            edge_hidari = UN_USED;
        }
        if(edge_ue == UN_USED){
            edge_ue = USED;
            getPoint(r - 1, c).move(is_return_path);
            edge_ue = USED;
        }
    }
}




int main(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            points[i][j] = Point(i,j);
        }
    }

    points[0][0].move(false);

    cout << answer << endl;
}
