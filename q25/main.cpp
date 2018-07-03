#include <iostream>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int,int> P;

int answer = 0;

bool is_cross(P a, P b){
    int a1 = a.first;
    int a2 = a.second;
    if(a1 > a2){
        int tmp = a1;
        a1 = a2;
        a2 = tmp;
    }
    return (a1 < b.first && b.first < a2) || (a1 < b.second && b.second < a2);
}

int keisan(vector<P> v){
    int count = 0;
    for(int i = 1; i < (int)v.size(); i++){
        P one = v[i];
        for(int j = 0; j < i; j++){
            P another = v[j];
            if(is_cross(one, another)) count++;
        }
    }
    return count;
}

void tansaku(bool is_right, vector<int> left, vector<int> right, vector<P> v, int start){
    if(is_right){
        if(right.empty()){
            v.push_back(P(start,0));
            tansaku(false, left, right, v, 0);
        }
        for(int i = 0; i < (int)right.size(); i++){
            int end = right[i];
            P p(start, end);
            v.push_back(p);
            right.erase(right.begin() + i);
            tansaku(false, left, right, v, end);
            v.pop_back();
            right.insert(right.begin() + i, end);
        }
    }else{
        if(left.empty()){
            int count = keisan(v);
            if(count > answer) answer = count;
            return;
        }
        for(int i = 0; i < (int)left.size(); i++){
            int end = left[i];
            P p(end, start);
            v.push_back(p);
            left.erase(left.begin() + i);
            tansaku(true, left, right, v, end);
            v.pop_back();
            left.insert(left.begin() + i, end);
        }
    }
}

int main(){

    int n = 12;
    vector<int> left;
    vector<int> right;
    vector<P> v;
    for(int i = 1; i < n/2; i++){
        left.push_back(i);
        right.push_back(i);
    }
    tansaku(true, left, right, v, 0);

    std::cout << answer << '\n';
}
