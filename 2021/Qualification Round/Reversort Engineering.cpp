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
		int a, b; cin >> a >> b;
		if(b < a-1 || b > a*(a+1)/2 - 1) {
			cout << "Case #" << tc << ": IMPOSSIBLE\n";
			continue; 
		} 
		vector<int> ans(a+1, 0);
		vector<int> v;
		for(int i=0; i<a; i++) {
			v.push_back(i);
		}
		bool flag = true;
		for(int i=0; i<a-1; i++) {
			int num = min(a-i, b-(a-i-2));
			ans[v[i+num-1]] = i+1;
			for(int j=i; j<=(i+i+num-1)/2; j++) {
				swap(v[j], v[i+num-1+i-j]);
			}
			b -= num;
		}
			
		cout << "Case #" << tc << ": ";
		for(int i=0; i<a; i++) {
			if(ans[i]) cout << ans[i] << " ";
			else cout << a << " ";
		}
		cout << "\n";
	}
}
