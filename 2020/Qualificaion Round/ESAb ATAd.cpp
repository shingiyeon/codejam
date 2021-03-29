#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <functional>
#include <math.h>
using namespace std;

int query(int num) {
	cout << num << "\n";
	cout.flush();
	int bit; cin >> bit;
	return bit;
}

char query2(vector<int> ans) {
	for(auto val: ans) {
		cout << val;
	}
	cout << "\n";
	cout.flush();
	char correct; cin >> correct;
	return correct;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int t, B; cin >> t >> B;
	if(B == 10) {
		while(t--) {
			vector<int> ans;
			for(int i=1; i<=10; i++) {
				ans.push_back( query(i) );
			}
			char isC = query2(ans);
			if(isC == 'N') return 0;
		}
	}
}
