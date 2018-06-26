#include <iostream>
#include <map>

using namespace std;

map<int, int> answer_map;
void tansaku(int v[], int n, int total){
    total += v[n];
    answer_map[total]++;
    for(int i = n + 1; i < 16; i++){
        tansaku(v, i, total);
    }
}

int main(){
    int a[] =   {1, 2, 3, 4,
                 5, 6, 7, 8,
                 9, 10,10,11,
                 13,14,14,15};

    tansaku(a, 0, 0);

    int max_value = 0;
    int max_key = 0;
    for(auto iter = answer_map.begin(); iter != answer_map.end(); ++iter){
        if(iter->second > max_value){
            max_key = iter->first;
            max_value = iter->second;
        }
    }

    std::cout << max_key << '\n';

}
