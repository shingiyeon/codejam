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
#include <unordered_map>
#include <unordered_set>
using namespace std;

long long p(int a, int b) {
	long long tmp = 1;
	while(b) {
		if(b % 2) tmp *= a;
		tmp = tmp * tmp;
		b /= 2;
	}
	return tmp;
}

pair<long long, long long> bf(long long state, vector<int> &v) {
	if(state == 0) {
		return {0, 1};
	}
	long long tp = p(2, v.size()-1);
	int idx = v.size() - 1;
	while(tp) {
		if(state >= tp) {
			auto tbf = bf(state - tp, v);
			return {v[idx] + tbf.first, v[idx] * tbf.second};
		}
		tp /= 2;
		idx--;
	}
	// cout << "JotBug" <<"\n";
} 

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int T; cin >> T;
	for(int tc=1; tc<=T; tc++) {
		int M; cin >> M;
		vector<int> v;
		long long sum = 0;
		long long ans = 0;
		for(int i=1; i<=M; i++) {
			int p, n; cin >> p >> n;
			for(int j=1; j<=n; j++) v.push_back(p);
			sum += (long long) p * n;
		}
		//cout << sum << "\n";

		for(long long i = p(2, (int)v.size()) -1; i >= 0; i--) {
			auto b = bf(i, v);
			// cout << b.first << " " << b.second << "\n";
			if(b.first + b.second == sum) {
				ans = max(b.second, ans);
			}
		}
		cout << "Case #" << tc << ": " << ans << "\n";
		

	}
}