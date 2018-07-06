const AND = 1;
const OR = 2;
const NONE = 3;

function calc_resistance(v){
    st = [];
    for(x of v){
        switch(x){
            case AND:
                a = st.pop();
                b = st.pop();
                st.push(a + b);
                break;
            case OR:
                a = st.pop();
                b = st.pop();
                st.push(1.0/(1.0/a + 1.0/b));
                break;
            case NONE:
                st.push(1.0);
                break;
        }
    }
    return st.pop();
}

var  answer = 0;
const GOLD = 1.6180339887;

function myabs(a){
    if(a < 0) return -a;
    else return a;
}
function set_resistance(resistances, n, diff){
    if(resistances.length == 19){
        const value = calc_resistance(resistances);
        if(myabs(GOLD - answer) > myabs(GOLD - value)){
            answer = value;
        }
    }
    for(x of [NONE, AND, OR]){
        if(x == NONE){
            if(n >= 10) continue;
            n++;
            diff++;
            resistances.push(x);
            set_resistance(resistances, n, diff);
            resistances.pop();
            n--;
            diff--;
        }else{
            if(diff < 1) break;
            diff--;
            resistances.push(x);
            set_resistance(resistances, n, diff);
            resistances.pop();
            diff++;
        }
    }
}

var resistances = [];
resistances.push(NONE);
resistances.push(NONE);
set_resistance(resistances, 2, 2);
alert(answer);
