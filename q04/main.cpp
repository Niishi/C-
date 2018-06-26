#include <iostream>
void cutbar(int m, int n) {
    int count = 0;
    int current = 1;
    while(n > current){
        if(current < m) current += current;
        else current += m;
        count++;
    }
    std::cout << count << '\n';
}
int main(){
    cutbar(3, 20);
    cutbar(5, 100);
}
