const square = 6;
let count = 0;
let is_used = new Array();
for(var i = 0; i <= square; i++){
    is_used[i] = new Array();
    for(var j = 0; j <= square; j++){
        is_used[i][j] = new Array(false, false);    //0番目が右方向、1番目が下方向
    }
}

function route(x, y, is_first_time){
    if(x == square && y == square){
        if(is_first_time){
            route(0, 0, false);
        }else{
            count++;
        }
    }
    if(x < square){
        if(!is_used[x][y][0]){
            is_used[x][y][0] = true;
            route(x+1,y,is_first_time);
            is_used[x][y][0] = false;
        }
    }
    if(y < square){
        if(!is_used[x][y][1]){
            is_used[x][y][1] = true;
            route(x, y + 1, is_first_time);
            is_used[x][y][1] = false;
        }
    }
}

route(0,0,true);
console.log(count);
