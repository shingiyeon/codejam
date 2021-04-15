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


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T; cin >> T;
	for(int tc=1; tc<=T; tc++) {
		int N; cin >> N;
		int arr[100];
		int tarr[100];
		vector<int> d[100];
		int ans = 0;
		for(int i=0; i<N; i++) {
			cin >> arr[i];
			tarr[i] = arr[i];
		}


		for(int i=0; i<N; i++) {
			vector<int> v;
			while(arr[i]) {
				v.push_back(arr[i] % 10);
				arr[i] /= 10;
			}
			for(auto it=v.rbegin(); it!=v.rend(); it++) {
				d[i].push_back(*it);
			}
		}


		for(int i=1; i<N; i++) {
			if(d[i].size() > d[i-1].size()) continue;
			else if(d[i].size() == d[i-1].size()) {
				bool tmp = false;
				for(int j=0; j<d[i].size(); j++) {
					if(d[i][j] > d[i-1][j]) {
						tmp = true;
						continue;
					}
					else if(d[i-1][j] > d[i][j]) break;
				}
				if(!tmp) {
					d[i].push_back(0);
					ans++;
				}
			}
			else {
				int state = 0;
				for(int j=0; j<d[i].size(); j++) {
					if(d[i-1][j] > d[i][j]) {
						state = -1;
						break;
					}
					else if(d[i-1][j] < d[i][j]) {
						state = 1;
						break;
					}
				} 
				// cout << "state: " << state << "\n";
				if(state == 1) {
					for(int j=d[i].size(); j<d[i-1].size(); j++) {
						d[i].push_back(0);
						ans++;
					}
					continue;
				}
				else if(state == -1) {
					for(int j=d[i].size(); j<=d[i-1].size(); j++) {
						d[i].push_back(0);
						ans++;
					}
					continue;
				}

				bool t = true;
				for(int j=d[i-1].size()-1; j>=d[i].size(); j--) {
					if(d[i-1][j] != 9) {
						for(int k=d[i].size(); k<=j-1; k++) {
							d[i].push_back(d[i-1][k]);
							ans++;
						}
						d[i].push_back(d[i-1][j] + 1);
						ans++;
						for(int k=j+1; k<d[i-1].size(); k++) {
							d[i].push_back(0);
							ans++;
						}
						t = false;
						break;
					}
				}
				if(t) {
					d[i].push_back(0);
					ans++;
					for(int j=d[i].size(); j<=d[i-1].size(); j++) {
						d[i].push_back(0);
						ans++;
					}
				}
			}

		}

		// for(int i=0; i<N; i++) {
		// 	cout << tarr[i] << " ";
		// 	for(int j=0; j<d[i].size(); j++) cout<<d[i][j];
		// 	cout<<"\n";
		// }
		 cout << "Case #" << tc << ": " << ans << "\n";
	}
}