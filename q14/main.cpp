#include <utility>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

typedef std::pair<char,char> P;

int max_count = 0;
vector<string> answer_path;

void siritori(string word, vector<string> words, int count, vector<string> path){
    bool is_exist = false;
    for(int i = 0; i < (int)words.size(); i++){
        string next_word = words[i];
        if(word[word.length()-1] == next_word[0]){
            //再帰前処理
            words.erase(words.begin() + i);
            path.push_back(next_word);

            //再帰
            siritori(next_word, words, count+1, path);

            //バックトラック
            words.insert(words.begin() + i, next_word);
            path.pop_back();
            is_exist = true;
        }
    }
    if(!is_exist && count > max_count){
        max_count = count;
        answer_path = path;
    }
}

int main(){
    vector<string> name_list;
    name_list.push_back("brazil");
    name_list.push_back("croatia");
    name_list.push_back("mexico");
    name_list.push_back("cameroon");
    name_list.push_back("spain");
    name_list.push_back("netherlands");
    name_list.push_back("chile");
    name_list.push_back("australia");
    name_list.push_back("colombia");
    name_list.push_back("greece");
    name_list.push_back("cote d'lvoire");
    name_list.push_back("japan");
    name_list.push_back("uruguay");
    name_list.push_back("costa rica");
    name_list.push_back("england");
    name_list.push_back("italy");
    name_list.push_back("switzerland");
    name_list.push_back("ecuador");
    name_list.push_back("france");
    name_list.push_back("honduras");
    name_list.push_back("argentina");
    name_list.push_back("bosnia and herzegovina");
    name_list.push_back("iran");
    name_list.push_back("nigeria");
    name_list.push_back("germany");
    name_list.push_back("portugal");
    name_list.push_back("ghana");
    name_list.push_back("usa");
    name_list.push_back("belgium");
    name_list.push_back("algeria");
    name_list.push_back("russia");
    name_list.push_back("korea republic");

    vector<string> path;
    for(int i = 0; i < (int)name_list.size(); i++){
        string word = name_list[i];
        name_list.erase(name_list.begin() + i);
        path.push_back(word);
        siritori(word, name_list, 1, path);
        name_list.insert(name_list.begin() + i, word);
        path.pop_back();

    }

    cout << max_count << '\n';

    string tab = "";
    for(int i = 0; i < (int)answer_path.size(); i++){
        cout << tab << answer_path[i];
        tab = " => ";
    }
}
