#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <functional>
#include <math.h>
#include <utility>
using namespace std;


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int t; cin >> t;
	for(int tc=1; tc<=t; tc++) {
		int n; cin >> n;
		vector<pair<int, pair<int, int> >  > v;
		vector<char> ans(n+1);
		for(int i=1; i<=n; i++) {
			int s, e; cin >> s >> e;
			v.push_back({s, {1, i}});
			v.push_back({e, {-1, i}});
		}
		sort(v.begin(), v.end());

		bool flag = true;
		int num = 0;
		for(auto info: v) {
			int time = info.first;
			int index = info.second.second; int diff= info.second.first;
			if(diff == -1) {
				int tn;
				if(ans[index] == 'J') tn = 2;
				else tn = 1;
				num &= tn;
			}

			if(diff == 1) {
				if(num == 0) {
					ans[index] = 'C';
					num = 2;
				}
				else if(num == 1) {
					ans[index] = 'C';
					num |= 2;
				}
				else if(num == 2) {
					ans[index] = 'J';
					num |= 1;
				}
				else {
					flag = false;
				}
			}

		}
		
		cout << "Case #" << tc << ": ";
		if(!flag) cout << "IMPOSSIBLE";
		else {
			for(int i=1; i<=n; i++) cout << ans[i];
		}
		cout << "\n";
	}

}