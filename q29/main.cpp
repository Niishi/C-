#include <iostream>
#include <vector>
#include <stack>
#include <math.h>
#include <complex>
#include <iomanip>

using namespace std;


typedef enum enm {
    AND,
    OR,
    NONE,
} Kind;

double calc_resistance(vector<Kind> v){
    stack<double> st;
    for(auto x : v){
        switch (x) {
            case AND:
                st.push(st.top() + st.top());
                st.pop();
                st.pop();
                break;
            case OR:

                st.push(1.0/(1.0/st.top() + 1.0/st.top()));
                st.pop();
                st.pop();
                break;
            case NONE:
                st.push(1.0);
                break;
        }
    }
    return st.top();
}
double answer = 0;
const double GOLD = 1.6180339887;
void set_resistance(vector<Kind> resistances, int n, int diff){
    if((int)resistances.size() == 19){
        double value = calc_resistance(resistances);
        if(abs(GOLD - answer) > abs(GOLD - value)){
            answer = value;
        }

    }else{
        for(auto x : {NONE, AND, OR}){
            if(x == NONE){
                if(n >= 10) continue;
                n++;
                diff++;
                resistances.push_back(x);
                set_resistance(resistances, n, diff);
                resistances.pop_back();
                n--;
                diff--;
            }else{
                if(diff < 1) break;

                diff--;
                resistances.push_back(x);
                set_resistance(resistances, n, diff);
                resistances.pop_back();
                diff++;
            }
        }
    }
}
int main(){
    vector<Kind> resistances;
    resistances.push_back(NONE);
    resistances.push_back(NONE);

    set_resistance(resistances, 2, 2);

    cout << fixed;
    cout << setprecision(10) << answer << endl;
}
