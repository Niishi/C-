#include <utility>
#include <vector>
#include <iostream>
using namespace std;
int answer = 0;
std::vector<pair<int, int> > dirs;
typedef pair<int,int> P;
void move(std::vector<P> tansakuzumi, pair<int,int>nowpos, pair<int,int>dir, int n){

    nowpos.first = nowpos.first + dir.first;
    nowpos.second = nowpos.second + dir.second;
    for(int i = 0; i < (int)tansakuzumi.size(); i++){
        if(tansakuzumi[i].first == nowpos.first && tansakuzumi[i].second == nowpos.second){
            return;
        }
    }
    if(n == 11){
        answer++;
        return;
    }
    tansakuzumi.push_back(nowpos);
    for(int i = 0; i < (int)dirs.size(); i++){
        move(tansakuzumi, nowpos, dirs[i], n+1);
    }
}

int main(){
    dirs.push_back(pair<int, int>(1,0));
    dirs.push_back(pair<int, int>(0,1));
    dirs.push_back(pair<int, int>(-1,0));
    dirs.push_back(pair<int, int>(0,-1));

    std::vector< pair<int, int> > tansakuzumi;
    pair<int, int> nowpos(0,0);
    tansakuzumi.push_back(nowpos);
    for(int i = 0; i < (int)dirs.size(); i++){
        move(tansakuzumi, nowpos, dirs[i], 0);
    }
    std::cout << answer << '\n';
}
