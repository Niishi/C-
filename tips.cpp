//swap
#include <algorithm>
using namespace std;
int main(){
    int a = 1;
    int b = 5;
    swap(a, b);
}

//sort
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    std::vector<int> vc;
    while(n--){
        int x;
        cin >> x;
        vc.push_back(x);
    }
    sort(vc.begin, vc.end());

    int arr[N];
    sort(arr, arr + N);	// 先頭のポインタ, 先頭のポインタ+要素数
    arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	sort(arr, arr+9, greater<int>());
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void) {
	int n;
	cin >> n;
	vector<int> vc;
	while(n--) {
		int x;
		cin >> x;
		vc.push_back(x);
	}
	sort(vc.begin(), vc.end());	// 二分探索なので必ずソートしておく

	int x;
	cin >> x;
	if(binary_search(vc.begin(), vc.end(), x))	//binary_searchはtrue, falseを返す
		cout << "I found " << x << '\n';
	vector<int>::iterator lit = lower_bound(vc.begin(), vc.end(), x);	// lower_boundは指定された値"以上"の値が初めて現れた位置のイテレータを返す
	vector<int>::iterator uit = upper_bound(vc.begin(), vc.end(), x);	// upper_boundは指定された値を"超える"値が初めて現れた位置のイテレータを返す
	if(lit != vc.end() && lit != uit)
		cout << uit - lit << '\n';	// この場合, ult - lit は vc 中の x の個数になる
}
