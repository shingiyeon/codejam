#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <functional>
#include <math.h>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int t; cin >> t;
	for(int tc = 1; tc <= t; tc++) {
		string str; cin >> str;
		vector<int> v(str.size());
		vector<int> open, close;

		int dy[10][105];
		for(int i=0; i<=9; i++) {
			for(int j=0; j<105; j++) dy[i][j] = 0;
		}

		for(int i=0; i<v.size(); i++) {
			v[i] = str[i] - '0';
		}

		for(int i=1; i<=9; i++) {
			for(int j=0; j<v.size(); j++) {
				if(v[j] >= i) {
					dy[i][j] = 1;
				}
			}
		}

		// for(int i=1; i<=9; i++) {
		// 	for(int j=0; j<v.size(); j++) {
		// 		cout << dy[i][j] << " ";
		// 	}
		// 	cout << "\n";
		// }

		for(int i=1; i<=9; i++) {
			bool flag = false;
			for(int j=0; j<v.size(); j++) {
				if(!flag && dy[i][j]) {
					open.push_back(j);
					flag = true;
				}
				else if(flag && !dy[i][j]) {
					close.push_back(j-1);
					flag = false;
				}
			}
			if(flag) close.push_back(v.size()-1);
		}

		sort(open.begin(), open.end());
		sort(close.begin(), close.end());

		cout << "Case #" << tc << ": ";

		for(int i=0; i<v.size(); i++) {
			while(!open.empty() && open.front() == i) {
				cout << "(";
				open.erase(open.begin());
			}
			cout << v[i];
			while(!close.empty() && close.front() == i) {
				cout << ")";
				close.erase(close.begin());
			}
		}
		cout << "\n";
	}
}