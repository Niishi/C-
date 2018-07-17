#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> split(string strFull, string punc){
    vector<string> v;
    int i=0;
	while((i = strFull.find(punc)) != string::npos){
		v.push_back(strFull.substr(0,i));
		strFull = strFull.substr(i+1);
	}
	v.push_back(strFull);
    return v;
}

int answer = 0;

void addKaruta(string karuta, map<char, vector<string> >& karuta_map, int n){
    if(karuta_map.find(karuta[n]) == karuta_map.end()){
        vector<string> v;
        v.push_back(karuta);
        karuta_map[karuta[n]] = v;
    }else{
        karuta_map[karuta[n]].push_back(karuta);
    }
}

void search(map<char, vector<string> >& m, int n){
    for(auto x : m){
        answer++;
        if((int)x.second.size() > 1){
            map<char, vector<string> > new_map;
            for(auto karuta : x.second){
                addKaruta(karuta, new_map, n+1);
            }
            search(new_map, n+1);
        }
    }
}

int main(){
    ifstream ifs("q33.csv");
    string str;
    if(ifs.fail()){
        cerr << "失敗" << endl;
    }
    string a = u8"あいうえお";
    for(auto aa : a){
        std::cout << aa << '\n';
    }

    map<char, vector<string> > kaminoko_map;
    map<char, vector<string> > simonoku_map;
    bool is_first = true;
    while(getline(ifs, str)){
        if(is_first){
            is_first = false;
            continue;
        }
        vector<string> words = split(str, ",");
        string kaminoko = words[3];
        string simonoku = words[4];
        addKaruta(kaminoko, kaminoko_map, 0);
        addKaruta(simonoku, simonoku_map, 0);
    }
    search(kaminoko_map, 0);
    search(simonoku_map, 0);

    cout << answer << endl;
}
