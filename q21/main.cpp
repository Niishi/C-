#include <iostream>
#include <vector>

using namespace std;

int my_xor(int a, int b){
    if(a != b) return 1;
    return 0;
}

int main(){
    int n = 2;
    vector<int> b;
    b.push_back(1);
    b.push_back(1);

    int count = 0;
    while(true){
        n++;
        vector<int> a;
        a.push_back(1);
        for(int i = 1; i < n-1; i++){   //2番目からn-1番目まで代入
            int number = my_xor(b[i-1], b[i]);
            a.push_back(number);
            if(number == 0)count++;
        }
        a.push_back(1); //最後の1を追加
        if(count >= 2014) break;
        b = a;
    }
    std::cout << n << '\n';
}
