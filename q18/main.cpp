#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

bool is_ok = false;

vector<int>::iterator find(vector<int> v, int n){
    for(vector<int>::iterator itr = v.begin(); itr != v.end(); itr++){
        if(*itr == n){
            return itr;
        }
    }
    return v.end();
}

void tansaku(vector<int> numbers, vector<int> square_numbers, int pre_number){
    if((int)numbers.size() == 0){
        vector<int>::iterator iter;
        bool is_exist = false;
        for(vector<int>::iterator itr = square_numbers.begin(); itr != square_numbers.end(); itr++){
            if(*itr == pre_number+1){
                iter = itr;
                is_exist = true;
            }
        }
        if(is_exist){
            is_ok = true;
            return;
        }
    }

    for(int i = 0; i < (int)numbers.size(); i++){
        if(is_ok) return;
        int next_number = numbers[i];
        bool is_exist = false;
        for(vector<int>::iterator itr = square_numbers.begin(); itr != square_numbers.end(); itr++){
            if(*itr == pre_number+next_number){
                is_exist = true;
            }
        }
        if(is_exist){
            numbers.erase(numbers.begin() + i);

            tansaku(numbers, square_numbers, next_number);

            numbers.insert(numbers.begin() + i, next_number);
        }
    }
}

void printVector(vector<int> v){
    for(int i = 0; i < (int)v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

int main(){
    int n = 5;
    while(true){
        vector<int> numbers;
        vector<int> square_numbers;
        for(int i = 2; i <= n; i++){
            numbers.push_back(i);
        }
        for(int i = 1; i <= sqrt(2 * n - 1); i++){
            square_numbers.push_back(i * i);
        }
        tansaku(numbers, square_numbers, 1);
        if(is_ok){
            std::cout << n << '\n';
            break;
        }
        n++;
    }
}
