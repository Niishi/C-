#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> v){
    for(auto x : v){
        cout << x << " ";
    }
}

int main(){
    int n = 10;
    vector<int> v;
    int a = 2;
    while(true){
        bool is_ok = true;
        for(int b = 2; b < a; b++){
            if(a % b == 0){
                is_ok = false;
                break;
            }
        }
        if(is_ok){
            v.push_back(a);
            n--;
            if(n==0) break;
        }
        a++;
    }
    printVector(v);
}
