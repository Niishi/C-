#include <iostream>
#include <vector>
using namespace std;

bool is_seisubai(int n, vector<int> v){
    for(int i = 0; i < (int)v.size(); i++){
        if(v[i] % n == 0) return true;
    }
    return false;
}

int main(){
    vector<int> answers;
    for(int i = 4; i <= 500; i+=4){
        if(is_seisubai(i, answers)) continue;

        int seihoukei_length = i / 4;
        int seihoukei_area = seihoukei_length * seihoukei_length;
        int max_len = i/4;
        for(int j = 1; j < max_len - 1; j++){
            for(int k = j + 1; k < max_len; k++){
                int r1 = j * (i/2 - j);
                int r2 = k * (i/2 - j);
                if(seihoukei_area == r1 + r2) {
                    answers.push_back(i);
                }
            }
        }
    }

    cout << (int)answers.size() << endl;
}
