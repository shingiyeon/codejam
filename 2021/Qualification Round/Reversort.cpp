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
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int t; cin >> t;
	for(int tc=1; tc<=t; tc++) {
		int n; cin >> n;
		vector<int> v;
		for(int i=0; i<n; i++) {
			int tmp; cin >> tmp; v.push_back(tmp);
		}
		int cost = 0;

		for(int i=0; i<n-1; i++) {
			int min_val = 999;
			int min_idx = -1;
			for(int j=i; j<n; j++) {
				if(v[j] < min_val) {
					min_val = v[j];
					min_idx = j;
				}
			}
			cost += min_idx - i + 1;
			for(int j=i; j<=(i+min_idx)/2; j++) {
				swap(v[j], v[min_idx+i-j]);
			}			
		}

		cout << "Case #" << tc << ": " << cost << "\n";

	}
}
