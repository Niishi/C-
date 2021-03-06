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

double calc_resistance(vector<Kind>& v){
    stack<double> st;
    for(auto x : v){
        double a = 1;
        double b = 1;
        double value = 1;
        switch (x) {
            case AND:
                a = st.top();
                st.pop();
                b = st.top();
                st.pop();
                value = a + b;
                st.push(value);
                break;
            case OR:
                a = st.top();
                st.pop();
                b = st.top();
                st.pop();
                value = 1.0/(1.0/a + 1.0/b);
                st.push(value);
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
    cout << "start" << endl;
    set_resistance(resistances, 2, 2);
    cout << "end" << endl;
    cout << fixed;
    cout << setprecision(10) << answer << endl;
}
