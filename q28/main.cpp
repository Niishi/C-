#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int max_area = 0;

void tansaku(vector<pair<int, int> > v, int current_area, int current_people){
    bool is_exist = false;
    for(int i = 0; i < (int)v.size(); i++){
        int next_people = v[i].second + current_people;
        if(next_people <= 150){
            is_exist = true;
            pair<int, int> p(v[i]);
            v.erase(v.begin() + i);
            tansaku(v, current_area + p.first, next_people);
            v.insert(v.begin() + i, p);
        }
    }
    if(!is_exist){
        if(current_area > max_area) max_area = current_area;
    }
}

int main(){
    vector<pair<int, int> > v;
    v.push_back(pair<int, int>(11000,40));
    v.push_back(pair<int, int>(7000 ,40));
    v.push_back(pair<int, int>(8000 ,30));
    v.push_back(pair<int, int>(400  ,24));
    v.push_back(pair<int, int>(800  ,20));
    v.push_back(pair<int, int>(1800 ,16));
    v.push_back(pair<int, int>(1000 ,15));
    v.push_back(pair<int, int>(900  ,14));
    v.push_back(pair<int, int>(300  ,12));
    v.push_back(pair<int, int>(100  ,10));

    tansaku(v, 0, 0);

    std::cout << max_area << '\n';

}
