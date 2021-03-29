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
	int tc = 1;
	int t; cin >> t;
	int arr[101][101];
	while(t--) {
		int n; cin >> n;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) cin >> arr[i][j];
		}
		int k = 0, r = 0, c = 0;
		int cnt[101];

		for(int i=1; i<=n; i++) {
			k += arr[i][i];
		}

		for(int i=1; i<=n; i++) {
			for(int j=1; j<=100; j++) cnt[j] = 0;
			for(int j=1; j<=n; j++) {
				cnt[arr[i][j]]++;
				if(cnt[arr[i][j]] >= 2) {
					r++;
					break;
				}
			}
		}

		for(int i=1; i<=n; i++) {
			for(int j=1; j<=100; j++) cnt[j] = 0;
			for(int j=1; j<=n; j++) {
				cnt[arr[j][i]]++;
				if(cnt[arr[j][i]] >= 2) {
					c++;
					break;
				}
			}
		}

		cout << "Case #" << tc << ": " << k << " " << r << " " << c << "\n";
		tc++;


	}

	
}