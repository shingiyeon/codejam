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
const int inf = 999999999;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int t; cin >> t;
	for(int tc=1; tc<=t; tc++) {
		int A, B; cin >> A >> B;
		string str;  cin >> str;
		int dy[1001][2];
		int n = (int)str.size() - 1;
		if(str[0] == 'C') {
			dy[0][0] = 0; dy[0][1] = inf;
		}
		else if(str[0] == 'J') {
			dy[0][1] = 0; dy[0][0] = inf;
		}
		else dy[0][0] = dy[0][1] = 0;

		//cout << dy[0][0] << " " << dy[0][1] << "\n";
		for(int i=1; i<str.size(); i++) {
			if(str[i] == 'C') {
				dy[i][1] = inf;
				dy[i][0] = min(dy[i-1][0], dy[i-1][1] + B);
			}
			else if(str[i] == 'J') {
				dy[i][0] = inf;
				dy[i][1] = min(dy[i-1][1], dy[i-1][0] + A);
			}
			else {
				dy[i][0] = min(dy[i-1][0], dy[i-1][1] + B);
				dy[i][1] = min(dy[i-1][1], dy[i-1][0] + A);
			}
			//cout << dy[i][0] << " " << dy[i][1] << "\n";
		}

		cout << "Case #" << tc << ": " << min(dy[n][0], dy[n][1]) << "\n";
	}
}
